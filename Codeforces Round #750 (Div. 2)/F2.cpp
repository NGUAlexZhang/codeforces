#include <bits/stdc++.h>
using namespace std;
const int MAXN=(1<<13)-1;
vector<int>g[MAXN+5];
int r[MAXN+5];
bool ans[MAXN+5];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<=MAXN;i++){
		g[i].push_back(0);
		r[i]=MAXN;
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j:g[x]){
			int to=j^x;
			ans[to]=1;
			while(r[to]>x){
				g[r[to]].push_back(to);
				r[to]--;
			}
		}
		g[x].clear();
	}
	int tot=0;
	for(int i=1;i<=MAXN;i++) tot+=ans[i];
	cout<<tot+1<<endl;
	cout<<0<<" ";
	for(int i=1;i<=MAXN;i++)
		if(ans[i]) cout<<i<<" ";
	return 0;
}
