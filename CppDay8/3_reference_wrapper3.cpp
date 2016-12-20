#include <iostream>
#include <functional>

using namespace std::placeholders;	// C++ bind() ����ϱ� ����

void foo(int a, int& b)
{
	std::cout << a << " ";
	std::cout << "foo" << std::endl;
	b = 20;
}

int main()
{
	std::function<void(int)> f;
	
		int n = 0;
		//logTime(foo, 10, n);	// �� �ڵ��� ������ ���� �Ǹ� �̹� foo�� ����Ǿ����ϴ�.
								// foo ������ n�� �ı����� �ʽ��ϴ�.
		f = std::bind(&foo, _1, n); // _1 : f�� ����Ҷ� 1��° ����
									// bind�� ������ ���ڸ� �����Ҵ� ������ �����ϰ� �ֽ��ϴ�.
									// �׷��� n�� �����ɶ� ���� �����ϰ� �ְ� �˴ϴ�.
	
	

	f(10);		// foo(10, n)

	std::cout << n << std::endl;
}