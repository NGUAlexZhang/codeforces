#include <bits/stdc++.h>
using namespace std;
int a[1005];
int tmp[1005];
vector<int>ans;
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--) a[i]-=a[i-1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++) tmp[j]=a[j];
		bool flag=0;
		for(int j=1;j<=n;j+=i){
			for(int k=0;k<i&&j+k<=n;k++){
				if(tmp[k+1]!=a[j+k]) flag=1;
			}
		}
		if(!flag) ans.push_back(i);
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
	return 0;
}
