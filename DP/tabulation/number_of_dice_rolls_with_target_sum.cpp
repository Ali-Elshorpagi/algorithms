#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define _CRT_SECURE_NO_DEPRECATE
#define Sukuna (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)

class Solution
{
    vvi memory; // for Memoization
    const int mod = 1e9 + 7;

public:
    Solution() { Sukuna; }
    int answer(int n, int target)
    {
        if (target < 0)
            return 0;
        if (n < 0)
            return !target ? 1 : 0;
        return memory[n][target];
    }
    int numRollsToTarget(int n, int k, int target)
    {
        memory.assign(35, vi(1005, 0)), memory[0][0] = 1;
        fr(dice, 1, n + 1)
        {
            fr(tar, 1, target + 1)
            {
                auto &ref(memory[dice][tar]);
                fr(face, 1, min(tar, k) + 1)
                {
                    ref += answer(dice - 1, tar - face);
                    ref %= mod;
                }
            }
        }
        return memory[n][target];
    }
    void TEST()
    {
        int n(1), k(6), target(3);
        cout << numRollsToTarget(n, k, target) << edl; // 1
        n = 2, k = 6, target = 7;
        cout << numRollsToTarget(n, k, target) << edl; // 6
        n = 30, k = 30, target = 500;
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