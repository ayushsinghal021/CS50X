#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s image\n", argv[0]);
        return 1;
    }

    // Open forensic image file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Could not open file %s\n", argv[1]);
        return 1;
    }

    // Initialize variables
    uint8_t buffer[BLOCK_SIZE];
    FILE *img = NULL;
    char filename[8];
    int count = 0;

    // Read blocks from forensic image
    while (fread(buffer, BLOCK_SIZE, 1, file))
    {
        // Check for JPEG signature
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Close previous JPEG file if one is open
            if (img != NULL)
            {
                fclose(img);
            }

            // Create new JPEG file
            sprintf(filename, "%03d.jpg", count++);
            img = fopen(filename, "w");
            if (img == NULL)
            {
                fprintf(stderr, "Could not create output file %s\n", filename);
                fclose(file);
                return 1;
            }
        }

        // Write block to JPEG file if one is open
        if (img != NULL)
        {
            fwrite(buffer, BLOCK_SIZE, 1, img);
        }
    }

    // Close files
    fclose(file);
    if (img != NULL)
    {
        fclose(img);
    }

    return 0;
}