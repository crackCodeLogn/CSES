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

vi permutation;
int n;
bool chosen[];

void search() {
    if (permutation.size() == n) {
        return;
    }
    REP(i,1,n) {
        if (chosen[i]) continue;
        chosen[i] = true;
        permutation.push_back(i);
        search();
        chosen[i] = false;
        permutation.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    n = 3;
    chosen = new bool[n];
    search();        
}