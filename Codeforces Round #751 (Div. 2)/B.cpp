#include <bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		vector<int>a(n+1);
		for(int i=1;i<=n;i++) cin>>a[i];
		vector<vector<int> >ans;
		ans.push_back(a);
		while(1){
			vector<int>tmp(n+1);
			map<int,int>cnt;
			for(int i=1;i<=n;i++){
				cnt[a[i]]++;
			}
			for(int i=1;i<=n;i++) tmp[i]=cnt[a[i]];
			ans.push_back(tmp);
			if(a==tmp) break;
			for(int i=1;i<=n;i++) a[i]=tmp[i];
		}
		int q;
		cin>>q;
		while(q--){
			int x,k;
			cin>>x>>k;
			if(k<ans.size()){
				cout<<ans[k][x]<<endl;
			}
			else{
				cout<<ans[ans.size()-1][x]<<endl;
			}
		}
	}
	return 0;
}
