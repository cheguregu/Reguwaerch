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

/* figure definitions according to the rules */
#define FIG_DRAGN1 0x1D1
#define FIG_DRAGN2 0x117
#define FIG_BRACEL 0x195
#define FIG_BRACER 0x153
#define FIG_CIRCLE 0x1EF
#define FIG_STRIKE 0x1FF
#define FIG_MDROAD 0x111
#define FIG_LROADL 0x84
#define FIG_LROADR 0x42
#define FIG_ARROW1 0x1F9
#define FIG_ARROW2 0x13F

typedef struct field_s {
    //TODO...
} field_t;

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

/* Turns a binary string into an integer */
static unsigned binstr2int(char *str) 
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

int main(int argc, char **argv)
{
    if(argc != 2){
        die("Exactly one argument required.");
    }

    unsigned int input = binstr2int(argv[1]);

    printf("Input: %d\n", input);

    return EXIT_SUCCESS;
}
