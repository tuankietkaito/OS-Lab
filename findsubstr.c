#include <stdio.h>
#include "findsubstr.h"

int find_sub_string(const char *str, const char *sub)
{
    int i = 0, j = 0, idx;

    while (str[i] != '\0')
    {
        while (str[i] != sub[0] && str[i] != '\0')
            i++;
        if (str[i] == '\0')
            return (-1);

        idx = i;
        while (str[i] == sub[j] && str[i] != '\0' && sub[j] != '\0')
        {
            i++;
            j++;
        }
        
        if (sub[j] == '\0')
            return (idx);
        if (str[i] == '\0')
            return (-1);

        i = idx + 1;
        j = 0;
    }
}