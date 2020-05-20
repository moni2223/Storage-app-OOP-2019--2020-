#pragma once
#include <iostream>
#include "Log.h"
using namespace std;

Logg::Logg(const char* name, const char* function, struct tm importdate) 
{
	set_name(name);
	set_function(function);
	set_importdate(importdate);
}
Logg::Logg() :Logg("Unknown", "Unknown", { 0 }) {};
void Logg::Free()// ne trqbva da delocatevame datite zashtoto sa statically allocated
{
	delete[] name;
	delete[] function;
}
Logg::~Logg()
{
	Free();
}

char* Logg::get_function()
{
	return name;
}
char* Logg::get_name()
{
	return name;
}
struct tm Logg::get_importdate()
{
	return importdate;
}

void Logg::set_name(const char* name)
{
	if (strlen(name) > 1) strcpy(this->name, name);
	else return;
}
void Logg::set_importdate(struct tm importdate)
{
	this->importdate = importdate;
}
void Logg::set_function(const char* function)
{
	strcpy(this->function, function);
}

void Logg::showfullinfo() 
{
	cout << function << "ed" <<" " << name <<" "<< "on" << " " << importdate.tm_year << "." << importdate.tm_mon << "." << importdate.tm_mday << endl;
}