#pragma once
#include"Node.h"
class Gate
{
protected:
	Node * In1;
	Node *In2;
	Node *Out;
public:
	Gate();
	void set_In1(Node *in1);
	void set_In2(Node *in2);
	void set_Out(Node *out);
	Node* get_In1();
	Node* get_In2();
	Node* get_Out();
	virtual void calc_Out() = 0;
};


