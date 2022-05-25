#include <bits/stdc++.h>
using namespace std;
int sum[250000],ce,ans,n;
void solve(int num1,int num2,int num3){
	if(num1+num2+num3<n){
		return;
	}
	int las=0,all=0;
	int l=1,r=ce;
	while(l<=r){
		int mid=(l+r)>>1;
		if(sum[mid]-sum[las]<=num1) l=mid+1;
		else r=mid-1;
	}
	all+=num1-(sum[l-1]-sum[las]);
	las=l-1;
	l=las+1,r=ce;
	while(l<=r){
		int mid=(l+r)>>1;
		if(sum[mid]-sum[las]<=num2) l=mid+1;
		else r=mid-1;
	}
	all+=num2-(sum[l-1]-sum[las]);
	las=l-1;
	l=las+1,r=ce;
	while(l<=r){
		int mid=(l+r)>>1;
		if(sum[mid]-sum[las]<=num3) l=mid+1;
		else r=mid-1;
	}
	all+=num3-(sum[l-1]-sum[las]);
	ans=min(ans,all);
}
int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		map<int,int>cnt;
		vector<int>num;
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			if(cnt[x]){
				cnt[x]++;
				continue;
			}
			cnt[x]++;
			num.push_back(x);
		}
		sort(num.begin(),num.end());
		ce=0;
		for(auto x:num){
			++ce;
			sum[ce]=sum[ce-1]+cnt[x];
		}
		//for(int i=1;i<=ce;i++) cout<<sum[i]<<" ";
		//cout<<endl;
		int maxn=0;
		while((1<<maxn)<n) maxn++;
		ans=2147483647;
		for(int i=0;i<=maxn;i++)
		for(int j=0;j<=maxn;j++)
		for(int k=0;k<=maxn;k++){
			solve(1<<i,1<<j,1<<k);
		}
		cout<<ans<<endl;
	}
	return 0;
}
