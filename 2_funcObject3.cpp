// 2_함수객체3

#include <algorithm>

// cmp1, cmp2, Less, Greate 복사
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

	// 1. 비교 정책으로 일반함수를 사용할때
	// 장점 : 정책을 변경해도 sort() 기계어는 한개이다. 코드 메모리 증가안함
	// 단점 : 정책을 인라인 치환할 수 없다. 성능저하!
	std::sort(x, x + 10, cmp1);	// sort( int*, int*, bool(*)(int, int)) 인 함수 생성
	std::sort(x, x + 10, cmp2);	// sort( int*, int*, bool(*)(int, int)) 인 함수 생성

	// 2. 비교 정책으로 함수객체를 사용할때
	// 장점 : 정책이 인라인 치환될 수 있다.
	// 단덤 : 정책을 교체한 횟수만큼의 sort() 기계어 코드 생성, 코드메모리 증가.
	Less f1;
	Greater f2;
	std::sort(x, x + 10, f1);	// sort(int*, int*, Less) 인 함수 생성
	std::sort(x, x + 10, f2);	// sort(int*, int*, Greater) 인 함수 생성
	return 0;
}