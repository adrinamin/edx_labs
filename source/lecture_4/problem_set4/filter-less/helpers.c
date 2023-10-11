#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            // calculate the average of the red, green, and blue values
            int average = (image[x][y].rgbtBlue + image[x][y].rgbtGreen + image[x][y].rgbtRed) / 3;

            image[x][y].rgbtBlue = average;
            image[x][y].rgbtGreen = average;
            image[x][y].rgbtRed = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    /*
    sepia formula:
        sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue
        sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue
        sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue
    */

    // iterate over each pixel in the image
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)

        {
            // calculate the sepia values for each color
            int sepiaRed = .393 * image[x][y].rgbtRed + .769 * image[x][y].rgbtGreen + .189 * image[x][y].rgbtBlue;
            int sepiaGreen = .349 * image[x][y].rgbtRed + .686 * image[x][y].rgbtGreen + .168 * image[x][y].rgbtBlue;
            int sepiaBlue = .272 * image[x][y].rgbtRed + .534 * image[x][y].rgbtGreen + .131 * image[x][y].rgbtBlue;

            // if the sepia value is greater than 255, set it to 255
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

            // set the pixel to the sepia values
            image[x][y].rgbtRed = sepiaRed;
            image[x][y].rgbtGreen = sepiaGreen;
            image[x][y].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // swap pixels on horizontally opposite sides of the image
    for (int x = 0; x < width / 2; x++)
    {
        for (int y = 0; y < height; y++)
        {
            // store the pixel on the left side of the image
            RGBTRIPLE temp = image[x][y];

            // set the pixel on the left side of the image to the pixel on the right side of the image
            image[x][y] = image[width - x - 1][y];

            // set the pixel on the right side of the image to the pixel on the left side of the image
            image[width - x - 1][y] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // blur each pixel in the image
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)

        {
            // initialize the sum of the red, green, and blue values
            int sumRed = 0;
            int sumGreen = 0;
            int sumBlue = 0;

            // initialize the number of pixels in the average
            int numPixels = 0;

            // iterate over the 3x3 grid centered on the pixel
            for (int i = -1; i < 2; i++)
            {
                // skip the pixel if it is outside the image
                if (x + i < 0 || x + i > width - 1)
                {
                    continue;
                }
                for (int j = -1; j < 2; j++)
                {
                    // skip the pixel if it is outside the image
                    if (y + j < 0 || y + j > height - 1)
                    {
                        continue;
                    }

                    // add the red, green, and blue values to the sum
                    sumRed += image[x + i][y + j].rgbtRed;
                    sumGreen += image[x + i][y + j].rgbtGreen;
                    sumBlue += image[x + i][y + j].rgbtBlue;

                    // increment the number of pixels in the average
                    numPixels++;
                }
            }

            // calculate the average of the red, green, and blue values
            int averageRed = sumRed / numPixels;
            int averageGreen = sumGreen / numPixels;
            int averageBlue = sumBlue / numPixels;

            // set the pixel to the average values
            image[x][y].rgbtRed = averageRed;
            image[x][y].rgbtGreen = averageGreen;
            image[x][y].rgbtBlue = averageBlue;
        }
    }
    return;
}
