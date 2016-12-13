// Safe Bool �̶�� ���� - Boost�� �ִ� ����
class File
{
public:
	File(const char* s) {}

	// C++ 11 : ��ȯ ������ �տ��� explicit�� ���� �� �ֽ��ϴ�.
	//			����� ��ȯ�� ����ϰ� �Ͻ��� ��ȯ�� �Ұ���
	// ��, if ���� ��ü�� ���� ���� �Ͻ��� ��ȯ ���
	explicit operator bool() { return true; }
	
};

int main()
{
	File f("a.txt");

	bool b = f;						// error �Ͻ��� ��ȯ�� ������ ����.
	bool b = static_cast<bool> (f);	// ok

	if (f) {}				// �Ͻ��� ��ȯ�� �ȵ����� if������ ���������� �Ͻ��� ��ȯ ���

}