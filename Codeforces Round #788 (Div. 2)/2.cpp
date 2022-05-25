#include <bits/stdc++.h>
using namespace std;
char s[150][150];
int main(){
	int h,w;
	cin>>h>>w;
	for(int i=1;i<=h;i++)
		cin>>(s[i]+1);
	map<int,bool>m1;
	map<int,bool>m2;
	for(int i=1;i<=h;i++){
		int flag=0;
		for(int j=1;j<=w;j++){
			if(s[i][j]=='#') flag=1;
		}
		if(flag==0) m1[i]=true;
	}
	for(int i=1;i<=w;i++){
		int flag=0;
		for(int j=1;j<=h;j++){
			if(s[j][i]=='#') flag=1;
		}
		if(flag==0) m2[i]=true;
	}
	for(int i=1;i<=h;i++){
		if(m1[i]) continue;
		
		bool flag=0;
		for(int j=1;j<=w;j++){
			if(m2[j]) continue;
			cout<<s[i][j];
			flag=1;
		}
		if(flag) puts("");
	}
	return 0;
}
