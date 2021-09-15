#include <bits/stdc++.h>
using namespace std;
void divide(int sum,int num){
	if(num==1){
		cout<<sum<<" ";
		return;
	}
	int x=sum-num+1,len=0;
	while(x) len++,x/=10;
	int res=1;
	for(int i=1;i<len;i++) res*=10;
	cout<<res<<" ";
	divide(sum-res,num-1);
}
int main(){
	int T;
	cin>>T;
	while(T--){
		int s,n;
		cin>>s>>n;
		divide(s,n);
		cout<<"\n";
	}
	return 0;
}
/*
112 14   99
10
102 13 90
10
92 12*