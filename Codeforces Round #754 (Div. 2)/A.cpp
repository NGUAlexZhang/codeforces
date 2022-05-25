#include <bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		int a,b,c;
		cin>>a>>b>>c;
		a+=c;
		if((2*b-a)%3){
			cout<<1<<endl;
		}
		else cout<<0<<endl;
	}
	return 0;
}
