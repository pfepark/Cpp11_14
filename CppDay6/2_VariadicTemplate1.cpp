// 2_�������� ���ø� - C++11 �߰�����

// �������� Ŭ���� ���ø�
template<typename ...T> class tuple {};

// �������� �Լ� ���ø�
template<typename ... T> void foo(T ... a) {}

int main()
{
	tuple<> t0;
	tuple<int, double, char> t;

	foo(10);
	foo();
	foo(10, "all", 4.5f);
}