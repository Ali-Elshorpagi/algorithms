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

class Solution
{
    vvi memory;
    string str;

public:
    Solution() { __elshorpagi__, memory.resize(1005, vi(1005, -1)); }
    int is_palindrome(int start, int end)
    {
        if (start >= end)
            return 1;
        auto &ref(memory[start][end]);
        if (ref != -1)
            return ref;
        if (str[start] != str[end])
            return 0;
        return ref = is_palindrome(start + 1, end - 1);
    }
    string longestPalindrome(string s)
    {
        str = s;
        int len(sz(s)), max_len(0), start_idx(-1);
        fr(i, 0, len)
        {
            fr(j, 0, len)
            {
                int tmp_len(j - i + 1); // the length of the current substring
                if (tmp_len > max_len && is_palindrome(i, j))
                    max_len = tmp_len, start_idx = i;
            }
        }
        return s.substr(start_idx, max_len);
    }
    void TEST()
    {
        // string str("babad");
        // cout << longestPalindrome(str) << edl; // bab
        string str("cbbd");
        cout << longestPalindrome(str) << edl; // bb
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