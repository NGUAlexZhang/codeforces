#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[1000500],b[1000500],c[2000500],tmp[2000500];
vector<int>v[1000500];
ll ans=0;
void qsort(int l,int r){
	//cout<<l<<" "<<r<<endl;
	if(l>=r) return;
	//cout<<l<<" "<<r<<endl;
	int mid=(l+r)>>1;
	qsort(l,mid);
	qsort(mid+1,r);
	
	int i=l,j=mid+1,cnt=i-1;
	while(i<=mid&&j<=r){
		if(c[i]<=c[j]){
			tmp[++cnt]=c[i];
			i++;
		}
		else{
			tmp[++cnt]=c[j];
			ans+=(mid-i+1);
			j++;
		}
	}
	while(i<=mid) tmp[++cnt]=c[i],i++;
	while(j<=r) tmp[++cnt]=c[j],j++;
	for(i=l;i<=r;i++) c[i]=tmp[i];
}
void solve(int l,int r,int L,int R){
	if(l>r||L>R) return;
	int mid=(l+r)>>1;
	int cnt=0,index=L,sum=0;
	for(int i=L+1;i<=R;i++){
		if(a[i]<b[mid]) cnt--;
		if(a[i]>b[mid]) cnt++;
		if(sum>cnt){
			index=i;
			sum=cnt;
		}
	}
	v[index].push_back(b[mid]);
	solve(l,mid-1,L,index);
	solve(mid+1,r,index,R);
}
int main(){
	int T;
	cin>>T;
	while(T--){
		ans=0;
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=0;i<=n;i++) v[i].clear();
		for(int i=1;i<=m;i++) cin>>b[i];
		sort(b+1,b+1+m);
		solve(1,m,0,n);
		int cnt=0;
		sort(v[0].begin(),v[0].end());
		for(int j:v[0]) c[++cnt]=j;
		//if(cnt==1) cout<<c[1]<<endl;
		//cout<<a[1]<<endl;
		int sum=0;
		for(int i=1;i<=n;i++){
			sort(v[i].begin(),v[i].end());
			sum+=v[i].size();
			c[++cnt]=a[i];
			for(int j:v[i]) c[++cnt]=j;
		}
		//cout<<sum+v[0].size()<<endl;
		//for(int i=1;i<=cnt;i++) cout<<c[i]<<" ";
		//cout<<endl;
		qsort(1,cnt);
		cout<<ans<<endl;
	}
	return 0;
}
