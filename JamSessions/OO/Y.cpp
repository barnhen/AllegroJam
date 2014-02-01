#include "Y.hpp"


Y::Y(void)
{
}


Y::~Y(void)
{
}




int main ()
{
	test::X x;
	std::cout<<"Variable default value is "<<x.getVariable()<<std::endl;
	x.setVariable(2);
	x.setMap();
	//X.setVariable(2);
	std::cout<<"Variable is "<<x.getVariable()<<std::endl;
	//int theMap[] = x.GetMap;
	std::cout<<"map is "<<x.GetMap()<<std::endl;
	//std::cout<<"ArraySize is "<<x.SizeOfArray(x.GetMap())<<std::endl;
	system("pause");
	return 0;
}