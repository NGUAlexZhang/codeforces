#include <bits/stdc++.h>
using namespace std;
int a[1005];
int main(){
	int n,minn=2147483647,maxn=-1;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		maxn=max(x,maxn);
		minn=min(x,minn);
	}
	cout<<(maxn-minn+1)-n;
	return 0;
}
