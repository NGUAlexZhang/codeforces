#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[1000005];
map<ll,int>m;
int main(){
	//freopen("I.in","r",stdin);
	//freopen("I.out","w",stdout);
	
	ll x,cnt=0;
	while(scanf("%lld",&x)!=EOF){
		a[++cnt]=x;
	}
	for(int i=1;i<=cnt-2;i++) m[a[i]]=1;
	int A=a[cnt-1],r=a[cnt];
	for(int i=A+r;i>=A-r;i--)
		if(m[i]) cout<<i<<" ";
	return 0;
}