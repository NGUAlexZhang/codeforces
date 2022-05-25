#include <bits/stdc++.h>
using namespace std;
int n,sum1[1000050],sum2[1000050];
char s[1000050];
int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		cin>>(s+1);
		vector<int>loc;
		for(int i=1;i<=n;i++){
			if(s[i]=='a') loc.push_back(i);
		}
		for(int i=1;i<=n;i++){
			sum1[i]=sum1[i-1],sum2[i]=sum2[i-1];
			if(s[i]=='b') sum1[i]++;
			if(s[i]=='c') sum2[i]++;
		}
		int ans=2147483647;
		for(auto i=1;i<loc.size();i++){
			if(sum1[loc[i]]-sum1[loc[i-1]]<2&&sum2[loc[i]]-sum2[loc[i-1]]<2){
				ans=min(ans,loc[i]-loc[i-1]+1);
			}
		}
		for(auto i=0;i+2<loc.size();i++){
			if(sum1[loc[i+2]]-sum1[loc[i]]<3&&sum2[loc[i+2]]-sum2[loc[i]]<3){
				ans=min(ans,loc[i+2]-loc[i]+1);
			}
		}
		if(ans==2147483647) cout<<-1<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}
