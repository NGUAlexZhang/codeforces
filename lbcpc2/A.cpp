#include <bits/stdc++.h>
using namespace std;
int sum;
int main(){
	int n,maxn=-1;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		maxn=max(maxn,x);
		sum+=x;
	}
	cout<<max(2*sum/n+1,maxn);
	//n*k-sum>sum
	return 0;
}
