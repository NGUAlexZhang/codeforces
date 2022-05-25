#include <bits/stdc++.h>
using namespace std;
int a[150000];
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int pos=0,nav=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]>0) pos++;
			else nav++;
		}
		for(int i=1;i<=nav;i++){
			if(a[i]>0) a[i]=-a[i];	
		}
		for(int i=nav+1;i<=n;i++){
			a[i]=abs(a[i]);
		}
		bool flag=0;
		for(int i=2;i<=n;i++)
			if(a[i]<a[i-1]) flag=1;
		if(flag) puts("NO");
		else puts("YES");
	}
	return 0;
}
