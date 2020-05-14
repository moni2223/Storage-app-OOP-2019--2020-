#include "Product.cpp"
#include <iostream>
#include <fstream>
using namespace std;
int main() 
{
	Product* products = new Product[100];
	products[0].showfullInfo();
}