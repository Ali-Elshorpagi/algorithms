#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define _CRT_SECURE_NO_DEPRECATE
#define __elshorpagi__ (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)

class Solution
{
    // for Memoization
    vvi memory;
    vvi bracket;
    vi rows, cols;
    int ans;

public:
    Solution() { __elshorpagi__, bracket.resize(105, vi(105, -1)); }
    char to_char(int idx)
    {
        assert(idx < 26);
        return char('A' + idx);
    }
    int dp(int start_idx, int end_idx)
    {
        if (start_idx == end_idx)
            return 0; // a single matrix: no multiplication

        auto &ref(memory[start_idx][end_idx]);
        if (ref != -1)
            return ref;

        ref = INT_MAX;
        fr(k, start_idx, end_idx)
        {
            int blocks_mult(rows[start_idx] * cols[end_idx] * cols[k]),
                sub1(dp(start_idx, k)),
                sub2(dp(k + 1, end_idx)),
                total_k(blocks_mult + sub1 + sub2);
            if (ref > total_k)
                ref = total_k, bracket[start_idx][end_idx] = k; // save the optimal choice
        }
        return ref;
    }
    void dp_print(int start_idx, int end_idx)
    {
        if (start_idx == end_idx)
        {
            cout << to_char(start_idx);
            return;
        }
        int optimal(dp(start_idx, end_idx));
        if (!start_idx && end_idx == sz(rows) - 1) // first call
            ans = optimal;

        int k(bracket[start_idx][end_idx]);
        cout << '(';
        dp_print(start_idx, k);   // print the first split
        dp_print(k + 1, end_idx); // print the second split
        cout << ')';
    }
    int mcm(const vvi &data)
    {
        rows.resize(sz(data)), cols.resize(sz(data));
        fr(i, 0, sz(data)) { rows[i] = data[i][0], cols[i] = data[i][1]; }
        memory.resize(105, vi(105, -1));
        dp_print(0, sz(rows) - 1);
        cout << edl;
        return ans;
    }
    void TEST()
    {
        cout << mcm({{2, 3}}) << edl << edl
             << mcm({{2, 3}, {3, 4}}) << edl << edl
             << mcm({{1, 2}, {2, 3}, {3, 4}}) << edl << edl
             << mcm({{5, 10}, {10, 19}, {19, 7}, {7, 5}}) << edl << edl
             << mcm({{40, 20}, {20, 30}, {30, 10}, {10, 30}}) << edl << edl;
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