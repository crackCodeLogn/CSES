// Two Sets

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long> vl;
typedef pair<int, int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define REP_MAP(it,dataMap) for(auto it = dataMap.cbegin(); it != dataMap.cend(); ++it)
#define REP_SET(it,dataSet) for(auto it = dataSet.begin(); it != dataSet.end(); ++it)
#define DISPLAY_SET(it,dataSet) REP_SET(it, dataSet) cout<<*it<<" ";

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long n; cin>>n;

    long total = n*(n+1)/2, total2=0;
    if (total % 2 !=0) {
        cout<<"NO"<<endl;
        return 0;
    }
    set<long> s1; set<long> s2;
    //REP(i,1,n) s1.insert(i);
    int lower = 1, upper = n;
    //while (total != total2) {
    while (lower <= upper) {
        s1.insert(lower);
        s1.insert(upper);

        bool trigger = true;
        if (upper + total2 <= total - upper) {
            total2+=upper;
            total-=upper;
            s2.insert(upper);
            s1.erase(upper);
            upper--;
            trigger = false;
        }
        if (trigger) upper--;
        trigger = true;
        if (lower + total2 <= total - lower) {
            total2+=lower;
            total-=lower;
            s2.insert(lower);
            s1.erase(lower);
            lower++;
            trigger = false;
        }
        if (trigger) lower++;
        //cout<<"l: "<<lower<<", u: "<<upper<<", t1: "<<total<<", t2: "<<total2<<endl;
    }
    cout<<"YES"<<endl<<s1.size()<<endl;
    DISPLAY_SET(it, s1);
    cout<<endl<<s2.size()<<endl;
    DISPLAY_SET(it, s2);
    cout<<endl;
}