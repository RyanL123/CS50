#include "helpers.h"
#include <math.h>

int min(int x, int y){
    if (x > y){
        return y;
    }
    else {
        return x;
    }
}

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            RGBTRIPLE original = image[i][j];
            BYTE avg = round(((float)original.rgbtBlue + (float)original.rgbtRed + (float)original.rgbtGreen)/3);
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            RGBTRIPLE original = image[i][j];
            BYTE originalRed = original.rgbtRed;
            BYTE originalGreen = original.rgbtGreen;
            BYTE originalBlue = original.rgbtBlue;
            image[i][j].rgbtBlue = min((int)(round(0.272 * (float)originalRed) + round(0.534 * (float)originalGreen) + round(0.131 * (float)originalBlue)), 255);
            image[i][j].rgbtRed = min((int)(round(0.393 * (float)originalRed) + round(0.769 * (float)originalGreen) + round(0.189 * (float)originalBlue)), 255);
            image[i][j].rgbtGreen = min((int)(round(0.349 * (float)originalRed) + round(0.686 * (float)originalGreen) + round(0.168 * (float)originalBlue)), 255);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++){
        for (int j = 0; j < ceil(width/2); j++){
            RGBTRIPLE original = image[i][j];
            BYTE tempRed = original.rgbtRed;
            BYTE tempGreen = original.rgbtGreen;
            BYTE tempBlue = original.rgbtBlue;
            image[i][j].rgbtRed = image[i][width-1-j].rgbtRed;
            image[i][j].rgbtGreen = image[i][width-1-j].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width-1-j].rgbtBlue;
            image[i][width-1-j].rgbtRed = tempRed;
            image[i][width-1-j].rgbtGreen = tempGreen;
            image[i][width-1-j].rgbtBlue = tempBlue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE blurImage[height][width];
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            int usedPixels = 1;
            int blueAvg = 0;
            int redAvg = 0;
            int greenAvg = 0;
            // Top Left
            if (i-1 >= 0 && j-1 >= 0){
                blueAvg += image[i-1][j-1].rgbtBlue;
                greenAvg += image[i-1][j-1].rgbtGreen;
                redAvg += image[i-1][j-1].rgbtRed;
                usedPixels++;
            }
            // Top Center
            if (i-1 >= 0){
                blueAvg += image[i-1][j].rgbtBlue;
                greenAvg += image[i-1][j].rgbtGreen;
                redAvg += image[i-1][j].rgbtRed;
                usedPixels++;
            }
            // Top Right
            if (i-1 >= 0 && j+1 < width){
                blueAvg += image[i-1][j+1].rgbtBlue;
                greenAvg += image[i-1][j+1].rgbtGreen;
                redAvg += image[i-1][j+1].rgbtRed;
                usedPixels++;
            }
            // Middle Left
            if (j-1 >= 0){
                blueAvg += image[i][j-1].rgbtBlue;
                greenAvg += image[i][j-1].rgbtGreen;
                redAvg += image[i][j-1].rgbtRed;
                usedPixels++;
            }
            // Center
            blueAvg += image[i][j].rgbtBlue;
            greenAvg += image[i][j].rgbtGreen;
            redAvg += image[i][j].rgbtRed;
            // Middle Right
            if (j+1 < width){
                blueAvg += image[i][j+1].rgbtBlue;
                greenAvg += image[i][j+1].rgbtGreen;
                redAvg += image[i][j+1].rgbtRed;
                usedPixels++;
            }
            // Bottom Left
            if (i+1 < height && j-1 >= 0){
                blueAvg += image[i+1][j-1].rgbtBlue;
                greenAvg += image[i+1][j-1].rgbtGreen;
                redAvg += image[i+1][j-1].rgbtRed;
                usedPixels++;
            }
            // Bottom Center
            if (i+1 < height){
                blueAvg += image[i+1][j].rgbtBlue;
                greenAvg += image[i+1][j].rgbtGreen;
                redAvg += image[i+1][j].rgbtRed;
                usedPixels++;
            }
            // Bottom Right
            if (i+1 < height && j+1 < width){
                blueAvg += image[i+1][j+1].rgbtBlue;
                greenAvg += image[i+1][j+1].rgbtGreen;
                redAvg += image[i+1][j+1].rgbtRed;
                usedPixels++;
            }
            blueAvg = round((float)blueAvg / (float)usedPixels);
            greenAvg = round((float)greenAvg / (float)usedPixels);
            redAvg = round((float)redAvg / (float)usedPixels);
            blurImage[i][j].rgbtBlue = blueAvg;
            blurImage[i][j].rgbtRed = redAvg;
            blurImage[i][j].rgbtGreen = greenAvg;
        }
    }
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            image[i][j] = blurImage[i][j];
        }
    }
    return;
}
