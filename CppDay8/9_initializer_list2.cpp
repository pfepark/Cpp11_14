// 9_initializer_list

#include <iostream>
#include <initializer_list>

class Point
{
public:
	explicit Point(int a, int b) { std::cout << "int, int" << std::endl; }								// 1
	//Point(std::initializer_list<int> ini) { std::cout << "initializer_list" << std::endl; }		// 2
};
int main()
{
	// �Ʒ� �ڵ尡 ���� � �����ڸ� ȣ������ �����غ�����.
//	Point p1(1, 2);			// 1, ���ٸ� error
//	Point p2{ 3, 4 };		// 2, ���ٸ� 1��
//	Point p3 = { 5, 6 };	// 2, ���ٸ� 1��

//	Point p4(1,2,3);		// error
//	Point p5{ 1, 2, 3 };	// ok.
//	Point p6 = { 1, 2, 3 };	// ok.	vector<int> v = { 1, 2, 3, 5, 6 };
	Point p7({ 5, 6 });		// 2, ������.. 
							// {5, 6} => Point ��ü�� �Ͻ��� ����ȯ �߻��ؼ� �ӽð�ü����, ���� �����ڷ� p7�� ����
							// �Ͻ��� ����ȯ�� �������� explicit�� ���̸� �ȴ�.

	// C++11/14
	// * ����, �Ϻ��� ������, move, �������� ���ø�..
}