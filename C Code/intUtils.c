#include "defendCode.h"
#include "math.h"
/*
 Team name - Dungeon Overflow

Team Member 1: Drew Bosco

Team Member 2: Eric Shervey

Team Member 3: Chester Southwood 
*/


//will return 1 if it will not overflow
//returns 0 if it will overflow
int intOverflow(long dnum)
{
    return INT_MIN <= dnum && dnum <= INT_MAX ? 0 : 1;
}

int canAdd(long dnum1, long dnum2)
{
    return(intOverflow(dnum1+dnum2));
}

int canMultiply(long dnum1, long dnum2)
{
    return(intOverflow(dnum1*dnum2));
}

int isWholeNum(long num)
{
    return abs(num) - abs(round(num)) == 0 ? 1 : 0;
}

int populateZeros(char* buf, int bufSize)
{
    int i;

    for(i = 0; i < bufSize - 1; i++)
    {
        buf[i] = '0';
    }

    return 1;
}

int nonWhiteSpaceOccurance(char* buf)
{
    int i = 0;

    while(buf[i] != '\0' && buf[i] == ' ')
    {
        i++;
    }

    return i;
}

int allNumersInCharArr(char* buf, int bufSize)
{
    int i = 0;//nonWhiteSpaceOccurance(buf);
    if(buf[i] == '\n')
    {
	return 0;
    }
    if(i >= bufSize - 1 || (buf[i] == '-' && !(isdigit(buf[i + 1]))))
    {
	return 0;
    }
    if(buf[i] == '-')
    {
        i++;
    }

    for(; buf[i] != '\n' && buf[i] != '\0' && i < bufSize - 1; i++)
    {
        if(!(isdigit(buf[i])))
        {
	    return 0;
        }
    }
    return 1;
}

double getNum(char * num)
{
    const  int    bufSize        = 13;
           int    validationFlag = 0;
           int    allNumFlag;
           long dnum;
    do
    {
        dnum       = 9999999991;
        allNumFlag = 0;

        char buf[bufSize];
        populateZeros(buf, bufSize);

        printf("Please enter %s int between %d and %d with no spaces or excess whitespace: ", num, INT_MIN, INT_MAX);
        fflush(stdin);

        if(fgets(buf, bufSize, stdin) != NULL){ //get user input
           int ch;
           int contains = 0;
           int index = 0;
           for(index = 0; index < bufSize - 1; index++) //determine if user entered valid number of digits
           {
               if(buf[index] == '\n')
               {
                    contains = 1;
               }
           }
           if(contains == 0) //eradicate remainder if user entered invalid number of digits
           {
               while ((ch = getchar())  != '\n') /* void */;
           }
        }

        if(allNumersInCharArr(buf, bufSize)) //check if all int values are in the buf
        {
             dnum       = atol(buf);
             allNumFlag = 1;
        }

        if(! (allNumFlag == 0 || intOverflow(dnum) == 1) ) //check if converted number is invalid
        {
	     validationFlag = 1;
        }
        else
        {
	     printf("Invalid, Input does not meet specified requirements, please check given specifications below in re-prompt\n");
        }
    } while( validationFlag == 0 );

    return dnum;
}
