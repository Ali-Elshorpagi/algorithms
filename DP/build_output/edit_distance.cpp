#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define _CRT_SECURE_NO_DEPRECATE
#define __elshorpagi__ (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define edl '\n'

class Solution
{
    // for Memoization
    vvi memory;

public:
    Solution() { __elshorpagi__; }
    int dp_forward(string &s1, string &s2, int idx1, int idx2)
    {
        if (idx1 >= sz(s1))
            return sz(s2) - idx2; // insert or delete remaining of s2
        if (idx2 >= sz(s2))
            return sz(s1) - idx1; // insert or delete remaining of s1

        auto &ref(memory[idx1][idx2]);
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
    void dp_print(string &s1, string &s2, int idx1, int idx2)
    {
        if (idx1 >= sz(s1) && idx2 >= sz(s2))
            return;
        if (idx1 >= sz(s1))
        {
            cout << "In " << s1 << " insert at the end " << s2.substr(idx2) << edl;
            return;
        }
        if (idx2 >= sz(s2))
        {
            cout << "In " << s2 << " insert at the end " << s1.substr(idx1) << edl;
            return;
        }

        int optimal(dp_forward(s1, s2, idx1, idx2));
        if (s1[idx1] == s2[idx2]) // skip
        {
            dp_print(s1, s2, idx1 + 1, idx2 + 1);
            return;
        }

        int replace_(1 + dp_forward(s1, s2, idx1 + 1, idx2 + 1)),
            delete_(1 + dp_forward(s1, s2, idx1 + 1, idx2));
        if (optimal == replace_)
        {
            cout << "In " << s1 << " replace letter at original idx "
                 << idx1 << " letter " << s1[idx1] << " to letter " << s2[idx2] << edl;
            dp_print(s1, s2, idx1 + 1, idx2 + 1);
        }
        else if (optimal == delete_)
        {
            cout << "In " << s1 << " delete original idx "
                 << idx1 << " letter " << s1[idx1] << edl;
            dp_print(s1, s2, idx1 + 1, idx2);
        }
        else // insert
        {
            cout << "In " << s1 << " insert at original idx "
                 << idx1 << " letter " << s2[idx2] << edl;
            dp_print(s1, s2, idx1, idx2 + 1);
        }
    }
    int edit_distance(string s1, string s2)
    {
        memory.assign(505, vi(505, -1));
        cout << "Steps for: " << s1 << " to " << s2 << edl;
        dp_print(s1, s2, 0, 0);
        return dp_forward(s1, s2, 0, 0);
    }
    void TEST()
    {
        cout << edit_distance("xy", "axy") << " steps in total" << edl << edl
             << edit_distance("axy", "xy") << " steps in total" << edl << edl
             << edit_distance("axy", "bxy") << " steps in total" << edl << edl
             << edit_distance("axy", "a") << " steps in total" << edl << edl
             << edit_distance("a", "axy") << " steps in total" << edl << edl
             << edit_distance("axy", "axy") << " steps in total" << edl << edl
             << edit_distance("horse", "ros") << " steps in total" << edl << edl
             << edit_distance("park", "spake") << " steps in total" << edl << edl
             << edit_distance("spake", "park") << " steps in total" << edl << edl
             << edit_distance("spakehz", "park") << " steps in total" << edl << edl;
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