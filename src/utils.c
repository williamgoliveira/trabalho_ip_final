#include "../include/prototypes.h"

void converte_String(char *str){
    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = tolower(str[i]);
    }
}
