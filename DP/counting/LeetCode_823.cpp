#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define _CRT_SECURE_NO_DEPRECATE
#define __elshorpagi__ (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define cl(v) ((v).clear())
#define edl '\n'
#define fc(it, v) for (auto &(it) : (v))

class Solution
{
    unordered_map<int, ll> memory; // for Memoization
    unordered_set<int> arr;
    const int mod = 1e9 + 7;

public:
    Solution() { __elshorpagi__; }
    ll dp(int x)
    {
        if (memory.count(x))
            return memory[x];
        ll cnt(1);
        fc(it, arr)
        {
            if (x % it == 0 && arr.count(x / it))
            {
                ll ways(dp(it) * dp(x / it));
                ways %= mod, cnt += ways, cnt %= mod;
            }
        }
        return memory[x] = cnt;
    }
    int numFactoredBinaryTrees(vi &nums)
    {
        // leetcode share global variables between cases, you must clean
        cl(arr), cl(memory);
        arr.insert(all(nums));
        ll ans(0);
        fc(it, arr) { ans += dp(it), ans %= mod; }
        return ans;
    }
    void TEST()
    {
        // vi arr{2, 4};
        // cout << numFactoredBinaryTrees(arr) << edl; // 3
        vi arr{2, 4, 5, 10};
        cout << numFactoredBinaryTrees(arr) << edl; // 7
    }
};

int main()
{
    Solution sol;
    // freopen("../../test/input.txt", "r", stdin);
    freopen("../../test/output.txt", "w", stdout);
    int tc(1);
    // cin >> tc;
    while (tc--)
        cout << "Case #" << tc + 1 << edl, sol.TEST();
    cout << edl << "DONE" << edl;
    return (0);
}