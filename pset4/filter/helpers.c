#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
	// Go over each column of pixel
	for (int i = 0; i < height; i++)
	{
		// Go over each row of pixel in each column
		for (int j = 0; j < width; j++)
		{
			// Get into array, obtain value of each colour
			int red = image[i][j].rgbtRed;
			int blue = image[i][j].rgbtBlue;
			int green = image[i][j].rgbtGreen;

			// Calculate the average value of each pixel (rounded)
			int avg = round(((float)red + (float)blue + (float)green) / 3);
			//set the calculated average to be the new value of each pixel
			image[i][j].rgbtRed = image[i][j].rgbtBlue = image[i][j].rgbtGreen = avg;
		}
	}
	return;
}
// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			int red = image[i][j].rgbtRed;
			int blue = image[i][j].rgbtBlue;
			int green = image[i][j].rgbtGreen;

			// New sepia
			int sepiaRed = round(0.393 * red + 0.769 * green + 0.189 * blue);
			if (sepiaRed > 255)
			{
				image[i][j].rgbtRed = 255;
			}
			else
			{
				image[i][j].rgbtRed = sepiaRed;
			}
			int sepiaGreen = round(0.349 * red + 0.686 * green + 0.168 * blue);
			if (sepiaGreen > 255)
			{
				image[i][j].rgbtGreen = 255;
			}
			else
			{
				image[i][j].rgbtGreen = sepiaGreen;
			}
			int sepiaBlue = round(0.272 * red + 0.534 * green + 0.131 * blue);
			if (sepiaBlue > 255)
			{
				image[i][j].rgbtBlue = 255;
			}
			else
			{
				image[i][j].rgbtBlue = sepiaBlue;
			}
		}
	}
	return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
	for (int i = 0; i < height; i++)
	{
		// Recap through the array until it gets to the mid-point
		for (int j = 0; j < (width / 2); j++)
		{
			RGBTRIPLE temp = image[i][j];
			image[i][j] = image[i][width - (j + 1)];
			image[i][width - (j + 1)] = temp;
		}
	}
	return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
	// Create a temporary image to be blurred
	RGBTRIPLE temp[height][width];
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			temp[i][j] = image[i][j];
		}
	}
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			int sum_blue;
			int sum_green;
			int sum_red;
			float counter;
			sum_blue = sum_green = sum_red = counter = 0;

			// Corner pixel on bottom right
			if (i >= 0 && j >= 0)
			{
				sum_red += temp[i][j].rgbtRed;
				sum_green += temp[i][j].rgbtGreen;
				sum_blue += temp[i][j].rgbtBlue;
				counter++;
			}
			// Corner pixel on bottom left
			if (i >= 0 && j - 1 >= 0)
			{
				sum_red += temp[i][j - 1].rgbtRed;
				sum_green += temp[i][j - 1].rgbtGreen;
				sum_blue += temp[i][j - 1].rgbtBlue;
				counter++;
			}
			// Corner pixel on top left
			if (i - 1 >= 0 && j >= 0)
			{
				sum_red += temp[i - 1][j].rgbtRed;
				sum_green += temp[i - 1][j].rgbtGreen;
				sum_blue += temp[i - 1][j].rgbtBlue;
				counter++;
			}
			// Corner pixel on top right
			if (i - 1 >= 0 && j - 1 >= 0)
			{
				sum_red += temp[i - 1][j - 1].rgbtRed;
				sum_green += temp[i - 1][j - 1].rgbtGreen;
				sum_blue += temp[i - 1][j - 1].rgbtBlue;
				counter++;
			}

			// pixels on bottom edge
			if ((i >= 0 && j + 1 >= 0) && (i >= 0 && j + 1 < width))
			{
				sum_red += temp[i][j + 1].rgbtRed;
				sum_green += temp[i][j + 1].rgbtGreen;
				sum_blue += temp[i][j + 1].rgbtBlue;
				counter++;
			}
			// pixels on top edge
			if ((i - 1 >= 0 && j + 1 >= 0) && (i - 1 >= 0 && j + 1 < width))
			{
				sum_red += temp[i - 1][j + 1].rgbtRed;
				sum_green += temp[i - 1][j + 1].rgbtGreen;
				sum_blue += temp[i - 1][j + 1].rgbtBlue;
				counter++;
			}
			// pixels on left edge
			if ((i + 1 >= 0 && j >= 0) && (i + 1 < height && j >= 0))
			{
				sum_red += temp[i + 1][j].rgbtRed;
				sum_green += temp[i + 1][j].rgbtGreen;
				sum_blue += temp[i + 1][j].rgbtBlue;
				counter++;
			}
			// pixels on right edge
			if ((i + 1 >= 0 && j - 1 >= 0) && (i + 1 < height && j - 1 >= 0))
			{
				sum_red += temp[i + 1][j - 1].rgbtRed;
				sum_green += temp[i + 1][j - 1].rgbtGreen;
				sum_blue += temp[i + 1][j - 1].rgbtBlue;
				counter++;
			}

			// middle pixels
			if ((i + 1 >= 0 && j + 1 >= 0) && (i + 1 < height && j + 1 < width))
			{
				sum_red += temp[i + 1][j + 1].rgbtRed;
				sum_green += temp[i + 1][j + 1].rgbtGreen;
				sum_blue += temp[i + 1][j + 1].rgbtBlue;
				counter++;
			}
			// Find average colour value
			image[i][j].rgbtRed = round(sum_red / counter);
			image[i][j].rgbtGreen = round(sum_green / counter);
			image[i][j].rgbtBlue = round(sum_blue / counter);
		}
	}
	return;
}