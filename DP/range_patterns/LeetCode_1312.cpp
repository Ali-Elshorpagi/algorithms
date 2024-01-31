#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define _CRT_SECURE_NO_DEPRECATE
#define __elshorpagi__ (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define edl '\n'

class Solution
{
    vvi memory;

public:
    Solution() { __elshorpagi__, memory.resize(505, vi(505, -1)); }
    int dp(string &str, int start_idx, int end_idx)
    {
        if (start_idx >= end_idx)
            return 0;
        auto &ref(memory[start_idx][end_idx]);
        if (ref != -1)
            return ref;
        if (str[start_idx] == str[end_idx])
            return ref = dp(str, start_idx + 1, end_idx - 1);
        int insertion_after(1 + dp(str, start_idx, end_idx - 1));
        int insertion_before(1 + dp(str, start_idx + 1, end_idx));
        return ref = min(insertion_after, insertion_before);
    }
    int minInsertions(string s)
    {
        return dp(s, 0, sz(s) - 1);
    }
    void TEST()
    {
        // string str("zzazz");
        // cout << minInsertions(str) << edl; // 0
        // string str("mbadm");
        // cout << minInsertions(str) << edl; // 2
        string str("leetcode");
        cout << minInsertions(str) << edl; // 5
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