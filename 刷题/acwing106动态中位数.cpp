#include <bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		int id,n;
		cin>>id>>n;
		cout<<id<<" "<<(n+1)/2<<endl;
		priority_queue<int,vector<int>,greater<int>>q2;
		priority_queue<int>q1;
		int x;
		cin>>x;
		q2.push(x);
		cout<<x<<" ";int cnt=1;
		for(int i=2;i<=n;i++){
			cin>>x;
			if(x>=q2.top())
				q2.push(x);
			else q1.push(x);
			if(i%2){
				//cout<<q1.size()<<" "<<q2.size()<<" "<<q2.size()-q1.size()<<endl;
//				int len1=q1.size(),len2=q2.size();
				while(int(q2.size())-int(q1.size())>1){
					q1.push(q2.top());
					q2.pop();
				}
				while(q1.size()>q2.size()){
					//cout<<q1.size()<<" "<<q2.size()<<endl;
					q2.push(q1.top());
					q1.pop();
				}
				cout<<q2.top()<<" ";
				cnt++;
				if(cnt==10){
					cout<<endl;
					cnt=0;
				}
			}
		}
		if(cnt) cout<<endl;
	}
	return 0;
}
