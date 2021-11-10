#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		ll a,b,c;
		cin>>a>>b>>c;
		ll tot=3*c+2*b+a;
		cout<<tot%2<<endl; 
	}
	return 0;
}
/*
1 2 3
1 2 3

3  3
3  1
   2
*/
