// Safe Bool �̶�� ���� - Boost�� �ִ� ����
class File
{
public:
	File(const char* s) {}

	//operator bool() { return true; }	// ����/���� ���θ� �����ؼ� ����
	//operator void*() { return this; }	// ���н� 0 ����

	void true_function() {}	// �ּҸ� ����ϱ� ���� ���� �Լ�
	typedef void(File::*PF)();
	operator PF() { return &File::true_function; }		// �ɹ� �Լ� �����ͷ��� ��ȯ. �ɹ� �Լ��� delete���� �ʴ´�.
};

int main()
{
	File f("a.txt");

	// ���� Open�� �����ߴ��� �˰� �ʹ�.
	if (f) {}	// ��ü�� if()�� test => scalar test

	//int a = f + 1;	//f�� bool�� ��ȯ�Ǿ� +�� �ȴ�. �̷��� �ϸ� �ȵ�. �׷��� operator void*()

	//delete f; // �ϸ� ��� �ϳ�...void*�� ��ȯ�Ǿ� �������� �ߵ�.

}