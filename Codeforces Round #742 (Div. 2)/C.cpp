#include <bits/stdc++.h>
using namespace std;
char s[1005];
int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>(s+1);
		int a=0,b=0;
		int len=strlen(s+1);
		for(int i=1;i<=len;i+=2){
			a=a*10+(s[i]-'0');
		}
		for(int i=2;i<=len;i+=2){
			b=b*10+(s[i]-'0');
		}
		long long ans=(a+1)*(b+1)-2;
		cout<<ans<<endl;
	}
	return 0;
}
/*
031030
100204


131234
113
13 100
324
24 300
*/