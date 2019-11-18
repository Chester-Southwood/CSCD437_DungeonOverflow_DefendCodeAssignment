#include "defendCode.h"

/*
 Team name - Dungeon Overflow

Team Member 1: Drew Bosco

Team Member 2: Eric Shervey

Team Member 3: Chester Southwood 
*/

int main()
{
    /*
    FILE *fout = NULL;
    FILE *fin = NULL;
    char *finName = (char*) malloc(sizeof(char)*256);
    char *foutName = (char*) malloc(sizeof(char)*256); 
    char* fname;
    char* lname;
    int num1 = 0;
    int num2 = 0;

    double dnum1, dnum2;
    int overflowFlag = 0;

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

    do{
        if(overflowFlag == 1)
        {
            printf("Invalid. Please try again.\n");
        }
        dnum1 = getNum("1st");
        dnum2 = getNum("2nd");
        overflowFlag = 1;
    } while(canAdd(dnum1, dnum2) == 1 || canMultiply(dnum1,dnum2) == 1);
    num1 = dnum1;
    num2 = dnum2;
    int sum = num1+num2;
    int product = num1*num2;

    printf("Please enter a password: ");
    fflush(stdin);
    validatePassword();

    //Write to output file
    writeChar(fout, fname);
    writeChar(fout, lname);
    writeInt(fout, &sum);
    writeInt(fout, &product);
    writeContents(fout, fin);

    free(fname);
    free(lname);
    free(finName);
    free(foutName);
    fclose(fin);
    fclose(fout);

    printf("\nDone");
    return 1;
    */
}