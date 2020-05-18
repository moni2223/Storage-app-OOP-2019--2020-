#include "Product.h"
#include "Functions.h"
#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;
void readfromtxtfile()
{
	std::ifstream file("storagee.txt");
	char input[1024];

	if (file.fail())
	{
		cout << "error with file" << endl;
		return;
	}

	while (!file.eof())
	{
		char buff[1024];
		file.getline(buff, 1024);
		cout << buff << endl;
		inputfunctions(buff);
	}

	file.close();


}

int main()
{
	readfromtxtfile();
}
