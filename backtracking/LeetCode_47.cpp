#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define _CRT_SECURE_NO_DEPRECATE
#define Sukuna (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define cl(v) ((v).clear())
#define edl '\n'
#define fc(it, v) for (auto &(it) : (v))
#define fr(i, x, n) for (int i(x); i < n; ++i)

class Solution
{
    vvi ans;
    vi prefix;

public:
    Solution() { Sukuna; }
    void backtracking() {}
    vvi permuteUnique(vi &nums) { return ans; }
    void TEST()
    {
        vi nums{1, 1, 2};
        vvi result = permuteUnique(nums);
        fc(it, result)
        {
            fc(jt, it) { cout << jt << ' '; }
            // [[1, 1, 2], [1, 2, 1], [2, 1, 1]];
            cout << edl;
        }
        nums = {1, 2, 3}, result = permuteUnique(nums);
        fc(it, result)
        {
            fc(jt, it) { cout << jt << ' '; }
            // [[1, 2, 3],[1, 3, 2],[2, 1, 3],[2, 3, 1],[3, 1, 2],[3, 2, 1]];
            cout << edl;
        }
    }
};

int main()
{
    Solution sol;
    // freopen("../test/input.txt", "r", stdin);
    freopen("../test/output.txt", "w", stdout);
    int tc(1);
    // cin >> tc;
    while (tc--)
        cout << "Case #" << tc + 1 << edl, sol.TEST();
    cout << edl << "DONE" << edl;
    return (0);
}