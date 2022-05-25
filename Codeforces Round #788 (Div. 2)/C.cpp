#include <bits/stdc++.h>
using namespace std;
int a[150000],b[150000],d[150000],fa[150000];
bool used[150000];
const int MOD=1e9+7;
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			fa[i]=i;
			d[i]=0;
			used[i]=0;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			cin>>b[i];
		}
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			used[x]=1;
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==b[i]){
				if(used[a[i]]==0)
				cnt++;
				continue;
			}
			if(find(a[i])==find(b[i])){
				continue;
			}
			if(used[a[i]]||used[b[i]]||used[find(a[i])]||used[find(b[i])]){
				fa[find(a[i])]=find(b[i]);
				used[find(b[i])]=1;
			}
			else
				fa[find(a[i])]=find(b[i]);
		}
		int sum=0;
		for(int i=1;i<=n;i++)
			if(fa[i]==i&&used[i]==0) sum++;
		cout<<cnt<<" "<<sum<<endl;
		sum-=cnt;
		long long ans=1;
		for(int i=1;i<=sum;i++){
			ans*=2;
			ans%=MOD;
		}
		cout<<ans<<endl;
	}
	return 0;
}
