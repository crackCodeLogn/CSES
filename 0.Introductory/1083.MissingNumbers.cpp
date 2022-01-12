//Missing Number

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

int solve(int n, int data[]) {
    int xori = 0;
    REP(i, 0, n-2) xori^=data[i];
    REP(i, 1, n) xori^=i;
    return xori;
}

int solve2(int n, int data[]) {
    int xori = 0;
    REP(i, 0, n-2) {
        xori^=data[i];
        xori^=(i+1);
    }
    xori^=n;
    return xori;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    int data[n-1];
    REP(i,0,n-2) cin>>data[i];

    int missing = solve2(n, data);
    cout<<missing<<endl;
}