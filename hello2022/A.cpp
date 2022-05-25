#include <bits/stdc++.h>
using namespace std;
char s[100][100];
int main(){
	int T;
	cin>>T;
	while(T--){
		int k,n;
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) s[i][j]='.';
		int now=1,flag=0;
		for(int i=1;i<=k;i++){
			if(now>n){
				puts("-1");
				flag=1;
				break;
			}
			s[now][now]='R';
			now+=2;
		}
		if(flag) continue;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) cout<<s[i][j];
			puts("");
		}
	}
	return 0;
}
