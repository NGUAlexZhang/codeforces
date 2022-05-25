#include <bits/stdc++.h>
using namespace std;
char s[1005];
int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>(s+1);
		int len=strlen(s+1);
		if(len%2){
			cout<<"NO\n";
			continue;
		}
		int flag=0;
		for(int i=1;i<=len/2;i++){
			if(s[i]!=s[i+len/2]) flag=1;
		}
		if(flag) cout<<"NO\n";
		else cout<<"YES\n";
	}
	return 0;
}
