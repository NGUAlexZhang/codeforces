#include <bits/stdc++.h>
using namespace std;
char ss[100];
int a[100006],b[1006];
vector<int> ans1[100006];
vector<int> ans2[100006];
map<int,bool>h;
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=3;j++) cin>>ss;
	}
	for(int i=1;i<=m;i++){
		int index;
		cin>>index;
		string s;
		cin>>s;
		int num=0;
		if(s=="203") num=3;
		else num=2;
		//cout<<num<<endl;
		for(int j=1;j<=num;j++){
			cin>>b[j];
			b[j]=a[b[j]];
			h[b[j]]=1;
		}
		for(int j=1;j<=num;j++){
			ans2[b[j]].push_back(index);
			for(int k=1;k<=num;k++){
				if(j==k) continue;
				ans1[b[j]].push_back(b[k]);
			}
		}
	}
	int q;
	cin>>q;
	while(q--){
		int x;
		cin>>x;
		cout<<x<<endl;
		if(!h[x]){
			printf("[]\n[]");
			if(q) cout<<endl;
			continue;
		}
		map<int,bool>m;
		printf("[");
		cout<<ans1[x][0];
		m[ans1[x][0]]=1;
		for(int i=1;i<ans1[x].size();i++){
			if(m[ans1[x][i]]) continue;
			cout<<","<<ans1[x][i];
			m[ans1[x][i]]=1;
		}
		printf("]");
		cout<<endl;
		m.clear();
		printf("[");
		cout<<ans2[x][0];
		m[ans2[x][0]]=1;
		for(int i=1;i<ans2[x].size();i++){
			if(m[ans2[x][i]]) continue;
			cout<<","<<ans2[x][i];
			m[ans2[x][i]]=1;
		}
		printf("]");
		if(q)
		cout<<endl;
	}
	return 0;
}