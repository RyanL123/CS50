//Determines if the user's credit card is valid using Luhn's algorithm

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //stores card number
    long cardNumber = get_long_long("Card number:");
    //used to count the number of digits in cardNumber
    long cardDigits = cardNumber;
    //varialbe to store the length of the card
    int cardDigitCount = 0;
    //creates variable to store the sum of every other digit
    int otherDigitSum = 0;
    //creates varialbe to store the total sum of all the digits
    int totalSum = 0;
    //creates first digit variable to store the first digit of the card
    int firstDigit = 0;
    //creates first two digits varaible
    int firstTwoDigits = 0;


    //gets how many digits there are in the card
    while (cardDigits > 1)
    {
        cardDigits = cardDigits / 10;
        cardDigitCount++;
    }
    //rests the cardDigits variable
    cardDigits = cardNumber;


    //if the card length is not 13, 15, or 16, the card is automatically invalid
    if (cardDigitCount != 13 && cardDigitCount != 15 && cardDigitCount != 16)
    {
        printf("INVALID\n");
    }
    //creates an array with the length of the card digit
    int cardDigitsArray[cardDigitCount];


    //stores every other digit starting from the last digit in the cardDigitArray array
    for (int i = 0; i < cardDigitCount / 2; i++)
    {
        //divides the cardDigits by 10 to get the seconds last digit
        cardDigits /= 10;
        //stores the digit in the carDigitsArray
        cardDigitsArray[i] = (floor(cardDigits % 10) * 2);
        //divides cardDigits by 10
        cardDigits /= 10;
    }


    //adds every integer stored in the cardDigitsArray
    for (int i = 0; i < cardDigitCount / 2; i++)
    {
        //if the integer is less than 10, add it to otherDigitSum
        if (cardDigitsArray[i] < 10)
        {
            otherDigitSum += cardDigitsArray[i];
        }
        //if the integer is bigger than 1, add 1 to the otherDigitSum, then add the 1s place of the integer to otherDigitSum
        else
        {
            otherDigitSum += 1;
            otherDigitSum += cardDigitsArray[i] % 10;
        }
    }
    //resets the cardDigits variable again
    cardDigits = cardNumber;


    //adds every other digit in the card
    while (cardDigits > 0)
    {
        //stores the digit in the carDigitsArray
        totalSum += floor(cardDigits % 10);
        //divides cardDigits by 100
        cardDigits /= 100;
    }
    //adds the all the digits together
    totalSum += otherDigitSum;
    //resets the cardDigits variable once again
    cardDigits = cardNumber;


    //gets the first digit of the card
    while (cardDigits > 10)
    {
        cardDigits /= 10;
        firstDigit = cardDigits;
    }

    //resets the cardDigits varaible
    cardDigits = cardNumber;

    //gets the first two digits of the card
    while (cardDigits > 100)
    {
        cardDigits /= 10;
        firstTwoDigits = cardDigits;
    }
    //if the last digit is 0, checks the length of the card to see which card it is
    if (totalSum % 10 == 0)
    {
        if (cardDigitCount == 13)
        {
            printf("VISA\n");
        }
        else if (cardDigitCount == 16 && firstDigit == 4)
        {
            printf("VISA\n");
        }
        else if (cardDigitCount == 15 && (firstTwoDigits == 34 || firstTwoDigits == 37) == true)
        {
            printf("AMEX\n");
        }
        else if (cardDigitCount == 16 && (firstTwoDigits == 51 || firstTwoDigits == 52 || firstTwoDigits == 53 || firstTwoDigits == 54
        || firstTwoDigits == 55) == true)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
