import sys

if len(sys.argv) == 2:

    k = sys.argv[1]

    for i in range(len(sys.argv[1])):
        if not sys.argv[1][i].isalpha():
            print("Please only input 1 command line argument, and the argument must only consist of alphabetical characters")
            sys.exit(1)

    plaintext = input("plaintext: ")

    print("ciphertext: ", end="")
    counter = 0
    for i in range(len(plaintext)):

        # only encrypts if the character is a letter
        if plaintext[i].isalpha():

            # if the encryption letter is uppercase
            if k[counter].isupper():

                # if the letter to be encrypted is lowercase
                if plaintext[i].islower():

                    print(chr((((ord(plaintext[i]) - 97) + (ord(k[counter]) - 65)) % 26) + 97), end="")

                # if the letter to be encrypted is uppercase
                elif plaintext[i].isupper():
                    print(chr((((ord(plaintext[i]) - 65) + (ord(k[counter]) - 65)) % 26) + 65), end="")

                if counter == len(k)-1:
                    counter = 0
                else:
                    counter += 1

            # if the encrpytion letter is lowercase
            elif k[counter].islower():

                # if the letter to be encrypted is lowercase
                if plaintext[i].islower():

                    print(chr((((ord(plaintext[i]) - 97) + (ord(k[counter]) - 97)) % 26) + 97), end="")

                # if the letter to be encrypted is uppercase
                elif plaintext[i].isupper():
                    print(chr((((ord(plaintext[i]) - 65) + (ord(k[counter]) - 97)) % 26) + 65), end="")

                if counter == len(k)-1:
                    counter = 0
                else:
                    counter += 1

        else:

            print(plaintext[i], end="")

    print("")

else:
    print("Please only input 1 command line argument, and the argument must only consist of alphabetical characters")
    sys.exit(1)
