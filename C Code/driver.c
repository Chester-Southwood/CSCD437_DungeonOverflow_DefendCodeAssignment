#include "defendCode.h"

int main()
{
    FILE *fout = NULL;
    FILE *fin = NULL;
    char *finName = (char*) malloc(sizeof(char)*256);
    char *foutName = (char*) malloc(sizeof(char)*256); 
    char* fname;
    char* lname;
    int num1;
    int num2;

    do {
        printf(" \nAll Files must reside in local directory or sub-directory contained within local.\nPlease enter input file name.\n");
        fin = getFile("r", finName);
        while(fin == NULL)
        {
            fin = getFile("r", finName);
        }

        printf("Enter output file\n");
        fout = getFile("w+", foutName);
        while(fin == NULL)
        {
            fout = getFile("w+", finName);
        }

    if(isSameFile(finName, foutName) == 1)
    {
        printf("ERROR, input and output file cannot be of the same name. Re-enter file names.\n");
    }

    } while (isSameFile(finName, foutName) == 1);




    printf("Please enter your first name: ");
    fname = getName();
    printf("Please enter your last name: ");
    lname = getName();

    printf("Please enter a password: ");
    validatePassword();

    writeChar(fout, fname);
    writeChar(fout, lname);
    writeContents(fout, fin);

    return 1;
    printf("Please enter 1st number: ");
    num1 = promptAndGetInt();

    printf("Please enter 2nd number: ");
    num2 = promptAndGetInt();

    writeChar(fout, fname);
    writeChar(fout, lname);
    if(canDoubleSumBeInt((double)num1, (double)num2) == 1)
    {
        int sum = num1+num2;
        writeInt(fout, &sum);
    }
    if(canDoubleProductBeInt((double)num1, (double)num2) == 1)
    {
        int product = num1*num2;
        writeInt(fout, &product);
    }

    printf("Done");
    return 1;
}