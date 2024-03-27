#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing

    // Iterate over infile's scanlines
    for (int i=0; i < height; i++)
    {
        // Iterate over pixels in scanline
        for (int j = 0; j < width; j++)
        {
            // check to see if pixel is black, since we only want to change the color of the black smiley face
            if (image[i][j].rgbtRed == 0 && image[i][j].rgbtGreen == 0 &&  image[i][j].rgbtBlue == 0)
            {
                // set the new RGB value
                image[i][j].rgbtRed = 210;
                image[i][j].rgbtGreen = 104;
                image[i][j].rgbtBlue = 252;
            }
        }
    }
}
