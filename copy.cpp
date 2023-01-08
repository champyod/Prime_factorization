#include <bits/stdc++.h>
using namespace std;

bool notprime[1000001];
vector<int> prime = {};
vector<int> factor = {};

int main () {

    prime.push_back(2);
    for (int i = 3; i < 1000000; i+=2) {
        if (notprime[i]) continue; // continue mean skip that round
        // else {
        prime.push_back(i);
        for (int j = i+i; j < 1000000; j+=i) notprime[j] = 1; // 1 mean true
        // }
    }
    // Now vector prime contain all of positive prime number from 1-1000000

    int n, t; cin >> n;
    t = n;
    if (n > 1000000) {
        cout << "invalid input!";
        return 0;
    }
    for (auto x : prime) {
        if (n == 1) break; // break mean end of that loop
        while (n%x == 0) {
            n /= x;
            factor.push_back(x);
        }
    }

    if (factor.size() <= 0) cout << t << " have none prime factor.";
    else if (factor.size() == 1) cout << "Prime factor of " << t << " is ";
    else cout << "Prime factors of " << t << " are ";
    for (int i = 0; i < factor.size(); ++i) {
        cout << factor[i];
        if (i != factor.size()-1) cout << " x ";
        else cout << ".";
    }

    return 0;
}