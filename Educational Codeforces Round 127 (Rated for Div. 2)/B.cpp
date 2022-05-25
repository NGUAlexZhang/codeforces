#include <bits/stdc++.h>
using namespace std;
int a[250000];
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int used=0,flag=0;
		for(int i=2;i<=n;i++){
			if(a[i]-a[i-1]==1) continue;
			if(a[i]-a[i-1]==2){
				if(used==0){
					used=1;
					continue;
				}
				a[i]--;
				continue;
			}
			if(a[i]-a[i-1]==3){
				if(used==0){
					a[i]--;
					used=1;
					continue;	
				}
				flag=1;
				break;
			}
			flag=1;
			break;
		}
		if(flag) puts("NO");
		else puts("YES");
	}
	return 0;
}
