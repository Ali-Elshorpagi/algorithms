#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define _CRT_SECURE_NO_DEPRECATE
#define __elshorpagi__ (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define fc(it, v) for (auto &(it) : (v))

class Solution
{
public:
    Solution() { __elshorpagi__; }
    void dfs(unordered_map<int, vi> &graph, unordered_map<int, int> &visited, vi &ans, int start)
    {
        visited[start] = 1;
        ans.emplace_back(start);
        fc(it, graph[start])
        {
            if (!visited[it])
                dfs(graph, visited, ans, it);
        }
    }
    vi restoreArray(vvi &adjacentPairs)
    {
        // adjacentPairs == edges in graph;
        unordered_map<int, vi> graph;
        fc(it, adjacentPairs)
        {
            graph[it[0]].emplace_back(it[1]);
            graph[it[1]].emplace_back(it[0]);
        }
        int start;
        fc(it, graph)
        {
            if (sz(it.second) == 1)
            {
                start = it.first;
                break;
            }
        }
        unordered_map<int, int> visited;
        vi ans;
        dfs(graph, visited, ans, start);
        return ans;
    }
    void TEST()
    {
        vvi pairs{{2, 1}, {3, 4}, {3, 2}};
        vi ans = restoreArray(pairs);
        fc(it, ans) cout << it << ' ';
        cout << edl;
        // output : 1, 2, 3, 4 and there are multiple solutions;
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
