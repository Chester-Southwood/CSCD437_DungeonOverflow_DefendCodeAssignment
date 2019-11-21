#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "defendCode.h"

/*
 Team name - Dungeon Overflow

Team Member 1: Drew Bosco

Team Member 2: Eric Shervey

Team Member 3: Chester Southwood 
*/

/*
fp is assumed to be open already for writing
*/
void writeChar(FILE *out, char *arr)
{
    size_t i = 0;
    for(i = 0; i < strlen(arr); i++)
    {
        //printf("%c", arr[i]);
        fputc(arr[i], out);
    }
    fputc('\n', out);
}

void writeInt(FILE *out, int *num)
{
    fprintf(out, "%d\n", *num);
}

/*
out and in are assumed to be open.
out is open for writing
in is open for reading
*/
void writeContents(FILE *out, FILE *in)
{
    char c = 'a';
    while(fscanf(in, "%c", &c) != EOF)
    {
        fputc(c, out);
    }
    fputc('\n', out);
}