import sys

if len(sys.argv) == 2:
    plaintext = input("plaintext: ")
    k = int(sys.argv[1])

    print("ciphertext: ", end="")
    for i in range(len(plaintext)):
        if (not plaintext[i].isalpha()):
            print(plaintext[i], end="")

        elif (plaintext[i].isupper()):
            print(chr((ord(plaintext[i]) + k - 65) % 26 + 65), end="")

        elif (plaintext[i].islower()):
            print(chr((ord(plaintext[i]) + k - 97) % 26 + 97), end="")

    print("")
else:
    sys.exit(1)
