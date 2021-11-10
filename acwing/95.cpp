#include <bits/stdc++.h>
using namespace std;
int a[10][10];
int tmp[10][10];
char s[10];
int dx[]={1,-1,0,0},dy[]={0,0,-1,1};
void turn(int x,int y){
	for(int i=0;i<4;i++){
		int tx=x+dx[i],ty=y+dy[i];
		if(tx<1||tx>5||ty<1||ty>5) continue;
		tmp[tx][ty]^=1;
	}
	tmp[x][y]^=1;
}
int main(){
	int T;
	cin>>T;
	while(T--){
	
	int ans=2147483647;
	for(int i=1;i<=5;i++){
		cin>>(s+1);
		for(int j=1;j<=5;j++) a[i][j]=s[j]-'0';
	}
	for(int i=0;i<(1<<5);i++){
		int cnt=0;
		for(int j=1;j<=5;j++) for(int k=1;k<=5;k++) tmp[j][k]=a[j][k];
		for(int j=0;j<5;j++){
			if((i>>j)&1){
				turn(1,j+1);
				cnt++;
			}
		}
		for(int j=2;j<=5;j++){
			for(int k=1;k<=5;k++){
				if(!tmp[j-1][k]){
					turn(j,k);
					cnt++;
				}
			}
		}
		bool flag=0;
		for(int j=1;j<=5;j++)
			if(!tmp[5][j]) flag=1;
		if(!flag) ans=min(ans,cnt);
	}
	if(ans>6) cout<<-1<<endl;
	else cout<<ans<<endl;
}
	return 0;
}
