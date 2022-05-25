#include <bits/stdc++.h>
using namespace std;
char s[100];
int a[100],b[100];
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>(s+1);
			int len=strlen(s+1);
			a[i]=s[len]-'0';
			if(a[i]==1||a[i]==2) a[i]=1;
			else a[i]=0;
		}
		for(int i=1;i<=n;i++){
			cin>>(s+1);
			int len=strlen(s+1);
			b[i]=s[len]-'0';
			if(b[i]==1||b[i]==2) b[i]=1;
			else b[i]=0;
		}
		int flag=0;
		for(int i=1;i<=n;i++){
			if(!(a[i]^b[i])) flag=1;
		}
		if(a[n]==1) flag=1;
		if(flag) cout<<"NO\n";
		else cout<<"YES\n";
	}
	return 0;
}
