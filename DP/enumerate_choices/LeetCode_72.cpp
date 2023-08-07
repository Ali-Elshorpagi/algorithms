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

class Solution
{
    vvi memeory; // for memoization
public:
    Solution() { Mesh_Ali, memeory.resize(505, vi(505, -1)); }
    int dp_forward(string &s1, string &s2, int idx1, int idx2)
    {
        if (idx1 >= sz(s1))
            return sz(s2) - idx2; // insert or delete remaining of s2
        if (idx2 >= sz(s2))
            return sz(s1) - idx1; // insert or delete remaining of s1

        auto &ref(memeory[idx1][idx2]);
        if (ref != -1)
            return ref;

        if (s1[idx1] == s2[idx2])
            ref = dp_forward(s1, s2, idx1 + 1, idx2 + 1);
        else
        {
            int replace_(1 + dp_forward(s1, s2, idx1 + 1, idx2 + 1)),
                delete_(1 + dp_forward(s1, s2, idx1 + 1, idx2)),
                insert_(1 + dp_forward(s1, s2, idx1, idx2 + 1));
            ref = min({replace_, delete_, insert_});
        }
        return ref;
    }
    int dp_backward(string &s1, string &s2, int idx1, int idx2)
    {
        if (idx1 < 0 || idx2 < 0)
            return max(idx1, idx2) + 1;

        auto &ref(memeory[idx1][idx2]);
        if (ref != -1)
            return ref;

        if (s1[idx1] == s2[idx2])
            ref = dp_backward(s1, s2, idx1 - 1, idx2 - 1);
        else
        {
            int replace_(1 + dp_backward(s1, s2, idx1 - 1, idx2 - 1)),
                delete_(1 + dp_backward(s1, s2, idx1 - 1, idx2)),
                insert_(1 + dp_backward(s1, s2, idx1, idx2 - 1));
            ref = min({replace_, delete_, insert_});
        }
        return ref;
    }
    int minDistance(string word1, string word2)
    {
        // return dp_forward(word1, word2, 0, 0);
        return dp_backward(word1, word2, sz(word1) - 1, sz(word2) - 1);
    }
    void TEST()
    {
        string word1("horse"), word2("ros");
        cout << minDistance(word1, word2) << edl; // 3
        word1 = "intention", word2 = "execution";
        // cout << minDistance(word1, word2) << edl; // 5
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