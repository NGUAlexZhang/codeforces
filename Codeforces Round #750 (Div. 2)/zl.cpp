#include <bits/stdc++.h>
using namespace std;
int a[14];
int main(){
	for(int i=1;i<=10;i++) cin>>a[i];
	int x;
	cin>>x;
	int l=1,r=10;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid]<=x) r=mid-1;
		else l=mid+1;
	}
	if(a[r+1]==x&&r+1<=10&&r+1>=1){
		cout<<r+1;
	}
	else cout<<"not exist";
	return 0;
}
