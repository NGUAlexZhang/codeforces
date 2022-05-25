#include <bits/stdc++.h>
using namespace std;
int main(){
	srand(unsigned(time(0)));
	freopen("I.in","w",stdout);
	int n=100,k=100;
	cout<<n<<" "<<k<<endl;
	for(int i=1;i<=n;i++){
		int a=rand()%1000000,b=rand()%14+1;
		cout<<a<<" "<<b<<endl;
	}
	return 0;
}
