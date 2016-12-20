// 9_initializer_list

#include <iostream>
#include <initializer_list>

void foo(std::initializer_list<int> e)
{
	e.begin();
}

int main()
{
	std::initializer_list<int> e = { 1,2,3 };

	//foo(e);

	foo({ 1,2,3 });
}