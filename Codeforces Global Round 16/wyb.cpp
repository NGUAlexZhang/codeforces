#include <bits/stdc++.h>
using namespace std;
int n,m;
double a[10005],b[10005];
bool check(double x){
	//double cc=(x-7.2500000448<1e-8);
	for(int i=2;i<=n;i++){
		x-=(m+x)/a[i-1];
		//printf("%.10f\n",x);
		if(x<0) return 0;
		x-=(m+x)/b[i];
		//printf("%.10f\n",x);
		if(x<0) return 0;
	}
	x-=(m+x)/a[n];
	if(x<0) return 0;
	x-=(m+x)/b[1];
	//printf("%.10f\n",x);
	if(x<0) return 0;
	return 1;
}
int main(){
	std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];//check(10);
	double l=0,r=2e9,ans=-1;
	while(r-l>1e-6){
		double mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			r=mid;
		}
		else l=mid;
	}
	if(ans==-1) printf("-1");
	else printf("%.10f",ans);
	return 0;
}