#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll res=0;
	char ch=getchar();
	while(ch>='0'&&ch<='9'){
		res+=(ch-'0');res*=10;ch=getchar();
	}
	return res/10;
}
int main(){
	ll n=read(),m=read();
	cout<<n<<" "<<m;
	return 0;
}
