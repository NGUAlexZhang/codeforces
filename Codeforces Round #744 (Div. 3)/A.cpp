#include <bits/stdc++.h>
using namespace std;
char s[100];
int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>(s+1);
		int len=strlen(s+1);
		int a=0,b=0,c=0;
		for(int i=1;i<=len;i++){
			if(s[i]=='A') a++;
			if(s[i]=='B') b++;
			if(s[i]=='C') c++;
		}
		//cout<<a<<" "<<b<<" "<<c<<endl;
		if(b==a+c){
			puts("YES");
		}
		else puts("NO");
	}
	return 0;
}
