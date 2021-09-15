#include <bits/stdc++.h>
using namespace std;
char s[1005];
int a[1005],b[1005];
int main(){
	int T;
	cin>>T;
	while(T--){
		int len;
		cin>>len;
		cin>>(s+1);
		for(int i=1;i<=len;i++){
			a[i]=a[i-1],b[i]=b[i-1];
			if(s[i]=='a') a[i]++;
			if(s[i]=='b') b[i]++;
		}
		bool flag=0;
		for(int i=1;i<=len;i++){
		if(flag) break;
		for(int j=i+1;j<=len;j++){
			if(a[j]-a[i-1]==b[j]-b[i-1]){
				cout<<i<<" "<<j<<endl;
				flag=1;
				break;
			}
		}
	}
		if(!flag) cout<<"-1 -1"<<endl;
	}
	return 0;
}