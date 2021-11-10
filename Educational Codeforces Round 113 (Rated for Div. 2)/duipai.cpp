#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<windows.h>
using namespace std;
 
int main()
{
	int t = 100000;
	while (t--)
	{
		system("data > mi.in");
		system("C < mi.in > 1.out");
		system("wjx < mi.in > 2.out");
		if (system("fc 1.out 2.out")) break;
	}
	system("pause");
	return 0;
}