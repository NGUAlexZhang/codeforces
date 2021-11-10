#include <bits/stdc++.h>
using namespace std;
struct Cow{
	int st,ed;
	int ans,index;
}cow[55000];
struct Cowcmp{
	bool operator()(const Cow& a,const Cow& b){
		return a.ed>b.ed;
	}
};
bool cmp(Cow a,Cow b){
	return a.st<b.st;
}
bool cmp2(Cow a,Cow b){
	return a.index<b.index;
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>cow[i].st>>cow[i].ed;
		cow[i].index=i;
	}
	sort(cow+1,cow+1+n,cmp);
	priority_queue<Cow,vector<Cow>,Cowcmp>q;
	int ans1=1;
	for(int i=1;i<=n;i++){
		while(q.size()&&q.top().ed<cow[i].st) q.pop();
		q.push(cow[i]);
		ans1=max(ans1,int(q.size()));
		//cout<<q.top().ed<<" ";
	}
	//cout<<endl;
	cout<<ans1<<endl;
	queue<int>q2;
	for(int i=1;i<=ans1;i++){
		q2.push(i);
	}
	while(q.size()) q.pop();
	for(int i=1;i<=n;i++){
		while(q.size()&&q.top().ed<cow[i].st){
			q2.push(q.top().ans);
			q.pop();
		}
		cow[i].ans=q2.front();
		q2.pop();
		q.push(cow[i]);
	}
	sort(cow+1,cow+1+n,cmp2);
	for(int i=1;i<=n;i++) cout<<cow[i].ans<<endl;	
	return 0;
}
