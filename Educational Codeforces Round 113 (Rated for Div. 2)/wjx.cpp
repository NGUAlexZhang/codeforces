#include <bits/stdc++.h>
using namespace std;
#define moe 998244353
int t;
long long li[200001];
long long jie[200001];
long long mx=0;
long long mx2=0;
int mxn=0;
int mx2n=0;
int els=0;
long long ksm(long long a,long long k){
	if(k==1)return a%moe;
	if(k%2==0)return ksm(a*a%moe,k/2);
	return a*ksm(a*a%moe,k/2)%moe;
}
long long C(long long a,long long b){
	return (((jie[a]*ksm(jie[b],moe-2))%moe)*ksm(jie[a-b],moe-2))%moe;
}
int main(){
	jie[0]=1;
	for(long long j=1;j<=2e5;j++){
		jie[j]=jie[j-1]*j%moe;
	}
	cin>>t;while(t--){
		mxn=mx2n=mx=mx2=els=0;
		int n;scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld",&li[i]);
			if(li[i]>mx){
				mx2=mx;
				els+=mx2n;
				mx2n=mxn;
				mxn=1;
				mx=li[i];
			}
			else if(li[i]==mx2)mx2n++;
			else if(li[i]==mx)mxn++;
			else if(li[i]>mx2){
				els+=mx2;
				mx2n=1;
				mx2=li[i];
			}
			else els++;
		}
		//printf("/%lld %lld %d %d %d/",mx,mx2,mxn,mx2n,els);
		if(mxn>=2){printf("%lld\n",jie[n]);continue;}
		if(mx-mx2>=2){printf("0\n");continue;}
		long long bas=jie[n]%moe;
		for(int i=mx2n+1;i<=n;i++){
			bas=((bas-((C(i-1,mx2n)*jie[mx2n]%moe)*jie[els])%moe)+moe)%moe;
		}
		printf("%lld\n",bas);

	}
}
