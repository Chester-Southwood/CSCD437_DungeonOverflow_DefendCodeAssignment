#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

char* getName()
{
    char *name = (char*) malloc(sizeof(char)*51);
    fgets(name, 51, stdin);

    while(strlen(name) == 0)
    {
        printf("Name must be at least 1 char in length. Please re-enter name.");
        fgets(name, 51, stdin);
    }

    //printf("%s in getName()\n", name);

    return name;
}

FILE* getFile(char *accessType, char *fileName)
{
    char path[256];
    getcwd(path, sizeof(path));
    int nameSize = (256 - (strlen(path))) - 1;

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

    while(f == NULL)
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

int main(int argc, char* argv[])
{
    char *finName = (char*) malloc(sizeof(char)*256);
    char *foutName = (char*) malloc(sizeof(char)*256);;
    
    char *t1 = "Test";
    char *t2 = "Test";

    int d = isSameFile(t1, t2);

    printf("%d\n", d);

    //FILE *fin = getFile("w", finName);
    //FILE *fout = getFile("r", foutName);

    //printf("fin: %s\n", finName);

    //printf("fin: %s\nfout: %s\n", finName, foutName);

    free(finName);
    free(foutName);

    /*
    char *fName;
    char *lName;
    char *test = "TEST";

    passwordThing();

    printf("Enter first name. Length must not exceed 50 chars and may only contain alphabetic characters.\n");
    
    FILE *readFile = getFile("r");

    while(readFile == NULL)
    {
        readFile = getFile("r");
    }

    while((c = fgetc(readFile)) != EOF)
        printf("%c", c); 
        
    free(fName);
    free(lName);

    //fclose(readFile);
    */
}