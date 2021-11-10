#include <bits/stdc++.h>
using namespace std;
int eular[105];
vector<int>all;
int gcd(int a,int b){
	if(!b) return a;
	return gcd(b,a%b);
}
bool is_prime(int x){
	for(int i=2;i*i<=x;i++){
		if(x%i==0) return 0;
	}
	return 1;
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++)
			if(gcd(i,j)==1) eular[i]++;
	}
	eular[1]=1;
	for(int i=2;i<=100;i++)
		if(is_prime(i)) all.push_back(i);
	for(int i=0;i<all.size();i++) cout<<all[i]<<" ";
	return 0;
}
