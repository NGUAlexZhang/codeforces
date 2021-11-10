#include <bits/stdc++.h>
using namespace std;
char s1[102005],s2[104005];
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		cin>>(s1+1);
		cin>>(s2+1);
		long long ans=0;
		for(int i=1;i<=n;i++){
			bool e0=s1[i]=='0'||s2[i]=='0',e1=s1[i]=='1'||s2[i]=='1';
			if(e0&&e1) ans+=2;
			if(e0&&!e1) ans++;
		}
		int las=0;
		for(int i=1;i<=n;i++){
			bool e0=s1[i]=='0'||s2[i]=='0',e1=s1[i]=='1'||s2[i]=='1';
			if(e0&&!e1){
				if(i-1>0&&s1[i-1]=='1'&&s2[i-1]=='1'&&las!=i-1) {
					las=i-1;
					ans++;
					continue;
				}
				if(i+1<=n&&s1[i+1]=='1'&&s2[i+1]=='1'&&las!=i+1){
					las=i+1;
					ans++;
					continue;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}