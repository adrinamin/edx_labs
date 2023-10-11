#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // iterating row by row
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            RGBTRIPLE *pixel = &image[y][x];
            
            // Calculate the average value of the red, green, and blue components
            int average = (pixel->rgbtBlue + pixel->rgbtGreen + pixel->rgbtRed) / 3;
            
            // Set each component to the average value
            pixel->rgbtBlue = average;
            pixel->rgbtGreen = average;
            pixel->rgbtRed = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // iterate over each pixel in the image
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            RGBTRIPLE *pixel = &image[y][x];

            // calculate the sepia values for each color
            int sepiaRed = .393 * pixel->rgbtRed + .769 * pixel->rgbtGreen + .189 * pixel->rgbtBlue;
            int sepiaGreen = .349 * pixel->rgbtRed + .686 * pixel->rgbtGreen + .168 * pixel->rgbtBlue;
            int sepiaBlue = .272 * pixel->rgbtRed + .534 * pixel->rgbtGreen + .131 * pixel->rgbtBlue;

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
            pixel->rgbtRed = sepiaRed;
            pixel->rgbtGreen = sepiaGreen;
            pixel->rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // swap pixels on horizontally opposite sides of the image
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width / 2; x++)
        {
            // Get a pointer to the pixel on the left side
            RGBTRIPLE *left_pixel = &image[y][x];
            
            // Get a pointer to the pixel on the right side
            RGBTRIPLE *right_pixel = &image[y][width - 1 - x];

            // Swap the pixels (RGB values)
            RGBTRIPLE temp = *left_pixel;
            *left_pixel = *right_pixel;
            *right_pixel = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of the original image
    RGBTRIPLE copy[height][width];
    
    // Iterate over each pixel in the image
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int totalRed = 0;
            int totalGreen = 0;
            int totalBlue = 0;
            int count = 0;

            // Iterate over a 3x3 grid centered at the current pixel
            for (int dy = -1; dy <= 1; dy++)
            {
                for (int dx = -1; dx <= 1; dx++)
                {
                    int newY = y + dy;
                    int newX = x + dx;

                    // Check if the new coordinates are within bounds
                    if (newY >= 0 && newY < height && newX >= 0 && newX < width)
                    {
                        totalRed += image[newY][newX].rgbtRed;
                        totalGreen += image[newY][newX].rgbtGreen;
                        totalBlue += image[newY][newX].rgbtBlue;
                        count++;
                    }
                }
            }

            // Calculate the average color
            copy[y][x].rgbtRed = totalRed / count;
            copy[y][x].rgbtGreen = totalGreen / count;
            copy[y][x].rgbtBlue = totalBlue / count;
        }
    }

    // Copy the blurred image back to the original image
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            image[y][x] = copy[y][x];
        }
    }
    return;
}
