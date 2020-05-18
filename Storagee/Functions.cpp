#include "Product.h"
#include <iostream>
using namespace std;


char add[] = "add";
Product* products = new Product[1024];
int productid = 0;

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

void inputfunctions(char input[]) 
{
	if (isAdd(input) == 1) 
	{
		char* temp;
		temp = strtok(input, " ");//registration
		int tempo = 0;
		while (temp != NULL)
		{
			tempo++;
			cout << temp << tempo << endl;
			temp = strtok(NULL, " ");
		}
	}
}