#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct Node{
	int time,id;
};
/*bool operator <(const Node& a,const Node& b){
	return a.time
}*/
int tot[150005];
int main(){
	int k,n;
	cin>>k>>n;
	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > >q;
	set<int>s;
	for(int i=0;i<k;i++) s.insert(i);
	for(int i=0;i<n;i++){
		ll a,b;
		cin>>a>>b;
		while(q.size()&&q.top().first<=a){
			s.insert(q.top().second);
			q.pop();
		}
		int tar=i%k;
		if(s.size()==0) continue;
		set<int>::iterator it=s.lower_bound(tar);
		if(it==s.end()){
			it=s.begin();
		}
		q.push(make_pair(a+b,*it));
		//cout<<i<<" "<<*it<<endl;
		tot[*it]++;
		s.erase(it);
	}
	int ans1=0,ans2=0;
	for(int i=0;i<k;i++){
		if(tot[i]>ans2){
			ans2=tot[i];
			ans1=i;
		}
		//cout<<i<<" "<<tot[i]<<endl;
	}
	int index=0;
	for(int i=0;i<k;i++){
		if(tot[i]==ans2) {
			cout<<i;
			index=i;
			break;
		}
	}
	for(int i=index+1;i<k;i++)
		if(tot[i]==ans2) cout<<" "<<i;
	return 0;
}