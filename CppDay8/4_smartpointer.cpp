#include <iostream>
#include <memory>

class Point
{
	int x, y;
public:
	Point(int a = 0, int b = 0) : x(a), y(b) {}

	static void* operator new(size_t sz)
	{
		return malloc(sz);
	}

	static void operator delete(void* p)
	{
		free(p);
	}
};

void* operator new(size_t sz)
{
	std::cout << "new : " << sz << std::endl;
	return malloc(sz);
}

int main()
{
	// �Ʒ� �ڵ�� �޸𸮸� ��� �Ҵ��ұ��?
	//std::shared_ptr<Point> p1(new Point(1, 2));

	// sizeof(Point) + sizeof(������ü) �� �ѹ��� �޸� �Ҵ��ϴ� �Լ�
	std::shared_ptr<Point> p1 = std::make_shared<Point>(1, 2);	// Point(1,2)�� ��ü�� �����޶�.
	//std::shared_ptr<Point> p2 = p1;
}

/*
// make_shared�� ����
template<typename T, typename ..Types>
shared_ptr<T> Make_shared(Types&&... args)
{
	// 1. �޸� �Ҵ�
	void* p = operator new(sizeof(T) + sizeof(������ü));

	// 2. �Ҵ��� �޸� �պκ��� ��ü�̴�. �����ڸ� ȣ���ؾ� �Ѵ�.
	new (p) T(args...);

	// 3. ���� ��ü�� �ʱ�ȭ�ϰ�

	// 4. shared_ptr�� ���� �����Ѵ�.
	shared_ptr<T> sp;
	sp._set(p, (char*)p + sizeof(T));

	// 3. 
}
*/