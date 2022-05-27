#include <iostream>
#include <string>
#include<vector>
#include<algorithm>

const int BUF = 512;
const int N = 5;
char buffer[BUF];


using namespace std;

struct chaff
{
	char dross[20];
	int slag;
};

/*
new ��ġ������ ��� �ش� ������ �迭�� ������ ��� ������ ����ϴ� ���̹Ƿ� ûũó�� ���ÿ� ���ļ� ���δ�.
����, �ش� �Լ��� ���� �� ��� �ڵ����� ���� �޸𸮰� ������ �ǹǷ� ���� delete[]�� ���� �ʾ��൵ �ȴ�.
*/
int main()
{
	double* pd1, * pd2;
	int i;
	cout << "new�� ��ġ ���� new�� ù ��° ȣ��:\n";
	pd1 = new double[N];
	pd2 = new (buffer) double[N]; //buffer �迭�� ����Ѵ�.

	for (i = 0; i < N; ++i)
	{
		pd2[i] = pd1[i] = 1000 + 20.0 * i;
	}

	cout << "�޸� �ּ�:\n" << pd1 << " : ��;\t" << (void*)buffer << " : ����" << endl;
	cout << "�޸� ����:\n";
	for (i = 0; i < N; ++i)
	{
		cout << &pd1[i] << "�� " << pd1[i] << ";  ";
		cout << &pd2[i] << "�� " << pd2[i] << endl;
	}


	cout << "\nnew����ġ ���� new�� �� ��° ȣ��:\n";
	double	*pd3, * pd4;
	pd3 = new double[N];
	pd4 = new(buffer)double[N];
	for (i = 0; i < N; ++i)
		pd4[i] = pd3[i] = 1000 + 40.0 * i;
	cout << "�޸𸮳���:\n";
	for (i = 0; i < N; ++i)
	{
		cout << &pd3[i] << "�� " << pd3[i] << ";  ";
		cout << &pd4[i] << "�� " << pd4[i] << endl;
	}


	cout << "\nnew����ġ ���� new�� �� ��° ȣ��:\n";

	delete[] pd1;
	pd1 = nullptr;
	pd1 = new double[N];
	pd2 = new(buffer + N * sizeof(double)) double[N];


	for (i = 0; i < N; ++i)
		pd2[i] = pd1[i] = 1000 + 60.0 * i;

	cout << "�޸� ����:\n";
	for (i = 0; i < N; ++i)
	{
		cout << &pd1[i] << "�� " << pd1[i] << ";  ";
		cout << &pd2[i] << "�� " << pd2[i] << endl;
	}


	delete[] pd1;
	delete[] pd3;


	return 0;
}

