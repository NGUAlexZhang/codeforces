#include <bits/stdc++.h>
using namespace std;
int n,m,p[355000];
bool check(int index){
	vector<int>v;
	v.push_back(0);
	for(int i=index+1;i<=n;i++) v.push_back(p[i]);
	for(int i=1;i<=index;i++) v.push_back(p[i]);
	int tot=0;
	map<int,int>nxt;
	map<int,bool>used;
	for(int i=1;i<=n;i++){
		nxt[i]=v[i];
	}
	for(int i=1;i<=n;i++){
		if(used[i]) continue;
		tot++;
		int now=nxt[i];
		while(!used[now]){
			used[now]=1;now=nxt[now];
		}
	}
	return n-tot<=m;
}
void solve(){
	map<int,int>cnt;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		cnt[(i-p[i]+n)%n]++;
	}
	vector<int>ans;
	for(int i=0;i<n;i++){
		if(n-2*m<=cnt[i]&&check(i)) ans.push_back(i);
	}
	cout<<ans.size();
	for(auto i:ans) cout<<" "<<i;
	cout<<endl;
}
int main(){
	int a=2147483648;
	cout<<a;
	int T;
	cin>>T;
	while(T--)
		solve();
	return 0;
}
