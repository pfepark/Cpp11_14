// typename

class AAA
{
public:
	//static int DWORD = 10;
	typedef int DWORD;
};

int p = 0;

// template �ȿ� typedef �� Ÿ���� ���� ����Ҷ��� �ݵ�� typename�� �ʿ��ϴ�.

template<typename T> typename T::DWORD foo(T a)
{
	typename T::DWORD * p;	// �� ������ �ؼ��Ͻÿ�.
					// 1. DWORD�� static �ɹ� data�ε� , ���ϱ� p�ϰ� �ִ�. (ǥ�ؿ����� �̰����� ����.)
					// 2. DWORD�� typedef�Ǿ� �ִµ� ������ ���� p�� �����ϰ� �ִ�. (���𿡼� typename�� �ٿ����Ѵ�)

	return 0;
}

int main()
{
	AAA aaa;
	foo(aaa);
}