#include <bits/stdc++.h>
using namespace std;
int main(){
	cout<<1<<endl;
	srand(unsigned(time(0)));
	int n=rand()%20;
	cout<<n<<endl;
	for(int i=1;i<=n;i++){
		int r=rand()%5000+1;
		int l=rand()%r+1;
		int c=rand()%4000+1;
		cout<<l<<" "<<r<<" "<<c<<endl;
	}
	return 0;
}
