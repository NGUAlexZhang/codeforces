#include <bits/stdc++.h>
using namespace std;
int n,a[350000],b[350000],pre[350000],used[350000],d[350000],ans[350000];
void bfs(){
	queue<int>q;
	q.push(n);
	used[n]=1;
	d[n]=n;
	int minn=n;
	int bound=n;
	while(q.size()){
		int now=q.front();
		q.pop();
		bool flag=0;
		for(int i=max(now-a[now],0);i<now;i++){
			//cout<<i<<"<---"<<now<<endl;
			if(i>bound){
				break;
			}
			int nxt=i+b[i];
			if(used[nxt]) continue;
			used[nxt]=1;
			q.push(nxt);
			d[nxt]=i;
			pre[nxt]=now;
			if(nxt==0){
				flag=1;
				break;
			}
		}
		if(flag) break;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	bfs();
	if(pre[0]==0){
		cout<<-1;
		return 0;
	}
	int now=0,cnt=0;
	while(pre[now]){
		int x=pre[now];
		ans[++cnt]=d[pre[now]];
		now=pre[now];
	}
	cout<<cnt<<endl;
	for(int i=cnt-1;i>0;i--)
		printf("%d ",ans[i]);
	cout<<0;
	return 0;
}
