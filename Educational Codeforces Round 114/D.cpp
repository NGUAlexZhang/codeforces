#include <bits/stdc++.h>
using namespace std;
int item[20][250005],ansum,ans[20];
int banned[250005][20];
int main(){
	map<vector<int>,bool>c;
	int n,m;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>item[i][0];
		for(int j=1;j<=item[i][0];j++){
			cin>>item[i][j];
		}
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		vector<int>v(n);
		for(int j=0;j<n;j++) {
			cin>>v[j];
			banned[i][j+1]=v[j];
		}
		c[v]=1;
	}
	int sum=0;
	vector<int>v(n);
	for(int i=1;i<=n;i++){
		sum+=item[i][item[i][0]];
		v[i-1]=item[i][0];
	}
	if(!c[v]){
		for(int i=0;i<v.size();i++){
			cout<<v[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=m;i++){
		sum=0;
		for(int j=1;j<=n;j++){
			sum+=item[j][banned[i][j]];
		}
		for(int j=1;j<=n;j++){
			if(banned[i][j]==1) continue;
			vector<int>ttmp(n);
			for(int k=0;k<n;k++) ttmp[k]=banned[i][k+1];
			ttmp[j-1]--;
			int tmp=sum-(item[j][banned[i][j]]-item[j][banned[i][j]-1]);
			if(tmp>ansum&&!c[ttmp]){
				ansum=tmp;
				for(int k=1;k<=n;k++) ans[k]=banned[i][k];
				ans[j]--;
			}
		}
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
	return 0;
}
