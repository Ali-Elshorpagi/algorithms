#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define _CRT_SECURE_NO_DEPRECATE
#define __elshorpagi__ (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)
#define fc(it, v) for (auto &(it) : (v))

class Solution // O(N *log(N) + M) time, O(N + M) space, where N is sz(s), M is no.Pairs
{
public:
    Solution() { __elshorpagi__; }
    void dfs(vvi &graph, vi &visited, int node, vi &indices)
    {
        visited[node] = 1;
        indices.emplace_back(node);
        fc(it, graph[node])
        {
            if (!visited[it]) // instead of base case
                dfs(graph, visited, it, indices);
        }
    }
    string smallestStringWithSwaps(string s, vvi &pairs)
    {
        vvi graph(sz(s));
        fc(it, pairs)
        {
            graph[it[1]].emplace_back(it[0]);
            graph[it[0]].emplace_back(it[1]);
        }
        int len(sz(graph));
        vi visited(len);
        fr(i, 0, len)
        {
            if (!visited[i])
            {
                vi indices;
                dfs(graph, visited, i, indices);
                string str(""); // connected letters;
                fc(it, indices) str += s[it];
                sort(all(str)), sort(all(indices));
                fr(i, 0, sz(indices)) s[indices[i]] = str[i];
            }
        }
        return s;
    }
    void TEST()
    {
        string str("dcab");
        vvi pairs{{0, 3}, {1, 2}, {0, 2}};
        cout << smallestStringWithSwaps(str, pairs) << edl;
        // output : abcd
    }
};

int main()
{
    Solution sol;
    // freopen("test/input.txt", "r", stdin);
    freopen("test/output.txt", "w", stdout);
    int tc(1);
    // cin >> tc;
    while (tc--)
        cout << "Case #" << tc + 1 << edl, sol.TEST();
    cout << edl << "DONE" << edl;
    return (0);
}
