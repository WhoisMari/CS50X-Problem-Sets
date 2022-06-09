#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc != 2) // Checks the usage
	{
		fprintf(stderr, "Usage: ./recover image\n");
		return 1;
	}

	FILE *file = fopen(argv[1], "r"); // Checks if memory card is opened
	if (file == NULL)
	{
		fprintf(stderr, "Could not open file %s.\n", argv[1]);
		return 1;
	}

	FILE *img; // Creates vars to allocate memory
	char filename[7];
	unsigned char *bf = malloc(512);
	int counter = 0;

	while (fread(bf, 512, 1, file))
	{
		// RPG file found
		if (bf[0] == 0xff && bf[1] == 0xd8 && bf[2] == 0xff && (bf[3] & 0xf0) == 0xe0)
		{
			if (counter > 0) // Closes previous JPG, if it exists
			{
				fclose(img);
			}

			sprintf(filename, "%03d.jpg", counter); // Create file name
			img = fopen(filename, "w"); // Open new file

			if (img == NULL) // Check if jpg file is created
			{
				fclose(file);
				free(bf);
				fprintf(stderr, "Could not creat output JPG %s", filename);
				return 3;
			}

			counter++;
		}

		if (counter > 0) // If JPG file exists, writes on the file opened
		{
			fwrite(bf, 512, 1, img);
		}
	}

	// Free memory and then close file
	fclose(img);
	fclose(file);
	free(bf);
	return 0;
}