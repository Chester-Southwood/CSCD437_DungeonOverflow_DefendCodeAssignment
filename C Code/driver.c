#include "defendCode.h"
#include <regex.h>

/*
 Team name - Dungeon Overflow

Team Member 1: Drew Bosco

Team Member 2: Eric Shervey

Team Member 3: Chester Southwood 
*/

int main()
{
    
    
    FILE *fout = NULL;
    FILE *fin = NULL;
    char *finName = (char*) malloc(sizeof(char)*256);
    char *foutName = (char*) malloc(sizeof(char)*256); 
    char* name = NULL;
    int num1 = 0;
    int num2 = 0;

    double dnum1, dnum2;
    int overflowFlag = 0;

    while(name == NULL)
    {
        name = getName(name);
    }
    
    do {
        printf(" \nfile names must end in .txt, not exceed 255 characters in length, and be in the same directory as program..\nPlease enter input file name.\n");
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
    
    printf("You will be asked to give two integer values. If the sum or product of the two integers would result in a "
            "over or underflow, you will be asked to re-enter with values that do not result in a over or underflow.\n");
    
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
    
    makePassword();

     while(validatePassword() == 1)
    {
       printf("Password did not match.\n");
       validatePassword();
    }

    printf("Password matched!\n");
    
    //Write to output file
    writeChar(fout, name);
    writeInt(fout, &sum);
    writeInt(fout, &product);
    writeContents(fout, fin);
    
    free(name);
    free(finName);
    free(foutName);
    fclose(fin);
    fclose(fout);

    printf("\nDone");
    return 1;
    
}