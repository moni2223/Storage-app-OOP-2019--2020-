#pragma once
#include <time.h> //for expiredate and importdate
const int MAX = 1024;

class Product
{
	char* name = new char[MAX];
	struct tm expiredate;
	struct tm importdate;
	char developer[100];
	int quantity;
	int place;
	int line;
	char* comment = new char[MAX];
	void CopyFrom(const Product& other);
	void Free();

public:
	Product(const char* name, struct tm expiredate, struct tm importdate, const char* developer, const int quantity, const int place,const int line, const char* comment);
	Product();
	//Product(const Product& other);
	//Product& operator=(const Product& other);
	~Product();

	char* get_name();
	struct tm get_expiredate();
	struct tm get_importdate();
	char* get_developer();
	int get_quantity();
	int get_place();
	int get_line();
	char* get_comment();

	void set_name(const char* name);
	void set_expiredate(struct tm expiredate);
	void set_importdate(struct tm importdate);
	void set_developer(const char* developer);
	void set_quantity(int quantity);
	void set_place(const int place);
	void set_line(const int line);
	void set_comment(const char* comment);

	void showfullInfo();
}; 
