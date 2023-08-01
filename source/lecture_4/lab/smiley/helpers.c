#include <stdlib.h>
#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            /*
            In C, arrays are passed to functions by reference,
            which means when we access and modify the image array elements inside the function,
            we are directly modifying the original array.
            However, when we assign RGBTRIPLE pixel = image[x][y];,
            we are creating a copy of the pixel,
            and any modifications made to pixel won't be reflected in the image array.
            We need to change the pixe to a pointer
            which points to the address of the image array.
            Any modification to the pixel variable will directly affect the corresponding
            pixel in the image array.
            */
            RGBTRIPLE *pixel = &image[x][y];

            // make pixels blue if they are black
            if (pixel->rgbtBlue == 0 && pixel->rgbtGreen == 0 && pixel->rgbtRed == 0)
            {
                pixel->rgbtBlue = 255;
                pixel->rgbtGreen = 0;
                pixel->rgbtRed = 0;
            }
        }
    }
}
