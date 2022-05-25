#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[5005];
long long ans;
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=k;i++) ans+=a[n-i+1];
	cout<<ans;
	return 0;
}
