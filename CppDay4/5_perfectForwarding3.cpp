template<typename T>
class List
{
public:
	List(int sz, T value)
	{

	}
};

template<typename T> void foo(T a)
{

}

int main()
{
	// �Լ� ���ø��� �Ͻ���/����� �ν��Ͻ�ȭ�� ��� �����ϴ�.
	foo<int>(3);	// ok
	foo(3);			// ok

	// Ŭ���� ���ø��� ����� �ν��Ͻ�ȭ�� �����ϴ�.
	List<int> s1(10, 3);
	List s2(10, 3);
}