#include <bits/stdc++.h>
using namespace std;
char s[1005];
char ans[100][100];
int main(){
	int T;
	cin>>T;
	while(T--){
		int len;
		cin>>len;
		cin>>(s+1);
		int cnt=0;
		for(int i=1;i<=len;i++)
			if(s[i]=='2') cnt++;
		if(cnt==1||cnt==2){
			cout<<"NO"<<endl;
			continue;
		}
		for(int i=1;i<=len;i++) for(int j=1;j<=len;j++) if(i==j) ans[i][j]='X';else ans[i][j]='=';
		for(int i=1;i<=len;i++){
			if(s[i]=='1') continue;
			//cout<<i<<endl;
			int flag=0;
			for(int j=i+1;j<=len;j++){
				if(s[j]=='1') continue;
				flag=1;
				ans[i][j]='+',ans[j][i]='-';
				cout<<i<<" "<<j<<endl;
				break;
			}
			if(flag) continue;
			for(int j=1;j<=len;j++){
				if(s[j]=='1') continue;
				ans[i][j]='+',ans[j][i]='-';
				break;
			}
			
		}
		for(int i=1;i<=len;i++){
			for(int j=1;j<=len;j++){
				cout<<ans[i][j];
			}
			cout<<endl;
		}
	}
	return 0;
}