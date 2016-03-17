#include <stdio.h>
#include <string.h>

#define maxline 1000

char main(char argv[], char argv[])
{
    char namea = argv[1];
    char nameb = argv[2];
    FILE *fpa;
    FILE *fpb;
    fpa = fopen(namea, "r");
    fpb = fopen(nameb, "r");
    
    char *fgets(char *linea, int maxline, FILE *fpa);       /* linea is the array that hold first file stream */
    char *fgets(char *lineb, int maxline, FILE *fpb);       /* the fgets buffer is the array and hence more than one files */
                                                            /* may be read simultaneously */
    
    if(*linea != *lineb) {
        
        printf("%s\n in %s\n differs from the %s\n in %s\n", *linea, argv[1], *lineb, argv[2]);
        *++linea;
        *++lineb;
        exit(0);
    }
    else
        printf("%s and %s are exactly alike.", argv[1], arg[2]);
        exit(0);
}
