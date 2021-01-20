#include <string.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;
const int MAX_LEN_WORD = 50;
const int MAX_LEN_CODE = 75;

map<char, string> rule;		  //letter-morse rule
vector<string> dic, res, txt; //authorized words, final result and massage of morse
char con[105][2][50] = {"0"}; //word and morse
int x = 0;

void loadin(FILE *fpin)
{
	char temp[MAX_LEN_WORD], let;
	string tempstr;

	//load in letter-morse rule and store them in a map<char,string>.
	for (int i = 0; i < 36; i++)
	{
		fscanf(fpin, "%c %s", &let, temp);
		rule.insert(pair<char, string>(let, temp));
		fgetc(fpin);
	}
	fgetc(fpin);

	//load in the words authorized by problem and store them in a vector<string>.
	while (fgetc(fpin))
	{
		fscanf(fpin, "%s", temp);
		if (temp[0] == '*')
			break;
		dic.push_back(temp);
	}

	//translate authorized words into morse codes and store them in map<string,string>con.
	for (vector<string>::iterator it = dic.begin(); it != dic.end(); it++, x++)
	{
		const char *word;
		char mc[MAX_LEN_CODE];
		memset(mc, 0, sizeof(mc));
		word = (*it).c_str();
		for (unsigned i = 0; i < strlen(word); i++)
		{
			map<char, string>::iterator mit = rule.find(word[i]);
			strcat(mc, (mit->second).c_str());
		}
		strcpy(con[x][0], word);
		strcpy(con[x][1], mc);
	}
	fgetc(fpin);

	//get the text of massage.
	do
	{
		fscanf(fpin, "%s", temp);
		if (temp[0] == '*')
			break;
		txt.push_back(temp);
	} while (fgetc(fpin));
}

void wrongCode(const char *a)
{
	unsigned max = 0;
	char temp[MAX_LEN_CODE], word[MAX_LEN_WORD];
	for (int i = 0; i < x; i++)
	{
		unsigned count = 0, j = 0;
		strcpy(temp, con[i][1]);
		while (temp[j] == a[j++])
			count++;
		if ((max < count) && (max = count))
		{
			strcpy(word, con[i][0]);
			strcat(word, "?");
		}
	}
	res.push_back(word);
}

//translate morse-code-message into English
void translate(string str)
{
	unsigned len = 10000, count = 0;
	const char *a = str.c_str();
	for (int i = 0; i < x; i++)
	{
		if (strcmp(a, con[i][1]) == 0)
		{
			len = len < strlen(con[i][0]) ? len : strlen(con[i][0]);
			count++;
		}
	}

	//if the input-code is not found
	if (count == 0)
	{
		wrongCode(a);
		return;
	}

	//if the input-code has been found
	for (int i = 0; i < x; i++)
	{
		if ((strcmp(a, con[i][1]) == 0) && (strlen(con[i][0]) == len))
		{
			if (count == 1)
			{ //only one word?
				res.push_back(con[i][0]);
				return;
			}
			else
			{ //more than one word corresponded
				char temp[MAX_LEN_WORD];
				strcpy(temp, con[i][0]);
				strcat(temp, "!");
				res.push_back(temp);
				return;
			}
		}
	}
}

int main()
{
	FILE *fpin = fopen("morsein.txt", "r");
	if (fpin == NULL)
		return 404;

	loadin(fpin);
	fclose(fpin);

	for (vector<string>::iterator tit = txt.begin(); tit != txt.end(); tit++)
		translate(*tit);

	FILE *fpout = fopen("morse.out", "w");
	for (vector<string>::iterator rit = res.begin(); rit != res.end(); rit++)
		fprintf(fpout, "%s\n", (*rit).c_str());
	fclose(fpout);

	return 0;
}