#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ll a[1000];
	a[0]=1;
	for(int i=1;i<=1000;i++){
		a[i]=a[i-1]+(i+1)*pow(2,i);
	}
	for(int i=1;i<=1000;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
