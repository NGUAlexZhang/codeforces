#include <bits/stdc++.h>
using namespace std;
int a[100][100],b[100][100];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++) cin>>a[i][j];
	vector<pair<int,int>>ans;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i+1>n||j+1>m) continue;
			if(a[i][j]&&a[i+1][j]&&a[i][j+1]&&a[i+1][j+1]){
				b[i][j]=b[i+1][j]=b[i][j+1]=b[i+1][j+1]=1;
				ans.push_back(make_pair(i,j));
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]!=b[i][j]){
				cout<<-1;
				return 0;
			}
		}
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}
	return 0;
}
