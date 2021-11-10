#include <bits/stdc++.h>
using namespace std;
struct Seg{
	double l,r;
}e[1500];
bool cmp(Seg a,Seg b){
	return a.l>b.l;
}
int main(){
	int n;
	double d;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		double x,y;
		cin>>x>>y;
		if(y>d){
			cout<<-1;
			return 0;
		}
		double tmp=sqrt(d*d-y*y);
		e[i].l=x-tmp,e[i].r=x+tmp;
	}
	sort(e+1,e+1+n,cmp);
	int ans=0;
	double now=2147483647;
	for(int i=1;i<=n;i++){
		if(e[i].r>=now){
			continue;
		}
		now=e[i].l;
		ans++;
	}
	cout<<ans;
	return 0;
}
