#include<iostream>
#include<vector>
#include<set>
using namespace std;
set<int> Node;
int main(void)
{
	int a, b;
	while (true)
	{
		cin >> a >> b;
		if (a == -1 && b == -1) break;
		Node.clear();
		int cnt = 0;
		while (true)
		{
			if (a == 0 && b == 0) break;
			cnt++;
			Node.insert(a); Node.insert(b);
			cin >> a >> b;
		}
		if (Node.size() == 0 && cnt == 0)
		{
			cout << "Yes" << endl;
		}
		else if (Node.size() == 1 && cnt == 1)
		{
			cout << "No" << endl;
		}
		else if (Node.size() == cnt + 1)
			cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}
