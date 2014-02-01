#include "X.hpp"
#include <iostream> //withou this std::cout does not work


using namespace test;


X::X(void)
{
	privateVariable= 1;
				}


X::~X(void)
{
}

template <unsigned S> //If you template the below, the function can accept arrays of any size:
int X::SizeOfArray (int (&v) [S])
{
	std::cout<<S;
	return S;
}

void X::setMap()
{
	int mapSize=80;
	int mapColumns = 10;
	//10x8=80
	int arrMap[80] = {0,0,1,2,3,4,5,1,0,0,
					0,1,0,0,1,1,0,0,1,0,
					1,0,0,0,1,1,0,0,0,1,
					0,1,0,0,1,2,3,4,6,0,
					0,0,1,1,0,0,1,1,0,0,
					0,0,1,1,0,0,1,1,0,0,
					0,1,0,0,1,1,0,0,1,0,
					0,0,1,1,0,0,1,1,0,0};

	

	//map.insert(map.begin(),arrMap);
	map.insert(map.begin(),arrMap, arrMap + 80);
	for (int i = 0; i < mapSize; i++)
	{
		std::cout<<i<<" Member = "<<map[i]<<std::endl;
		//std::cout<<"Member = "<<map[i]<<std::endl;
	}
	//int arraySize;
	//SizeOfArray(arrMap);
	//std::cout<<"The array size is "<< SizeOfArray(arrMap);

	/*int map[] = {0,0,1,2,3,4,5,1,0,0,
				0,1,0,0,1,1,0,0,1,0,
				1,0,0,0,1,1,0,0,0,1,
				0,1,0,0,1,2,3,4,6,0,
				0,0,1,1,0,0,1,1,0,0,
				0,0,1,1,0,0,1,1,0,0,
				0,1,0,0,1,1,0,0,1,0,
				0,0,1,1,0,0,1,1,0,0};
				*/
	
}

void X::setVariable(int userVariable)
{  
	privateVariable = userVariable;             
} 

int X::getVariable()
{
	return privateVariable;                     
}

int* X::GetMap()
{
	//for (int i = 0; i < map; i++)
	//{


	//}
	//return map[];
	return arrMap;
}

//int* PrintMap(int* map[])
//{
//	int theMap[] = X::GetMap();
//	for (int i = 0; i < 80; i++)
//	{
//		std::cout<<i<<" Member = "<<map[i]<<std::endl;
//		//std::cout<<"Member = "<<map[i]<<std::endl;
//	}
//}