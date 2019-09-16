#include "And_Gate.h"

void And_Gate::calc_Out()
{
	Out->set_value((In1->get_value()) || (In2->get_value()));
}

