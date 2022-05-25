#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n,m;
	cin>>n>>m;
	cout<<min(n,m)+abs(n-m)/2+abs(n-m)%2;
	return 0;
}
