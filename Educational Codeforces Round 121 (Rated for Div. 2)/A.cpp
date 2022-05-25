#include <bits/stdc++.h>
using namespace std;
char s[100];
int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>(s+1);
		int len=strlen(s+1);
		map<int,int>cnt;
		for(int i=1;i<=len;i++){
			cnt[s[i]-'a'+1]++;
		}
		for(int i=1;i<=26;i++){
			if(cnt[i]==0) continue;
			printf("%c",i+'a'-1);
			if(cnt[i]==2) printf("%c",i+'a'-1);
		}
		puts("");
	}
	return 0;
}
