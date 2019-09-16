#include "Node.h"

void Node::set_name(string n)
{
	name = n;
}

void Node::set_value(short num)
{
	value = num;
}

string Node::get_name()
{
	return name;
}

short Node::get_value()
{
	return value;
}

void Node::print_node(ofstream& o)
{
	o << name << "\t" << value << endl;
}

void Node::print_node()
{
	cout << name << "   " << value << endl;
}
