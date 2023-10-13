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
#define fl(i, x, n) for (int i(x); i > n; --i)

class Solution
{
    vi memory; // for Memoization

public:
    Solution() { Sukuna; }
    int answer(int idx)
    {
        if (idx < 0)
            return 0;
        return memory[idx];
    }
    int minHeightShelves(vvi &books, int shelfWidth)
    {
        memory.assign(1005, -1);
        fr(i, 0, sz(books))
        {
            auto &ref(memory[i]);
            int total_width(0), mx_height(0), _min(INT_MAX);
            fl(k, i, -1)
            {
                total_width += books[k][0];
                if (total_width > shelfWidth)
                    break;
                mx_height = max(mx_height, books[k][1]);
                _min = min(_min, mx_height + answer(k - 1));
            }
            ref = _min;
        }
        return memory[sz(books) - 1];
    }
    void TEST()
    {
        vvi books{{1, 1}, {2, 3}, {2, 3}, {1, 1}, {1, 1}, {1, 1}, {1, 2}};
        int shelfWidth(4);
        cout << minHeightShelves(books, shelfWidth) << edl; // 6
        books = {{1, 3}, {2, 4}, {3, 2}};
        shelfWidth = 6;
        cout << minHeightShelves(books, shelfWidth) << edl; // 4
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