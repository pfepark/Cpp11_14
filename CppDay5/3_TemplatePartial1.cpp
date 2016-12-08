// 3_���ø��κ�����ȭ template partial specialization

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

// �������϶��� �Ʒ� ���ø��� ���
// partial specialization �κ� ����ȭ
template<typename T>
class stack<T*>
{
public:
	void push(T a)
	{
		std::cout << "T*" << std::endl;
	}
};

// specialization ����ȭ
template<>		// char*�� Ȯ���Ǿ����� T�� �ʿ����.
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