#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[56000];
ll sum[56000];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	ll ans=-1e19,ans1=0,ans2=0,ans3=0;
	for(int i=0;i<=n;i++){
		ll sum1=1e19,sum2=1e19,tmp1=0,tmp2=0;
		for(int j=0;j<=i;j++){
			if(sum1>sum[i]-sum[j]){
				sum1=sum[i]-sum[j];
				tmp1=j;
			}
		}
		for(int j=i;j<=n;j++){
			if(sum2>sum[n]-sum[j]){
				sum2=sum[n]-sum[j];
				tmp2=j;
			}
		}
		if(ans<sum[n]-2*sum1-2*sum2){
			ans=sum[n]-2*sum1-2*sum2;
			ans1=tmp1,ans2=i,ans3=tmp2;
		}
	}
	printf("%lld %lld %lld",ans1,ans2,ans3);
	return 0;
}
