#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define cl(v) ((v).clear())
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)
#define fl(i, x, n) for (int i(x); i > n; --i)
#define fc(it, v) for (auto &(it) : (v))
#define sq(x) (x) * (x)
#define yes cout << "YES\n"
#define no cout << "NO\n"

// link : https://leetcode.com/problems/minimum-operations-to-convert-number/
// code : leetcode 2059

class Solution
{
public:
    Solution() { Mesh_Ali; }
    int minimumOperations(vi &nums, int start, int goal)
    {
        return -2;
    }
    void TEST()
    {
        vi arr{2, 4, 12};
        int start(2), goal(12);
        cout << minimumOperations(arr, start, goal) << edl; // 2
        arr = {2, 8, 16};
        start = 0, goal = 1;
        cout << minimumOperations(arr, start, goal) << edl; // -1
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