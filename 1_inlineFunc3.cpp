#include <algorithm>
using namespace std;

// ���̺귯���� ����
// 1. ���� : ����� �Ѵ�.
// 2. ������ : ��å ������ �����ؾ� �Ѵ�.
// ������ �ʴ� �帧�ӿ��� ���ؾ� �ϴ� ��å�� �и��Ǿ�� �Ѵ�.
// �Ϲ� �Լ������� ���ϴ� ���� ����ȭ �Ѵ�.

void Sort(int* x, int sz, bool(*cmp)(int, int) )	// qsort()�� ���� (��å ��ü ����)
{
	for (size_t i = 0; i < sz - 1; i++)
	{
		for (size_t j = i+1; j < sz; j++)
		{
			//if (x[i] > x[j])
			if (cmp(x[i], x[j]))	// �� �Լ� ���
				swap(x[i], x[j]);
		}

	}
}

// �ƹ����� �����񱳺��� �Լ� ȣ���� �����Ƿ� ������. �׷��� ��å ���� ���ľ˰��� ������ �����.
// �̰� �غ��ϱ� ���Ͽ� �Լ���ü ����..

bool cmp1(int a, int b) { return a < b; } //less
bool cmp2(int a, int b) { return a > b; } //greater

int main()
{
	int x[10] = { 1, 3, 5, 7,9,2,4,6,8,10 };
	Sort(x, 10, cmp1);
}