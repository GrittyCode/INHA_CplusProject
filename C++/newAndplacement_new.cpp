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
new 위치지정의 경우 해당 변수나 배열의 공간을 잠시 빌려서 사용하는 것이므로 청크처럼 스택에 뭉쳐서 쓰인다.
만약, 해당 함수가 종료 된 경우 자동으로 스택 메모리가 해제가 되므로 따로 delete[]를 하지 않아줘도 된다.
*/
int main()
{
	double* pd1, * pd2;
	int i;
	cout << "new와 위치 지정 new의 첫 번째 호출:\n";
	pd1 = new double[N];
	pd2 = new (buffer) double[N]; //buffer 배열을 사용한다.

	for (i = 0; i < N; ++i)
	{
		pd2[i] = pd1[i] = 1000 + 20.0 * i;
	}

	cout << "메모리 주소:\n" << pd1 << " : 힙;\t" << (void*)buffer << " : 정적" << endl;
	cout << "메모리 내용:\n";
	for (i = 0; i < N; ++i)
	{
		cout << &pd1[i] << "에 " << pd1[i] << ";  ";
		cout << &pd2[i] << "에 " << pd2[i] << endl;
	}


	cout << "\nnew와위치 지정 new의 두 번째 호출:\n";
	double	*pd3, * pd4;
	pd3 = new double[N];
	pd4 = new(buffer)double[N];
	for (i = 0; i < N; ++i)
		pd4[i] = pd3[i] = 1000 + 40.0 * i;
	cout << "메모리내용:\n";
	for (i = 0; i < N; ++i)
	{
		cout << &pd3[i] << "에 " << pd3[i] << ";  ";
		cout << &pd4[i] << "에 " << pd4[i] << endl;
	}


	cout << "\nnew와위치 지정 new의 세 번째 호출:\n";

	delete[] pd1;
	pd1 = nullptr;
	pd1 = new double[N];
	pd2 = new(buffer + N * sizeof(double)) double[N];


	for (i = 0; i < N; ++i)
		pd2[i] = pd1[i] = 1000 + 60.0 * i;

	cout << "메모리 내용:\n";
	for (i = 0; i < N; ++i)
	{
		cout << &pd1[i] << "에 " << pd1[i] << ";  ";
		cout << &pd2[i] << "에 " << pd2[i] << endl;
	}


	delete[] pd1;
	delete[] pd3;


	return 0;
}

