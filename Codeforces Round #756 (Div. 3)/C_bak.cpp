#include<iostream>
#include<list>
#include<optional>

using namespace std;

int main() {
  int t;
  cin >> t;
  while(t-->0) {
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
      cin >> a[i];
    }
    bool found=false;
    for(int s=0;s<=n;s++){
      list<int> p;
      for(int i=0;i<s;i++){
        p.push_front(a[i]);
      }
      for(int i=n-1;i>=s;i--){
        p.push_back(a[i]);
      }
      list<int> p0=p;
      list<int> a0;
      while(p0.size()>1){
        if(p0.front()<p0.back()){
          a0.push_front(p0.front());
          p0.pop_front();
        }else{
          a0.push_back(p0.back());
          p0.pop_back();
        }
      }
      int remaining=p0.front();
      if (remaining==a[0]){
        a0.push_front(p0.front());
      }else if (remaining==a[n-1]){
        a0.push_back(p0.back());
      }else{
        continue;
      }
      int i=0;
      bool flag = false;
      for(int x:a0){
        if(x!=a[i++]){
          flag=true;
        }
      }
      if(flag)continue;
      for(int x:p){
        cout<<x<<" ";
      }
      cout<<"\n";
      found=true;
      break;
    }
    if(!found)cout<<"-1\n";
  }
}