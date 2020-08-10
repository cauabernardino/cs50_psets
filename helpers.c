#include "helpers.h"
#include <stdlib.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int mean;

    // Height loop
    for (int i = 0; i < height; i++)
    {
        // Width loop
        for (int j = 0; j < width; j++)
        {
            mean = round((round(image[i][j].rgbtBlue) + round(image[i][j].rgbtGreen) + round(image[i][j].rgbtRed)) / 3);
            image[i][j].rgbtBlue = mean;
            image[i][j].rgbtGreen = mean;
            image[i][j].rgbtRed = mean;
        }
    }
    return;
}


// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed, sepiaGreen, sepiaBlue;

    // Height loop
    for (int i = 0; i < height; i++)
    {
        // Width loop
        for (int j = 0; j < width; j++)
        {
            sepiaRed = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
            sepiaGreen = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            sepiaBlue = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}


// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE(*tmp)[width] = calloc(height, width * sizeof(RGBTRIPLE));

    // First loop -> buffer gets reflected pixels
    // Height loop
    for (int i = 0; i < height; i++)
    {
        // Width loop
        for (int j = 0, k = width - 1; j < width && k >= 0; j++, k--)
        {
            tmp[i][j] = image[i][k];
        }
    }
    // Second loop -> images gets the reflected image from buffer
    for (int i = 0; i < height; i++)
    {
        // Width loop
        for (int j = 0;  j < width; j++)
        {
            image[i][j] = tmp[i][j];
        }
    }
    free(tmp);
    return;
}


// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Copying image
    RGBTRIPLE(*tmp)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    for (int i = 0; i < height; i++)
    {
        // Width loop
        for (int j = 0; j < width; j++)
        {
            tmp[i][j] = image[i][j];
        }
    }

    float meanRed, meanBlue, meanGreen;
    int count;

    // Pixel loop
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            meanRed = 0;
            meanBlue = 0;
            meanGreen = 0;
            count = 0;

            for (int k = -1; k < 2; k++)
            {
                if (i + k < 0 || i + k > height - 1)
                {
                    continue;
                }
                else
                {
                    for (int l = -1; l < 2; l++)
                    {
                        if (j + l < 0 || j + l > width - 1)
                        {
                            continue;
                        }
                        else
                        {
                            count++;
                            meanRed += tmp[i + k][j + l].rgbtRed;
                            meanBlue += tmp[i + k][j + l].rgbtBlue;
                            meanGreen += tmp[i + k][j + l].rgbtGreen;
                        }
                    }
                }

            }
            image[i][j].rgbtRed = round(meanRed / count);
            image[i][j].rgbtBlue = round(meanBlue / count);
            image[i][j].rgbtGreen = round(meanGreen / count);
        }
    }
    free(tmp);
    return;
}
