#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int menu()
{
	int choice;
	printf("\t\t\t Welcome to Student Database\n\n");
	printf("\t\t\t Please select an option\n\n");
	printf("\t\t\t 1. Add a student\n\t\t\t 2. View student detail\n\t\t\t 3. Delete a student\n\t\t\t 4. Exit\n\n");
	printf("\t\t\t ");
	scanf("%d", &choice);
	while(choice < 1 || choice > 4)
	{
		if (choice == 1)
		{
			return 1;
		}
		else if (choice == 2)
		{
			return 2;
		}
		else if (choice == 3)
		{
			return 3;
		}
		else if (choice == 4)
		{
			return 4;
		}
		else
		{
			printf("\t\t\t Error!! Please select a valid option\n\n");
			printf("\t\t\t ");
			scanf("%d", &choice);
		}
	}
	
}

int main()
{
	int option = 0;
	while (option != 4)
	{
		option = menu();
		if (option == 1)
		{
			char name[30];
			char roll_no[10];
			char email[30];
			int check = 0;
			char *c = NULL;
			size_t line_ = 0;
			int line_no = 0;
			char *str = NULL;
			FILE* fptr1 = fopen("Student Database.txt", "a+");
			printf("\t\t\t Enter name: ");
			scanf("\t\t\t %s", name);
			printf("\t\t\t Enter roll number: ");
			scanf("\t\t\t %s", roll_no);
			printf("\t\t\t Enter email id: ");
			scanf("\t\t\t %s", email);
			line_no = getline(&str, &line_, fptr1);
			while (line_no >= 0)
			{
				c = strtok(str,"_");
				if (strcmp(c, roll_no) == 0)
				{
					check = 1;
					break;
				}
				line_no = getline(&str, &line_, fptr1);
			}
			if (check == 0)
			{
				fprintf(fptr1, "%s_", roll_no);
				fprintf(fptr1, "%s_", name);
				fprintf(fptr1, "%s\n", email);
				printf("\n\t\t\t Student added successfully!!\n\n");
			}
			else
				printf("\n\t\t\t Student with this roll number already exists!!\n\n");
			fclose(fptr1);
		}
		else if (option == 2)
		{
			int student_no;
			int check = 0;
			char *c = NULL;
			size_t line_ = 0;
			int line_no = 0;
			int count = 0;
			char *str = NULL;
			FILE* fptr1 = fopen("Student Database.txt", "r");
			printf("\n\t\t\t Enter record number to view details: ");
			scanf("\t\t\t %d", &student_no);
			line_no = getline(&str, &line_, fptr1);
			while (line_no >= 0)
			{
				if (count == student_no)
				{
					printf("\n\t\t\t Student record:\n");
					c = strtok(str,"_");
					printf("\t\t\t Roll no: %s\n", c);
					c = strtok(NULL,"_");
					printf("\t\t\t Name: %s\n", c);
					c = strtok(NULL,"_");
					printf("\t\t\t Email: %s\n", c);
					check = 1;
					break;
				}
				line_no = getline(&str, &line_, fptr1);
				count++;
			}
			if (check == 0)
				printf("\n\t\t\t Student record not found!!\n\n");
			fclose(fptr1);
		}
		else if (option == 3)
		{
			int student_no;
			int check = 0;
			char *c = NULL;
			size_t line_ = 0;
			int line_no = 0;
			int count = 0;
			char *str = NULL;
			FILE* fptr1 = fopen("Student Database.txt", "r");
			FILE* fptr2 = fopen("temp.txt", "w");
			printf("\n\t\t\t Enter record number to delete: ");
			scanf("\t\t\t %d", &student_no);
			line_no = getline(&str, &line_, fptr1);
			while (line_no >= 0)
			{
				if (count == student_no)
					check = 1;
				else
					fprintf(fptr2, "%s", str);
				line_no = getline(&str, &line_, fptr1);
				count++;
			}
			fclose(fptr1);
			fclose(fptr2);
			if (check == 0)
			{
				remove("temp.txt");
				printf("\n\t\t\t Student record not found!!\n\n");
			}
			else
			{
				FILE* fptr3 = fopen("Student Database.txt", "w");
				FILE* fptr4 = fopen("temp.txt", "r");
				line_no = getline(&str, &line_, fptr4);
				while (line_no >= 0)
				{
					fprintf(fptr3, "%s", str);
					line_no = getline(&str, &line_, fptr1);
				}
				fclose(fptr3);
				fclose(fptr4);
				remove("temp.txt");
				printf("\n\t\t\t Successfully deleted!!\n\n");
			}
		}
	}
		
	return 0;
}
