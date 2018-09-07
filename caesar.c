#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //if there are more than 2 command arguements or less than 2 the program will give an error message and return 1
    if (argc > 2 || argc < 2)
    {
        printf("Please only input 1 command line argument");
        return 1;
    }
    //set k to the second input of the command line argument
    int k = atoi(argv[1]);
    //gets plain text from user and stores it in variable s
    s =  get_string("plaintext: ");
    //loops through the string and increases the ascii code of each character by the input k on argv[2]
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        //checks if the character is upper case
        if (isupper(s[i]))
        {
            //encrypts the character with k, then uses the alphabetical index by modding 26, then adding 65 back
            s[i] = (s[i] + k - 65) % 26 + 65;
        }
        //checks if the character is lower case
        else if (islower(s[i]))
        {
            //encrypts the character with k, then uses the alphabetical index by modding 26, then adding 97 back
            s[i] = (s[i] + k - 97) % 26 + 97;
        }
    }
    //prints the cipher text
    printf("ciphertext: %s\n", s);
}

