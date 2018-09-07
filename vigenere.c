//Encrypts the text user inputs using the vigenere cypher

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //if there are more than 2 command arguements or less than 2, the program will give an error message and return 1
    if (argc > 2 || argc < 2)
    {
        printf("Please only input 1 command line argument, and the argument must only consist of alphabetical characters\n");
        return 1;
    }
    //if the command line argument is not entirely alphanumberic, then program will give an error message and return 1
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Please only input 1 command line argument, and the argument must only consist of alphabetical characters\n");
            return 1;
        }
    }
    //store first input from the command line arguement into the variable a
    string a = argv[1];
    //gets plain text from user and stores it in variable s
    string s = get_string("plaintext: ");
    //variable for looping through k
    int counter = 0;
    //loops through the string and increases the ascii code of each character by the input k on argv[1]
    for (int i = 0, n = strlen(s); i < n; i++)

    {
        //checks if the character is a letter
        if (isalpha(s[i]))
        {
            //checks if the character in k is upper case
            if (isupper(a[counter]))
            {
                //encrypts the character with k
                //checks if the current plain text is lowercase
                if (islower(s[i]))
                {
                    //encrypts the character with k
                    s[i] = (((s[i] - 97) + (argv[1][counter] - 65)) % 26) + 97;
                }
                //checks if the current plain text is upper case
                else if (isupper(s[i]))
                {
                    //encrypts the character with k
                    s[i] = (((s[i] - 65) + (argv[1][counter] - 65)) % 26) + 65;
                }
                //if the k has been looped through once, reset the counter to loop through k again
                if (counter == strlen(a) - 1)
                {
                    counter = 0;
                }
                else
                {
                    counter ++;
                }
            }
            //checks if the character in k is lower case
            else if (islower(a[counter]))
            {
                //encrypts the character with k
                //checks if the current plain text is lowercase
                if (islower(s[i]))
                {
                    //encrypts the character with k
                    s[i] = (((s[i] - 97) + (argv[1][counter] - 97)) % 26) + 97;
                }
                //checks if the current plain text is upper case
                else if (isupper(s[i]))
                {
                    //encrypts the character with k
                    s[i] = (((s[i] - 65) + (argv[1][counter] - 97)) % 26) + 65;
                }
                //if the k has been looped through once, reset the counter to loop through k again
                if (counter == strlen(a) - 1)
                {
                    counter = 0;
                }
                else
                {
                    counter ++;
                }
            }
        }
    }
    //prints the cipher text
    printf("ciphertext: %s\n", s);
}

