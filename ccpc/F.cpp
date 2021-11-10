#include <bits/stdc++.h>
#define ll long long
const ll MOD=998244353;
using namespace std;
ll a[15];
char s[100006];
int main(){
	int T;
	cin>>T;
	while(T--){
		ll ans=0;
		for(int i=1;i<=9;i++) a[i]=0;
		scanf("%s",s+1);
		int len=strlen(s+1);
		for(int i=1;i<=len;i++){
			if(s[i]=='n'){
				a[3]+=a[2];
				a[1]++;
			}
			if(s[i]=='u') a[2]+=a[1];
			if(s[i]=='e'){
				a[5]+=a[4];
				a[8]+=a[7];
			}
			if(s[i]=='h'){
				a[9]+=a[8];
				a[7]+=a[6];
				a[6]+=a[5];
				a[4]+=a[3];
			}
			if(s[i]=='a'){
				ans+=(ans+a[9]);
				ans%=MOD;
			}
			for(int i=1;i<=9;i++) a[i]%=MOD;
		}
		cout<<ans<<endl;
	}
	return 0;
}
