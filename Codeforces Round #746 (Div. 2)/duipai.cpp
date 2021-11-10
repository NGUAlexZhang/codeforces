#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<windows.h>
using namespace std;
 
int main()
{
	int t = 10000;
	while (t--)
	{
		system("data > mi.in");
		system("new < mi.in > 1.out");
		system("zj < mi.in > 2.out");
		if (system("fc 1.out 2.out")) break;
	}
	system("pause");
	return 0;
}
