#include <bits/stdc++.h>
using namespace std;
char s[10005];
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		cin>>(s+1);
		bool flag1=0,flag2=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='a') flag1=1;
			if(s[i]=='b') flag2=1;
		}
		if(!flag1||!flag2){
			cout<<"-1 -1"<<endl;
			continue;
		}
		for(int i=1;i<n;i++){
			if(s[i]!=s[i+1]){
				cout<<i<<" "<<i+1<<endl;
				break;
			}
		}
	}
	return 0;
}
