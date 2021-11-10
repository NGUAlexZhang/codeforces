#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	int T,cnt=0;
	cin>>T;
	while(T--){
		double a,b,R;
		cin>>a>>b>>R;
		double ans=0;
		if(b<=R){
			ans=2*a-R;
		}
		else{
			ans+=sqrt(a*a+(b-R)*(b-R));
			ans+=sqrt(a*a+(b-R)*(b-R))-R;
		}
		printf("Case #%d: %.2f",++cnt,ans);
		if(T) cout<<endl; 
	}
	return 0;
}