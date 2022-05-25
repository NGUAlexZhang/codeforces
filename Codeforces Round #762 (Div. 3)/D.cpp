#include <bits/stdc++.h>
using namespace std;
int m,n;
bool check(vector<vector<int>>a,int x){
	for(int i=1;i<=n;i++){
		int tmp=0;
		for(int j=1;j<=m;j++) tmp=max(tmp,a[j][i]);
		if(tmp<x) return 0;
	}
	for(int i=1;i<=m;i++){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(a[i][j]>=x) cnt++;
		}
		if(cnt>=2) return 1;
	}
	return 0;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		
		cin>>m>>n;
		vector<vector<int>>a(m+10,vector<int>(n+10));
		
		for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
		int l=0,r=1e9;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(a,mid)) l=mid+1;
			else r=mid-1;
		}
		cout<<l-1<<endl;
	}
	return 0;
}
