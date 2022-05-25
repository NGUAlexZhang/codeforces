#include <bits/stdc++.h>
using namespace std;
char s1[10],s2[10];
int a[10],b[10],f[100][20],ki[20];
int aa[10],bb[10],ans,cnt;
void dfs(int now){
	if(now>4){
		cnt++;
		for(int i=1;i<=4;i++) f[cnt][i]=ki[i];
		return;
	}
	ki[now]=a[now];
	dfs(now+1);
	ki[now]=a[now]-10;
	dfs(now+1);
	ki[now]=a[now]+10;
	dfs(now+1);
}
void solve(){
	cnt=0;
	cin>>(s1+1)>>(s2+1);
	for(int i=1;i<=4;i++)
		a[i]=s1[i]-'0',b[i]=s2[i]-'0';
	dfs(1);
	int ans=2147483647;
	for(int l=1;l<=cnt;l++){
		for(int i=1;i<=4;i++) aa[i]=f[l][i]-f[l][i-1];
		for(int i=1;i<=4;i++) bb[i]=b[i]-b[i-1];
		int cnt1=0,cnt2=0;
		for(int i=1;i<=4;i++){
			if(aa[i]>bb[i]) cnt1+=(aa[i]-bb[i]);
			else cnt2+=(bb[i]-aa[i]);
		}
		ans=min(ans,min(cnt1,cnt2)+abs(cnt1-cnt2));
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	cin>>T;
	while(T--)
		solve();
	return 0;
} 