#include <iostream>
#include <string>
#include<vector>
#include<algorithm>

using namespace std;

struct Job
{
	char name[40];
	double salary;
	int floor;
};


//���ø� �⺻ ����
/*
typename == class ���� ��
*/
template <typename T> T& add(T& x, T& y)
{
	return x + y;
}

//template <class T> T& add(T& x, T& y)
//template <typename Any, typename Any2)

template <class Any> void Swap(Any& a, Any& b)
{
	Any temp;
	temp = a;
	a = b;
	b = temp;
}


//���ø��� �Ѱ�
template <typename Any, typename Any2> void Swap(Any& a, Any& b)
{
	/*
	* ���� �ڵ���� �迭�� ��� ������ �� Ȯ���� ����.
	*/

	a = b;
	if (a > b)
	{

	}
}
template<> void Swap<Job>(Job& a, Job& b)
{
	Job temp;
	temp.floor = a.floor;
	temp.salary = a.salary;

	a.floor = b.floor;
	a.salary = b.salary;

	b.floor = temp.floor;
	b.salary = temp.salary;
}

void Show(Job& j);
int main()
{
	cout.precision(2);
	cout.setf(ios::fixed, ios::floatfield);
	int i = 10, j = 20;
	cout << "i, j" << i << ", " << j << ".\n";

	Job sue = { "Susan Yaffee", 73000.60, 7 };
	Job sideny = { "Sideny taffe", 78060.72,9 };;

	cout << "job ��ȯ��: \n";
	Show(sue);
	Show(sideny);

	Swap(sue, sideny);


	cout << "job ��ȯ��: \n";
	Show(sue);
	Show(sideny);
	return 0;
}
void Show(Job& j)
{
	cout << j.name << ": (" << j.floor << "���� ����)" << "$" << j.salary << endl;
}


