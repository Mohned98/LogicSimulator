#include "Gate.h"

Gate::Gate()
{
	In1 = NULL;
	In2 = NULL;
	Out = NULL;
}

void Gate::set_In1(Node* in1)
{
	In1 = in1;
}

void Gate::set_In2(Node* in2)
{
	In2 = in2;
}

void Gate::set_Out(Node* out)
{
	Out = out;
}

Node* Gate::get_In1()
{
	return In1;
}

Node* Gate::get_In2()
{
	return In2;
}

Node* Gate::get_Out()
{
	return Out;
}

