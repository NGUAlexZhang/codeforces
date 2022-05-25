#include <bits/stdc++.h>
using namespace std;
char s[250000];
int ans;
int main(){
	cin>>(s+1);
	int len=strlen(s+1);
	for(int i=1;i+4<=len;i++){
		if(s[i]=='e'&&s[i+1]=='d'&&s[i+2]=='g'&&s[i+3]=='n'&&s[i+4]=='b') ans++;
	}
	cout<<ans;
	return 0;
}
