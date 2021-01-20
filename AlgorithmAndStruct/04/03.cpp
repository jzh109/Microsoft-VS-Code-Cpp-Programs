#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
#define MAXSIZE 50

typedef struct node
{
	char ch;
	int n;
	struct node *left, *right;
} BTNode, *BTTree;

struct code
{
	char ch;
	char a[10];
} code[MAXSIZE];

BTTree create(int n)
{
	BTTree p, tree, relative;
	int i, j;
	p = (BTTree)malloc(sizeof(BTNode));
	p->left = nullptr;
	p->right = nullptr;
	p->n = 0;
	tree = p;
	for (i = 0; i < n; i++)
	{
		for (j = 0; code[i].a[j] != '\0'; j++)
		{
			if (code[i].a[j] == '0')
			{
				if (p->left == nullptr)
				{
					relative = p;
					p = (BTTree)malloc(sizeof(BTNode));
					p->left = nullptr;
					p->right = nullptr;
					p->n = 0;
					relative->left = p;
				}
				else
					p = p->left;
			}
			else if (code[i].a[j] == '1')
			{
				if (p->right == nullptr)
				{
					relative = p;
					p = (BTTree)malloc(sizeof(BTNode));
					p->left = nullptr;
					p->right = nullptr;
					p->n = 0;
					relative->right = p;
				}
				else
					p = p->right;
			}
		}
		p->ch = code[i].ch;
		p = tree;
	}
	return tree;
}

void print(BTTree tree)
{
	if (tree != nullptr)
	{
		print(tree->left);
		print(tree->right);
		cout << tree->n << " ";
	}
}

void process(BTTree tree, char data[])
{
	int len;
	BTTree p;
	p = tree;
	p->n++;
	len = strlen(data);
	for (int i = 0; i < len; i++)
	{
		if (data[i] == '0')
		{
			if (p->left == nullptr)
			{ // reach element
				cout << p->ch;
				i--;
				p = tree;
				p->n++;
			}
			else
			{
				p = p->left;
				p->n++;
			}
		}
		else if (data[i] == '1')
		{
			if (p->right == nullptr)
			{ // reach element
				cout << p->ch;
				i--;
				p = tree;
				p->n++;
			}
			else
			{
				p = p->right;
				p->n++;
			}
		}
	}
	cout << p->ch;
}

void distroy(BTTree tree)
{
	BTTree p = tree;
	if (p->left != nullptr)
	{
		distroy(p->left);
	}
	if (p->right != nullptr)
	{
		distroy(p->right);
	}
	free(p);
}

int main(int argc, const char *argv[])
{
	int i = 0, n;
	char data[100];
	// FILE *file;
	// if ((file = fopen("in.txt", "r")) == NULL)
	// {
	// 	exit(0);
	// }
	// fgets(data, 100, file);
	// fclose(file);

	cin >> data;
	getchar();
	cin >> n;
	getchar();
	for (i = 0; i < n; i++)
	{
		code[i].ch = getchar();
		getchar(); //:
		cin.getline(code[i].a, 50);
	}
	BTTree tree = create(n);
	process(tree, data);
	cout << endl;
	print(tree);
	distroy(tree);
	return 0;
}