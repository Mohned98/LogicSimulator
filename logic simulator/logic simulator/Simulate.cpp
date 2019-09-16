#include "Simulate.h"

Simulate::Simulate()
{

}

short Simulate::get_gates_size()
{
	return gates.size();
}

short Simulate::get_nodes_size()
{
	return nodes.size();
}

Node* Simulate::find_node(string s)
{
	for (unsigned int i = 0; i<nodes.size(); i++)
	{
		if (nodes[i]->get_name() == s)
		{
			return nodes[i];
		}
	}
	return NULL;
}

Node* Simulate::add_node(string s)
{
	Node *n_node = new Node();
	nodes.push_back(n_node);
	n_node->set_name(s);
	return n_node;
}

Node* Simulate::find_or_add_node(string s)
{
	Node *ptr = find_node(s);
	if (ptr != NULL)
	{
		return ptr;
	}
	else
	{
		return add_node(s);
	}
}

Gate* Simulate::add_gate(string name)
{
	if (name == "AND")
	{
		Gate *p = new And_Gate();
		gates.push_back(p);
	}
	else if (name == "OR")
	{
		gates.push_back(new Or_Gate());
	}
	else if (name == "NAND")
	{
		gates.push_back(new Nand_Gate());
	}
	return gates[gates.size() - 1];
}

void Simulate::print_all_nodes(ofstream& o)
{
	for (unsigned int i = 0; i<nodes.size(); i++)
	{
		nodes[i]->print_node(o);
	}
}

void Simulate::print_all_nodes()
{
	for (unsigned int i = 0; i<nodes.size(); i++)
	{
		nodes[i]->print_node();
	}
}

void Simulate::sim()
{
	for (unsigned int j = 0; j<gates.size(); j++)
	{
		for (unsigned int i = 0; i<gates.size(); i++)
		{
			gates[i]->calc_Out();
		}
	}
}

void Simulate::load(string s1, string s2)
{
	ifstream f1;
	ofstream f2;
	f1.open(s1);
	f2.open(s2);
	string inp;
	while (!f1.eof())
	{
		f1 >> inp;
		if (inp == "SET")
		{
			string n;
			short v;
			f1 >> n >> v;
			find_node(n)->set_value(v);
		}
		else if (inp == "SEM")
		{
			sim();
		}
		else if (inp == "OUT")
		{
			string n;
			f1 >> n;
			if (n == "*")
			{
				print_all_nodes(f2);
			}
			else
			{
				find_node(n)->print_node(f2);
			}
		}
		else
		{
			Gate *ngate = add_gate(inp);
			string i1, i2, o1;
			f1 >> i1 >> i2 >> o1;
			ngate->set_In1(find_or_add_node(i1));
			ngate->set_In2(find_or_add_node(i2));
			ngate->set_Out(find_or_add_node(o1));
		}
	}
	f1.close();
	f2.close();
}

void Simulate::load(string s1)
{
	ifstream f1;
	f1.open(s1);
	string inp;
	while (!f1.eof())
	{
		f1 >> inp;
		if (inp == "SET")
		{
			string n;
			short v;
			f1 >> n >> v;
			find_node(n)->set_value(v);
		}
		else if (inp == "SEM")
		{
			sim();
		}
		else if (inp == "OUT")
		{
			string n;
			f1 >> n;
			if (n == "*")
			{
				print_all_nodes();
			}
			else
			{
				find_node(n)->print_node();
			}
		}
		else
		{
			Gate *ngate = add_gate(inp);
			string i1, i2, o1;
			f1 >> i1 >> i2 >> o1;
			ngate->set_In1(find_or_add_node(i1));
			ngate->set_In2(find_or_add_node(i2));
			ngate->set_Out(find_or_add_node(o1));
		}
	}
	f1.close();
}

Simulate::~Simulate()
{
	for (unsigned int i = 0; i<gates.size(); i++)
	{
		delete gates[i];
	}
	for (unsigned int i = 0; i<nodes.size(); i++)
	{
		delete nodes[i];
	}
}


