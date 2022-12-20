#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main() {
	setlocale(0, " ");
	char S[1000];
	char let[] = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm";
	char symbols[] = { ',','.',':','"', ' ', '?', '!', '-', '(', ')', ';', '\0' };
	int temp;
	char tempChar[20];
	int count = 0;
	cin.getline(S, 1000, '.');
	//Задание 2

	for (int i = 0; i < strlen(S); i++)
	{
		for (int j = 0; j < (strlen(let) - 26); j++)
		{
			if (i != 0 && S[i] == let[j])
			{
				S[i] = let[j + 26];
			}
		}
	}
	for (int i = 0; i < strlen(S) - 1; i++)
	{
		for (int j = 0; j < strlen(symbols); j++)
		{
			if (S[i] == symbols[j] && S[i + 1] == symbols[j])
			{
				temp = i;
				while (S[i] != 0) {
					S[i] = S[i + 1];
					i++;
				}
				i = temp - 1;
			}
		}
	}
	//Задание 3

	for (int i = 0, j = 0; i < strlen(S); i++, j++)
	{
		tempChar[j] = S[i];
		if (S[i] == ' ' || i == strlen(S) - 1)
		{
			int f = 1;
			tempChar[j] = '\0';
			j = -1;
			for (int k = 0; k < strlen(tempChar); k++)
			{
				if (tempChar[k] == '1' || tempChar[k] == '2' || tempChar[k] == '3' || tempChar[k] == '4' || tempChar[k] == '5' ||
					tempChar[k] == '6' || tempChar[k] == '7' || tempChar[k] == '8' || tempChar[k] == '9' || tempChar[k] == '0')
				{
					f = 0;
				}
			}
			if (f)
			{
				cout << tempChar << " ";
			}
		}
	}
	//Задание 4



}