class Test
{
	int value;
public:
	explicit Test(int n) : value(n) {}
};

int main()
{
	// �Ʒ� 2���� ��������?
	Test t1(5);		// 1. ���� �Ѱ�¥�� ������ ȣ��
	Test t2 = 5;	// 2. a. 5�� ��ȯ�����ڸ� ����ؼ� Test �ӽð�ü ����
					//	  b. �ӽð�ü�� ���� �����ڸ� ����ؼ� t2�� ���� (��ǥ�� shared_ptr.. �� �̷��� �ȵ�)
}