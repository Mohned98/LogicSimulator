#pragma once
#include<vector>
#include"And_Gate.h"
#include"Or_Gate.h"
#include"Nand_Gate.h"
class Simulate
{
	vector<Gate*>gates;
	vector<Node*>nodes;
public:
	Simulate();
	short get_gates_size();
	short get_nodes_size();
	Node* find_node(string s);
	Node* add_node(string s);
	Node* find_or_add_node(string s);
	Gate* add_gate(string name);
	void print_all_nodes(ofstream & o);
	void print_all_nodes();
	void sim();
	void load(string s1, string s2);
	void load(string s1);
	~Simulate();
};

