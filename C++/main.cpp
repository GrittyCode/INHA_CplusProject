#include<stdio.h>
#include<string.h>
#include<time.h>
#include<Windows.h>
#include<iostream>

using namespace std;


void check_time_prime(int num) //소수 출력 구문
{
	int cnt = 0; //줄바꾸기 확인 변수
	for (int i = 2; i <= num; i++)
	{
		bool flag = 1; //초기값은 소수라고 가정


		for (int j = 2; j < i; ++j) //소수 검증 부분(2~num까지)
		{
			if (i % j == 0) //자기보다 작은 수로 나뉘어 떨어진다면 소수가 아님. 
			{
				flag = 0; //소수가 아닌것으로 플래그 변경
				break;
			}
		}

		if (flag) //위의 j 포문에서 플래그 변경되지 않았다면 현재 i는 소수임.
		{
			printf("%5d\t", i);
			cnt++; //소수를 출력할때마다 1개씩 카운트를 늘린다.
		}

		if (cnt == 5) //5개 들어갈때 마다 줄바꿈
		{
			printf("\n");
			cnt = 0;
		}
	}
}


//1번
void check_time_prime1(int num) //소수 출력 구문
{
	int i = 0, n= 0;
	int cnt = 0;
	bool flag = false;
	for (n = 3; n <= num; n += 2)
	{
		flag = false;

		for (i = 3; i < n; ++i)
		{
			if (n % i == 0)
			{
				flag = true;
				break; //소수가 아니므로 반복 멈춤
			}
				
		}

		if (!flag)
		{
			printf("%5d\t", n);

			if (cnt == 5) //5개 들어갈때 마다 줄바꿈
			{
				printf("\n");
				cnt = 0;
			}
		}
	}
}

void check_time_prime2(int num)
{
	int i = 0, n = 0;
	int prime[10000];
	int ptr = 0;
	int cnt = 0;

	prime[ptr++] = 2;
	prime[ptr++] = 3;

	for (n = 5; n <= num; n += 2) //홀수만을 대상으로 합니다.
	{
		int flag = 0;
		for (i = 1; prime[i] < n; ++i)
		{
			if (n % prime[i] == 0)
			{
				flag = 1;
				break;
			}
		}

		if (!flag)
		{
			cnt++;
			prime[ptr++] = n;
			printf("%5d\t", n);
		}


		if (cnt == 5) //5개 들어갈때 마다 줄바꿈
		{
			printf("\n");
			cnt = 0;
		}
	}

}


void check_time_prime3(int num)
{
	int i = 0, n = 0;
	int prime[10000];
	int ptr = 0;
	int cnt = 0;

	prime[ptr++] = 2;
	prime[ptr++] = 3;

	for (n = 5; n <= num; n += 2) //홀수만을 대상으로 합니다.
	{
		int flag = 0;
		for (i = 1; prime[i] * prime[i] <= n; ++i)
		{
			if (n % prime[i] == 0)
			{
				flag = 1;
				break;
			}
		}

		if (!flag)
		{
			cnt++;
			prime[ptr++] = n;
			printf("%5d\t", n);
		}


		if (cnt == 5) //5개 들어갈때 마다 줄바꿈
		{
			printf("\n");
			cnt = 0;
		}
	}

}


int main()
{	
	int num;
	cout << "원하는 숫자를 입력하세요 : ";
	cin >> num;
	clock_t start = clock();
	check_time_prime2(num);
	cout << "\n" << "걸린 밀리세컨드 : " << clock() - start << "초" << endl;

	return 0;
}