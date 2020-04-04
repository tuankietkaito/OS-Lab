#include <stdio.h>
#include <stdlib.h>
#include "readline.h"

int read_line(char *str)
{
    int count = 0;
    do
    {
        count++;
        str++;
        if (*str == '\n')
            return count;
    } while (*str != '\0');
    return -1;
}