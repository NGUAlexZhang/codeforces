#include <bits/stdc++.h>
using namespace std;
int a[1005];
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			if(i==a[i]) continue;
			int r=i;
			for(int j=i+1;j<=n;j++){
				if(a[j]<a[r]) r=j;
			}
			int l=i;
			while(l<=r){
				swap(a[l],a[r]);
				l++,r--;
			}
			break;
		}
		for(int i=1;i<=n;i++) cout<<a[i]<<" ";
		puts("");
	}
	return 0;
}
