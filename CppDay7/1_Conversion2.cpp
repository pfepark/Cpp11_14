class Vector
{
public:
	// explicit ������ : ���� �ϳ�¥�� �����ڰ� �Ͻ��� ��ȯ�� ����Ű�� ���� ���´�.
	explicit Vector(int sz) {}
};

void foo(const Vector& v) {}

int main()
{
	Vector v(10);
	foo(v);		// ok

	foo(10);	// ?? ���ڸ� �߸����´�. �׷���..
				// 10(int) => Vector�� �Ͻ��� ��ȯ�Ǹ� �ȴ�.
}