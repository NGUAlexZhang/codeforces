#include <bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		int a,b;
		cin>>a>>b;
		if(a>b) swap(a,b);
		vector<int>ans;
		int maxn1=(a+b)/2,maxn2=(a+b)/2;
		if((a+b)%2) maxn1++;
		for(int i=0;i<=a;i++){
			if(i<=maxn1){
				ans.push_back(i+(maxn2-(a-i)));
			}
		}
		swap(maxn1,maxn2);
		for(int i=0;i<=a&&i<=maxn1;i++){
			ans.push_back(i+(maxn2-(a-i)));
		}
		sort(ans.begin(),ans.end());
		int pos = unique(ans.begin(), ans.end())-ans.begin();
		cout<<pos<<endl;
		for(int i=0;i<pos;i++) cout<<ans[i]<<" ";
		cout<<endl;
	}
	return 0;
}
