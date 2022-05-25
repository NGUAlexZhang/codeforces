#include <bits/stdc++.h>
using namespace std;
char a[100],s[100];
int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>(a+1)>>(s+1);
		int len1=strlen(a+1),len2=strlen(s+1);
		vector<int>ans;
		bool flag=0;
		for(int i=len1;i>=1;i--){
			if(len2==0){
				flag=1;
				break;
			}
			if(a[i]<=s[len2]){
				ans.push_back(s[len2]-a[i]);
				len2--;
			}
			else{
				if(s[len2-1]!='1'){
					flag=1;
					break;
				}
				ans.push_back(s[len2]-a[i]+10);
				len2-=2;
			}
		}
		if(flag){
			cout<<"-1\n";
			continue;
		}
		while(len2>=1) ans.push_back(s[len2]-'0'),len2--;
		auto it=ans.rbegin();
		while(it!=ans.rend()&&*it==0){
			it++;
		}
		if(it==ans.rend()){
			cout<<"0\n";continue;
		}
		while(it!=ans.rend()){
			cout<<*it;
			it++;
		}
		cout<<endl;
	}
	return 0;
}
