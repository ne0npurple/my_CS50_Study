#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef uint8_t BYTE;
int const BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s IMAGE", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("File cannot be opened!\n");
        return 1;
    }

    BYTE buffer[BLOCK_SIZE];
    FILE *output = NULL;
    int idx = 0;

    while (fread(buffer, sizeof(BYTE), BLOCK_SIZE, file) == BLOCK_SIZE)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            char tmp[8];
            sprintf(tmp, "%03d.jpg", idx);
            if (output != NULL)
            {
                fclose(output);
            }
            output = fopen(tmp, "w");
            if (output == NULL)
            {
                printf("File cannot be written!\n");
                return 2;
            }
            idx++;
        }
        if (output != NULL)
        {
            fwrite(buffer, 1, BLOCK_SIZE, output);
        }    
    }

    fclose(file);
    fclose(output);
}