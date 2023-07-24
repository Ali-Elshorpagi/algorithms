#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define edl '\n'

// link : https://leetcode.com/problems/longest-common-subsequence/
// name : LeetCode 1143

class Solution // O(N * M) time & space
{
    vvi memory; // for memoization
public:
    Solution() { Mesh_Ali, memory.resize(1005, vi(1005, -1)); }
    int dp(int idx1, int idx2, string &s1, string &s2)
    {
        if (idx1 >= sz(s1) || idx2 >= sz(s2))
            return 0;
        auto &ref(memory[idx1][idx2]);
        if (ref != -1)
            return ref;
        int pick(0);
        if (s1[idx1] == s2[idx2])
            pick = 1 + dp(idx1 + 1, idx2 + 1, s1, s2); // pick
        int leave1(dp(idx1, idx2 + 1, s1, s2));
        int leave2(dp(idx1 + 1, idx2, s1, s2));
        return ref = max({pick, leave1, leave2});
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        return dp(0, 0, text1, text2);
    }
    void TEST()
    {
        // string text1("abcde"), text2("ace");
        // cout << longestCommonSubsequence(text1, text2) << edl; // 3
        // string text1("abc"), text2("def");
        // cout << longestCommonSubsequence(text1, text2) << edl; // 0
        string text1("pmjghexybyrgzczy"), text2("hafcdqbgncrcbihkd");
        cout << longestCommonSubsequence(text1, text2) << edl; // 4
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