#pragma once
#include <vector>

namespace test{
	//extern vector <int> map;// with this 'extern' the complier won't be complaining about the var being undefined
	class X
	{
		
	private:
		int privateVariable;
		int arrMap[80];
		std::vector <int> map;
	public:
		X(void);

		~X(void);

		template <unsigned S> //If you template the below, the function can accept arrays of any size:
		int SizeOfArray (int (&v) [S]);

		void setMap();

		void setVariable(int userVariable);

		int getVariable();

		int* GetMap();
		
	};
}

