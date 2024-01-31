#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define _CRT_SECURE_NO_DEPRECATE
#define __elshorpagi__ (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)
#define fc(it, v) for (auto &(it) : (v))

class Solution
{
    vi dr{-1, 0, 1, 0}; // Delta for: up, right, down, left
    vi dc{0, 1, 0, -1};

public:
    Solution() { __elshorpagi__; }
    bool is_valid(int new_row, int new_col, vvi &image)
    {
        if (new_row < 0 || new_row >= sz(image) || new_col < 0 || new_col >= sz(image[0]))
            return false;
        return true;
    }
    void dfs(vvi &image, int r, int c, int old_color, int new_color)
    {
        if (!is_valid(r, c, image) || old_color != image[r][c] || new_color == image[r][c])
            return;
        image[r][c] = new_color;

        fr(d, 0, 4) dfs(image, r + dr[d], c + dc[d], old_color, new_color);
    }
    vvi floodFill(vvi &image, int sr, int sc, int new_color)
    {
        int old_color(image[sr][sc]);
        if (old_color != new_color)
            dfs(image, sr, sc, old_color, new_color);
        return image;
    }
    void TEST()
    {
        vvi image{{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
        int sr(1), sc(1), new_color(2);
        vvi ans = floodFill(image, sr, sc, new_color);
        fc(i, ans)
        {
            fc(j, i)
            {
                cout << j << ' ';
            }
            cout << edl;
        }
        // Output: [[2,2,2],[2,2,0],[2,0,1]};
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
    {
        cout << "Case #" << tc + 1 << edl;
        sol.TEST();
        cout << edl << "DONE" << edl;
    }
    return (0);
}