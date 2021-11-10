#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct Dish{
	int a,b,m,index;
	bool operator <(Dish k){
		return a<k.a;
	}
};
vector<Dish>dish[2600000];
int main(){
	int T;
	cin>>T;
	while(T--){
		map<int,bool>c;
		vector<int>tot;
		int n,ans=0;
		cin>>n;
		vector<pair<int,int>>fans(n+5);
		for(int i=1;i<=n;i++){
			int a,b,m;
			cin>>a>>b>>m;
			if(!c[a+b-m]){
				c[a+b-m]=1;
				dish[a+b-m].clear();
				tot.push_back(a+b-m);
			}
			Dish d;
			d.a=a,d.b=b,d.m=m,d.index=i;
			dish[a+b-m].push_back(d);
			
		}
		for(auto it=tot.begin();it!=tot.end();it++){
			sort(dish[*it].begin(),dish[*it].end());
			int now=0;
			ans++;
			fans[dish[*it][0].index]=make_pair(dish[*it][0].m-min(dish[*it][0].m,dish[*it][0].b),
			min(dish[*it][0].m,dish[*it][0].b));
			dish[*it][0].a-=dish[*it][0].m-min(dish[*it][0].m,dish[*it][0].b);
			for(int i=1;i<dish[*it].size();i++){
				if(dish[*it][i].a-dish[*it][i].m<=dish[*it][now].a){
					fans[dish[*it][i].index]=make_pair(dish[*it][i].a-dish[*it][now].a,dish[*it][i].m-(dish[*it][i].a-dish[*it][now].a));
					continue;
				}
				now=i,ans++;
				fans[dish[*it][i].index]=make_pair(dish[*it][i].m-min(dish[*it][i].m,dish[*it][i].b),
				min(dish[*it][i].m,dish[*it][i].b));
				dish[*it][i].a-=dish[*it][i].m-min(dish[*it][i].m,dish[*it][i].b);
			}
		}
		cout<<ans<<endl;
		for(int i=1;i<=n;i++) cout<<fans[i].first<<" "<<fans[i].second<<endl;
	}
	return 0;
}
