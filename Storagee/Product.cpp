#include "Product.h"
#include <iostream>
using namespace std;

Product::Product(const char* name, struct tm expiredate, struct tm importdate, const char* developer, const int quantity, const int place,const int line, const char* comment)
{
	
	set_name(name);
	set_expiredate(expiredate);
	set_importdate(importdate);
	set_developer(developer);
	set_quantity(quantity);
	set_place(place);
	set_line(line);
	set_comment(comment);

}
Product::Product() :Product("Unknown", { 0 }, { 0 }, "Unknown", 0, 0, 0, "Unknown") {};

//void Product::CopyFrom(const Product& other) 
//{
//	name = new char[strlen(other.name) + 1];
//	strcpy(name, other.name);
//
//	expiredate = other.expiredate;
//	importdate = other.importdate;
//
//	strcpy(developer, other.developer);
//	quantity = other.quantity;
//
//
//	comment = new char[strlen(other.comment) + 1];
//	strcpy(comment, other.comment);
//}
void Product::Free()// ne trqbva da delocatevame datite zashtoto sa statically allocated
{
	delete[] name;
	delete[] developer;
	quantity = place = 0;
	delete[] comment;
    
}
//Product& Product::operator=(const Product& other)
//{
//	if (this != &other)
//	{
//		Free();
//		CopyFrom(other);
//	}
//	return *this; // this   Product*
//}
Product::~Product()
{
	Free();
}
//Product::Product(const Product& other)
//{
//	CopyFrom(other);
//}

char* Product::get_name()
{
	return name;
}
struct tm Product::get_expiredate()
{
	return expiredate;
}
struct tm Product::get_importdate()
{
	return importdate;
}
char* Product::get_developer()
{
	return developer;
}
int Product::get_quantity()
{
	return quantity;
}
int Product::get_place()
{
	return place;
}
int Product::get_line()
{
	return line;
}
char* Product::get_comment()
{
	return comment;
}

void Product::set_name(const char* name)
{
	if (strlen(name) > 1) strcpy(this->name, name);
	else return;
}
void Product::set_expiredate(struct tm expiredate)
{
	this->expiredate = expiredate;
}
void Product::set_importdate(struct tm importdate)
{
	this->importdate = importdate;
}
void Product::set_developer(const char* developer)
{
	if (strlen(name) > 1) strcpy(this->developer, developer);
	else return;
}
void Product::set_quantity(int quantity)
{
	this->quantity = quantity;
}
void Product::set_place(const int place)
{
	this->place = place;
}
void Product::set_line(const int line)
{
	this->line = line;
}
void Product::set_comment(const char* comment)
{
	strcpy(this->comment, comment);
}
void Product::showfullInfo()
{
	cout << "Product name is: " << name << endl;
	cout << "Product expire date is: " << expiredate.tm_year << "." << expiredate.tm_mon << "." << expiredate.tm_mday << endl;
	cout << "Product import date is: " << importdate.tm_year << "." << importdate.tm_mon << "." << importdate.tm_mday << endl;
	cout << "Product developer is: " << developer << endl;
	cout << "Product quantity is: " << quantity << endl;
	cout << "Product place is: " << place << endl;
	cout << "Product comment is: " << comment << endl;
}