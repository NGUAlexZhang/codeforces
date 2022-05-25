#include <bits/stdc++.h>
using namespace std;
char s[10005];
int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>(s+1);
		int len=strlen(s+1);
		if((s[len]-'0')%2==0){
			cout<<0<<endl;
			continue;
		}
		if((s[1]-'0')%2==0){
			cout<<1<<endl;
			continue;
		}
		bool flag=0;
		for(int i=1;i<=len;i++){
			if((s[i]-'0')%2==0) flag=1;
		}
		if(flag) cout<<2<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}
