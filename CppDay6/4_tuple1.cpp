#include <iostream>

// �������� ���ø��� ����� C++11 ǥ���� Ʃ�� �����
// ������ : ��� ���ڰ� �������� �̹Ƿ� ���޵� Ÿ���� ���� �� ����.!
template<typename ... Types> class xtuple
{

};

template<typename T, typename ... Types> class xtuple
{

};

int main()
{
	xtuple<int, double, short> t3;
}