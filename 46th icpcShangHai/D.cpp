#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool check(ll x){
	ll tmp=sqrt(x);
	//cout<<tmp<<endl;
	if(tmp*tmp!=x) return 0;
	return 1;
}
ll gcd(ll a,ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}
int main(){
	int T;
	//cout<<check(253)<<endl;
	cin>>T;
	while(T--){
		ll p,q;
		cin>>p>>q;
		ll g=gcd(p,q);
		p/=g,q/=g;
		//cout<<p<<" "<<q<<endl;
		ll dert=p*p-4*q*q;
		//cout<<dert<<endl;
		if(dert<0||check(dert)==0){
			cout<<"0 0\n";
			continue;	
		}
		ll d1=sqrt(dert);
		ll x=p+d1;
		if(x%2==0&&check(x/2)){
			ll ans1=sqrt(x/2);
			if(q%ans1==0){
				ll ans2=q/ans1;
				g=gcd(ans1,ans2);
				if(ans1/g<=1e9&&ans2/g<=1e9){
					cout<<min(ans1/g,ans2/g)<<" "<<max(ans1/g,ans2/g)<<endl;
					continue;
				}
			}
		}
		x=p-d1;
		if(x>0&&x%2==0&&check(x/2)){
			ll ans1=sqrt(x/2);
			if(q%ans1==0){
				ll ans2=q/ans1;
				g=gcd(ans1,ans2);
				if(ans1/g<=1e9&&ans2/g<=1e9){
					cout<<min(ans1/g,ans2/g)<<" "<<max(ans1/g,ans2/g)<<endl;
					continue;
				}
			}
		}
		cout<<"0 0\n";
	}
	return 0;
}
//1234565432100 1234566543210 
