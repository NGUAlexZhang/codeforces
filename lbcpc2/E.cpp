#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[305000],b[305000],sum1[305000],sum2[305000];
int main(){
	int n,m;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++) scanf("%lld",&b[i]);
	for(int i=1;i<=n;i++) sum1[i]=sum1[i-1]+a[i];
	for(int i=1;i<=m;i++) sum2[i]=sum2[i-1]+b[i];
	if(sum1[n]!=sum2[m]){
		cout<<-1;
		return 0;
	}
	int p1=1,p2=1;
	int ans=0;
	while(p1<=n&&p2<=m){
		for(int i=0;i+p1<=n;i++){
			int l=p2,r=m;
			ll tar=sum1[i+p1]-sum1[p1-1];
			while(l<=r){
				int mid=(l+r)>>1;
				if(sum2[mid]-sum2[p2-1]<=tar) l=mid+1;
				else r=mid-1;
			}
			if(sum2[l-1]-sum2[p2-1]!=tar) continue;
			ans++;
			p1+=i+1;
			p2=l;
			break;
		}
	}
	cout<<ans;
	return 0;
}
