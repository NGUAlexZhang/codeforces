#include <bits/stdc++.h>
using namespace std;
int a[1200][1200],b[1200][1200];
struct Ans{
	int i,j,k;
};
int main(){
	vector<Ans>ans;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++) cin>>a[i][j];
	bool flag=0;
	for(int i=1;i<n;i++){
	for(int j=1;j<m-1;j++){
			if(a[i][j]==b[i][j]) continue;
			b[i][j]=b[i+1][j]=b[i][j+1]=b[i+1][j+1]=a[i][j];
			Ans tmp;tmp.i=i,tmp.j=j,tmp.k=a[i][j];
			ans.push_back(tmp);	
		}
		if(b[i][m]!=a[i][m]){
			Ans tmp;tmp.i=i,tmp.j=m-1,tmp.k=a[i][m];
			ans.push_back(tmp);
			b[i][m-1]=b[i+1][m-1]=b[i][j+1]=b[i+1][j+1]=a[i][j];
			continue;
		}
	}
	if(flag){
		printf("-1");
		return 0;
	}
	cout<<ans.size()<<endl;
	for(auto a:ans) printf("%d %d %d\n",a.i,a.j,a.k);
	return 0;
}
