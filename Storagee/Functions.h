#pragma once
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
bool isequalarrays(char* temp, char* temp1)
{
	int len = strlen(temp);
	int len1 = strlen(temp1);
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		if (temp[i] == temp1[i])count++;
		else break;
	}
	if (count == len)return 1;
	else return 0;
}
int takingday(char* temp) 
{
	int day = 0;
	int num1;
	int num2;
	char* dayaschar=new char[4];
	for (int i = 0; i < strlen(temp); i++)
	{
		if (temp[i] == '.') 
		{
			for (int j = 0; j < i; j++)
			{
				dayaschar[j] = temp[j];
			}
		}
	}
	day = atoi(dayaschar);
	return day;
}
int takingmonth(char* temp)
{
	int month = 0;
	int num1;
	int num2;
	for (int i = 3; i < strlen(temp); i++)
	{
		if (temp[i] == '.')
		{
			num1 = temp[i - 2] - '0';
			num2 = temp[i - 1] - '0';
			month = num1 * 10 + num2;
		}
	}
	return month;

}
int takingyear(char* temp)
{
	int year = 0;
	int num1 = temp[6] - '0';
	int num2 = temp[7] - '0';
	int num3 = temp[8] - '0';
	int num4 = temp[9] - '0';
	year = num1 * 1000 + num2*100 + num3*10 + num4;
	return year;
}

void inputfunctions(char input[])
{
	if (isAdd(input) == 1)
	{
		char* temp;
		temp = strtok(input, " ");//add
		int tempo = 0;
		int isSame = 0;
		int sameprodid;
		char samename[20];
		while (temp != NULL)
		{
			tempo++;
			if (tempo == 2) //naame
			{
				for (int i = 0; i < productid; i++)
				{
					if (isequalarrays(products[i].get_name(), temp) == 1) 
					{
						isSame = 1;
						strcpy(samename, temp);
						sameprodid = i;
						break;
					}
				}
				if (isSame == 0) 
				{
					products[productid].set_name(temp);
					char unknown[] = "Unknown";
					if (isequalarrays(products[productid].get_name(), unknown) == 1) //ifvalidname
					{
						cout << "Invalid name" << endl;
						return;
					}
				}
			}
			if (tempo == 3)//expiredate
			{
				int day = takingday(temp);
				int month = takingmonth(temp);
				int year = takingyear(temp);
				if (isSame == 1)
				{
					struct tm olddate = products[sameprodid].get_expiredate();
					int oldyear = olddate.tm_year;
					int oldmonth = olddate.tm_mon;
					int oldday = olddate.tm_mday;
					if (day == oldday && month == oldmonth && year == oldyear);
					
					else 
					{
						products[productid].set_name(samename);
						isSame = 0;
					} 
				}
				if (isSame == 0) 
				{
					struct tm expiredate;//calling date variable from <time.h>
					expiredate.tm_year = year;//setting year
					expiredate.tm_mon = month;//setting month
					expiredate.tm_mday = day;//setting day
					products[productid].set_expiredate(expiredate);
				}
			}
			if (tempo == 4)//importdate 
			{
				if (isSame == 1);
				int day = takingday(temp);
				int month = takingmonth(temp);
				int year = takingyear(temp);
				struct tm importdate;//calling date variable from <time.h>
				importdate.tm_year = year;//setting year
				importdate.tm_mon = month;//setting month
				importdate.tm_mday = day;//setting day
				products[productid].set_importdate(importdate);
			}
			if (tempo == 5) //developer
			{
				if (isSame == 1);
				products[productid].set_developer(temp);
				char unknown[] = "Unknown";
				if (isequalarrays(products[productid].get_developer(), unknown) == 1) //ifvaliddev
				{
					cout << "Invalid developer" << endl;
					return;
				}
				

			}
			if (tempo == 6)//quantity
			{
				if (isSame == 1) 
				{
					int oldcount = products[sameprodid].get_quantity();
					int quantity = atoi(temp) + oldcount;
					products[sameprodid].set_quantity(quantity);
					products[sameprodid].showfullInfo();
					return;
				}
				else
				{
					int quantity = atoi(temp);
					products[productid].set_quantity(quantity);
				}
			}
			if (tempo == 7)//comment
			{
					products[productid].set_comment(temp);

			}
			if (tempo > 7) 
			{
				char* oldcomment = products[productid].get_comment();
				char* newcomment = strcat(oldcomment, " ");
				char* verynew = strcat(newcomment, temp);
				products[productid].set_comment(verynew);
				
			}

			temp = strtok(NULL, " ");
		}
		if (isSame == 0) 
		{
			products[productid].set_place(productid);
			products[productid].showfullInfo();
		} 
		
		productid++;
	}
}





/*
pattern: add <Name> <expiredate> <importdate> <developer> <quantity> { auto:<place> <line> } <comment>

add Vafla 21.09.2020 17.08.2020 Moreni 1 mnogo qka taq vafla
add Vafla 21.09.2020 18.08.2020 Moreni 1 daje po qka ot minalata tupa vafla

*/