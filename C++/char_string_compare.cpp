
#include "2022-05-19.h"
#include "Chapter5.h"
using namespace std;

int main()
{
	char word[20] = "word";
	char* p_word = (char*)"word";

	//�ּҸ� ��
	if (word == "word")
	{
		cout << "word �迭�� �ּҰ��� word ��� ���ڿ��� �ּҰ� �ٸ���.\n";
	}

	//�ּҸ� ��
	if (p_word == "word")
	{
		cout << "point char�� word�� word ��� ���ڿ��� �ּҰ� ����.\n";
	}
	
	string str = "word";


	//�ּҿ� �ִ� ���� ��
	if (str == "word")
	{
		cout << "string str�� word�� word ��� ���ڿ��� ����\n";
	}



	return 0;
}