#include <bits/stdc++.h>
using namespace std;
int main(){
	cout<<1<<endl;
	srand((unsigned)time(0));
	int n=rand()%15+2;
	cout<<n<<endl;
	for(int i=1;i<=n;i++)
		cout<<rand()%1000+1<<" ";
	
	return 0;
}