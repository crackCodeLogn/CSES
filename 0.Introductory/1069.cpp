// Repetitions

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

    string data;
    getline(cin, data);

    char lastCh = data[0];
    int lastLength = 1;
    map<char, int> maxCounterMap;
    maxCounterMap[lastCh] = lastLength;

    REP(i, 1, data.length()-1) {
        if (data[i] == lastCh) {
            lastLength++;
        } else {
            if (maxCounterMap[lastCh] < lastLength) maxCounterMap[lastCh] = lastLength;
            lastCh = data[i];
            lastLength = 1;
        }
        //cout<<"i: "<<i<<", ch: "<<lastCh<<", len: "<<lastLength<<endl;
    }
    if (maxCounterMap[lastCh] < lastLength) maxCounterMap[lastCh] = lastLength;

    int maxValue = 1;
    REP_MAP(it, maxCounterMap) {
        if (it->second > maxValue) maxValue = it->second;
        //cout << it->first << " " << it->second << endl;
    }
    cout<<maxValue<<endl;
}