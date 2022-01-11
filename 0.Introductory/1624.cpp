//Chessboard and Queens

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
bool *col, *diag1, *diag2;

void solve(int y, vector<vector<bool>> matrix) {
    if (y == n) {
        ways++;
        return;
    }
    for (int x=0;x<n;x++) {
        if (col[x] || diag1[x+y] || diag2[x-y+n-1] || matrix[y][x]) continue;
        col[x] = diag1[x+y] = diag2[x-y+n-1] = true;
        solve(y+1, matrix);
        col[x] = diag1[x+y] = diag2[x-y+n-1] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    n=8;
    col = (bool *)malloc(n);
    diag2 = (bool *)malloc(n*2);
    diag1 = (bool *)malloc(n*2);
    vector<vector<bool>> matrix(n, vector<bool> (n, false)); //creating vector x vector of 'n' rows and 'n' columns each, defaulting to 'false'

    for(int i=0;i<n;i++) {
        string data;
        getline(cin, data);
        for (int j=0;j<n;j++) {
            bool val = false;
            if (data[j] == '*') val = true;
            matrix[i][j] = val;
        }
    }

    solve(0, matrix);
    cout<<ways<<endl;
}

/**
Input:
........
........
..*.....
........
........
.....**.
...*....
........

output: 65
*/