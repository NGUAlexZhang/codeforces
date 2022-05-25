#include <bits/stdc++.h>
using namespace std;
int a[1005],b[1005];
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		map<int,int>cnt2;
		map<int,int>cnt1;
		vector<int>ls;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			cnt1[a[i]]++;
		}
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			if(!cnt2[x]) ls.push_back(x); 
			cnt2[x]++;
		}
		sort(ls.begin(),ls.end());
		bool flag=0;
		for(int num:ls){
			int sum=cnt2[num];
			if(sum>cnt1[num]+cnt1[num-1]){
				flag=1;break;
			}
			cnt1[num]-=max(sum-cnt1[num-1],0);
		}
		if(flag) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}
