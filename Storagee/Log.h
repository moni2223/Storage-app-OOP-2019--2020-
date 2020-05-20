#pragma once
#include <time.h> //for importdate

class Logg
{

	char name[100];
	char function[10];
	struct tm importdate;
	void Free();

public:
	Logg(const char* name, const char* function, struct tm importdate);
	Logg();
	~Logg();

	char* get_name();
	char* get_function();
	struct tm get_importdate();

	void set_name(const char* name);
	void set_function(const char* function);
	void set_importdate(struct tm importdate);
	void showfullinfo();

};