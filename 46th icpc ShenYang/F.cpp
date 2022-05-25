#include <bits/stdc++.h>
using namespace std;
int n,cnt[2000],G[100];
char s[2000];
string ans="";
void getG(int len){
	cnt[len+1]=0;
	map<char,bool>m;
	for(int i=len;i>=1;i--){
		cnt[i]=cnt[i+1];
		if(!m[s[i]]){
			m[s[i]]=1;
			cnt[i]++;
		}
	}
	for(int i=1;i<=26;i++) G[i]=0;
	for(int i=1;i<=26;i++){
		for(int j=len;j>=1;j--){
			if(s[j]=='a'+i-1){
				G[i]=cnt[j+1];
				break;
			}
		}
	}
}
int main(){
	cin>>n;
	cin>>(s+1);
	for(int len=1;len<=n;len++){
		getG(len);
		string tmp="";
		for(int i=1;i<=len;i++){
			int index=G[s[i]-'a'+1]+1;
			char c='a'+index-1;
			tmp+=c;
		}
		ans=max(ans,tmp);
	}
	cout<<ans;
	return 0;
}
