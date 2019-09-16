#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Node 
{
	string name;
	short value;
public:
	void set_name(string n);
	void set_value(short num);
	string get_name();
	short get_value();
	void print_node(ofstream & o);
	void print_node();
};


