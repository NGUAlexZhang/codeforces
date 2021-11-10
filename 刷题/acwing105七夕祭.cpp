#include <bits/stdc++.h>
using namespace std;
int n,m,t;
int x[150000],y[150000];
long long ans;
void solve1(){
	int tmp[150000];
	tmp[0]=0;
	for(int i=1;i<=n;i++){
		tmp[i]=0;
		tmp[i]=tmp[i-1]+t/n-x[i];
	}
	sort(tmp+1,tmp+1+n);
	for(int i=1;i<=n;i++){
		ans+=abs(tmp[n/2+1]-tmp[i]);
	}
}
void solve2(){
	int tmp[150000];
	tmp[0]=0;
	for(int i=1;i<=m;i++){
		tmp[i]=0;
		tmp[i]=tmp[i-1]+t/m-y[i];
	}
	sort(tmp+1,tmp+1+m);
	for(int i=1;i<=m;i++){
//		cout<<tmp[i]<<" ";
		ans+=abs(tmp[m/2+1]-tmp[i]);
	}
	//cout<<endl;
}
int main(){
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1;i<=t;i++){
		int xx,yy;
		cin>>xx>>yy;
		x[xx]++,y[yy]++;
	}
	if((t%n)&&(t%m)){
		cout<<"impossible";
		return 0;
	}
	if(!(t%n)&&!(t%m)) cout<<"both";
	else if(!(t%n)) cout<<"row";
	else cout<<"column";
	cout<<" ";
	if(!(t%n)){
		solve1();
	}
	if(!(t%m)){
		solve2();
	}
	cout<<ans;
	return 0;
}
