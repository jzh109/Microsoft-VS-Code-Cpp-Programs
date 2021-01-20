#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;
#define MAXSIZE 10

typedef struct Node
{
	Node *left;
	Node *right;
	int weight;

	// bool operator<(const BTTree other) const
	// {
	// 	return this->weight < other->weight;
	// } //problem
} BTNode, *BTTree;

BTTree trees[MAXSIZE];

bool cmp(BTTree a, BTTree b)
{
	return a->weight < b->weight;
}

BTTree create(const int data[], int n)
{ //"n" is the number of all nodes
	//while the "len" is the number of unsorted nodes
	int len = n;
	BTTree p;
	for (int i = 0; i < len; i++)
	{
		p = (BTTree)malloc(sizeof(BTNode));
		p->weight = data[i];
		p->left = nullptr;
		p->right = nullptr;
		trees[i] = p;
	}
	for (int i = 0; i < n - 1; i++)
	{
		sort(trees, trees + len, cmp);
		p = (BTTree)malloc(sizeof(BTNode));
		p->weight = trees[0]->weight + trees[1]->weight;
		p->left = trees[0];
		p->right = trees[1];
		trees[0] = p;
		for (int j = 1; j < len; j++)
		{ //change all unsorted position
			trees[j] = trees[j + 1];
		}
		len--;
	}
	return trees[0];
}

void makeSummation(int &sum, BTTree tree, int init = -1)
{
	int roadLength = init;
	if (tree != nullptr)
	{
		roadLength++;
		if (tree->left == nullptr && tree->right == nullptr)
			sum += roadLength * (tree->weight);
		makeSummation(sum, tree->left, roadLength);
		makeSummation(sum, tree->right, roadLength);
	}
}

void destroy(BTTree tree)
{
	BTTree p = tree;
	if (p->left != nullptr)
	{
		destroy(p->left);
	}
	if (p->right != nullptr)
	{
		destroy(p->right);
	}
	free(p);
}

int main(int argc, const char *argv[])
{
	int n, sum = 0;
	int data[MAXSIZE];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> data[i];
	}
	BTTree tree = create(data, n);
	makeSummation(sum, tree);
	cout << sum << endl;
	destroy(tree);
	return 0;
}