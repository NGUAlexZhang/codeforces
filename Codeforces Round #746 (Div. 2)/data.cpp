#include <bits/stdc++.h>
using namespace std;
int main(){
	srand(unsigned(time(0)));
	int n=rand()%50+1;
	cout<<n<<endl;
	for(int i=1;i<=n;i++){
		int s=rand()%1000000,c=rand()%s;
		cout<<s<<" "<<c<<endl;
	}
	cout<<0;
	return 0;
}
