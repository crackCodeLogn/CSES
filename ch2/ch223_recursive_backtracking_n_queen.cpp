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

int n, ways=0;
bool *columns, *diag1, *diag2;

void search(int y) {
    if (y == n) {
        ways++;
        return;
    }
    for (int x=0;x<n;x++) {
        if (columns[x] || diag1[x+y] || diag2[x-y+n-1]) continue;
        columns[x] = diag1[x+y] = diag2[x-y+n-1] = 1;
        search(y+1);
        columns[x] = diag1[x+y] = diag2[x-y+n-1] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    columns = (bool *)malloc(n);
    diag1 = (bool *)malloc(n);
    diag2 = (bool *)malloc(n);

    search(0);
    cout << "Ways of placing queens: " << ways << endl;
}