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
		sort(a+1,a+1+n);
		if(a[n]-a[n-1]>1){
			puts("NO");
			continue;
		}
		puts("YES");
	}
	return 0;
}
