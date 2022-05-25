#include <bits/stdc++.h>
using namespace std;
struct Person{
	int s,a;
}per[550000];
bool cmp(Person a,Person b){
	if(max(a.s,a.a)==max(b.s,b.a)){
		return a.s<b.s;
	}
	return  max(a.s,a.a)<max(b.a,b.s);
}
int n,d;
int main(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>per[i].s>>per[i].a;
	}
	sort(per+1,per+1+n,cmp);
	int ans=0;
	for(int i=1;i<=n;i++){
		cout<<per[i].s<<" "<<per[i].a<<" "<<d<<endl;
		if(per[i].s>=d) ans++;
		d=max(per[i].a,d);
	}
	cout<<ans;
	return 0;
}
