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


//템플릿 기본 형식
/*
typename == class 같은 뜻
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


//템플릿의 한계
template <typename Any, typename Any2> void Swap(Any& a, Any& b)
{
	/*
	* 밑의 코드들은 배열일 경우 문제가 될 확률이 높다.
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

	cout << "job 교환전: \n";
	Show(sue);
	Show(sideny);

	Swap(sue, sideny);


	cout << "job 교환후: \n";
	Show(sue);
	Show(sideny);
	return 0;
}
void Show(Job& j)
{
	cout << j.name << ": (" << j.floor << "층에 거주)" << "$" << j.salary << endl;
}


