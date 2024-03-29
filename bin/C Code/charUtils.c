<<<<<<< HEAD
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "defendCode.h"

/*
 Team name - Dungeon Overflow

Team Member 1: Drew Bosco

Team Member 2: Eric Shervey

Team Member 3: Chester Southwood 
*/

char* getName()
{
    char *name = (char*) malloc(sizeof(char)*50);
    fgets(name, 50, stdin);
    fflush(stdin);
    while(strlen(name) <= 1 || name[0] == ' ')
    {
        printf("Name must be at least 1 char in length. Please re-enter name.\n");
        fgets(name, 50, stdin);
        fflush(stdin);
    }
    if(name[strlen(name) -1] != '\n'  ) name[strlen(name)-1] = '\n';
    //printf("%s in getName()\n", name);

    return name;
}

FILE* getFile(char *accessType, char *fileName)
{
    char path[256];
    getcwd(path, sizeof(path));

    //printf("0.) PATH: %s\n", path);


    fscanf(stdin, "%255s", fileName); //breaking here.
    fflush(stdin); //Nope that doesn't fix it either.
    //printf("0.) PATH: %s\n", path);
    //printf("X\n", fileName);
    
    strncat(path, "\\/\\/", 256 - 1);
    //printf("Y\n", fileName);
    strncat(path, fileName, 256 - 1);
    //printf("Z\n", fileName);
    //printf("2.) %s\n", fileName);

    FILE *f = fopen(fileName, accessType);

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

void validatePassword()
{
    char p1[51];
    char p2[51];

    fgets(p1, 51, stdin);
    printf("Please enter it again to validate it: ");
    fflush(stdin);
    fgets(p2, 51, stdin);

    //printf("%s = %s", p1, p2);

    while(strncmp(p1, p2, 51) != 0)
    {
        printf("Password does not match. Re-enenter matching password.\n");
        fgets(p2, 51, stdin);
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
=======
#define _XOPEN_SOURCE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <regex.h>
#include "defendCode.h"
#include <crypt.h>
#include <sys/random.h>
#include <time.h>

/*
Team name - Dungeon Overflow

Team Member 1: Drew Bosco

Team Member 2: Eric Shervey

Team Member 3: Chester Southwood 
*/

char* getName()
{
    printf("Name must be alphabetic characters, have length of at least 2 for first "
                "and last names and must have a single space between first and last name. "
                "if a name is hyphenated then both names must be capitalized. Length in excess of 100 characters"
                "will be truncated.\n");
    
    
    char *name = (char*) malloc(sizeof(char)*101);
    fgets(name, 51, stdin);
    
    if(strchr(name, '\n') == NULL)
    {
        int ch = getchar();
        while(ch!= EOF && ch != '\n') {ch = getchar();};
    }
    
    name[strcspn(name, "\n")] = '\0';
    regex_t reg;
    int reti;
    //char *s = "DOG";
    //[A-Z][a-z]\\+\\(-[A-Z][a-z]\\+\\)\\?\n\\?$
    reti = regcomp(&reg, "^[A-Z][A-Za-z]\\+\\(-[A-Z][A-Za-z]\\+\\)\\? [A-Z][A-Za-z]\\+\\(-[A-Z][A-Za-z]\\+\\)\\?$", 0);
    reti = regexec(&reg, name, 0, NULL, 0);
    
    //printf("%d\n", reti);
    
    if(reti == 1) 
    { 
        free(name);
        name = NULL;
        return name;
    }
    
    /*
    while(reti == 1)
    {
        reti = -1;
        printf("Name must be alphabetic characters, have length of at leat 2 for first "
                "and last names and must have a single space between first and last name. "
                "if a name is hyphenated then both names must be capitalized. Length in excess of 100 characters"
                "will be truncated.\n");
        
        fgets(name, 51, stdin);
        
        printf("%s", name);
        
        if(strchr(name, '\n') == NULL)
        {
        int ch = getchar();
        while(ch!= EOF && ch != '\n') {ch = getchar();};
        }
        
        //reti = regcomp(&reg, "^[A-Z][A-Za-z]\\+\\(-[A-Z][A-Za-z]\\+\\)\\? [A-Z][A-Za-z]\\+\\(-[A-Z][A-Za-z]\\+\\)\\?$", 0);
        reti = regexec(&reg, name, 0, NULL, 0);
        
        printf("%d\n", reti);
    }
     */
    
    if(name[strlen(name) -1] == '\n') 
    {
        name[strlen(name)-1] = '\0';
    }
    //printf("%s in getName()\n", name);

    return name;
}

FILE* getFile(char *accessType, char *fileName)
{
    fscanf(stdin, "%255s", fileName); //breaking here.
    
    if(strchr(fileName, '\n') == NULL)
    {
        int ch = getchar();
        while(ch!= EOF && ch != '\n') {ch = getchar();};
    }
    
    regex_t reg1, reg2;
    int r1, r2;
    //char *s = "DOG";
    
    r1 = regcomp(&reg1, "[//\\]", 0);
    
    r2 = regcomp(&reg2, ".txt$", 0);
    
    r1 = regexec(&reg1, fileName, 0, NULL, 0);
    r2 = regexec(&reg2, fileName, 0, NULL, 0);
    
    while(r1 == 0 || r2 == 1)
    {
        printf("Reenter file, file must end in .txt and be in the same directory"
                "as the program.\n");
        fscanf(stdin, "%255s", fileName); //breaking here.
        
        if(strchr(fileName, '\n') == NULL)
        {
            int ch = getchar();
            while(ch!= EOF && ch != '\n') {ch = getchar();}
        }
        
        r1 = regexec(&reg1, fileName, 0, NULL, 0);
        r2 = regexec(&reg2, fileName, 0, NULL, 0);
    }
    
    FILE *f = fopen(fileName, accessType);

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

void makePassword()
{
    char constChars[64] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890./";
    
    char salt[3];
    
    srand(time(NULL));
    
    salt[0] = constChars[rand() % 64];
    salt[1] = constChars[rand() % 64];
    salt[2] = '\0';
    
    printf("Please enter password. Password must be of a length of at least 8, and at most 30 chars."
            "Any characters beyond 30 will be truncated.\n");
    
    char uIn[31];
    fgets(uIn, 31, stdin);
    
    
    if(strchr(uIn, '\n') == NULL)
    {
        int ch = getchar();
        while(ch!= EOF && ch != '\n') {ch = getchar();};
    }
    
    while(strlen(uIn) < 8 )
    {
        printf("Password too small. Please try again.\n");
        fgets(uIn, 31, stdin);
        
        if(strchr(uIn, '\n') == NULL)
    {
        int ch = getchar();
        while(ch!= EOF && ch != '\n') {ch = getchar();};
    }
        
    }
    
    char *pass = crypt(uIn, salt);
    //printf("P1:%s\n", pass);
    
    FILE *fOut = fopen("password.txt", "w+");
    
    if(fOut == NULL)
    {
        printf("ERROR, PASSWORD FILE DOES NOT EXIST AND COULD NO BE CREATED. EXITING\n");
        exit(-1);
    }
    
    fprintf(fOut, "%s", pass);
    fclose(fOut);
}

int validatePassword()
{
    FILE *fIn = fopen("password.txt", "r");
    
    if(fIn == NULL)
    {
        printf("ERROR, PASSWORD FILE DOES NOT EXIST AND COULD NO BE CREATED. EXITING\n");
        exit(-1);
    }
    
    char inString[1000];
    
    fgets(inString, 1000, fIn);
    
    if(strlen(inString) == 0)
    {
        printf("ERROR, password.txt is empty. Please create a password.\n");
        makePassword();
        fgets(inString, 100, fIn);
        
    }
    char salt[3];
    
    salt[0] = inString[0];
    salt[1] = inString[1];
    salt[2] = '\0';
    
    //printf("%s", salt);
    
    fclose(fIn);
    
    printf("Please re-enter password for validation.\n");
    
    char uIn[31];
    fgets(uIn, 31, stdin);
    
    if(strchr(uIn, '\n') == NULL)
    {
        int ch = getchar();
        while(ch!= EOF && ch != '\n') {ch = getchar();};
    }
    
    while(strlen(uIn) < 8 )
    {
        //printf("UIN: %s\nPassword too small. Please try again.", uIn);
        fgets(uIn, 31, stdin);
        
        if(strchr(uIn, '\n') == NULL)
    {
        int ch = getchar();
        while(ch!= EOF && ch != '\n') {ch = getchar();};
    }
    }
    
    char *pass = crypt(uIn, salt);
    
    //printf("P2:%s\nUP:%s\n", inString, pass);
    
    if(strncmp(pass, inString, 31) == 0)
    {
        return 0;
    }
    
    return 1;
    
}
>>>>>>> EricBranch
