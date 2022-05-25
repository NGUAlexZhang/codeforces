#include <bits/stdc++.h>
using namespace std;
int len;
void f1(char s[],char str[],char str1[]){
	for(int i=0;i<len;i++){
		int tmp=0;
		if(str[i]<='z'&&str[i]>='a') tmp=str[i]-'a'+1;
		else tmp=str[i]-'A'+1+26;
		tmp*=3;
		tmp%=52;
		str1[i]=s[tmp];
	}
	str1[len]='\0';
}
void f2(char s[],char str1[],char str2[]){
	for(int i=0;i<len;i++){
		int tmp=0;
		if(str1[i]<='z'&&str1[i]>='a') tmp=str1[i]-'a'+1;
		else tmp=str1[i]-'A'+1+26;
		while(tmp%3) tmp+=52;
		tmp/=3;
		str2[i]=s[tmp];
	}
	str2[len]='\0';
}
int main(){
	char str[100],str1[100],s[100],str2[100];
	cin>>str;
	len=strlen(str);
	for(int i=1;i<=26;i++)
		s[i]='a'+i-1,s[26+i]='A'+i-1;
	s[0]='Z';
	f1(s,str,str1);
	cout<<str1<<endl;
	f2(s,str1,str2);
	cout<<str2;
	return 0;
}
