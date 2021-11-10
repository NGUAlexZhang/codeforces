#include <bits/stdc++.h>
using namespace std;
int a[150000];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	long long ans=0;
	int cnt1=0,cnt2=0;
	for(int i=1;i<=n;i++){
		if(a[i]>0) ans+=a[i]-1,a[i]=1;
		if(a[i]<0) ans+=-1-a[i],a[i]=-1,cnt1++;
		if(a[i]==0){
			cnt2++;
		}
	}
	if(cnt1%2){
		if(cnt2){
			cout<<ans+cnt2;
		}
		else{
			cout<<ans+2;
		}
	}
	else{
		cout<<ans+cnt2;
	}
	return 0;
}
