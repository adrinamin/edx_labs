#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    // Your program should accept exactly one command-line argument, the name of a forensic image from which to recover JPEGs.
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // If the forensic image cannot be opened for reading, your program should inform the user as much, and main should return 1.
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    unsigned char *buffer = malloc(BLOCK_SIZE);
    int jpeg_count = 0;
    FILE *outfile = NULL;

    while (fread(buffer, BLOCK_SIZE, 1, file) == BLOCK_SIZE)
    {
        // If found, open a new JPEG
        // If not, keep looking
        // look for beginning of JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff)
        {
            // If already found a JPEG, close it
            if (outfile != NULL)
            {
                fclose(outfile);
            }

            // Open a new JPEG
            char filename[8];
            sprintf(filename, "%03i.jpg", jpeg_count);
            outfile = fopen(filename, "w");
            jpeg_count++;
        }

        // If already found a JPEG, write to it
        if (outfile != NULL)
        {
            fwrite(buffer, BLOCK_SIZE, 1, outfile);
        }
    }

    return 0;
}