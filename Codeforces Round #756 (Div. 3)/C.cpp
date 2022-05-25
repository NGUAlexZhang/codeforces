#include <bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		deque<int>q1,q2;
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			q1.push_back(x);
			q2.push_front(x);
		}
		if(q1.front()!=n&&q1.back()!=n){
			cout<<-1<<endl;
			continue;
		}
		while(q2.size()){
			cout<<q2.front()<<" ";
			q2.pop_front();
		}
		cout<<endl;
	}
	return 0;
}