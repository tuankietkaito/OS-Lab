#include <stdio.h>
#include "readline.h"
#include "findsubstr.h"

int length(char *s)
{
    int count = 0;
    while (*s != '\0')
    {
        count++;
        s++;
    }
    return count;
}

int main(int argc, char *argv[])
{
    char sub[100];
    int z = 0;
    for (int i = 2; i < argc; i++)
    {
        for (int j = 0; j < length(argv[i]); j++)
        {
            sub[z] = argv[i][j];
            z++;
        }
        if (i != argc - 1)
        {
            sub[z] = ' ';
            z++;
        }
        else
        {
            sub[z] = '\0';
        }
    }
    /*printf("argc = %d\n", argc);
    for (int i = 0; i < argc; i++)
        printf("--> %s\n", argv[i]);
    printf("file = %s, substr = %s\n", argv[1], sub);*/

    FILE *fp = fopen(argv[1], "r");
    char buff[500];
    int line = 1;
    while (fgets(buff, sizeof(buff), fp) != NULL)
    {
        //printf("Line %d: read_line = %d - %s", line, read_line(buff), buff);
        //printf("==> Find = %d\n", find_sub_string(buff, sub));
        if (find_sub_string(buff, sub) != -1)
        {
            printf("Line %d: %s", line, buff);
        }
        line++;
    }
    fclose(fp);
    return 0;
}
