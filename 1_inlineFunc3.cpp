#include <algorithm>
using namespace std;

// 라이브러리의 조건
// 1. 성능 : 빨라야 한다.
// 2. 유연성 : 정책 변경이 가능해야 한다.
// 변하지 않는 흐름속에서 변해야 하는 정책은 분리되어야 한다.
// 일반 함수에서는 변하는 것을 인자화 한다.

void Sort(int* x, int sz, bool(*cmp)(int, int) )	// qsort()의 원리 (정책 교체 가능)
{
	for (size_t i = 0; i < sz - 1; i++)
	{
		for (size_t j = i+1; j < sz; j++)
		{
			//if (x[i] > x[j])
			if (cmp(x[i], x[j]))	// 비교 함수 사용
				swap(x[i], x[j]);
		}

	}
}

// 아무래도 직접비교보단 함수 호출이 있으므로 느리다. 그래서 정책 변경 정렬알고리즘 제공이 어려움.
// 이걸 극복하기 위하여 함수객체 등장..

bool cmp1(int a, int b) { return a < b; } //less
bool cmp2(int a, int b) { return a > b; } //greater

int main()
{
	int x[10] = { 1, 3, 5, 7,9,2,4,6,8,10 };
	Sort(x, 10, cmp1);
}