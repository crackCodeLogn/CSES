//Weird algorithm
//Collatz conjecture which states that the above algorithm terminates for every value of n

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    while (true)
    {
        cout << n << " ";
        if (n==1) break;
        if (n%2==0) n/=2;
        else n=n*3+1;
    }
}