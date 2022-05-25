#include <bits/stdc++.h>
using namespace std;
char s[1005];
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		vector<int>ans;
		cin>>(s+1);
		int l=1,r=n;
		while(l<=r){
			while(l<r&&s[l]=='0') l++;
			while(l<r&&s[r]=='1') r--;
			if(l==r){
				//ans.push_back(l);
				break;
			}
			ans.push_back(l);
			ans.push_back(r);
			l++,r--;
		}
		if(ans.size()) cout<<1<<endl;
		else cout<<0<<endl;
		if(ans.empty()) continue;
		cout<<ans.size()<<" ";
		sort(ans.begin(),ans.end());
		for(int i:ans) cout<<i<<" ";
		cout<<endl;
	}
	return 0;
}
