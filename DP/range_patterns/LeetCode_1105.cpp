#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define edl '\n'

class Solution
{
    vvi memory;

public:
    Solution() { Mesh_Ali, memory.resize(1005, vi(1005, -1)); }
    // Case 1 : I keep the book in current shelf
    // Case 2 : I keep the book in next shelf
    int dp(vvi &books, int idx, int shelfwidth, int remaing_width, int max_height)
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
    int minHeightShelves(vvi &books, int shelfWidth)
    {
        return dp(books, 0, shelfWidth, shelfWidth, 0);
    }
    void TEST()
    {
        // vvi books{{1, 1}, {2, 3}, {2, 3}, {1, 1}, {1, 1}, {1, 1}, {1, 2}};
        // int shelfWidth(4);
        // cout << minHeightShelves(books, shelfWidth) << edl; // 6
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