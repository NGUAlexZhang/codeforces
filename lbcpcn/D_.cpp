#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <iomanip>

using namespace std; 

int main()
{
 int n,s;
 char o;
 cin >>n;
 for(int i=0;i<4;i++)
 {
  cin >>o;
  s*=2;
  s+=o-65;
 }
 
 long long p=1,las=1;
 for(int i=3;i<=n-2;i++)
 {
	long long tmp=(p+las)%1000000007;
	las=p;
	p=tmp;
  p%=1000000007;
 }
 
 if(s==0||s==1||s==2||s==3||s==5||s==7||s==13||s==15)
  cout<<"1"<<endl;
 else
  cout<<p<<endl;
 
 return 0; 
}