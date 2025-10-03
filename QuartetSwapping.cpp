#include<bits/stdc++.h>
using namespace std;
int t,n,a[200005],p[200005];
void swbp(int x,int y)
{
	swap(a[x],a[y]);
	swap(p[a[x]],p[a[y]]);
}
int main()
{
	set<int> s[2];
	cin>>t;
	while(t--)
	{
		s[1].clear(),s[0].clear();
		cin>>n;
		for(int i=1;i<=n;++i)
		{
			cin>>a[i];
			p[a[i]]=i;
			s[i&1].insert(a[i]);
		}
		for(int i=1;i<=n-3;++i)
		{
			int x=*s[i&1].begin();
			s[i&1].erase(x);
//			cout<<x<<' '<<p[x]<<'\n';
			if(p[x]==n) swbp(n,n-2),swbp(n-1,n-3);
			swbp(p[x]+1,i+1),swbp(p[x],i);
		}
		for(int i=1;i<=n;++i)
			cout<<a[i]<<' ';
		cout<<'\n';
	}
	return 0;
}
