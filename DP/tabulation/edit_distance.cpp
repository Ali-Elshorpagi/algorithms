#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

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
    vvi memory; // for Memoization

public:
    Solution() { Sukuna; }
    int answer(int i, int j)
    {
        if (i < 0 || j < 0)
            return max(i, j) + 1;
        assert(memory[i][j] != -1);
        return memory[i][j];
    }
    int minDistance(string word1, string word2)
    {
        int n(sz(word1)), m(sz(word2));

        if (!n || !m) // special case
            return max(n, m);

        memory.assign(505, vi(505, -1));
        fr(i, 0, n)
        {
            fr(j, 0, m)
            {
                auto &ref(memory[i][j]);
                if (word1[i] == word2[j])
                    ref = answer(i - 1, j - 1);
                else
                {
                    int replace_(1 + answer(i - 1, j - 1)),
                        delete_(1 + answer(i - 1, j)),
                        insert_(1 + answer(i, j - 1));
                    ref = min({replace_, delete_, insert_});
                }
            }
        }
        return memory[n - 1][m - 1];
    }
    void TEST()
    {
        string word1("horse"), word2("ros");
        cout << minDistance(word1, word2) << edl; // 3
        word1 = "intention", word2 = "execution";
        cout << minDistance(word1, word2) << edl; // 5
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