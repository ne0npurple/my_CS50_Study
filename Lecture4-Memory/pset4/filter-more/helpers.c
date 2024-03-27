#include <stdio.h>
#include <math.h>
#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avg = round((float)(image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue)/3);
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width/2; j++)
        {
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][width-j-1];
            image[i][width-j-1] = tmp;
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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < width; y++)
        {
            int RedGx = 0;
            int GreenGx = 0;
            int BlueGx = 0;
            int RedGy = 0;
            int GreenGy = 0;
            int BlueGy = 0;

            RedGx += image[x][y].rgbtRed * 0;
            GreenGx += image[x][y].rgbtGreen * 0;
            BlueGx += image[x][y].rgbtBlue * 0;
            RedGy += image[x][y].rgbtRed * 0;
            GreenGy += image[x][y].rgbtGreen * 0;
            BlueGy += image[x][y].rgbtBlue * 0;

            if (x-1 >= 0 && y-1 >= 0)
            {
                RedGx += image[x-1][y-1].rgbtRed * -1;
                GreenGx += image[x-1][y-1].rgbtGreen * -1;
                BlueGx += image[x-1][y-1].rgbtBlue * -1;
                RedGy += image[x-1][y-1].rgbtRed * -1;
                GreenGy += image[x-1][y-1].rgbtGreen * -1;
                BlueGy += image[x-1][y-1].rgbtBlue * -1;
            }
            if (x-1 >= 0)
            {
                RedGx += image[x-1][y].rgbtRed * 0;
                GreenGx += image[x-1][y].rgbtGreen * 0;
                BlueGx += image[x-1][y].rgbtBlue * 0;
                RedGy += image[x-1][y].rgbtRed * -2;
                GreenGy += image[x-1][y].rgbtGreen * -2;
                BlueGy += image[x-1][y].rgbtBlue * -2;
            }
            if (x-1 >= 0 && y+1 < width)
            {
                RedGx += image[x-1][y+1].rgbtRed * 1;
                GreenGx += image[x-1][y+1].rgbtGreen * 1;
                BlueGx += image[x-1][y+1].rgbtBlue * 1;
                RedGy += image[x-1][y+1].rgbtRed * -1;
                GreenGy += image[x-1][y+1].rgbtGreen * -1;
                BlueGy += image[x-1][y+1].rgbtBlue * -1;
            }
            if (y-1 >= 0)
            {
                RedGx += image[x][y-1].rgbtRed * -2;
                GreenGx += image[x][y-1].rgbtGreen * -2;
                BlueGx += image[x][y-1].rgbtBlue * -2;
                RedGy += image[x][y-1].rgbtRed * 0;
                GreenGy += image[x][y-1].rgbtGreen * 0;
                BlueGy += image[x][y-1].rgbtBlue * 0;
            }
            if (y + 1 < width)
            {
                RedGx += image[x][y+1].rgbtRed * 2;
                GreenGx += image[x][y+1].rgbtGreen * 2;
                BlueGx += image[x][y+1].rgbtBlue * 2;
                RedGy += image[x][y+1].rgbtRed * 0;
                GreenGy += image[x][y+1].rgbtGreen * 0;
                BlueGy += image[x][y+1].rgbtBlue * 0;
            }
            if (x+1 < height && y-1 >= 0)
            {
                RedGx += image[x+1][y-1].rgbtRed * -1;
                GreenGx += image[x+1][y-1].rgbtGreen * -1;
                BlueGx += image[x+1][y-1].rgbtBlue * -1;
                RedGy += image[x+1][y-1].rgbtRed * 1;
                GreenGy += image[x+1][y-1].rgbtGreen * 1;
                BlueGy += image[x+1][y-1].rgbtBlue * 1;
            }
            if (x+1 < height)
            {
                RedGx += image[x+1][y].rgbtRed * 0;
                GreenGx += image[x+1][y].rgbtGreen * 0;
                BlueGx += image[x+1][y].rgbtBlue * 0;
                RedGy += image[x+1][y].rgbtRed * 2;
                GreenGy += image[x+1][y].rgbtGreen * 2;
                BlueGy += image[x+1][y].rgbtBlue * 2;
            }
            if (x+1 < height && y+1 < width)
            {
                RedGx += image[x+1][y+1].rgbtRed * 1;
                GreenGx += image[x+1][y+1].rgbtGreen * 1;
                BlueGx += image[x+1][y+1].rgbtBlue * 1;
                RedGy += image[x+1][y+1].rgbtRed * 1;
                GreenGy += image[x+1][y+1].rgbtGreen * 1;
                BlueGy += image[x+1][y+1].rgbtBlue * 1;
            }

            int Red = round(sqrt((float)(RedGx * RedGx) + (float)(RedGy * RedGy)));
            int Green = round(sqrt((float)(GreenGx * GreenGx) + (float)(GreenGy * GreenGy)));
            int Blue = round(sqrt((float)(BlueGx * BlueGx) + (float)(BlueGy * BlueGy)));

            if (Red > 255)
            {
                Red = 255;
            }
            if (Blue > 255)
            {
                Blue = 255;
            }
            if (Green > 255)
            {
                Green = 255;
            }

            copy[x][y].rgbtRed = Red;
            copy[x][y].rgbtBlue = Blue;
            copy[x][y].rgbtGreen = Green;
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
