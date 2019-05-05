#include "Header.h"

Fred::Fred()
	: m_a(0)
{
}

void Fred::wilma(int)
{
}

Fred *cpluscplus_function(Fred *fred)
{
	fred->wilma(123);
	return fred;
}
