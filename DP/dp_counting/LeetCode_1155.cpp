#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)

class Solution
{
    vvi memory; // for Memoization
    const ll mod = 1e9 + 7;

public:
    Solution() { Mesh_Ali, memory.resize(35, vi(1005, -1)); }
    int min_(int &a, int &b) { return a < b ? a : b; }
    ll dp(int n, int k, int target)
    {
        if (!n)
            return !target ? 1 : 0;
        if (target <= 0)
            return 0;
        auto &ref(memory[n][target]);
        if (ref != -1)
            return ref;
        ref = 0;
        fr(face, 1, min_(target, k) + 1)
        {
            ref += dp(n - 1, k, target - face);
            ref %= mod;
        }
        return ref;
    }
    int numRollsToTarget(int n, int k, int target)
    {
        return dp(n, k, target);
    }
    void TEST()
    {
        // int n(1), k(6), target(3);
        // cout << numRollsToTarget(n, k, target) << edl; // 1
        // int n(2), k(6), target(7);
        // cout << numRollsToTarget(n, k, target) << edl; // 6
        int n(30), k(30), target(500);
        cout << numRollsToTarget(n, k, target) << edl; // 222616187
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