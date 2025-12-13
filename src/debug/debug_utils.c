#include "parsing.h"
#include <stdio.h>

void ft_print_tab(char **tab)
{
    int i = 0;

    while(tab[i])
    {
        printf("%s\n", tab[i]);
        i++;
    }
}
