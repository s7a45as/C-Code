#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define pb push_back
#define endl '\n'
void markAsSolved();
int t,n,ans[10000010]={0};
unsigned long long d[10000010]={0};
int prime[1000010],tot=0;
bitset<(int)1e7+10> v;
long long num(int x)   //暴算约数和
{
	int res=0;
	for(int i=1;i*i<=x;i++)
	{
		if(x%i!=0) continue;
		res+=i;
		if(x/i==i) continue;
		res+=(x/i);
	}
	return res;
}
void shai()
{
	d[1]=1;
	for(int i=2;i<=1e7;i++)
	{
		if(!v[i]) prime[++tot]=i,d[i]=1+prime[tot];
		for(int j=1;j<=tot&&prime[j]*i<=1e7;j++)
		{
			v[prime[j]*i]=1;
			if(i%prime[j]==0)
			{
				int x=i*prime[j],s=1;
				while(x%prime[j]==0) x/=prime[j],s*=prime[j];
				d[i*prime[j]]=d[x]*num(s);
				if(d[i*prime[j]]<0||d[i*prime[j]]>1e7) d[i*prime[j]]=0;
				break;
			}
			else d[i*prime[j]]=d[i]*d[prime[j]];
			if(d[i*prime[j]]<0||d[i*prime[j]]>1e7) d[i*prime[j]]=0;  //防爆系统
		}
	}
	for(int i=1;i<=1e7;i++)
	  if(ans[d[i]]==0)
	    ans[d[i]]=i;
	return ;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	shai();
	while(t)
	{
		t--;
		cin>>n;
	    if(ans[n]==0) cout<<-1<<'\n';
	    else cout<<ans[n]<<'\n';
	}
	// markAsSolved();
	return 0;
}

// 标记完成函数
void markAsSolved() {
    string current_file = __FILE__;
    string new_file = current_file.substr(0, current_file.length() - 4) + "_ok.cpp";
    string filename = new_file.substr(new_file.find_last_of("/\"") + 1);
    
    #ifdef _WIN32
        string command = "rename \"" + current_file + "\" \"" + filename + "\"";
    #else
        string command = "mv \"" + current_file + "\" \"" + new_file + "\"";
    #endif
    
    system(command.c_str());
    cout << "File marked as solved!" << endl;
}