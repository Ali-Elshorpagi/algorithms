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
    vvi memory;
    vi memory_;

public:
    Solution() { Sukuna, memory_.resize(1005, -1), memory.resize(1005, vi(1005, -1)); }
    // Case 1 : I keep the book in current shelf
    // Case 2 : I keep the book in next shelf
    int dp(vvi &books, int idx, int shelfwidth, int remaing_width, int max_height) // O(N^2) time, O(N^2) space
    {
        if (idx >= sz(books))
            return max_height;
        auto &ref(memory[idx][remaing_width]);
        if (ref != -1)
            return ref;
        int curr_shelf(INT_MAX), next_shelf(INT_MAX),
            book_width(books[idx][0]), book_height(books[idx][1]);

        if (book_width <= remaing_width)
            curr_shelf = dp(books, idx + 1, shelfwidth, remaing_width - book_width, max(max_height, book_height));
        next_shelf = max_height + dp(books, idx + 1, shelfwidth, shelfwidth - book_width, book_height);

        return ref = min(curr_shelf, next_shelf);
    }
    int dp_(vvi &books, int idx, int shelfwidth) // O(N^2) time, O(N) space
    {
        if (idx >= sz(books))
            return 0;

        auto &ref(memory_[idx]);
        if (ref != -1)
            return ref;

        ref = INT_MAX;
        int total_width(0), mx_height(0);
        fr(k, idx, sz(books))
        {
            total_width += books[k][0];
            mx_height = max(mx_height, books[k][1]);

            if (total_width > shelfwidth)
                break;
            ref = min(ref, mx_height + dp_(books, k + 1, shelfwidth));
        }
        return ref;
    }
    int minHeightShelves(vvi &books, int shelfWidth)
    {
        return dp_(books, 0, shelfWidth);
    }
    int minHeightShelves_(vvi &books, int shelfWidth)
    {
        return dp(books, 0, shelfWidth, shelfWidth, 0);
    }
    void TEST()
    {
        // vvi books{{1, 1}, {2, 3}, {2, 3}, {1, 1}, {1, 1}, {1, 1}, {1, 2}};
        // int shelfWidth(4);
        // cout << minHeightShelves_(books, shelfWidth) << edl; // 6
        vvi books{{1, 3}, {2, 4}, {3, 2}};
        int shelfWidth(6);
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