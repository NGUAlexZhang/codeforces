#include <bits/stdc++.h>
using namespace std;
struct Node{
	int p,v,s;
	double avg; 
}node[1105];
int n,root;
int find(){
	int index=0;
	double avg=0;
	for(int i=1;i<=n;i++){
		if(i==root) continue;
		if(node[i].avg>avg){
			avg=node[i].avg;
			index=i;
		}
	}
	return index;
}
int main(){
	cin>>n>>root;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>node[i].s;
		node[i].avg=node[i].s;
		node[i].v=1;
		ans+=node[i].s;
	}
	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		node[b].p=a;
	}
	for(int i=1;i<n;i++){
		int p=find();
		int fa=node[p].p;
		ans+=node[fa].v*node[p].s;
		node[p].avg=-1;
		for(int j=1;j<=n;j++)
			if(node[j].p==p)
				node[j].p=fa;
		node[fa].v+=node[p].v,node[fa].s+=node[p].s;
		node[fa].avg=(double)node[fa].s/node[fa].v;
	}
	cout<<ans;
	return 0;
}
