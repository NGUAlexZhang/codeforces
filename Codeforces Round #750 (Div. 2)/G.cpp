#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[1000055],pmi[1000555],prime[1000555],cnt;
char b[1000555];
vector<int>v[1000555],s;
int main(){
	for(int i=2;i<=1e6;i++){
		if(!pmi[i]) pmi[i]=i,prime[++cnt]=i;
		for(int j=1;j<=cnt&&prime[j]*i<=1e6;j++){
			pmi[i*prime[j]]=prime[j];
			if(i%prime[j]==0) break;
		}
	}
	ll ans=0;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%s",b+1);
	for(int i=1;i<=n;i++){
		s.push_back(i);
		if(b[i]=='*'){
			for(int now=a[i];now!=1;now/=pmi[now]){
				v[pmi[now]].push_back(i);
			}
		}
		else{
			for(int now=a[i];now!=1;now/=pmi[now]){
				while(s.size()&&(v[pmi[now]].empty()||v[pmi[now]].back()<s.back())) s.pop_back();
				if(v[pmi[now]].size()) v[pmi[now]].pop_back();
			}
		}
		ans+=s.size();
	}
	cout<<ans;
	return 0;
}
