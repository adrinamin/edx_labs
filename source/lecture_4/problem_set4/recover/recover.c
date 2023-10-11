#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/stat.h>
#include <errno.h> // Add this line

#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check for the correct number of command-line arguments
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    const char *dirname = "images";
    if (mkdir(dirname, 0777) && errno != EEXIST)
    {
        fprintf(stderr, "Could not create directory 'images'.\n");
        return 1;
    }

    // Open the forensic image file for reading
    FILE *infile = fopen(argv[1], "r");
    if (infile == NULL)
    {
        fprintf(stderr, "Could not open %s for reading.\n", argv[1]);
        return 1;
    }

    // Initialize variables
    BYTE buffer[BLOCK_SIZE];
    FILE *outfile = NULL;
    int jpeg_count = 0;

    while (fread(buffer, sizeof(BYTE), BLOCK_SIZE, infile) == BLOCK_SIZE)
    {
        // Check for the start of a new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // If we're already writing to a JPEG file, close it
            if (outfile != NULL)
            {
                fclose(outfile);
            }

            // Create a new JPEG file in the "images" directory
            char filename[15];
            snprintf(filename, sizeof(filename), "images/%03i.jpg", jpeg_count);
            outfile = fopen(filename, "w");
            if (outfile == NULL)
            {
                fclose(infile);
                fprintf(stderr, "Could not create %s.\n", filename);
                return 1;
            }

            jpeg_count++;
        }

        // Write to the current JPEG file if one is open
        if (outfile != NULL)
        {
            fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, outfile);
        }
    }

    // Close the last JPEG file
    if (outfile != NULL)
    {
        fclose(outfile);
    }

    // Close the input file
    fclose(infile);

    return 0;
}
