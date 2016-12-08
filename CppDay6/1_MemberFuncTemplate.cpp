// 1_�ɹ��Լ� ���ø�, 81page

// 1. �Ʒ� Complex�� ���ø����� �ϴ� ����... double�� �ص� ������ ��������
// 2. T a = T() : zero initialize
//				T �� primitive �Ǵ� �������̸� 0,
//				����� Ÿ���̸� ����Ʈ �����ڷ� �ʱ�ȭ
template<typename T> class Complex
{
	T re, im;
public:
	Complex(T a = T(), T b = T()) : re(a), im(b)
	{

	}

	// ���� ������ generic ���������..
	// "U�� T�� ����(����)�� �� �ִٸ�, Complex<U>�� Complex<T>�� ����(����)�� �� �־�� �Ѵ�."
	template<typename U> Complex(const Complex<U>& c);

	// ��� ������ Complex�� ģ���̴�.
	template<typename U> friend class Complex;
};

// template Ŭ������ �ɹ� �Լ� ���ø��� �ܺ� ����
template<typename T> template<typename U>
Complex<T>::Complex(const Complex<U>& c) : re(c.re), im(c.im)
{}

int main()
{
	Complex<int> c1(1, 2);

	Complex<int> c2 = c1;		// ���� ������. �����Ϸ� ���������̸� ok.

	Complex<double> c3 = c1;	// c1, c3�� ���� �ٸ� Ÿ��. private�� ������ �ȵǹǷ� friend �������� ó��.


	// ����Ʈ �����͸� �����غ��ô�.
	std::shared_ptr<Dog> p1(new Dog);
	std::shared_ptr<Animal> p2 = p1;

	// ���� ������ ����Ʈ �����ʹ� �⺻������
	// ���� ������, ���Կ�����, ==, != �� template ������ �����Ǿ�� �Ѵ�.
}