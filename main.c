#include <stdio.h>
#include <stdlib.h>
#include "findsubstr.h"

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

int main()
{
    FILE *fp = fopen("test.txt", "r");
    char buff[500];
    int line = 1;
    while (fgets(buff, sizeof(buff), fp) != NULL)
    {
        printf("Line %d: read_line = %d - %s", line, read_line(buff), buff);
        line++;
    }
    fclose(fp);
    return 0;
}
