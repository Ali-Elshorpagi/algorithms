#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

#define _CRT_SECURE_NO_DEPRECATE
#define Sukuna (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define edl '\n'

class Solution
{
    vvll memory; // for Memoization
    string str;

public:
    Solution() { Sukuna; }
    ll dp(int left, int right)
    {
        auto &ref(memory[left][right]);
        if (ref != -1)
            return ref;

        if (left == right)
            return ref = 1;
        else if (left == right - 1)
            return ref = 2 + (str[left] == str[right]);

        ref = 0;
        if (str[left] == str[right])
            ref = 1 + dp(left + 1, right - 1);

        ll remove_left(dp(left + 1, right)),
            remove_right(dp(left, right - 1)),
            duplicates(dp(left + 1, right - 1));
        ref += (remove_left + remove_right - duplicates);

        return ref;
    }
    void TEST()
    {
        cin >> str;
        memory.assign(65, vll(65, -1));
        cout << dp(0, sz(str) - 1) << edl;
    }
};

int main()
{
    Solution sol;
    freopen("../../test/input.txt", "r", stdin);
    freopen("../../test/output.txt", "w", stdout);
    int tc(1);
    cin >> tc;
    while (tc--)
        sol.TEST();
    return (0);
    // intput:
    // 3
    // BAOBAB
    // AAAA
    // ABA
    // output:
    // 22
    // 15
    // 5
}