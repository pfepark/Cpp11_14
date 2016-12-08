// 3_템플릿부분전문화 template partial specialization

#include <iostream>

// primary template
template<typename T>
class stack
{
public:
	void push(T a)
	{
		std::cout << "T" << std::endl;
	}
};

// 포인터일때는 아래 템플릿을 사용
// partial specialization 부분 전문화
template<typename T>
class stack<T*>
{
public:
	void push(T a)
	{
		std::cout << "T*" << std::endl;
	}
};

// specialization 전문화
template<>		// char*로 확정되었으니 T가 필요없다.
class stack<char*>
{
public:
	void push(char* a)
	{
		std::cout << "char*" << std::endl;
	}
};

int main()
{
	stack<int> s1;
	s1.push(0);

	stack<int*> s2;
	s2.push(0);

	stack<char*> s3;
	s3.push(0);
}