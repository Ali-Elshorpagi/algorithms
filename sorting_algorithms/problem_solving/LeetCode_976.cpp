#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define fl(i, x, n) for (int i(x); i > n; --i)

class Solution
{
public:
    Solution() { Mesh_Ali; }
    int largestPerimeter(vi &arr)
    {
        sort(all(arr));
        int len(sz(arr));
        fl(i, len - 3, -1)
        {
            if (arr[i + 1] + arr[i] > arr[i + 2])
                return arr[i + 1] + arr[i] + arr[i + 2];
        }
        return 0;
    }

    void TEST()
    {
        vi arr{1, 2, 1, 10};
        cout << largestPerimeter(arr) << edl; // 0
        arr = {2, 1, 2};
        cout << largestPerimeter(arr) << edl; // 5
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