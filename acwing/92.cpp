#include <bits/stdc++.h>
using namespace std;
int n;
void dfs(vector<int> ans,int now){
	for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
	cout<<endl;
	for(int i=now+1;i<=n;i++){
		vector<int> tmp=ans;
		tmp.push_back(i);
		dfs(tmp,i);
	}
}
int main(){
	vector<int>ans;
	cin>>n;
	dfs(ans,0);
	return 0;
}
