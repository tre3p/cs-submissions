#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
const int JPEG_BYTE_BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    FILE *raw_file = fopen(argv[1], "r");

    if (raw_file == NULL)
    {
        return 1;
    }

    BYTE *buf = malloc(JPEG_BYTE_BLOCK_SIZE * sizeof(BYTE));

    if (buf == NULL)
    {
        return 1;
    }

    FILE *out_jpeg = NULL;

    char file_name[8] = {0};
    int jpeg_counter = 0;
    while((fread(buf, sizeof(BYTE), JPEG_BYTE_BLOCK_SIZE, raw_file)) == JPEG_BYTE_BLOCK_SIZE)
    {
        if (buf[0] == 0xff && buf[1] == 0xd8 && buf[2] == 0xff && (buf[3] & 0xf0) == 0xe0)
        {
            if (out_jpeg != NULL) {
                fclose(out_jpeg);
            }

            sprintf(file_name, "%03d.jpg", jpeg_counter++);
            out_jpeg = fopen(file_name, "w");
        }

        if(out_jpeg != NULL)
        {
            fwrite(buf, sizeof(BYTE), JPEG_BYTE_BLOCK_SIZE, out_jpeg);
        }
    }


    if (out_jpeg != NULL)
    {
        fclose(out_jpeg);
    }
    free(buf);
    fclose(raw_file);
}