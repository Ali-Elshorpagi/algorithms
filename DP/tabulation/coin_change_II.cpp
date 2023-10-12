#include <iostream>
#include <vector>
#include <cassert>

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

public:
    Solution() { Sukuna; }
    int answer(int remaining, int idx)
    {
        if (!remaining)
            return 1;
        if (remaining < 0)
            return 0;
        if (idx < 0)
            return 0;
        assert(memory[remaining][idx] != -1);
        return memory[remaining][idx];
    }
    int change(int amount, vi &coins)
    {
        memory.assign(5005, vi(305, -1));
        fr(idx, 0, sz(coins))
        {
            fr(remaining, 0, amount + 1)
            {
                int pick(answer(remaining - coins[idx], idx)),
                    leave(answer(remaining, idx - 1));
                memory[remaining][idx] = pick + leave;
            }
        }
        return memory[amount][sz(coins) - 1];
    }
    void TEST()
    {
        int amount(5);
        vi coins{1, 2, 5};
        cout << change(amount, coins) << edl; // 4
        amount = 10;
        coins = {10};
        cout << change(amount, coins) << edl; // 1
        amount = 3;
        coins = {2};
        cout << change(amount, coins) << edl; // 0
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