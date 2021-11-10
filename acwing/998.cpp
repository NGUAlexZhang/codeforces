#include <bits/stdc++.h>
using namespace std;
struct Ope{
	int num[35];
	int kind;
}op[150000];
int n,m,binm[35],ans[35];
int cal(int x,int index){
	for(int i=1;i<=n;i++){
		if(op[i].kind==1) x&=op[i].num[index];
		if(op[i].kind==2) x|=op[i].num[index];
		if(op[i].kind==3) x^=op[i].num[index];
	}
	return x;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		string opt;
		int x;
		cin>>opt>>x;
		if(opt=="AND") op[i].kind=1;
		if(opt=="OR") op[i].kind=2;
		if(opt=="XOR") op[i].kind=3;
		int cnt=0;
		while(x){
			op[i].num[++cnt]=x&1;
			x>>=1;
		}
	}
	{
		int cnt=0;
		while(m){
			binm[++cnt]=m&1;
			m>>=1;
		}
	}
	int flag=0;
	for(int i=32;i>=1;i--){
		int ans1=cal(0,i);
		int ans2=0;
		int opt=0;
		if(flag||binm[i]==1){
			ans2=cal(1,i);
		}
		if(ans1>=ans2){
			opt=0;
		}else opt=1;
		ans[i]=max(ans1,ans2);
		if(opt<binm[i]) flag=1;
	}
	int fans=0;
	for(int i=1;i<=32;i++){
		fans+=(ans[i]<<(i-1));
	}
	cout<<fans;
	return 0;
}
