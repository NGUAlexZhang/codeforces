#include <bits/stdc++.h>
using namespace std;
char s[250000];
int lst[100];
//int dp[250000][2];
int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>(s+1);
		int len=strlen(s+1);
		for(int i=0;i<=26;i++) lst[i]=0;
		int cnt=0,ans=0;
		for(int i=1;i<=len;i++){
			int num=s[i]-'a'+1;
			if(lst[num]){
				cnt++;
				ans+=cnt-2;
				for(int j=1;j<=26;j++) lst[j]=0;
				cnt=0;
			}
			else{
				cnt++;
				lst[num]=i;
			}
		}
		cout<<ans+cnt<<endl;
	}
	return 0;
}
