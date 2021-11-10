#include <bits/stdc++.h>
using namespace std;
int a[1005];
int ans1[1005],ans2[1005],ans3[1005];
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		a[0]=2147483647;
		for(int i=1;i<=n;i++) cin>>a[i];
		int tot=0;
		for(int i=1;i<=n;i++){
			int index=0;
			for(int j=i;j<=n;j++){
				if(a[index]>a[j]){
					index=j;
				}
			}
			if(index==i) continue;
			
			//cout<<i<<" "<<index<<" "<<index-i<<endl;
			ans1[++tot]=i,ans2[tot]=index,ans3[tot]=index-i;
			for(int j=index;j>i;j--){
				swap(a[j],a[j-1]);
			}
		}
		cout<<tot<<endl;
		for(int i=1;i<=tot;i++)
			cout<<ans1[i]<<" "<<ans2[i]<<" "<<ans3[i]<<endl;
	}
	return 0;
}
