#include <bits/stdc++.h>
using namespace std;
char s[1006];
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		cin>>(s+1);
		for(int i=1;i<=n;i++){
			if(s[i]=='L'||s[i]=='R'){
				cout<<s[i];
				continue;
			}
			if(s[i]=='U') cout<<"D";
			if(s[i]=='D') cout<<"U";
		}
		cout<<endl;
	}
	return 0;
}