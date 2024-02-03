#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define _CRT_SECURE_NO_DEPRECATE
#define __elshorpagi__ (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)
#define fc(it, v) for (auto &(it) : (v))

typedef vector<int> vi;
typedef unordered_set<int> usi;
typedef unordered_map<int, usi> GRAPH;

void add_directed_edge(GRAPH &graph, int from, int to)
{
    graph[from].insert(to);
}

void build_graph(GRAPH &graph, vi &ppid, vi &pid)
{
    int len(sz(ppid));
    fr(i, 0, len)
        add_directed_edge(graph, ppid[i], pid[i]);
}

void dfs(GRAPH &graph, int node, usi &visited)
{
    visited.insert(node);
    fc(neighbour, graph[node])
    {
        if (!visited.count(neighbour))
            dfs(graph, neighbour, visited);
    }
}

vi reachability(GRAPH &graph, int node)
{
    usi visited;
    dfs(graph, node, visited);
    return vi(all(visited));
}

class Solution
{
public:
    Solution() { __elshorpagi__; }
    vi killProcess(vi &pid, vi &ppid, int kill)
    {
        GRAPH graph;
        build_graph(graph, ppid, pid);
        return reachability(graph, kill);
    }
    void TEST()
    {
        vi pid{1, 3, 10, 5}, ppid{3, 0, 5, 3};
        int kill(5);
        vi ans = killProcess(pid, ppid, kill);
        fc(it, ans) cout << it << ' '; // 10 5
    }
};

int main()
{
    Solution sol;
    // freopen("../test/input.txt", "r", stdin);
    freopen("../test/output.txt", "w", stdout);
    int tc(1);
    // cin >> tc;
    while (tc--)
    {
        cout << "Case #" << tc + 1 << edl;
        sol.TEST();
        cout << edl << "DONE" << edl;
    }
    return (0);
}