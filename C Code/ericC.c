#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

char* getName()
{
    char *name = (char*) malloc(sizeof(char)*50);
    fgets(name, 50, stdin);

    while(strlen(name) == 0)
    {
        printf("Name must be at least 1 char in length. Please re-enter name.");
        fgets(name, 50, stdin);
    }

    //printf("%s in getName()\n", name);

    return name;
}

FILE* getFile(char *accessType, char *fileName)
{
    char path[256];
    getcwd(path, sizeof(path));

    printf("0.) PATH: %s\n", path);


    fscanf(stdin, "%255s", fileName); //breaking here.
    fflush(stdin); //Nope that doesn't fix it either.
    //printf("0.) PATH: %s\n", path);
    //printf("X\n", fileName);

    strncat(path, "\\", 256 - 1);
    //printf("Y\n", fileName);
    strncat(path, fileName, 256 - 1);
    //printf("Z\n", fileName);
    //printf("2.) %s\n", fileName);

    FILE *f = fopen(path, accessType);

    if(f == NULL)
    {
        printf("FILE DOES NOT EXIST. RETRY WITH VALID FILE\n");
        return NULL;
    }
    //printf("FILE PATH IS: %s\n", path);
    return f;
}

int isSameFile(char *file1Name, char *file2Name)
{
    if(strncmp(file1Name, file2Name, 256) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void passwordThing()
{
    char p1[51];
    char p2[51];

    fgets(p1, 51, stdin);
    fgets(p2, 51, stdin);

    //printf("%s = %s", p1, p2);

    while(strncmp(p1, p2, 51) != 0)
    {
        fgets(p2, 51, stdin);
        printf("Password does not match. Re-enenter matching password.\n");
    }
    printf("Passwords match.\n");
}
/*
int main(int argc, char* argv[])
{
    char *finName = (char*) malloc(sizeof(char)*256);
    char *foutName = (char*) malloc(sizeof(char)*256);
    FILE *fin = NULL;
    FILE *fout = NULL;

    char *fname;
    char *lname;

    printf("Enter first name: ");
    fname = getName();
    printf("Enter last name: ");
    lname = getName();

    do
    {
        printf(" \nAll Files must reside in local directory or sub-directory contained within local.\nPlease enter input file name.\n");
        fin = getFile("r", finName);
        while(fin == NULL)
        {
            fin = getFile("r", finName);
        }

        printf("Enter output file\n");
        fout = getFile("w", foutName);
        while(fin == NULL)
        {
            fout = getFile("w", finName);
        }

    if(isSameFile(finName, foutName) == 1)
    {
        printf("ERROR, input and output file cannot be of the same name. Re-enter file names.\n");
    }

    } while (isSameFile(finName, foutName) == 1);
    
    passwordThing();

    free(fname);
    free(lname);
    free(finName);
    free(foutName);
    fclose(fin);
    fclose(fout);
} */