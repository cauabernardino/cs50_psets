#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;


int main(int argc, char *argv[])
{
    // Check for invalid usage
    if (argc !=  2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }


    // Open input file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Could not open the file.\n");
        return 2;
    }

    // Find size of file
    fseek(file, 0L, SEEK_END);
    unsigned int size = ftell(file);
    fseek(file, 0L, SEEK_SET);

    // Number of iterations
    int block = 512;
    int n = size / block;

    // Read file in blocks
    BYTE buffer[n][block];
    fread(&buffer, block, n, file);


    // Looking for JPEGs
    char imgname[8];
    int count = 0;
    FILE *img = NULL;

    int jpg_found = 0;

    for (int i = 0; i < n; i++)
    {
        if (buffer[i][0] == 0xff && buffer[i][1] == 0xd8 && buffer[i][2] == 0xff && (buffer[i][3] & 0xf0) == 0xe0)
        {
            if (jpg_found == 1)
            {
                // If other jpeg running, close it.
                fclose(img);
            }
            else
            {
                // First jpeg ready to go
                jpg_found = 1;
            }

            sprintf(imgname, "%03i.jpg", count);
            img = fopen(imgname, "w");
            count++;
        }

        if (jpg_found == 1)
        {
            fwrite(buffer[i], block, 1, img);
        }
    }

    fclose(img);
    fclose(file);

    return 0;
}
