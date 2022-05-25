#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[100005];
int main(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	//for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	//cout<<endl;
	int las=1,now=2,ans=0;
	int cnt1=1,cnt2=1;
	while(now<=n){
		while(now<=n&&a[now]-a[las]<k) now++;
		if(now>n) break;
		//cout<<now<<endl;
		cnt1++;
		las=now;
		now++;
	}
	las=n,now=n-1;
	while(now>=1){
		while(now>=1&&a[las]-a[now]<k) now--;
		if(now<1) break;
		cnt2++;
	//	cout<<now<<" "<<a[now]<<" "<<a[las]<<endl;
		las=now;
		now--;
	}
	//cout<<cnt1<<" "<<cnt2<<endl;
	cout<<max(cnt1,cnt2);
	return 0;
}

