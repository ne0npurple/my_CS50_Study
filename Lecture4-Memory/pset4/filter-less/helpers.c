#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avg = round((float)(image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3);
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // sepia color algorithm
            int sepiaRed = round((0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen) + (0.189 * image[i][j].rgbtBlue));
            int sepiaGreen = round((0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) + (0.168 * image[i][j].rgbtBlue));
            int sepiaBlue = round((0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) + (0.131 * image[i][j].rgbtBlue));

            // if sepia rgb more than 255, then just capped to 255
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // temp placeholder
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][width - j - 1];
            image[i][width - j - 1] = image[i][j];
            image[i][j] = temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int x = 0; x < height; x++)
    {
        for (int y = 0 ; y < width; y++)
        {
            int sumRed = 0 ;
            int sumGreen = 0;
            int sumBlue = 0;
            int count = 1;

            sumRed += image[x][y].rgbtRed;
            sumGreen += image[x][y].rgbtGreen;
            sumBlue += image[x][y].rgbtBlue;

            if (x-1 >= 0 && y-1 >= 0)
            {
                sumRed += image[x-1][y-1].rgbtRed;
                sumGreen += image[x-1][y-1].rgbtGreen;
                sumBlue += image[x-1][y-1].rgbtBlue;
                count += 1;
            }
            if (x-1 >= 0)
            {
                sumRed += image[x-1][y].rgbtRed;
                sumGreen += image[x-1][y].rgbtGreen;
                sumBlue += image[x-1][y].rgbtBlue;
                count += 1;
            }
            if (x-1 >= 0 && y+1 < width)
            {
                sumRed += image[x-1][y+1].rgbtRed;
                sumGreen += image[x-1][y+1].rgbtGreen;
                sumBlue += image[x-1][y+1].rgbtBlue;
                count += 1;
            }
            if (y-1 >= 0)
            {
                sumRed += image[x][y-1].rgbtRed;
                sumGreen += image[x][y-1].rgbtGreen;
                sumBlue += image[x][y-1].rgbtBlue;
                count += 1;
            }
            if (y + 1 < width)
            {
                sumRed += image[x][y+1].rgbtRed;
                sumGreen += image[x][y+1].rgbtGreen;
                sumBlue += image[x][y+1].rgbtBlue;
                count += 1;
            }
            if (x+1 < height && y-1 >= 0)
            {
                sumRed += image[x+1][y-1].rgbtRed;
                sumGreen += image[x+1][y-1].rgbtGreen;
                sumBlue += image[x+1][y-1].rgbtBlue;
                count += 1;
            }
            if (x+1 < height)
            {
                sumRed += image[x+1][y].rgbtRed;
                sumGreen += image[x+1][y].rgbtGreen;
                sumBlue += image[x+1][y].rgbtBlue;
                count += 1;
            }
            if (x+1 < height && y+1 < width)
            {
                sumRed += image[x+1][y+1].rgbtRed;
                sumGreen += image[x+1][y+1].rgbtGreen;
                sumBlue += image[x+1][y+1].rgbtBlue;
                count += 1;   
            }
            sumRed = round((float)sumRed/count);
            sumGreen = round((float)sumGreen/count);
            sumBlue = round((float)sumBlue/count);

            copy[x][y].rgbtRed = sumRed;
            copy[x][y].rgbtGreen = sumGreen;
            copy[x][y].rgbtBlue = sumBlue;
        }
    }
    
    // copy the blurred image (copy) to the original image (image)
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = copy[i][j].rgbtRed;
            image[i][j].rgbtGreen = copy[i][j].rgbtGreen;
            image[i][j].rgbtBlue = copy[i][j].rgbtBlue;
        }
    }
}
