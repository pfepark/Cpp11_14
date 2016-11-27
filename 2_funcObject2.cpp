// 아래 주석이 아주 중요.

// 1. 일반 함수는 자신만의 타입이 없다.
//	signature가 동일한 함수는 같은 타입이다.

// 2. 함수 객체는 자신만의 타입이 있다.
//	signature가 동일해도 모두 다른 타입이다.
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

// 정책 변경이 가능하고, 정책의 인라인 치환이 되는 함수
// template + 함수 객체로 만드는 기술
template<typename T>
void Sort(int* x, int sz, T cmp)	// -> 타입이 정해지므로 inline화 가능
{
	for (size_t i = 0; i < sz - 1; i++)
	{
		for (size_t j = i + 1; j < sz; j++)
		{
			//if (x[i] > x[j])
			if (cmp(x[i], x[j]))	// 비교 함수 사용
				std::swap(x[i], x[j]);
		}

	}
}

Sort(x, 10, f1);
Sort(x, 10, f2);