<<<<<<< HEAD
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

extern void validatePassword();

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
=======
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <ctype.h>

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

extern void makePassword();

extern int alternative_fgets(char* buf, int length);

extern int canDoubleProductBeInt(double a, double b);

extern int canDoubleSumBeInt(double a, double b);

extern int canDoubleBeInt(double d);

extern int isCharANegative(char charValue);

extern int isInt(char* buf, int intDigitSize);

extern int promptAndGetInt();

extern int intOverflow(double dnum);

extern int canAdd(double dnum1, double dnum2);

extern int canMultiply(double dnum1, double dnum2);

extern double getNum(char * num);
>>>>>>> EricBranch
