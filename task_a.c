#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *arg[])
{
	if (argc == 1)
		printf("Only one argument passed i.e the file name.\n");
	else if (argc == 2)
	{
		//char file_name[20] = "\0";		//add .txt in command line argument
		//strcat(file_name, arg[1]);
		//strcat(file_name, ".txt");
		FILE *fptr = fopen(arg[1], "r");
		if (fptr)
		{
			int count = 0;
			char c = fgetc(fptr);
			while (!feof(fptr))
			{
				if (c >= '0' && c <= '9')
					count++;
				c = fgetc(fptr);
			}
			printf("Total count of numbers in string: %i\n", count);
			fclose(fptr);
		}
		else
			printf("Error! Could not open file.\n");
	}
	else
		printf("Error! More than one argument passed.\n");
	return 0;
}
