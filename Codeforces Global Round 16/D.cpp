#include <bits/stdc++.h>
using namespace std;
struct Person{
	int sig,index,id;
}p[1050005];
bool c[95000];
bool cmpIndex(Person a,Person b){
	return a.index<b.index;
}
bool cmpSig(Person a,Person b){
	if(a.sig==b.sig) return a.index>b.index;
	return a.sig<b.sig;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		int n,m;
		cin>>n>>m;
		memset(c,0,sizeof(c));
		for(int i=1;i<=n*m;i++){
			cin>>p[i].sig;
			p[i].index=i;
		}
		sort(p+1,p+1+n*m,cmpSig);
		for(int i=1;i<=n*m;i++) p[i].id=i;
		sort(p+1,p+1+n*m,cmpIndex);
		long long ans=0;
		for(int i=1;i<=n*m;i++){
			int id=p[i].id;
			int line=id/m;
			if(id%m==0) line--;
			for(int j=line*m+1;j<=id;j++){
				//cout<<i<<" "<<j<<endl;
				if(c[j]) {
					ans++;
				}
			}
		//	cout<<id<<endl;
			c[id]=1;
		}
		cout<<ans<<endl;
	}
	return 0;
}