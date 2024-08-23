#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check that the argument count is 2
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // Open file for reading
    FILE *input_file = fopen(argv[1], "r");

    // Check that the input_file is valid
    if (input_file == NULL)
    {
        printf("Could not open file\n");
        return 2;
    }

    // Store blocks of 512 bytes in an array
    unsigned char buffer[512];

    // Track the number of images generated
    int count_image = 0;

    // File pointer for recovered images
    FILE *output_file = NULL;

    // Loop to read the blocks of 512 bytes
    while (fread(buffer, sizeof(char), 512, input_file))
    {
        // Check if the bytes indicate the start of a JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Close the previous output_file if it's open
            if (output_file != NULL)
            {
                fclose(output_file);
            }

            // Write the JPEG filename
            char filename[8];
            sprintf(filename, "%03i.jpg", count_image);

            // Open output_file for writing
            output_file = fopen(filename, "w");

            // Check if the output_file is valid
            if (output_file == NULL)
            {
                fprintf(stderr, "Could not create %s\n", filename);
                fclose(input_file);
                return 3;
            }

            // Increment the count of images found
            count_image++;
        }

        // Check if output_file is open for valid input
        if (output_file != NULL)
        {
            fwrite(buffer, sizeof(char), 512, output_file);
        }
    }

    // Close the output_file outside the loop
    if (output_file != NULL)
    {
        fclose(output_file);
    }

    // Close the input_file
    fclose(input_file);

    return 0;
}
