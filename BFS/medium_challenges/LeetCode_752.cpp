#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <utility>

using namespace std;

typedef vector<string> vs;

#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)

// link : https://leetcode.com/problems/open-the-lock/
// code : leetcode 752

class Solution
{
public:
    Solution() { Mesh_Ali; }
    // we can code as equation too:
    //                - for next : (ch - '0' + 1) % 10 + '0'
    //                - for prev : (ch - '0' - 1 + 10) % 10 + '0'

    pair<char, char> roll_it(char ch) // return prev - next, u can split them as u see in the next func
    {
        if (ch == '9')
            return {'8', '0'};
        if (ch == '0')
            return {'9', '1'};
        char tmp(ch);
        return {--tmp, ++ch};
    }
    char next(char ch)
    {
        if (ch == '9')
            return '0';
        return ++ch;
    }
    char prev(char ch)
    {
        if (ch == '0')
            return '9';
        return --ch;
    }
    int openLock(vs &deadends, string target)
    {
        if (target == "0000")
            return 0;
        // works as a visited array, and I put the deadends in it so it's considered visited
        unordered_set<string> visited{all(deadends)};
        if (visited.count("0000"))
            return -1;

        queue<string> nodes;
        nodes.push("0000");
        visited.insert("0000");
        for (int cnt(0), sze(sz(nodes)); !nodes.empty(); ++cnt, sze = sz(nodes))
        {
            while (sze--)
            {
                string cur(nodes.front());
                nodes.pop();
                fr(i, 0, 4) // traversing for each wheel
                {
                    cur[i] = roll_it(cur[i]).second; // next(cur[i])
                    if (cur == target)
                        return cnt + 1;

                    if (visited.insert(cur).second) // if the cur is already exist it will return false
                        nodes.push(cur);

                    // undo to the original cur, we can do it by copy it in another variable but this is faster
                    cur[i] = roll_it(roll_it(cur[i]).first).first; // prev(prev(cur[i]))
                    if (cur == target)
                        return cnt + 1;

                    if (visited.insert(cur).second)
                        nodes.push(cur);
                    cur[i] = roll_it(cur[i]).second; // next(cur[i]) // undo to the original cur
                }
            }
        }
        return -1;
    }
    void TEST()
    {
        vs deadends{"0201", "0101", "0102", "1212", "2002"};
        string target("0202");
        cout << openLock(deadends, target) << edl; // 6
        deadends = {"8887", "8889", "8878", "8898", "8788", "8988", "7888", "9888"};
        target = "8888";
        cout << openLock(deadends, target) << edl; // -1
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