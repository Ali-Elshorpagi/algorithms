#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

#define _CRT_SECURE_NO_DEPRECATE
#define Sukuna (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)
#define yes cout << "YES\n"
#define no cout << "NO\n"

class Solution
{

public:
    Solution() { Sukuna; }
    int largestRectangleArea(vi &heights) {}
    void TEST()
    {
        vi heights{2, 1, 5, 6, 2, 3};
        cout << largestRectangleArea(nums) << edl; // 10
        heights = {2, 4};
        cout << largestRectangleArea(nums) << edl; // 4
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