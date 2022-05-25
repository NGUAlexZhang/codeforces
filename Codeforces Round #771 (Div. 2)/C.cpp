#include <bits/stdc++.h>
using namespace std;
int a[150000],loc[150000];
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			loc[a[i]]=i;
		}
		int ans=0,cnt=0,now=0,flag=0;
		for(int i=1;i<=n;i++){
			if(loc[i]>now){
				//cout<<now<<"  "<<cnt<<endl;
				if(now==cnt) ans++;
				cnt++;
				now=loc[i];
			}
			else cnt++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
