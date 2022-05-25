#include <bits/stdc++.h>
using namespace std;
char s[150000],c[100];
int a[150000];
int main(){
	int T;
	cin>>T;
	while(T--){
		int n,k;
		cin>>n;
		cin>>(s+1);
		cin>>k;
		for(int i=1;i<=k;i++) cin>>c[i];
		for(int i=1;i<=n;i++){
			bool yes=0;
			for(int j=1;j<=k;j++)
				if(c[j]==s[i]) yes=1;
			if(yes) a[i]=1;
			else a[i]=0;
		}
		int cnt=0,ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]){
				ans=max(ans,cnt);
				cnt=1;
			}
			else cnt++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
