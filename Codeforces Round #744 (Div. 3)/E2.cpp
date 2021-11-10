#include <bits/stdc++.h>
using namespace std;
struct Num{
	int num,index;
	bool operator >(const Num& sb){
		return num>sb.num;
	}
}a[2500001],b[2501000];
int c[2500100],ni[2015000],arr[2505000];
void merg(int l,int r){
	if(l==r) return;
	int mid=(l+r)/2;
	merg(l,mid);
	merg(mid+1,r);
	int ll=l,rr=mid+1,now=l-1;
	while(ll<=mid&&rr<=r){
		if(a[ll]>a[rr]){
			ni[a[rr].index]+=(mid-ll+1);
			b[++now]=a[rr++];
		}
		else{
			b[++now]=a[ll++];
		}
	}
	while(ll<=mid) b[++now]=a[ll++];
	while(rr<=r) b[++now]=a[rr++];
	for(int i=l;i<=r;i++) a[i]=b[i];
}
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		scanf("%d",&n);
		map<int,int>cnt;
		for(int i=1;i<=n;i++) scanf("%d",&c[i]);
		for(int i=1;i<=n;i++){
			int x=c[i];
			arr[i]=cnt[x];
			cnt[x]++;
			a[i].num=c[i];
			a[i].index=i;
		}
		memset(ni,0,sizeof(ni));
		merg(1,n);
		deque<int>d;
		long long ans=0;
		for(int i=1;i<=n;i++){
			if(ni[i]>i-1-arr[i]-ni[i]) ans+=i-1-arr[i]-ni[i];
			else ans+=ni[i];
			//cout<<ni[i]<<" ";
		}
	//	cout<<endl;
		cout<<ans<<endl;
	}
	return 0;
}
