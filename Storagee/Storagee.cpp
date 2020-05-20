#include "Product.h"
#include "Functions.h"
#include "userfunctions.h"
#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;
void readfromtxtfile()
{
	std::ifstream file("storagee.txt");
	char input[1024];
	ofstream consoleCopy;
	consoleCopy.open("example.txt");

	if (file.fail())
	{
		cout << "error with file" << endl;
		return;
	}
	cout << "storagee.txt file is opened." << endl;

	while (!file.eof())
	{
		char buff[1024];
		file.getline(buff, 1024);
		
		consoleCopy << buff;
		consoleCopy << '\n';

		cout << buff << endl;
		
		if (isexit(buff) == 1)
		{
			file.close();
		}
		
		else if (isclose(buff) == 1)
		{
			file.close();
		}
		
		else if (issave(buff) == 1) 
		{
			ofstream consoleCopy;
			consoleCopy.open("example.txt");
			//consoleCopy << buff;
			cout << "Ready" << endl;
		}

		else if (ishelp(buff) == 1) 
		{
			cout << "For adding:" << " add <Name> <expiredate> <importdate> <developer> <quantity> { auto:<place> <line> } <comment>" << endl;
			cout << "For removing:" << " remove <Name> <quantity> " << endl;
			cout << "For log info:" << " log <from> <to>" << endl;
			cout << "For cleaning: " << "clean" << endl;
			cout << "For outputting everything in the storage: " << "print" << endl;
			cout << "And you have usual commands: " << "exit " << "close " << "save " << "help " << "open" << endl;
		}

		else if (isopen(buff) == 1) 
		{
			char* temp;
			temp = strtok(buff, " ");
			temp = strtok(NULL, " ");
			file.close();
			
			std::ifstream file(temp);
			char input[1024];

			if (file.fail())
			{
				cout << "error with file" << endl;
				return;
			}

			cout << temp << " is opened." << endl;

			while (!file.eof())
			{
				char buff[1024];
				file.getline(buff, 1024);
				cout << buff << endl;
				inputfunctions(buff);
			}
		}

		inputfunctions(buff);
	}

	file.close();


}

int main()
{
	readfromtxtfile();
}
