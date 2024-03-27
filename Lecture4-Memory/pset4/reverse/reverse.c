#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

// made by me
const int HEADER_SIZE = 44;
WAVHEADER header;

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if (argc < 3)
    {
        printf("Usage: %s infile.wav outfile.wav\n", argv[0]);
        return 1;
    }

    // Open input file for reading
    // TODO #2
    FILE *infile = fopen(argv[1], "r");
    if (infile == NULL)
    {
        printf("File cannot be opened!\n");
        return 1;
    }

    // Read header
    // TODO #3
    fread(&header, HEADER_SIZE, 1, infile);
    // printf("is %li", ftell(infile));

    // Use check_format to ensure WAV format
    // TODO #4
    if (check_format(header) == 1)
    {
        printf("File is not .wav formatted!\n");
        return 1;
    }

    // Open output file for writing
    // TODO #5
    FILE *outfile = fopen(argv[2], "w");
    if (outfile == NULL)
    {
        printf("File cannot be opened!\n");
        return 1;
    }

    // Write header to file
    // TODO #6
    fwrite(&header, HEADER_SIZE, 1,outfile);

    // Use get_block_size to calculate size of block
    // TODO #7
    int blocksize = get_block_size(header);

    // Write reversed audio to file
    // TODO #8
    // initialized buffer 
    uint8_t *buffer[blocksize];

    fseek(infile, -blocksize, SEEK_END);

    // loop to go through the sound data, stop when the pointer point to the header size since we only wants to read the sound data
    while (ftell(infile) >= HEADER_SIZE)
    {
        // read and write the sound data
        fread(&buffer, blocksize, 1, infile);
        fwrite(&buffer, blocksize, 1, outfile);
        // move file pointer two steps backwards, when all the data is read, then return 
        if (fseek(infile, -2 * blocksize, SEEK_CUR))
        {
            return 1;
        }
    }
    
    fclose(infile);
    fclose(outfile);
}

int check_format(WAVHEADER header)
{
    // TODO #4
    // define an num array which represent digit of "WAVE" for comparison
    int num[] = {87, 65, 86, 69};

    for (int i = 0; i < 4; i++)
    {
        // check if format incorrect, return false
        if (header.format[i] != num[i])
        {
            return 1;
        }
    }
    // if the header format is correct, return true
    return 0;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    int size = header.numChannels * (header.bitsPerSample/8);
    return size;
}