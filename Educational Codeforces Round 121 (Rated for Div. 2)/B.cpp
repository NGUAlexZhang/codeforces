#include <bits/stdc++.h>
using namespace std;
char s[250000];
int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>(s+1);
		int len=strlen(s+1);
		bool flag=0;
		for(int i=1;i<len;i++){
			int num=s[i]+s[i+1]-'0'-'0';
			if(num>=10) flag=1;
		}
		if(flag){
			for(int i=len;i>=1;i--){
				int num=s[i]+s[i-1]-'0'-'0';
				if(num>=10){
					s[i-1]='1';
					s[i]=num%10+'0';
					break;
				}
			}
			cout<<s+1;
		}
		else{
			s[2]+=s[1]-'0';
			cout<<s+2;
		}
		puts("");
	}
	return 0;
}
