#include <bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		deque<int>d;
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			if(d.empty()){
				d.push_back(x);
				continue;
			}
			if(x<d.front()){
				d.push_front(x);
			}
			else d.push_back(x);
		}
		while(d.size()){
			cout<<d.front()<<" ";
			d.pop_front();
		}
		cout<<endl;
	}
	return 0;
}
