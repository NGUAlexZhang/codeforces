#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll res=0;
	char ch=getchar();
	while(ch>='0'&&ch<='9'){
		res+=(ch-'0');res*=10;ch=getchar();
	}
	return res/10;
}
int c[35][150000],flag,cnt1,cnt2;
int head[35][150000],nt[35][400005],val[35][400005],cea[35],to[35][400005];
ll pow2[40];
ll ans=0;
void add(int th,int u,int v,int w){
	int& ce=cea[th];
	to[th][++ce]=v,nt[th][ce]=head[th][u],head[th][u]=ce,val[th][ce]=w;
	to[th][++ce]=u,nt[th][ce]=head[th][v],head[th][v]=ce,val[th][ce]=w;	
}
void dfs(int th,int now,int color){
	if(flag) return;
	c[th][now]=color;
	if(color==1)cnt1++;
	else cnt2++;
	for(int i=head[th][now];i;i=nt[th][i]){
		int nxt=color,v=to[th][i];
		if(val[th][i]==1) nxt=3-color;
		if(c[th][v]==0)
			dfs(th,v,nxt);
		else
		if(c[th][v]!=nxt){
			flag=1;
			return;
		}
	}
}
int main(){
	pow2[0]=1;
	for(int i=1;i<=30;i++) pow2[i]=pow2[i-1]*2;
	int n=read(),m=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read();
		ll w=read();
		for(int j=0;j<=30;j++){
			int tmp=pow2[j]&w;
			if(tmp) tmp=1;
			add(j,u,v,tmp);
			//if(j==2) cout<<(pow2[j]&w)<<endl;
		}
	}
	//cout<<endl;
	for(int i=0;i<=30;i++){
		for(int j=1;j<=n;j++){
			if(c[i][j]) continue;
			cnt1=0,cnt2=0;
			dfs(i,j,1);
			if(flag){
				cout<<-1;
				return 0;
			}
			/*if(i==2) cout<<cnt1<<
			" "<<cnt2<<endl;*/
			ans+=min(cnt1,cnt2)*pow2[i];	
		}
	}
	/*for(int i=head[2][3];i;i=nt[2][i])
		cout<<to[2][i]<<" ";*/
	printf("%lld",ans);
	return 0;
}
