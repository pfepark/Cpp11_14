template<typename T> struct identity // �̰� Ŭ���� ���ø��̹Ƿ�..��������� ����ؾ���.
{
	typedef T Type;
};

// �Ʒ� �Լ��� �� ���ڸ� �̷��� ����������?
// foo�� ����Ҷ� �ݵ�� ��������� Ÿ���� �����ؾ� �Ѵٴ� �ǹ��Դϴ�.
// �Ͻ������� ����ϸ� ������ ���� �߻�..
template<typename T> void foo(typename identity<T>::Type a)	// foo(T a)�� �ǹ̴� �����մϴ�.
{

}

int main()
{
	foo<int>(3);	// ok
	//foo(3);		// error
}