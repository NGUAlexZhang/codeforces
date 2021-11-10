#include <bits/stdc++.h>
#define ll long long
using namespace std;
char s[200005];
char tmp[200005];
int main(){
	int T;
	cin>>T;
	while(T--){
		int n,ans=2147483647;
		cin>>n;
		cin>>(s+1);
		map<char,int>m;
		for(int i=1;i<=n;i++){
			m[s[i]]++;
		}
		/*int l=1,r=n,flag=0;
		while(l<=r){
			if(s[l]!=s[r]) flag=1;
			l++,r--;
		}
		if(!flag){
			//cout<<"111";
			cout<<0<<endl;continue;
		}*/
		for(int i=0;i<26;i++){
			char c=i+'a';
			int l=1,r=n,flag=0,sum=0;
			while(l<=r){
				if(s[l]==s[r]){
					l++,r--;continue;
				}
				if(s[l]!=c&&s[r]!=c){
					flag=1;break;
				}
				while(s[l]==c&&l<r)l++,sum++;
				while(s[r]==c&&l<r)r--,sum++;
				if(s[l]!=s[r]){
					flag=1;break;
				}
				l++,r--;
			}
			if(!flag) ans=min(ans,sum);
		}
		if(ans==2147483647) cout<<-1<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}
/*
hyyhhyhy
*/