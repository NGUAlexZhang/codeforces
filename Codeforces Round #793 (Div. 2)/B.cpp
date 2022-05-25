#include <bits/stdc++.h>
using namespace std;
int p[150000];
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int ans=0;
		vector<int>v;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			if(x!=i)
			v.push_back(x);
		}
		for(int i=25;i>=0;i--){
			bool flag=0;
			for(auto j:v){
				//cout<<j<<endl;
				if(((j>>(i-1))&1)==0){
					flag=1;
					break;
				} 
			}
			if(!flag){
				ans+=(1<<(i-1));
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
