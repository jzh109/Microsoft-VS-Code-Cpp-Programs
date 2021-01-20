#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

typedef struct node
{
	int data;
	int depth;
	node *leftChild, *rightChild;
} BTNode, *BTTree;

int maxDepth;

BTTree create()
{
	BTTree floor[100], p = nullptr, BTroot = nullptr;
	char ch, str[100] = {0}, num[10] = {0};
	int pairs = -1, i = 0, j, len, sum = 0;
	bool left = false;

	cin.getline(str, 100);
	len = strlen(str);
	while (true)
	{
		memset(num, '\0', 10);
		ch = str[i];
		if (str[i] >= '0' && str[i] <= '9')
		{
			j = 0;
			while (str[i] >= '0' && str[i] <= '9')
			{
				num[j] = str[i];
				i++;
				j++;
			}
			sscanf(num, "%d", &sum);
		} //get element
		else
		{
			i++;
		}
		if (i >= len)
		{
			return BTroot;
		}
		else
		{
			switch (ch)
			{
			case '(':
				floor[++pairs] = p;
				left = true;
				break;
			case ',':
				left = false;
				break;
			case ')':
				pairs--;
				break;
			default:
				p = (BTTree)malloc(sizeof(BTNode));
				p->data = sum;
				p->leftChild = nullptr;
				p->rightChild = nullptr;
				p->depth = 0;
				if (BTroot == nullptr)
				{
					BTroot = p;
					BTroot->depth = 1;
					maxDepth = 1;
				}
				else
				{
					if (left)
					{
						floor[pairs]->leftChild = p;
						p->depth = pairs + 2;
					}
					else
					{
						floor[pairs]->rightChild = p;
						p->depth = pairs + 2;
					}
					if (p->depth > maxDepth)
					{
						maxDepth = p->depth;
					}
				}
			}
		}
	}
}

void distroy(BTTree tree)
{
	BTTree p = tree;
	if (p->leftChild != nullptr)
	{
		distroy(p->leftChild);
	}
	if (p->rightChild != nullptr)
	{
		distroy(p->rightChild);
	}
	free(p);
}

void print(BTTree tree, int depth)
{
	BTTree p = tree;
	if (p->depth == depth)
	{
		cout << p->data << " ";
	}
	if (p->leftChild != nullptr)
	{
		print(p->leftChild, depth);
	}
	if (p->rightChild != nullptr)
	{
		print(p->rightChild, depth);
	}
}

int main(int argc, const char *argv[])
{
	BTTree tree = create();
	for (int i = maxDepth; i > 0; i--)
	{
		print(tree, i);
		cout << endl;
	}
	distroy(tree);
}