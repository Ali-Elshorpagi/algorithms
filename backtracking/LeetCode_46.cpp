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
#define fc(it, v) for (auto &(it) : (v))
#define yes cout << "YES\n"
#define no cout << "NO\n"

class Solution
{
public:
    Solution() { Sukuna; }
    vvi permute(vi &nums) {}
    void TEST()
    {
        vi nums{1, 2, 3};
        vvi result = permute(nums);
        fc(it, result)
        {
            fc(jt, it) { cout << jt << ' '; }
            // [[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]];
            cout << edl;
        }
        nums = {0, 1}, result = permute(nums);
        fc(it, result)
        {
            fc(jt, it) { cout << jt << ' '; }
            // [[0, 1], [1, 0]];
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