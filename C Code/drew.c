#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    FILE *out;
    FILE *in;

    out = fopen("test.txt", "w+");
    in = fopen("in.txt", "r");
    char c = 'a';
    char str1[50];
    int num = 10;
    int i = 0;

    printf("Please enter a char[50]: ");
    scanf("%s", str1);

    writeChar(out, str1);
    writeInt(out, num);
    writeContents(out, in);

    printf("Operations Complete.");
}


/*
fp is assumed to be open already for writing
*/
writeChar(FILE *out, char *arr)
{
    int i = 0;
    for(i = 0; i < strlen(arr); i++)
    {
        fputc(arr[i], out);
    }
    fputc('\n', out);
}

writeInt(FILE *out, int num)
{
    char snum[50];
    sprintf(snum, "%d", num);
    writeChar(out, snum);
}

/*
out and in are assumed to be open.
out is open for writing
in is open for reading
*/
writeContents(FILE *out, FILE *in)
{
    char c = 'a';
    while(fscanf(in, "%c", &c) != EOF)
    {
        fputc(c, out);
    }
    fputc('\n', out);
}