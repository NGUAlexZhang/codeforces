#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[150000];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//a[0]=a[1];
	for(int i=n;i>=1;i--) a[i]-=a[i-1];
	ll sum1=0,sum2=0;
	for(int i=2;i<=n;i++){
		if(a[i]>0) sum1+=a[i];
		else sum2-=a[i];
	}
	//cout<<endl<<sum1<<endl;
	cout<<min(sum1,sum2)+abs(sum1-sum2)<<endl<<abs(sum1-sum2)+1;
	return 0;
}
