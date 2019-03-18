from cs50 import get_float
import math
import sys

# prompts for card number
cardNumber = get_float("Card Number: ")

# creates variables
cardDigits = cardNumber

cardDigitCount = 0

otherDigitSum = 0

totalSum = 0

firstDigit = 0

firstTwoDigits = 0


# counts the number of digits in the card
while cardDigits > 1:
    cardDigits /= 10
    cardDigitCount += 1

cardDigits = cardNumber

# checks if the card is valid
if cardDigitCount != 13 and cardDigitCount != 15 and cardDigitCount != 16:
    print("INVALID")
    sys.exit()

cardDigitsArray = []

# stores every other digit starting from the second last digit in an array
for i in range(0, (int(cardDigitCount/2)), 1):
    cardDigits /= 10
    cardDigitsArray.append(math.floor(cardDigits % 10) * 2)
    cardDigits /= 10

# adds every digit in the array
for i in range(0, len(cardDigitsArray)):
    if (cardDigitsArray[i] < 10):
        otherDigitSum += cardDigitsArray[i]
    else:
        otherDigitSum += 1
        otherDigitSum += cardDigitsArray[i] % 10

cardDigits = cardNumber

# adds every other digit in the card
while cardDigits > 0:
    totalSum += math.floor(cardDigits % 10)
    cardDigits /= 100

totalSum += otherDigitSum

cardDigits = cardNumber

# gets 1st digit of the card
while cardDigits > 10:
    cardDigits /= 10
    firstDigit = int(math.floor(cardDigits))

cardDigits = cardNumber

# gets first 2 digits of the card
while cardDigits > 100:
    cardDigits /= 10
    firstTwoDigits = int(math.floor(cardDigits))

# matches the card to the correct provider
if totalSum % 10 == 0:
    if cardDigitCount == 13:
        print("VISA")
    elif cardDigitCount == 16 and firstDigit == 4:
        print("VISA")
    elif cardDigitCount == 15 and (firstTwoDigits == 34 or firstTwoDigits == 37) == True:
        print("AMEX")
    elif cardDigitCount == 16 and (firstTwoDigits == 51 or firstTwoDigits == 52 or firstTwoDigits == 53 or firstTwoDigits == 54 or firstTwoDigits == 55) == True:
        print("MASTERCARD")
    else:
        print("INVALID")
else:
    print("INVALID")
