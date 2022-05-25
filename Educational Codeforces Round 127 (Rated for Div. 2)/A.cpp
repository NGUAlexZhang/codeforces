#include <bits/stdc++.h>
using namespace std;
char s[1500];
int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>(s+1);
		int len=strlen(s+1);
		bool flag=0;
		if(s[1]!=s[2]) flag=1;
		if(s[len]!=s[len-1]) flag=1;
		for(int i=2;i<len;i++){
			if(s[i]!=s[i-1]&&s[i]!=s[i+1]){
				flag=1;
			}
		}
		if(flag) puts("NO");
		else puts("YES");
	}
	return 0;
}
