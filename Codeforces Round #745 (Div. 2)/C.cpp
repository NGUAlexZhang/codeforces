#include <bits/stdc++.h>
using namespace std;
char s[500][500];
int a[500][500],b[500][500],sum[500][500];
int get1(int x1,int y1,int x2,int y2){
	return sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
}
int get0(int x1,int y1,int x2,int y2){
	return (x2-x1+1)*(y2-y1+1)-(sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1]);
}
int getSum(int x1,int y1,int x2,int y2){
	int res=0;
	res+=get1(x1+1,y1+1,x2-1,y2-1);
	//cout<<res<<endl;
	res+=get0(x1+1,y1,x2-1,y1);
	//cout<<res<<endl;
	res+=get0(x1+1,y2,x2-1,y2);//cout<<res<<endl;
	res+=get0(x1,y1+1,x1,y2-1);//cout<<res<<endl;
	res+=get0(x2,y1+1,x2,y2-1);
	//cout<<res<<endl;
	return res;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			cin>>(s[i]+1);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+(s[i][j]=='1');
			}
		}
		int ans=2147483647;
		for(int l=1;l<=m;l++){
			for(int r=l+3;r<=m;r++){
				for(int k=5,now=1;k<=n;k++){
					int nxt=k-4;
					int v1=getSum(now,l,k,r);
					int v2=getSum(nxt,l,k,r);
					if(v1>v2){
						now=nxt;
						v1=v2;
					}
					ans=min(ans,v1);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}