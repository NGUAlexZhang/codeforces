#include <bits/stdc++.h>
using namespace std;
double a[150000];
int n,f;
bool check(double x){
	double minn=2147483647;
	for(int i=1;i<=n;i++){
		if(i-f<0) continue;
		minn=min(a[i-f]-(i-f)*x,minn);
		if(minn<=a[i]-i*x) return 1;
	}
	return 0;
}
int main(){
	cin>>n>>f;
	double r=-1,l=2001;
	for(int i=1;i<=n;i++){
		scanf("%lf",a+i);
		l=min(a[i],l),r=max(a[i],r);
		a[i]+=a[i-1];
	}
	double ans=0;
	while(r-l>=1e-5){
		double mid=(l+r)/2;
		if(check(mid)) l=mid;
		else r=mid;
	}
	printf("%d",(int)(r*1000));
	return 0;
}
