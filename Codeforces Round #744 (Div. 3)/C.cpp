#include <bits/stdc++.h>
using namespace std;
char s[25][25];
bool f[25][25];
int main(){
	int T;
	cin>>T;
	while(T--){
		int n,m,t;
		cin>>n>>m>>t;
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++) cin>>(s[i]+1);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(s[i][j]=='.') continue;
				int k;
				for(k=1;;k++){
					if(j+k>m||j-k<1||i-k<1) break;
					if(s[i-k][j-k]=='.'||s[i-k][j+k]=='.') break;
				}
				k--;
			//	if(i==3&&j==3) cout<<k<<endl;
				if(k<t) continue;
				//cout<<i<<" "<<j<<" "<<k<<endl;
				while(k){
					f[i-k][j-k]=f[i-k][j+k]=1;
					k--;
				}
				f[i][j]=1;
			}
		}
		bool flag=0;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		if(f[i][j]==0&&s[i][j]=='*') {
			flag=1;
			//cout<<i<<" "<<j<<endl;
		}
		if(!flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
