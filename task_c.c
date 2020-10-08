#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *arg[])
{
	if (argc == 1)
		printf("Only one argument passed i.e the file name.\n");
	else if (argc == 2)
	{
		//char file_name[20] = "\0";
		char temp[30];
		char* c = NULL;
		//strcat(file_name, arg[1]);		//add .txt in command line argument
		//strcat(file_name, ".txt");
		size_t line_ = 0;
		int line_no = 0;
		char *str = NULL;
		int check = 0;
		FILE *fptr = fopen(arg[1], "r");
		FILE *fptr2 = fopen("Output_c.txt", "w");
		if (fptr)
		{
			line_no = getline(&str, &line_, fptr);
			while (line_no >= 0)
			{
				c = strtok(str," \n\0");
				while (c != NULL)
				{
					check = 0;
					//printf("%c\n",c[strlen(c)-1]);
					for (int i = 0; i < strlen(c); i++)
					{
						if (c[i] == 'a' || c[i] == 'e' || c[i] == 'i' || c[i] == 'o' || c[i] == 'u' || c[i] == 'A' || c[i] == 'E' || c[i] == 'I' || c[i] == 'O' || c[i] == 'U')
						{
							check = 1;
							break;
						}
					}
					//printf("%d\n", check);
					if (check == 1)
					{
						memset(temp,'\0',sizeof(temp));
						int chek = 0;
						int j = 0;
						int i = strlen(c) - 1;
						//printf("%c\n", c[strlen(c) - 1]);
						if ((c[strlen(c) - 1] < 'a' && (c[strlen(c) - 1] < 'A') || (c[strlen(c) - 1] > 'z') && c[strlen(c) - 1] > 'Z'))
						{
							temp[strlen(c) - 1] = c[strlen(c) - 1];
							i--;
							chek = 1;
						}
						for (; i >= 0; j++, i--)
						{
							temp[j] = c[i];
						}
						if (chek == 0)						
							temp[j++] = '\0';
						else
							temp[j+2] = '\0';
						fprintf(fptr2, "%s ", temp);
					}
					else
						fprintf(fptr2, "%s ", c);
						
					c = strtok(NULL," \n\0");
				}
				line_no = getline(&str, &line_, fptr);
			}
			fclose(fptr);
			fclose(fptr2);
		}
		else
			printf("Error! Could not open file.\n");
	}
	else
		printf("Error! More than one argument passed.\n");
	return 0;
}
