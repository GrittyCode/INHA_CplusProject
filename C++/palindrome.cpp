
#include "2022-05-19.h"
#include "Chapter5.h"
using namespace std;


bool Chapter5::FindWordCorrect(string str)
{
	//ȸ���� ã��
	//ȸ���� ���� leel level��츦 ���Ѵ�.
	//�ε��� �� �հ� �ǵڰ� ��� ���� ��츸 ȸ��, Ȧ���� ��쿡�� �����ϰ� �����
	for (int i = 0; i < str.size() / 2; i++)
	{
		if (str[i] != str[str.size() - (i + 1)])
		{
			return false;
		}
	}
	return true;

}
int main()
{
	string str;
	
	while (1)
	{
		cout << "�ܾ �Է��Ͻÿ�(���Ḧ ���ϸ� exit�Է�) : ";
		cin >> str;
		if (str == "exit") break;
		int flag = Chapter5::FindWordCorrect(str);
		if (flag == true)
		{
			cout << str << "�� ȸ���Դϴ�. \n";
		}
		else
		{
			cout << str << "�� ȸ���� �ƴմϴ�. \n";
		}
	}
	

	return 0;
}