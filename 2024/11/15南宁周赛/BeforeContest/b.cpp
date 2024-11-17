#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MAX = (int)2E9;
const int N=1e6+1213;
int a[N];
int bit[32];


int n;
void solve() {
   
    cin>>n;
    int ans=0;
    int sum=0;

    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];

        int j=0;
        while(a[i]){
            if(a[i]&1){
               bit[j]++;
                j++;
               
            }
             a[i]>>=1;
        }
    }
    
    int asum=sum;
    int x=0;
  
    for(int i=0;i<=32;i++){
       if(bit[i]){
  
        }
       
        
       }
    }



 

/*
5 
2 2 3 4 5
2

5
1 2 4 6 7

1 
2



 */
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}