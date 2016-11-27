// 2_�Լ���ü3

#include <algorithm>

// cmp1, cmp2, Less, Greate ����
bool cmp1(int a, int b) { return a < b; } //less
bool cmp2(int a, int b) { return a > b; } //greater

struct Less
{
	inline bool operator()(int a, int b)
	{
		return a < b;
	}
};

struct Greater
{
	inline bool operator()(int a, int b)
	{
		return a < b;
	}
};

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	// 1. �� ��å���� �Ϲ��Լ��� ����Ҷ�
	// ���� : ��å�� �����ص� sort() ����� �Ѱ��̴�. �ڵ� �޸� ��������
	// ���� : ��å�� �ζ��� ġȯ�� �� ����. ��������!
	std::sort(x, x + 10, cmp1);	// sort( int*, int*, bool(*)(int, int)) �� �Լ� ����
	std::sort(x, x + 10, cmp2);	// sort( int*, int*, bool(*)(int, int)) �� �Լ� ����

	// 2. �� ��å���� �Լ���ü�� ����Ҷ�
	// ���� : ��å�� �ζ��� ġȯ�� �� �ִ�.
	// �ܴ� : ��å�� ��ü�� Ƚ����ŭ�� sort() ���� �ڵ� ����, �ڵ�޸� ����.
	Less f1;
	Greater f2;
	std::sort(x, x + 10, f1);	// sort(int*, int*, Less) �� �Լ� ����
	std::sort(x, x + 10, f2);	// sort(int*, int*, Greater) �� �Լ� ����
	return 0;
}