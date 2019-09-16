#include "Nand_Gate.h"

void Nand_Gate::calc_Out()
{
	Out->set_value(!(In1->get_value()));
}

