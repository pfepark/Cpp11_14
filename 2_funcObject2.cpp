// �Ʒ� �ּ��� ���� �߿�.

// 1. �Ϲ� �Լ��� �ڽŸ��� Ÿ���� ����.
//	signature�� ������ �Լ��� ���� Ÿ���̴�.

// 2. �Լ� ��ü�� �ڽŸ��� Ÿ���� �ִ�.
//	signature�� �����ص� ��� �ٸ� Ÿ���̴�.
#include <algorithm>

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

Less f1;
Greater f2;

int x[10] = { 1, 3, 5, 7,9,2,4,6,8,10 };


//------------------------------------------------------------

// ��å ������ �����ϰ�, ��å�� �ζ��� ġȯ�� �Ǵ� �Լ�
// template + �Լ� ��ü�� ����� ���
template<typename T>
void Sort(int* x, int sz, T cmp)	// -> Ÿ���� �������Ƿ� inlineȭ ����
{
	for (size_t i = 0; i < sz - 1; i++)
	{
		for (size_t j = i + 1; j < sz; j++)
		{
			//if (x[i] > x[j])
			if (cmp(x[i], x[j]))	// �� �Լ� ���
				std::swap(x[i], x[j]);
		}

	}
}

Sort(x, 10, f1);
Sort(x, 10, f2);