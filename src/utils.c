#include "../include/prototypes.h"

char *compare_strings(const char *texto, const char *busca) {
    if (!busca || !*busca) return (char *)texto; 

    for (; *texto; texto++) {
        if (tolower((unsigned char)*texto) == tolower((unsigned char)*busca)) {
            const char *t = texto, *b = busca;
            while (*t && *b && tolower((unsigned char)*t) == tolower((unsigned char)*b)) {
                t++;
                b++;
            }
            if (!*b) return (char *)texto; 
        }
    }
    return NULL; 
}

