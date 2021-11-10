#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<string>sum[20][6];
	map<char,int>m;
	m['a']=1,m['e']=2,m['i']=3,m['o']=4,m['u']=5;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		char c;
		int cnt=0;
		int len=s.size();
		for(int j=0;j<len;j++){
			if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u'){
				c=s[j],cnt++;
			}
		}
		sum[cnt][m[c]].push_back(s);
	}
	vector<string>ans1,ans2;
	for(int i=1;i<=15;i++){
		int cnt=0;
		for(int j=1;j<=5;j++){
			while(sum[i][j].size()>=2){
				ans2.push_back(sum[i][j][sum[i][j].size()-1]);
				sum[i][j].pop_back();
				ans2.push_back(sum[i][j][sum[i][j].size()-1]);
				sum[i][j].pop_back();
			}
		}
	}
	for(int i=1;i<=15;i++){
		string first="";
		for(int j=1;j<=5;j++){
			if(sum[i][j].size()){
				if(first!=""){
					ans1.push_back(first);
					ans1.push_back(sum[i][j][0]);
					sum[i][j].pop_back();
					first="";
				}
				else{
					first=sum[i][j][0];
					sum[i][j].pop_back();
				}
			}
		}
	}
	while(ans2.size()&&ans1.size()/2<ans2.size()/2){
		ans1.push_back(ans2[ans2.size()-1]);
		ans2.pop_back();
		ans1.push_back(ans2[ans2.size()-1]);
		ans2.pop_back();
	}
	cout<<min(ans1.size(),ans2.size())/2<<endl;
	for(int i=0;i<min(ans1.size(),ans2.size());i++)
		cout<<ans1[i]<<" "<<ans2[i]<<endl;		
	return 0;
}
