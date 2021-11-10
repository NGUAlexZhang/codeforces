#include <bits/stdc++.h>
using namespace std;
int sg[1500000];
int dfs(int maxn,int now){
	//cout<<maxn<<" "<<now<<endl;
	if(sg[now]!=-1){
		return sg[now];
	}
	priority_queue<int,vector<int>,greater<int> >q;
	for(int i=1;i<=now*now&&i+now<=maxn;i++){
		//if(i+now>maxn) break;
		q.push(dfs(maxn,now+i));
	}
	int mex=0;
	while(q.size()){
		if(q.top()<mex){
			q.pop();
			continue;
		}
		if(q.top()!=mex) break;
		q.pop();
		mex++;
	}
	return sg[now]=mex;
}
priority_queue<int>q[1500000];
int main(){
	memset(sg,-1,sizeof(sg));
	int maxn=31,init=17;
	sg[maxn]=0;
	dfs(maxn,init);
	//for(int i=init;i<=maxn;i++) cout<<sg[i]<<" ";
	memset(sg,0,sizeof(sg));
	cout<<endl;
	for(int i=maxn;i>=0;i--){
		priority_queue<int,vector<int>,greater<int> >q;
		for(int j=1;j<=maxn-i;j++){
			if(i<sqrt(j)){
				break;
			}
			q.push(sg[i+j]);
		}
		int mex=0;
		while(q.size()){
			if(q.top()<mex){
				q.pop();
				continue;
			}
			if(q.top()!=mex) break;
			q.pop();
			mex++;
		}
		//cout<<mex<<endl;
		sg[i]=mex;	
	}
	
	//cout<<sg[init]<<" "<<(maxn^init);
	for(int i=1;i<=maxn;i++) cout<<sg[i]<<" ";
	return 0;
}