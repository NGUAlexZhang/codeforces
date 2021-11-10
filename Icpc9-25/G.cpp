#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200005],b[200005],c[200005],ans1[200005],ans2[200005],tmp1[200005],tmp2[200005];
ll gcd(ll a,ll b){
	if(!b) return a;
	return gcd(b,a%b);
}
int main(){
	int n;
	ll t;
	cin>>n>>t;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	for(int i=1;i<=n;i++) c[i]=a[i]*b[i];
	ans2[0]=1,ans2[1]=b[1];
	ans1[0]=a[1]*b[1];	
	for(int i=1;i<n;i++){
		for(int j=0;j<=t-1;j++){
			tmp1[j]=ans2[j]*c[i+1];
			//cout<<tmp1[j]<<" ";
		}
		//cout<<endl;
		for(int j=t-1;j>=1;j--){
			ans1[j]+=ans1[j-1]*b[i+1];
			//cout<<ans1[j]<<" ";
		}
	//	cout<<endl;
		for(int j=0;j<=t-1;j++) ans1[j]+=tmp1[j];
		for(int j=t-1;j>=1;j--){
			ans2[j]+=ans2[j-1]*b[i+1];
			//cout<<ans2[j]<<" ";
		}
		//cout<<endl;
	}
	/*for(int i=0;i<=t-1;i++){
		cout<<ans1[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<=t-1;i++)
		cout<<ans2[i]<<" ";
	cout<<endl;*/
	for(int i=0;i<t-1;i++)
		if(ans1[i]){
			cout<<"infinity";
			return 0;
		}
	
	int g=gcd(ans1[t-1],t);
	if(g==t){
		cout<<ans1[t-1]/t;
		return 0;
	}
	cout<<ans1[t-1]/g<<"/"<<t/g;
	return 0;
}
