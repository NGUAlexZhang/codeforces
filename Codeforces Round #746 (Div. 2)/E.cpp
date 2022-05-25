#include <bits/stdc++.h>
using namespace std;
int a[1000005],ans;
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int k=20;k>=0;k--){
		int mask=(1<<21)-(1<<k);
		vector<int>pre(n+5);
		map<int,int>cnt;
		int l=1;
		for(int i=1;i<=n;i++){
			pre[i]=pre[i-1]^(mask&a[i]);
			if(a[i]&(1<<k)){
				if(l==-1) l=i;
				if((cnt[pre[i]]||pre[i]==0)&&cnt[pre[i]]+1>=l){
					ans=max(ans,i-cnt[pre[i]]);
				}
			}
			else{
				l=-1;
			}
			if(l==-1||cnt[pre[i]]+1<l||(cnt[pre[i]]==0&&pre[i]!=0)) cnt[pre[i]]=i;
		}
	}
	cout<<ans;
	return 0;
}
