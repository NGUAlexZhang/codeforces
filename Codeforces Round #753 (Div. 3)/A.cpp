#include <bits/stdc++.h>
using namespace std;
char s[100005],s2[100005];
int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>(s+1);
		map<char,int>loc;
		int len=strlen(s+1);
		for(int i=1;i<=len;i++){
			loc[s[i]]=i;
		}
		cin>>(s2+1);
		len=strlen(s2+1);
		int ans=0;
		for(int i=2;i<=len;i++){
			ans+=abs(loc[s2[i]]-loc[s2[i-1]]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
