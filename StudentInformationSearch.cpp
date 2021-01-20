#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define ESC 0x1b

struct node
{
	char name[20];
	char num[15];
	char sex[7];
	int age;
	float score[10];
	struct node *next;
};

struct node *head = (struct node *)malloc(sizeof(struct node));
struct node *tail = (struct node *)malloc(sizeof(struct node));
const int SUBJECTNUM = 3;

void init_ht()
{
	head = NULL;
	tail = NULL;
}

void insertToEnd(struct node *p)
{
	p->next = NULL;
	if (head == NULL)
		head = p;
	else
		tail->next = p;
	tail = p;
}

void input_data_from_console()
{
	int i;
	char ch;
	char *temp = (char *)malloc(7);
	struct node *p = (struct node *)malloc(sizeof(struct node));
	while (1)
	{
		printf("Input Data(Y/N):");
		ch = getchar();
		if (ch == 'y' || ch == 'Y')
		{
			p = (struct node *)malloc(sizeof(struct node));
			printf("Input name >> ");
			scanf("%s", p->name);
			printf("Input student number >> ");
			getchar();
			scanf("%s", p->num);
			do
			{
				memset(temp, 0, sizeof(temp));
				printf("Input sex >> ");
				getchar();
				scanf("%s", temp);
			} while (!(strcmp(temp, "male") == 0 || strcmp(temp, "female") == 0 || strcmp(temp, "boy") == 0 || strcmp(temp, "gile") == 0 || strcmp(temp, "man") == 0 || strcmp(temp, "woman") == 0));
			if (strcmp(temp, "male") == 0 || strcmp(temp, "man") == 0 || strcmp(temp, "boy") == 0)
			{
				strcpy(p->sex, "male");
			}
			else
			{
				strcpy(p->sex, "female");
			}
			printf("Input age >> ");
			scanf("%d", &p->age);
			printf("Input the %d scores >> ", SUBJECTNUM);
			for (i = 0; i < SUBJECTNUM; i++)
				scanf("%f", &p->score[i]);
			insertToEnd(p);
			fflush(stdin);
		}
		else if (ch == 'n' || ch == 'N')
		{
			break;
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
			printf("* Unknown command!\n");
			getchar();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 0x7);
		}
	}
	free(temp);
	free(p);
}
void FDname()
{
	char *name = (char *)malloc(20);
	struct node *p = (struct node *)malloc(sizeof(struct node));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf("Option [1]: Find By Name.\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 0x7);
	printf("Input name >> ");
	scanf("%s", name);
	p = head;
	while (p != NULL)
	{
		if (strcmp(name, p->name) == 0)
		{
			printf("* Name = %s\n", p->name);
			printf("* Num = %s\n", p->num);
			printf("* Sex = %s\n", p->sex);
			printf("* Age = %d\n", p->age);
			for (int i = 0; i < SUBJECTNUM; i++)
				printf("* Score[%d]=%f\n", i + 1, p->score[i]);
			return;
		}
		p = p->next;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	printf("* Person does NOT exist.\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 0x7);
	free(name);
	free(p);
}
void FDnum()
{
	char *snum = (char *)malloc(15);
	//memset(snum, 0, sizeof(snum));
	struct node *p = (struct node *)malloc(sizeof(struct node));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf("Option [2]: Find By Number.\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 0x7);
	printf("Input num >> ");
	getchar();
	scanf("%s", snum);
	p = head;
	while (p != NULL)
	{
		if (strcmp(snum, p->num) == 0)
		{
			printf("* Name = %s\n", p->name);
			printf("* Num = %s\n", p->num);
			printf("* Sex = %s\n", p->sex);
			printf("* Age = %d\n", p->age);
			for (int i = 0; i < SUBJECTNUM; i++)
				printf("* Score[%d]=%f\n", i + 1, p->score[i]);
			return;
		}
		p = p->next;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	printf("* Person does NOT exist.\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 0x7);
	free(snum);
	free(p);
}

void removeOnePerson()
{
	char *snum = (char *)malloc(15);
	//memset(snum, 0, sizeof(snum));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf("Option [3]: Delet one person.\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 0x7);
	printf("Input the number of the student >> ");
	getchar();
	scanf("%s", snum);
	struct node *p = (struct node *)malloc(sizeof(struct node));
	struct node *f = (struct node *)malloc(sizeof(struct node));
	p = head;
	f = head;

	while (p != NULL)
	{
		if (strcmp(snum, p->num) == 0)
		{
			if (p == head)
			{
				head = p->next;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
				printf("* Succeed!\n");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 0x7);
				return;
			}
			f->next = p->next;
			p->next = NULL;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
			printf("* Succeed!\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 0x7);
			return;
		}
		p = p->next;
		if (f != head)
		{
			f = f->next;
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	printf("* Person does NOT exist!\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 0x7);
	free(snum);
	free(p);
	free(f);
}

void find_data()
{
	while (1)
	{
		printf("----------------------------\n");
		printf("Option List : \n");
		printf("[1]\tFind by name\n");
		printf("[2]\tFind by num\n");
		printf("[3]\tDelet by number\n");
		printf("[ESC]\tExit\n");
		printf("----------------------------\n");
		printf("Input option >> ");
		while (true)
		{
			if (kbhit())
			{
				switch (getche())
				{
				case '1':
					printf("\n----------------------------\n");
					FDname();
					break;
				case '2':
					printf("\n----------------------------\n");
					FDnum();
					break;
				case '3':
					printf("\n----------------------------\n");
					removeOnePerson();
					break;
				case ESC:
					printf("\n");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
					printf("b");
					printf("* Bye bye!\n");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 0x7);
					return;
				default:
					printf("\n----------------------------\n");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
					printf("* Unknown option!\n");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 0x7);
				}
				break;
			}
		}
	}
}

int main()
{
	system("color 7");
	init_ht();
	input_data_from_console();
	system("cls");
	free(tail);
	find_data();
	system("pause");
	return 0;
}