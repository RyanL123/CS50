#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    if (argc != 2){
        return 1;
    }
    char *fileName = argv[1];
    FILE *f = fopen(fileName, "r");
    if (f == NULL){
        return 1;
    }
    unsigned char buf[512];
    int fileNum = 0;
    char outFileName[10];
    FILE *img = NULL;
    bool isJPG = false;
    while (fread(buf, 512, 1, f)){
        // End of file
        if (feof(f)){
            break;
        }
        // New jpeg file
        if (buf[0] == 0xff && buf[1] == 0xd8 && buf[2] == 0xff && (buf[3] & 0xf0) == 0xe0){
            if (isJPG){
                fclose(img);
            }
            isJPG = true;
            sprintf(outFileName, "%03i.jpg", fileNum);
            img = fopen(outFileName, "w");
            fileNum++;
        }
        if (isJPG){
            fwrite(buf, 512, 1, img);
        }
    }
}
