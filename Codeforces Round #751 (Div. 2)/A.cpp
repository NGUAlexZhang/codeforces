#include <bits/stdc++.h>
using namespace std;
char s[1005];
int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>(s+1);
		int len=strlen(s+1);
		int index=1;
		char minn=s[1];
		for(int i=1;i<=len;i++){
			if(minn>s[i]){
				minn=s[i];
				index=i;
			}
		}
		cout<<minn<<" ";
		for(int i=1;i<=len;i++){
			if(i==index) continue;
			cout<<s[i];
		}
		cout<<endl;
	}
	return 0;
}
