#include "stdafx.h"


// �ٽ� : �ɹ� �Լ��ȿ��� ��ü�� ���°� ������ �ʴ´ٸ�
//		 �ݵ�� ��� �Լ��� �ؾ� �Ѵ�.
//		����Լ��� ������ �ƴ� �ʼ�.
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
	int s = r.GetArea();	// r�� �Ϲݰ�ü�̹Ƿ� ok.
	foo(r);

	return 0;
}