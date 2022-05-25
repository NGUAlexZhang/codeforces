#include <bits/stdc++.h>
using namespace std;
char s[150000];
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		cin>>(s+1);
		int p;
		if(n%2){
			p=n/2+2;
		}
		else{
			p=(n/2)+1;
		}
		int cnt=0;
		while(p<=n){
			if(s[p]!=s[p-1]) break;
			cnt++;
			p++;
		}
		cnt<<=1;
		if(n%2) cnt++;
		cout<<cnt<<endl;
	}
	return 0;
}
