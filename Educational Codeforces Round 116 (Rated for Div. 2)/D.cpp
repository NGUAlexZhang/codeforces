#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin>>T;
	while(T--){
		int n,m;
		bool yes=0;
		scanf("%d%d",&n,&m);
		vector<vector<int>>a(n+5,vector<int>(m+5));
		vector<vector<int>>max1(n+5,vector<int>(m+5,-1));
		vector<vector<int>>max2(n+5,vector<int>(m+5,-1));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++) max1[i][j]=max(max1[i][j-1],a[i][j]);
			for(int j=m;j>=1;j--) max2[i][j]=max(max2[i][j+1],a[i][j]);
		}
		for(int k=1;k<m;k++){
			int maxn1=-1,maxn2=-1,tar=-1;
			vector<int>v1,v2;
			map<int,bool>check;
			bool flag=0;
			vector<char>ans(n+5,'B');
			for(int i=1;i<=n;i++) maxn1=max(maxn1,max1[i][k]),maxn2=max(maxn2,max2[i][k+1]);
			for(int i=1;i<=n;i++)
				if(maxn1==max1[i][k])
					ans[i]='R';
			for(int i=1;i<=n;i++)
				if(maxn2==max2[i][k+1]&&ans[i]=='R'){
					flag=1;
					break;
				}
			if(flag) continue;
			yes=1;
			cout<<"YES\n";
			for(int i=1;i<=n;i++) cout<<ans[i];
			cout<<" "<<k<<endl;
			break;
		}
		if(yes==0){
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
