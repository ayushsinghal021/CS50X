#include "helpers.h"
#include <math.h>
#include <string.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int R = image[i][j].rgbtRed;
            int G = image[i][j].rgbtGreen;
            int B = image[i][j].rgbtBlue;
            int avg = round((double)(R + G + B) / 3.0);
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
}


// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // Swap the pixels across the vertical centerline
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
     // Create a temporary image array to store the blurred image
    RGBTRIPLE temp[height][width];

    // Iterate through each pixel in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Initialize sum and count for each color channel
            int sumRed = 0, sumGreen = 0, sumBlue = 0;
            int count = 0;

            // Iterate through the 3x3 neighborhood centered at pixel (i, j)
            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int ni = i + di;
                    int nj = j + dj;

                    // Check if the neighboring pixel is within the bounds of the image
                    if (ni >= 0 && ni < height && nj >= 0 && nj < width)
                    {
                        // Accumulate color values and increment count
                        sumRed += image[ni][nj].rgbtRed;
                        sumGreen += image[ni][nj].rgbtGreen;
                        sumBlue += image[ni][nj].rgbtBlue;
                        count++;
                    }
                }
            }

            // Calculate the average color values
            temp[i][j].rgbtRed = round((float)sumRed / count);
            temp[i][j].rgbtGreen = round((float)sumGreen / count);
            temp[i][j].rgbtBlue = round((float)sumBlue / count);
        }
    }

    // Copy the blurred image from the temporary array to the original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    

}