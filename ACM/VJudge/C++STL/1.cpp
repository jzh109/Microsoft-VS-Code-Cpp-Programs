#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

struct Person
{
	string name;
	int num;
	set<int> scores;
	int sum;
};

bool operator<(Person &a, Person &b)
{
	if (a.sum != b.sum)
		return a.sum > b.sum;
	return a.name.compare(b.name);
}

int main()
{
	int N, M, G;
	while (cin >> N >> M >> G)
	{
		int n = 0;
		vector<int> val;
		for (int i = 0; i < M; i++)
		{
			int a;
			cin >> a;
			val.push_back(a);
		}
		set<Person> students;
		Person temp;
		for (int i = 0; i < N; i++)
		{
			cin >> temp.name >> temp.num;
			temp.sum = 0;
			for (int j = 0; j < temp.num; j++)
			{
				int s;
				cin >> s;
				temp.scores.insert(val[s - 1]);
				temp.sum += val[s - 1];
			}
			students.insert(temp);
			if (temp.sum >= G)
				n++;
		}
		sort(students.begin(), students.end());
		cout << n << endl;
		int cnt = 0;
		set<Person>::iterator it;
		for (it = students.begin(); cnt < n && it != students.end(); it++, cnt++)
		{
			cout << it->name << " " << it->sum << endl;
		}
	}
	return 0;
}