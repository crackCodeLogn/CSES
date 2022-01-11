// Increasing Array

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define REP_MAP(it,dataMap) for(auto it = dataMap.cbegin(); it != dataMap.cend(); ++it)


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long n, count=0;
    cin>>n;
    long data[n];
    REP(i,0,n-1) cin>>data[i];
    int last = data[0];

    REP(i, 1, n-1) {
        if (data[i] < last) count += last - data[i];
        else last = data[i];
    }
    cout<<count<<endl;
}