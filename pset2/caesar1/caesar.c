#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, string argv[])
{
	if (argc == 2 && isNumeric(argv[1])) // Check if there is only 1 argument and it is a number. If not, returns instructions
	{
		int k = atoi(argv[1]);  // Get the caesar KEY value convert into integer

		string code = get_string("plaintext: ");  // Get text
		printf("ciphertext: ");  //Print out cipher

		// Iterate through plain text letter by letter
		for (int i = 0, n = strlen(code) ; i < n; i++)
		{
			// Checking if it is lowercase 97 = a to 112 = z and if + 13 characters along
			if (code[i] >= 'a' && code[i] <= 'z')
			{
				printf("%c", (((code[i] - 'a') + k) % 26) + 'a');  // Print out lowercase with KEY
			}
			// If it is between uppercase A and Z
			else if (code[i] >= 'A' && code[i] <= 'Z')
			{
				printf("%c", (((code[i] - 'A') + k) % 26) + 'A');  // Print out uppercase with KEY
			}
			else
			{

				printf("%c", code[i]);
			}
		}
		printf("\n");
		return 0;
	}

	else
	{
		printf("Usage ./caesar key\n");
		return 1;
	}
}

int isNumeric (const char * s)
{
	if (s == NULL || *s == '\0' || isspace(*s))
	return 0;
	char * p;
	strtod (s, &p);
	return *p == '\0';
}