#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdint.h>
#include<errno.h>

/*   Field numbering
 *
 *        1
 *      2   3
 *    4   5   6
 *      7   8
 *        9
 */

/* Definitions */
#define STR_LEN 100 // max string length
#define N_FIGS 11 // number of possible figures

#define FIG_1 0b111010001 // 0x1d1 dragon 
#define FIG_2 0b100010111 // 0x117 reverse dragon
#define FIG_3 0b110010101 // 0x195 curly brace left
#define FIG_4 0b101010011 // 0x153 curly brace right
#define FIG_5 0b111101111 // 0x1ef hollow circle
#define FIG_6 0b111111111 // 0x1ff filled circle
#define FIG_7 0b100010001 // 0x111 middle road
#define FIG_8 0b010000100 // 0x84 little road left
#define FIG_9 0b001000010 // 0x42 little road right
#define FIG_10 0b111111001 // 0x1f9 arrow
#define FIG_11 0b100111111 // 0x13f reverse arrow

/* Figure data type */
typedef struct figure_s {
    uint8_t fignumber;
    uint8_t message[STR_LEN];
    uint16_t pattern;
    uint16_t points;
} figure_t;

/* Score set and "pretty name" for each figure */
figure_t figures[N_FIGS] = {
    {0, "Drache", FIG_1, 17},
    {1, "Vercherta Drache", FIG_2, 34},
    {2, "Linggi Gschweifti Chlammera", FIG_3, 15},
    {3, "Rächti Gschweifti Chlammera", FIG_4, 15},
    {4, "Chranz", FIG_5, 25},
    {5, "Babeli", FIG_6, 30},
    {6, "Grossi Strass", FIG_7, 10},
    {7, "Chlini Linggi Strass", FIG_8, 5},
    {8, "Chlini Rächti Strass", FIG_9, 17},
    {9, "Pfüû", FIG_10, 15},
    {10, "Vercherta Pfüû", FIG_11, 12},
};

/* Abort on failure */
static void die(const char *message)
{
    if(errno) {
        perror(message);
    } else {
        fprintf(stderr, "[ERROR] %s\n ", message);
    }

    exit(EXIT_FAILURE);
}

/* Turn a binary string into an integer */
static uint16_t binstr2int(char *str)
{
    uint16_t i = 0;

    while (*str != '\0' && *str != '\n') {
        if (*str != '0' && *str != '1') {
            die("Not a binary digit");
        }
        i = i*2 + (*str++ & 1);
    }

    return i;
}

/* Count the number of set bits in an integer */
static uint16_t count_set_bits(uint16_t in)
{
    uint16_t c;

    for (c = 0; in; c++) {
        in &= in-1; // clear lsb
    }

    return c;
}

/* Check incoming pattern for matches return figumber or -1 if no match*/
static int check_figures(uint16_t in)
{
    for(int i=1; i<(N_FIGS); i++) {
        if(in == figures[i].pattern) {
            return figures[i].fignumber;
        }
    }

    return -1;
}

int main(int argc, char **argv)
{
    uint16_t input=0;
    int n=0;

    if(argc!=2) {
        die("Exactly one argument required. Binary representation of field, see code.");
    }

    input = binstr2int(argv[1]);

    printf("[DEBUG]: Input: %d\n", input); // Debug print

    if((n=check_figures(input))>0) {
        printf("Figur: %s\nPunkte: %d\n", figures[n].message, figures[n].points);
    } else {
        printf("Keine Figur.\nPunkte: %d\n", count_set_bits(input));
    }

    return EXIT_SUCCESS;
}
