// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

void copy_wav_header(FILE *src, FILE *dst);
void change_volume(float factor, FILE *src, FILE *dst);

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    copy_wav_header(input, output);

    // TODO: Read samples from input file and write updated data to output file
    change_volume(factor, input, output);

    // Close files
    fclose(input);
    fclose(output);
}

void copy_wav_header(FILE *src, FILE *dst)
{
    uint8_t src_header[HEADER_SIZE];
    fread(src_header, sizeof(src_header), 1, src);
    fwrite(src_header, sizeof(src_header), 1, dst);
}

void change_volume(float factor, FILE *src, FILE *dst)
{
    int16_t buf;
    while((fread(&buf, sizeof(int16_t), 1, src)) > 0)
    {
        buf *= factor;
        fwrite(&buf, sizeof(int16_t), 1, dst);
    }
}
