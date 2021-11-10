#include <bits/stdc++.h>
using namespace std;
struct Cow{
	int maxx,minn;
}c[2505];
struct Med{
	int spf,sum;
}med[2505];
bool cmp(Cow a,Cow b){
	if(a.minn==b.minn) return a.maxx>b.maxx; 
	return a.minn>b.minn;
}
bool cmp2(Med a,Med b){
	return a.spf>b.spf;
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>c[i].minn>>c[i].maxx;
	sort(c+1,c+1+n,cmp);
	for(int i=1;i<=m;i++){
		cin>>med[i].spf>>med[i].sum;
	}
	sort(med+1,med+1+m,cmp2);
	int ans=0;
	for(int i=1;i<=n;i++){
		bool flag=0;
		for(int j=1;j<=m;j++){
//			cout<<c[i].minn<<" "<<c[i].maxx<<" "<<a[j]<<endl;
			if(med[j].spf>=c[i].minn&&med[j].spf<=c[i].maxx&&med[j].sum){
				flag=1;
				med[j].sum--;
				break;
			}
		}
		if(flag) ans++;
	}
	cout<<ans; 
	return 0;
}
