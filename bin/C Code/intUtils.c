#include "defendCode.h"

/*
 Team name - Dungeon Overflow

Team Member 1: Drew Bosco

Team Member 2: Eric Shervey

Team Member 3: Chester Southwood 
*/

//will return 1 if it will not overflow
//returns 0 if it will overflow
int intOverflow(double dnum)
{
    if(dnum > INT_MAX || dnum < INT_MIN)
        return 1;
    else
        return 0;
}

int canAdd(double dnum1, double dnum2)
{
    return(intOverflow(dnum1+dnum2));
}

int canMultiply(double dnum1, double dnum2)
{
    return(intOverflow(dnum1*dnum2));
}

double getNum(char * num)
{
    int nitems;
    double dnum;
    do
    {
        printf("Please enter %s number: ", num);
        fflush(stdin);
        nitems = scanf("%lf", &dnum);
    } while((nitems == EOF || nitems == 0) || intOverflow(dnum));
    nitems = dnum;
    return dnum - (dnum - nitems);
}