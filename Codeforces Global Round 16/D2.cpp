#include <bits/stdc++.h>
using namespace std;
pair<int,int> vec[9000055];
bool cmp(pair<int,int> a,pair<int,int> b){
	if(a.first==b.first) return a.second>b.second;
	return a.first<b.first;
}
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>vec[i].first;
		vec[i].second=i;
	}
	sort(vec+1,vec+1+n*m);
	long long ans=0;
	for(int i=1;i<=n;i++){
		//cout<<(i-1)*m+1<<" "<<i*m<<endl;
		sort(vec+(i-1)*m+1,vec+i*m+1,cmp);
		for(int j=(i-1)*m+1;j<=i*m;j++){
			//cout<<vec[j].first<<" ";
			for(int k=(i-1)*m+1;k<j;k++){
				if(vec[k].second<vec[j].second) ans++;
			}
		}
		//cout<<endl;
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}