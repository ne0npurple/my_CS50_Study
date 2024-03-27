#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
int const BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    // check usage
    if (argc < 2)
    {
        printf("Usage: %s IMAGE\n", argv[0]);
        return 1;
    }
    
    // read file and check
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("File cannot be read!\n");
        return 1;
    }

    //  initialized a buffer 
    BYTE buffer[BLOCK_SIZE];

    // initialized output file to NULL
    FILE *output = NULL;
    int idx = 0;

    // read the input file and write it to the output file
    while (fread(buffer, sizeof(BYTE), BLOCK_SIZE, file) == BLOCK_SIZE)
    {
        // check for signature 
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            char tmp[8];
            sprintf(tmp, "%03d.jpg", idx);
            // if new signature found, close the opened file to write it to a new file
            if (output != NULL)
            {
                fclose(output);
            }
            output = fopen(tmp, "w");
            if (output == NULL)
            {
                printf("File cannot be write!\n");
                return 1;
            }
            idx++;
        }
        // write the infile which has a same signature to output file
        if (output != NULL)
        {
            fwrite(buffer, 1, BLOCK_SIZE, output);
        }
    }
    fclose(output);
    fclose(file);
}