#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * Populates given char array with input given from the user.
 * The method will only take in enough chars for the array and
 * ignore the remainder the user typed in besides an additional
 * digit to show that the value is greater then a normal int.
 *
 * @param  buf    a given char array to populate user input with
 * @param  length the length of the given char array
 * @return        arbitrary int
 */
int alternative_fgets(char* buf, int length)
{
    int  index;

    for(index=0; index<length-1; index++)
    {
        buf[index] = getchar();
        if(buf[index] == '\n')
        {
            buf[index + 1] = '\n';
            buf[index + 2] = '\0';
            return index;
        }
    }
    
    while ((getchar()) != '\n'); //get rid of strings greater then length of digits int can be
    
    buf[length - 2] = '\n';
    buf[length - 1] = '\0';
    
    return index;
}

/**
 * Given two double values, a int (1 = true, 0 = false) determining
 * if the product could be converted to a integer without conflicts.
 *
 * @param  a      first  double
 * @param  b      second double
 * @return        int (boolean) value that the two values can be multiplied
 */
int canDoubleProductBeInt(double a, double b)
{
    double c = a * b;
    return canDoubleBeInt(c);
}

/**
 * Given two double values, a int (1 = true, 0 = false) determining
 * if the sum could be converted to a integer without conflicts.
 *
 * @param  a      first  double
 * @param  b      second double
 * @return        int (boolean) value that the two values can be added
 */
int canDoubleSumBeInt(double a, double b)
{
    double c = a + b;
    return canDoubleBeInt(c);
}


/**
 * Given two double values, a int (1 = true, 0 = false) determining
 * if the product could be converted to a integer without conflicts.
 *
 * @param  a      first  double
 * @param  b      second double
 * @return        int (boolean) value that the two values can be multiplied
 */
int canDoubleProductBeInt(double a, double b)
{
    double c = a * b;
    return canDoubleBeInt(c);
}

/**
 * Given a double, the method returns a value that determines if the 
 * double can be converted to a integer without conflicts.
 *
 * @param  d      double used for determining if can become a int
 * @return        int (boolean) value that determines if double can be converted to a int
 */
int canDoubleBeInt(double d)
{
    return INT_MIN <= d && d <= INT_MAX;
}

/**
 * Given a char, determines if it is a '-', used for "negative" determining
 *
 * @param  charValue      char that is potentially a '-'
 * @return                int (boolean) value that determines if char is a '-'
 */
int isCharANegative(char charValue)
{
    return charValue == '-';
}


/**
 * Given a char array and its size, returns a boolean determining
 * if the given char array can be converted to a valid int
 *
 * @param  buf               a given char array that is already filled
 * @param  intDigitSize      the length of the given char array
 * @return                   int (boolean) value that determines if char array can be converted to int
 */
int isInt(char* buf, int intDigitSize)
{
    int isFlag = 0;
    
    alternative_fgets(buf, intDigitSize + 1); //return is abitrary, userInput goes to passed in char* / arr
    
    if(isdigit(buf[0]) || isCharANegative(buf[0]))
    {
        int index;
        
        for(index = 1; index <= intDigitSize; index++)
        {
            if(!isdigit(buf[index]) && buf[index] != '\n' && buf[index] != '\0')
            {
                return -1;
            }
        }
        
        double possibleInt = atof(buf);
        
        return (canDoubleBeInt(possibleInt) && buf[intDigitSize - 1] == '\0' && buf[index - 2] != '\n') ? 1 : 0;
    }
    return -1;
}

/**
 * Prompts the user for a valid int, determines from the users input
 * if the char array is valid as a int, and reprompts the user for and
 * new value if the char array is too large, or contains invalid characters
 *
 * @return       valid int value calculated from the users input
 */
int promptAndGetInt()
{
    int isFlag       = -1;
    int intDigitSize = 13; //Counting the sign as a decimal
    int promptedInt;
    
    while(isFlag == -1)
    {
        char buf[] = "0000000000\n\0"; //resetting array structure
        
        if(isInt(buf, intDigitSize) == 1)
        {
            isFlag      = 1;
            promptedInt = atoi(buf);
        }
        else
        {
            printf("Please try a integer, values between %d and %d\n", INT_MIN, INT_MAX);
        }
    }
    
    return promptedInt;
}

int main()
{
    int promptedInt = promptAndGetInt();
    printf("%d",canDoubleProductBeInt(promptedInt, promptedInt));
    return 0;
}