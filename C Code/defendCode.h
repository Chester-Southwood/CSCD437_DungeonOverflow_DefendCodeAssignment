#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <ctype.h>

extern void writeChar(FILE *out, char *arr);

extern void writeInt(FILE *out, int *num);

extern void writeContents(FILE *out, FILE *in);

extern char* getName();

extern FILE* getFile(char *accessType, char *fileName);

extern int isSameFile(char *file1Name, char *file2Name);

extern void validatePassword();

extern int alternative_fgets(char* buf, int length);

extern int canDoubleProductBeInt(double a, double b);

extern int canDoubleSumBeInt(double a, double b);

extern int canDoubleBeInt(double d);

extern int isCharANegative(char charValue);

extern int isInt(char* buf, int intDigitSize);

extern int promptAndGetInt();

