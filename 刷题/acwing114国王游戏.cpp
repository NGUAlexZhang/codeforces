#include <bits/stdc++.h>
using namespace std;
struct Per{
	int l,r;
}p[1005];
bool cmp(Per a,Per b){
	return a.l*a.r<b.l*b.r;
}
vector<int> mul(vector<int>a, int b)
{
    vector<int> c;
    int t = 0;
    for (int i = 0; i < a.size(); i ++ )
    {
        t += a[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }
    while (t)
    {
        c.push_back(t % 10);
        t /= 10;
    }
    return c;
}

vector<int> div(vector<int>a, int b)
{
    vector<int> c;
    bool is_first = true;
    for (int i = a.size() - 1, t = 0; i >= 0; i -- )
    {
        t = t * 10 + a[i];
        int x = t / b;
        if (!is_first || x)
        {
            is_first = false;
            c.push_back(x);
        }
        t %= b;
    }
    reverse(c.begin(), c.end());
    return c;
}

vector<int> max_vec(vector<int> a, vector<int> b)
{
    if (a.size() > b.size()) return a;
    if (a.size() < b.size()) return b;
    if (vector<int>(a.rbegin(), a.rend()) > vector<int>(b.rbegin(), b.rend())) return a;
    return b;
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<=n;i++) cin>>p[i].l>>p[i].r;
	sort(p+1,p+1+n,cmp);
	vector<int>sum(1,1);
	vector<int>res(1,0);
	for(int i=0;i<=n;i++){
		if(i) res=max_vec(res,div(sum,p[i].r));
		sum=mul(sum,p[i].l);
	}
	for(int i=res.size()-1;i>=0;i--) cout<<res[i];
	return 0;
}
