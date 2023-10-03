#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

#define _CRT_SECURE_NO_DEPRECATE
#define Sukuna (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define edl '\n'

class Solution
{
    vi memory; // for Memoization
public:
    Solution() { Sukuna, memory.resize(105, -1); }
    int dp(string str, int idx)
    {
        if (idx >= sz(str))
            return 1;
        if (str[idx] == '0')
            return 0;
        if (idx == sz(str) - 1)
            return 1;
        auto &ref(memory[idx]);
        if (ref != -1)
            return ref;
        int num(stoi(str.substr(idx, 2)));
        ref = dp(str, idx + 1);
        if (num >= 1 && num <= 26)
            ref += dp(str, idx + 2);
        return ref;
    }
    int numDecodings(string s) { return dp(s, 0); }
    void TEST()
    {
        string str("226");
        cout << numDecodings(str) << edl; // 3
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