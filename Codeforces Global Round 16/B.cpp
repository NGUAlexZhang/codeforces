#include <bits/stdc++.h>
using namespace std;
char s[105005];
int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>(s+1);
		int len=strlen(s+1);
		long long ans=0;
		int cnt=0;
		for(int i=1;i<=len;i++){
			if(s[i]=='0'){
				cnt++;
				continue;
			}
			if(cnt)
				ans++;
			cnt=0;
		}
		if(cnt) ans++;
		if(ans>2)
			cout<<2<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}