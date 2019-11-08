#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "defendCode.h"


void dostuff()
{
    /*
    FILE *out;
    FILE *in;

    out = fopen("test.txt", "w+");
    in = fopen("in.txt", "r");
    char str1[50];
    int num = 10;

    printf("Please enter a char[50]: ");
    scanf("%s", str1);

    writeChar(out, str1);
    writeInt(out, num);
    writeContents(out, in);

    printf("Operations Complete.");
    */
}


/*
fp is assumed to be open already for writing
*/
void writeChar(FILE *out, char *arr)
{
    size_t i = 0;
    for(i = 0; i < strlen(arr); i++)
    {
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