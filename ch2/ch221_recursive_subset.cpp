#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i <= b; i++)

vi subset;
int n;
void search(int k)
{
    if (k == n + 1)
    {
        for (int val : subset)
            cout << val << " ";
        cout << "\n";
        return;
    }
    subset.push_back(k);
    search(k + 1);
    subset.pop_back();
    search(k + 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    search(1);
}