#include <bits/stdc++.h>
using namespace std;
int main(){
	int a[]={1,3,5,6,7,8,9,12,13,15};
	int l=0,r=9;
	int x=8;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid]>x) r=mid-1;
		else l=mid+1;
	}
	cout<<r+1;
	return 0;
}
