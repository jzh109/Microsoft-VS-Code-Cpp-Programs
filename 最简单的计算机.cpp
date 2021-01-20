#include <string.h>
#include <iostream>
using namespace std;
int main()
{
	int M1, M2, R1 = 0, R2 = 0, R3 = 0, len, i;
	char str[200], o;
	while (scanf("%d %d", &M1, &M2) != EOF)
	{
		scanf("%s", str);
		len = strlen(str);
		for (i = 0; i < len; i++)
		{
			o = str[i];
			switch (o)
			{
			case 'A':
				R1 = M1;
				break;
			case 'B':
				R2 = M2;
				break;
			case 'C':
				M1 = R3;
				break;
			case 'D':
				M2 = R3;
				break;
			case 'E':
				R3 = R1 + R2;
				break;
			case 'F':
				R3 = R1 - R2;
			}
		}
		printf("%d,%d\n", M1, M2);
	}
	return 0;
}
