#include <bits/stdc++.h>
using namespace std;
int ans1[1000005],ans2[1000005];
int main(){
	int T;
	cin>>T;
	while(T--){
		priority_queue<pair<int,int> >q;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			if(x) q.push({x,i});
		}
		int ans=0;
		int cnt=0;
		while(q.size()>1){
			pair<int,int> fir=q.top();q.pop();
			pair<int,int> sec=q.top();q.pop();
			fir.first--,sec.first--;
			ans1[++ans]=fir.second,ans2[ans]=sec.second;
			if(fir.first) q.push({fir.first,fir.second});
			if(sec.first) q.push({sec.first,sec.second});
		}
		cout<<ans<<endl;
		for(int i=1;i<=ans;i++)
			cout<<ans1[i]<<" "<<ans2[i]<<endl;
	}
	return 0;
}
