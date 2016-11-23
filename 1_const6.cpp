#include "stdafx.h"


// 핵심 : 맴버 함수안에서 객체의 상태가 변하지 않는다면
//		 반드시 상수 함수로 해야 한다.
//		상수함수는 선택이 아닌 필수.
class Rect
{
	int x, y, w, h;
public:
	int GetArea() const { return w * h; }
};

void foo(const Rect& r)
{
	int n = r.GetArea();		// error
}

int main()
{
	Rect r;
	int s = r.GetArea();	// r은 일반객체이므로 ok.
	foo(r);

	return 0;
}