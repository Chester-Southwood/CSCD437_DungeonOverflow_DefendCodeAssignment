#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <ctype.h>
#include <math.h>

/*
 Team name - Dungeon Overflow

Team Member 1: Drew Bosco

Team Member 2: Eric Shervey

Team Member 3: Chester Southwood 
*/

extern void writeChar(FILE *out, char *arr);

extern void writeInt(FILE *out, int *num);

extern void writeContents(FILE *out, FILE *in);

extern char* getName();

extern FILE* getFile(char *accessType, char *fileName);

extern int isSameFile(char *file1Name, char *file2Name);

extern int validatePassword();

extern int alternative_fgets(char* buf, int length);

extern int canDoubleProductBeInt(long a, long b);

extern int canDoubleSumBeInt(long a, long b);

extern int canDoubleBeInt(long d);

extern int isCharANegative(char charValue);

extern int isInt(char* buf, int intDigitSize);

extern int promptAndGetInt();

extern int intOverflow(long dnum);

extern int canAdd(long dnum1, long dnum2);

extern int canMultiply(long dnum1, long dnum2);

extern double getNum(char* arr);

extern int isWhole(long num);

extern int promptAndGetInt();

//________________________________________________________________________________________________
//Had to accept both changes in merge process as it was just accept one over the other.

extern void writeChar(FILE *out, char *arr);

extern void writeInt(FILE *out, int *num);

extern void writeContents(FILE *out, FILE *in);

extern char* getName();

extern FILE* getFile(char *accessType, char *fileName);

extern int isSameFile(char *file1Name, char *file2Name);

extern void makePassword();

extern int alternative_fgets(char* buf, int length);

extern int isCharANegative(char charValue);

extern int isInt(char* buf, int intDigitSize);

extern int promptAndGetInt();

extern double getNum(char * num);
