#include <vector>
#include <time.h>
#include <conio.h>
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

int i, j;

void head(char mas[])
{
	int len, third, s1_len, s2_len, s3_len, maks;
	len = strlen(mas);
	third = len / 3;
	s1_len = third;
	for (int i = s1_len; i < len; i++)
	{
		if (mas[s1_len] != ' ') s1_len++;
		else break;
	}
	s2_len = third;
	for (int i = s1_len + s2_len; i < len; i++)
	{
		if (mas[s1_len + s2_len] != ' ') s2_len++;
		else break;
	}
	s3_len = len - (s1_len + s2_len);
	vector<char>str1(s1_len);
	vector<char>str2(s2_len);
	vector<char>str3(s3_len);
	for (int i = 0; i < s1_len; i++)
	{
		str1[i] = mas[i];
	}
	for (int i = s1_len + 1; i < s1_len + s2_len; i++)
	{
		str2[i - (s1_len + 1)] = mas[i];
	}
	for (int i = s1_len + s2_len + 1; i < len; i++)
	{
		str3[i - (s1_len + s2_len + 1)] = mas[i];
	}
	maks = s1_len;
	if (s2_len > maks)maks = s2_len;
	if (s3_len > maks)maks = s3_len;
	system("cls");
	SetConsoleTextAttribute(hConsole, 11);
	setlocale(LC_ALL, ".866");
	cout << " Ъ";
	for (int i = 0; i <= maks + 1; i++)cout << "Д";
	cout << "ї\n";
	cout << " і "; setlocale(LC_ALL, ".1251");
	for (int i = 0; i<s1_len; i++) cout << str1[i];
	if (s1_len < maks)
	{
		for (int i = 0; i < maks - s1_len; i++)cout << " ";
	}
	setlocale(LC_ALL, ".866"); cout << " і\n";
	cout << " і "; setlocale(LC_ALL, ".1251");
	for (int i = 0; i<s2_len; i++) cout << str2[i];
	if (s2_len < maks)
	{
		for (int i = 0; i < maks - s2_len; i++)cout << " ";
	}
	setlocale(LC_ALL, ".866"); cout << " і\n";
	cout << " і "; setlocale(LC_ALL, ".1251");
	for (int i = 0; i<s3_len; i++) cout << str3[i];
	if (s3_len < maks)
	{
		for (int i = 0; i < maks - s3_len; i++)cout << " ";
	}
	setlocale(LC_ALL, ".866"); cout << " і\n";
	cout << " А";
	for (int i = 0; i <= maks + 1; i++)cout << "Д";
	cout << "Щ\n";
	SetConsoleTextAttribute(hConsole, 15);
	setlocale(LC_ALL, ".1251");
}

void yellow()
{
	SetConsoleTextAttribute(hConsole, 14);
}

void white()
{
	SetConsoleTextAttribute(hConsole, 15);
}

void red()
{
	SetConsoleTextAttribute(hConsole, 12);
}

void green()
{
	SetConsoleTextAttribute(hConsole, 11);
}

int kolS(char *m, int r, char ch)
{
	int c = 0;
	for (int i = 0; i < r; i++)
	{
		if (m[i] == ch)c++;
	}
	return c;
}

void sCount(char *m, int r)
{
	char ch = 'а';
	int c;
	for (int i = 0; i < 16; i++)
	{		
		c = kolS(m, r, ch);
		if(c!=0)		
		printf("Символов '%c' в строке - %d\n", ch, c);
		ch = ch + 1;
	}
	ch = 'р';
	for (int i = 0; i < 16; i++)
	{		
		c = kolS(m, r, ch);
		if (c != 0)
		printf("Символов '%c' в строке - %d\n", ch, c);
		ch = ch + 1;
	}
	ch = ' ';
	c = kolS(m, r, ch);
	printf("Пробелов в строке - %d\n", c);
}

void obr(char *m, int r)
{
	char str[255];
	int n = r;
	int rs=n, ch=0;
	while (n!=0)
	{
		while (m[rs]!=' ')
		{
			if(rs!=0) rs--;
			else break;
		}
		for (int i = rs+1; i < n; i++)
		{
			str[ch] = m[i];
			ch++;			
		}
		str[ch] = ' ';
		ch++;
		n = rs;
		if(rs!=0) rs--;
		else break;
	}
	str[ch] = '\0';
	red();
	cout << str << endl;
	white();	
}

int cSlov(char *m, int r)
{
	int n = r, rs = n, c=0;
	bool a = 1;
	while (n != 0)
	{
		a = 1;
		while (m[rs] != ' ')
		{
			if (rs != 0) rs--;
			else break;
		}
		for (int i = rs; i < n; i++)
		{
			if (m[i] < -32)a = 0;			
		}
		if (a == 1)c++;
		n = rs;
		if (rs != 0) rs--;
		else break;
	}
	return c;
}

void mSlov(char *m, int r)
{
	char matr[20][20] = {'*'};
	int kol = 0,row=0,n=0;
	while (n+kol<r)
	{
		kol = 1;
		while (m[n+kol] != ' ')
		{
			kol++;
			if (m[n + kol] == '\0') break;
		}
		for (int i = 0; i < kol; i++)
		{
			matr[row][i] = m[n + i];
			if(row>0)
				matr[row][i] = m[n + i+1];
			matr[row][kol] = '\0';
		}
		n = n+kol;		
		row++;
	}
	red();
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if(matr[i][j]!='\0'&&matr[i][j] != '*')
			cout << matr[i][j];
			else break;
		}
		cout << endl;
	}
	white();
}

void kSim(char *m, int r)
{
	char mas[66] = {'*'};
	int kol = 0,b=0;
	for (int i = 0; i < r; i++)
	{
		b = 0;
		for (int j = 0; j <= kol; j++)
		{
			if (m[i] != mas[j])
			{				
				b = 1;
			}
			else
			{
				b = 0;
				break;
			}
		}
		if (b == 1)
		{
			mas[kol] = m[i];
			kol++;
		}
	}
	mas[kol] = '\0';
	red();
	printf("Количество символов в строке - %d\n", kol);
	cout << "Символы: ";
	for (int i = 0; i < kol; i++)
	{
		cout << mas[i] << "\t";
	}
	cout << endl;
	white();
}

int kA(char *m, int r)
{
	int k = 0,c=0;
	for (int i = 0; i < r; i++)
	{
		if (m[i] == 'а')k++;
		else
		{
			if(c<k)	c = k;
			k = 0;
		}
	}
	return c;
}