#pragma once
#include "Product.h"
#include "userfunctions.h"
#include "Log.h"
#include <iostream>
using namespace std;


Product* products = new Product[1024];
Logg* logs = new Logg[1024];

int productid = 0;
int logid = 0;

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
	if (temp[6] == '.') 
	{
		
		int num2 = temp[7] - '0';
		int num3 = temp[8] - '0';
		int num4 = temp[9] - '0';
		int num5 = temp[10] - '0';
		year= num2 * 1000 + num3 * 100 + num4 * 10 + num5;
		return year;
	}
	int num1 = temp[6] - '0';
	int num2 = temp[7] - '0';
	int num3 = temp[8] - '0';
	int num4 = temp[9] - '0';
	year = num1 * 1000 + num2*100 + num3*10 + num4;
	return year;
}
bool compare2dates(struct tm firstexpdate, struct tm secondexpdate) 
{
	int firstexpyear = firstexpdate.tm_year;
	int firstexpmonth = firstexpdate.tm_mon;
	int firstexpday = firstexpdate.tm_mday;
	int secondexpyear = secondexpdate.tm_year;
	int secondexpmonth = secondexpdate.tm_mon;
	int secondexpday = secondexpdate.tm_mday;
	if (firstexpyear <= secondexpyear)
	{
		if (firstexpmonth <= secondexpmonth)
		{
			if (firstexpday <= secondexpday)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
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
			cout << "Added successfully" << endl;
		}
		
		logs[logid].set_name(products[productid].get_name());
		logs[logid].set_function("Add");
		logs[logid].set_importdate(products[productid].get_importdate());
		productid++;
		logid++;
		cout << endl;
	}
	if (isRemove(input) == 1)
	{
		char* temp;
		temp = strtok(input, " ");//remove
		int tempo = 0;
		int found = 0;
		int foundproducts[4];
		int index = 0;
		int foundproductid;
		int firstone=0;
		int secondone=0;
		while (temp != NULL)
		{
			tempo++;
			if (tempo == 2)
			{
				for (int i = 0; i <= productid; i++)
				{

					if (isequalarrays(temp, products[i].get_name()) == 1)
					{
						found = 1;
						foundproducts[index] = i;
						index++;
					}
				}
				if (found == 0)
				{
					cout << "There is no such product in the storage" << endl;
					return;
				}
				if (index > 1)
				{
					for (int j = 0; j < 2; j++)
					{
						struct tm firstexpdate = products[foundproducts[j]].get_expiredate();
						struct tm secondexpdate = products[foundproducts[j + 1]].get_expiredate();
						if (compare2dates(firstexpdate, secondexpdate) == 1)
						{
							firstone = j;
						}
						else firstone = j + 1;
					}
					for (int k = 2; k < 4; k++)
					{
						struct tm firstexpdatee = products[foundproducts[k]].get_expiredate();
						struct tm secondexpdatee = products[foundproducts[k + 1]].get_expiredate();
						if (compare2dates(firstexpdatee, secondexpdatee) == 1)
						{
							secondone = foundproducts[k];
						}
						else secondone = foundproducts[k + 1];
					}

					struct tm lastone = products[firstone].get_expiredate();
					struct tm otherlastone = products[secondone].get_expiredate();

					if (compare2dates(lastone, otherlastone) == 1)
						foundproductid = firstone;

					else foundproductid = secondone;
				}
				else if (index <= 1) 
				{
					foundproductid = foundproducts[0];
				}
			}
			if (tempo == 3)
			{
				if (found == 1)
				{
					int quantity = products[foundproductid].get_quantity();
					int inputquantity = atoi(temp);
					if (inputquantity > quantity)
					{
						cout << "There arent so much products" << endl;
						products[foundproductid].showfullInfo();
						cout << endl;
						return;
					}
					else
					{
						int finale = quantity - inputquantity;
						products[foundproductid].set_quantity(finale);
						products[foundproductid].showfullInfo();
						logs[logid].set_name(products[foundproductid].get_name());
						logs[logid].set_function("Remov");
						logs[logid].set_importdate(products[foundproductid].get_importdate());
						logid++;
						cout << endl;
						return;
					}
				}
			}
			temp = strtok(NULL, " ");
		}
	}
	if (isprint(input) == 1) 
	{
		char unknown[] = "Unknown";
		for (int i = 0; i < productid; i++)
		{
			if (isequalarrays(products[i].get_name(), unknown) == 1);
			else products[i].showfullInfo();
			cout << endl;
		}
		return;
	}
	if (isclean(input) == 1)
	{
		time_t now = time(0);
		struct tm* noww = localtime(&now);
		struct tm todayy;
		int nowyear = noww->tm_year+1900;//+1900 zashtoto pokazva kolko godini sa minali ot 1900
		int nowmonth = noww->tm_mon + 1;
		int nowdays = noww->tm_mday;
		for (int i = 0; i < productid; i++)
		{
			todayy = products[i].get_expiredate();
			if (nowyear < todayy.tm_year);
			else if (nowyear == todayy.tm_year) 
			{
				if (nowmonth > todayy.tm_mon)
				{
					cout << products[i].get_name() << " Deleted due to expired date" << endl;
					logs[logid].set_name(products[i].get_name());
					products[i].set_name("Unknown");
					logs[logid].set_function("Clean");
					logs[logid].set_importdate(products[i].get_importdate());
					logid++;
				}
				else if (nowmonth == todayy.tm_mon)
				{
					if (todayy.tm_mon - 15 >= nowdays);
					else
					{
						cout << products[i].get_name() << " Deleted due to soon expiration" << endl;
						logs[logid].set_name(products[i].get_name());
						products[i].set_name("Unknown");
						logs[logid].set_function("Clean");
						logs[logid].set_importdate(products[i].get_importdate());
						logid++;
					}
				}
				else;
			}
			else if (nowyear > todayy.tm_year) 
			{
				cout << products[i].get_name() << " Deleted due to expired date" << endl;
				logs[logid].set_name(products[i].get_name());
				products[i].set_name("Unknown");
				logs[logid].set_function("Clean");
				logs[logid].set_importdate(products[i].get_importdate());
				logid++;
			}
		}
		cout << endl;

		return;

	}
	if (isLog(input) == 1) 
	{
		char* temp;
		char firstdate[11];
		char seconddate[11];
		temp = strtok(input, " ");//add
		int tempo = 0;
		while (temp != NULL) 
		{
			tempo++;
			if (tempo == 2) 
				strcpy(firstdate, temp);
			
			if (tempo == 3)
				strcpy(seconddate, temp);
			
			temp = strtok(NULL, " ");
		}
		
		int fromdate[4];
		fromdate[0] = takingday(firstdate);
		fromdate[1] = takingmonth(firstdate);
		fromdate[2] = takingyear(firstdate);
		int todate[4];
		todate[0] = takingday(seconddate);
		todate[1] = takingmonth(seconddate);
		todate[2] = takingyear(seconddate);
		if (fromdate[2] == todate[2]) 
		{
			if (fromdate[1] == todate[1]) 
			{
				for (int i = 0; i < logid; i++)
				{
					struct tm importdatee = logs[i].get_importdate();
					if (fromdate[2] == importdatee.tm_year)
					{
						if (fromdate[1] == importdatee.tm_mon)
						{
							if (fromdate[0] <= importdatee.tm_mday && importdatee.tm_mday <= todate[0])
							{
								logs[i].showfullinfo();
							}
							else continue;
						}
						else continue;
					}
					else continue;
				}
			}
		}
		else
		{
			cout << "You can check only for one month at moment" << endl;
			cout << endl;
			return;
		}
	}
	
}



/*
pattern: add <Name> <expiredate> <importdate> <developer> <quantity> { auto:<place> <line> } <comment>

add Vafla 21.09.2020 17.08.2020 Moreni 1 mnogo qka taq vafla
add Vafla 21.09.2020 18.08.2020 Moreni 1 daje po qka ot minalata tupa vafla

*/