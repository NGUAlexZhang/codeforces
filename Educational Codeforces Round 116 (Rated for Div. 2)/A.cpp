#include <bits/stdc++.h>
using namespace std;
char s[1005];
int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>(s+1);
		int len=strlen(s+1);
		int sum1=0,sum2=0;
		for(int i=1;i<len;i++){
			if(s[i]=='a'&&s[i+1]=='b') sum1++;
			if(s[i]=='b'&&s[i+1]=='a') sum2++;
		}
		if(sum1==sum2){
			//cout<<"111"<<endl;
			cout<<(s+1)<<endl;
			continue;
		}
		sum1=sum2=0;
		if(s[1]=='a') s[1]='b';
		else s[1]='a';
		for(int i=1;i<len;i++){
			if(s[i]=='a'&&s[i+1]=='b') sum1++;
			if(s[i]=='b'&&s[i+1]=='a') sum2++;
		}
		if(sum1==sum2){
			cout<<(s+1)<<endl;
			continue;
		}
		sum1=sum2=0;
		if(s[1]=='a') s[1]='b';
		else s[1]='a';
		if(s[len]=='a') s[len]='b';
		else s[len]='a';
		for(int i=1;i<len;i++){
			if(s[i]=='a'&&s[i+1]=='b') sum1++;
			if(s[i]=='b'&&s[i+1]=='a') sum2++;
		}
		if(sum1==sum2){
			cout<<(s+1)<<endl;
			continue;
		}
	}
	return 0;
}
