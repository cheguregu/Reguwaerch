#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>

/*   Field numbering
 *
 *        1
 *      2   3
 *    4   5   6
 *      7   8
 *        9
 *
 *  #define FIG_DRAGN1 0b111010001
 *  #define FIG_DRAGN2 0b100010111
 *  #define FIG_BRACEL 0b110010101
 *  #define FIG_BRACER 0b101010011
 *  #define FIG_CIRCLE 0b111101111
 *  #define FIG_STRIKE 0b111111111
 *  #define FIG_MDROAD 0b100010001
 *  #define FIG_LROADL 0b010000100
 *  #define FIG_LROADR 0b001000010
 *  #define FIG_ARROW1 0b111111001
 *  #define FIG_ARROW2 0b100111111
 */

/* Definitions */
#define STR_LEN 100 // max string length
#define N_FIGS 11 // number of possible figures

#define FIG_1 0x1d1 // dragon
#define FIG_2 0x117 // reverse dragon
#define FIG_3 0x195 // curly brace left
#define FIG_4 0x153 // curly brace right
#define FIG_5 0x1ef // hollow circle
#define FIG_6 0x1ff // filled circle
#define FIG_7 0x111 // middle road
#define FIG_8 0x84 // left little road
#define FIG_9 0x42 // right little road
#define FIG_10 0x1f9 // arrow
#define FIG_11 0x13f // reverse arrow

/* Figure data type */
typedef struct figure_s {
    char fignumber;
    char message[STR_LEN];
    unsigned int pattern;
    unsigned int points;
} figure_t;

/* Rule set for the figures */
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
void die(const char *message)
{
    if(errno) {
        perror(message);
    } else {
        fprintf(stderr, "[ERROR] %s\n ", message);
    }

    exit(EXIT_FAILURE);
}

/* Turn a binary string into an integer */
unsigned int binstr2int(char *str)
{
    int i = 0;

    while (*str != '\0' && *str != '\n') {
        if (*str != '0' && *str != '1') {
            die("Not a binary digit");
        }
        i = i*2 + (*str++ & 1);
    }

    return i;
}

/* Check incoming pattern for matches return figumber or -1 if no match*/
int check_figures(unsigned int in)
{
    for(int i=0; i<(N_FIGS-1); i++) {
        if(in==figures[i].pattern) {
            return figures[i].fignumber;
        }
    }

    return -1;
}

int main(int argc, char **argv)
{
    unsigned int input=0;
    int n=0;

    if(argc!=2) {
        die("Exactly one argument required. Binary representation of field, see code.");
    }

    input = binstr2int(argv[1]);

    printf("[DEBUG]: Input: %x\n", input); // Debug print

    if((n=check_figures(input))>0) {
        printf("Figur: %s\nPunkte: %d\n", figures[n].message, figures[n].points);
    } else {
        printf("%d",n);
        printf("No figure, calculating points ...\n");
        // TODO Add all binary 1's and return points
        // ...
    }

    return EXIT_SUCCESS;
}
