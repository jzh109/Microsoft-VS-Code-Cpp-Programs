#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000 + 10;

int n, v;
int dp[MAXN][MAXN];
int value[MAXN], weight[MAXN];  // ��Ʒ�ļ�ֵ������

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		memset(dp, 0, sizeof(dp));  // ��������ע���������
		cin >> n >> v;
		for (int i = 1; i <= n; i++)
		{
			cin >> value[i];
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> weight[i];
		}
        // ����ת�Ʒ���
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j <= v; j++)
			{
				if (j < weight[i])
					dp[i][j] = dp[i - 1][j];
				else
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
			}
		}
		cout << dp[n][v] << endl;
	}
	return 0;
}

