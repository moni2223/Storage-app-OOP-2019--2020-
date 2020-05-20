#pragma once
#include <iostream>
using namespace std;

char add[] = "add";
char removee[] = "remove";
char printa[] = "print";
char cleana[] = "clean";
char loga[] = "log";
char exitt[] = "exit";
char closee[] = "close";
char save[] = "save";
char help[] = "help";
char open[] = "open";

void opena(const char* filename, ios_base::openmode mode = ios_base::out);

bool isAdd(char input[])
{
	int len = 0;
	int temp = 0;
	for (int i = 0; i < strlen(input); i++)
	{
		if (input[i] == ' ')
		{
			for (int j = 0; j < i; j++)
			{
				if (input[j] == add[j])
					len++;

				else break;
			}
		}
		if (len == strlen(add))
		{
			return 1;
			break;
		}
	}
	return 0;
}
bool isprint(char input[])
{
	int len = 0;
	int temp = 0;
	for (int i = 0; i < strlen(input); i++)
	{
		if (input[i] == printa[i])
			len++;

		else break;
	}
	if (len == strlen(printa))
	{
		return 1;
	}
	return 0;
}
bool isRemove(char input[])
{
	int len = 0;
	int temp = 0;
	for (int i = 0; i < strlen(input); i++)
	{
		if (input[i] == ' ')
		{
			for (int j = 0; j < i; j++)
			{
				if (input[j] == removee[j])
					len++;

				else break;
			}
		}
		if (len == strlen(removee))
		{
			return 1;
			break;
		}
	}
	return 0;
}
bool isclean(char input[])
{
	int len = 0;
	int temp = 0;
	for (int i = 0; i < strlen(input); i++)
	{
		if (input[i] == cleana[i])
			len++;

		else break;
	}
	if (len == strlen(cleana))
	{
		return 1;
	}
	return 0;
}
bool isLog (char input[])
{
	int len = 0;
	int temp = 0;
	for (int i = 0; i < strlen(input); i++)
	{
		if (input[i] == ' ')
		{
			for (int j = 0; j < i; j++)
			{
				if (input[j] == loga[j])
					len++;

				else break;
			}
		}
		if (len == strlen(loga))
		{
			return 1;
			break;
		}
	}
	return 0;
}
bool isexit(char input[])
{
	int len = 0;
	int temp = 0;
	for (int i = 0; i < strlen(input); i++)
	{
		if (input[i] == exitt[i])
			len++;

		else break;
	}
	if (len == strlen(exitt))
	{
		return 1;
	}
	return 0;
}
bool isclose(char input[]) 
{
	int len = 0;
	int temp = 0;
	for (int i = 0; i < strlen(input); i++)
	{
		if (input[i] == closee[i])
			len++;

		else break;
	}
	if (len == strlen(closee))
	{
		return 1;
	}
	return 0;
}
bool issave(char input[]) 
{
	int len = 0;
	int temp = 0;
	for (int i = 0; i < strlen(input); i++)
	{
		if (input[i] == save[i])
			len++;

		else break;
	}
	if (len == strlen(save))
	{
		return 1;
	}
	return 0;

}
bool ishelp(char input[]) 
{
	int len = 0;
	int temp = 0;
	for (int i = 0; i < strlen(input); i++)
	{
		if (input[i] == help[i])
			len++;

		else break;
	}
	if (len == strlen(help))
	{
		return 1;
	}
	return 0;

}
bool isopen(char input[]) 
{
	int len = 0;
	int temp = 0;
	for (int i = 0; i < strlen(input); i++)
	{
		if (input[i] == open[i])
			len++;

		else break;
	}
	if (len == strlen(open))
	{
		return 1;
	}
	return 0;
}