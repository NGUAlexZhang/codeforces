#include <bits/stdc++.h>
using namespace std;
struct Per{
	int a,index,id;
}per[1000005];
bool cmp(Per a,Per b){
	if(a.a==b.a) return a.index<b.index;
	return a.a<b.a;
}
bool cmp2(Per a,Per b){
	return a.index<b.index;
}
int n;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>per[i].a;
		per[i].index=i;
	}
	sort(per+1,per+1+n,cmp);
	for(int i=1;i<=n;i++){
		per[i].id=i;
	}
	sort(per+1,per+1+n,cmp2);
	int maxn=0,ans=0;
	for(int i=1;i<=n;i++){
		maxn=max(maxn,per[i].id);
		if(maxn==i) ans++;
	}
	cout<<ans;
	return 0;
}
