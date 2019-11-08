#include "defendCode.h"

int main()
{
    FILE *out;
    FILE *in;
    out = fopen("test.txt", "w+");
    char str1[50];
    char password[100];
    char filePath[256];
    int num;

    printf("Please enter a string: ");
    scanf("%s", str1);
    writeChar(out, str1);

    printf("Please enter a number: ");
    scanf("%d", &num);
    writeInt(out, &num);

    printf("Please enter a password: ");
    scanf("%s", password);
    writeChar(out, password);

    printf("Please enter a file name: ");
    scanf("%s", filePath);
    in = fopen(filePath, "r");
    writeContents(out, in);

    printf("Done");
    return 1;
}