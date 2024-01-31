#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

#define _CRT_SECURE_NO_DEPRECATE
#define __elshorpagi__ (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)

class Solution
{
public:
    Solution() { __elshorpagi__; }
    void wiggleSort_0(vi &arr) // O(N * log(N)) time, O(1) space
    {
        sort(all(arr));
        int len(sz(arr));
        for (int i(1); i < len - 1; i += 2)
            swap(arr[i], arr[i + 1]);
    }
    void wiggleSort_1(vi &arr) // O(N) time, O(1) space
    {
        int len(sz(arr));
        fr(i, 0, len - 1)
        {
            if ((i % 2 == 0 && arr[i] > arr[i + 1]) || (i % 2 != 0 && arr[i] < arr[i + 1]))
                swap(arr[i], arr[i + 1]);
        }
    }
    void TEST() {}
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