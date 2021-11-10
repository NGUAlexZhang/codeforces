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
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=(s[i]-'0');
		}
		for(int i=1;i<n;i++){
			if(s[i]-'0'!=0) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
