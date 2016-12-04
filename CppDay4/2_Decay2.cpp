#include <stdio.h>
#include <iostream>

// 규칙 1. 모든 객체는 자신과 동일한 타입으로 초기화 될 수 있다.
//     2. 

int main()
{
	int n1 = 10;
	int n2 = n1;

	double d1 = 3.4;
	double d2 = d1;

	int x[3] = { 1,2,3 }; // x의 타입은 int[3]
	//int y[3] = x;		// error 배열만큼은 자신의 타입으로 초기화할 수 없는 예외. 복사로 인한 성능 저하..

	int* p = x;	// 배열의 이름은 배열의 1번째 요소의 주소로 암시적 형변환된다.
				// "Array to Pointer Conversion" 이라는 문법 C++표준문서 4.2절

	int(*p1)[3] = &x;		// 배열의 주소
	int* p2 = x;			// 배열의 1번째 요소의 주소

	printf("%p, %p\n", p1, p1 + 1);		// +12바이트 (배열의 크기)
	printf("%p, %p\n", p2, p2 + 1);		// +4바이트 (요소의 크기)

	int a[3] = { 1, 2, 3 };
	//int b[3] = a;	// 동일 타입으로 초기화 안됨

	int* p = a;		// ok. 배열의 1번째 요소의 주소로 암시적 형변환 - C언어에서 정한 규칙

	int(&b)[3] = a;	// ok. 참조는 됨.
}