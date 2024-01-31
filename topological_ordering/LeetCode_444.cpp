#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef unordered_map<int, vi> GRAPH;

#define _CRT_SECURE_NO_DEPRECATE
#define __elshorpagi__ (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)
#define fc(it, v) for (auto &(it) : (v))
#define yes cout << "YES\n"
#define no cout << "NO\n"

class Solution
{
public:
    Solution() { __elshorpagi__; }
    void add_directed_edge(GRAPH &graph, int from, int to)
    {
        graph[from].emplace_back(to);
    }
    vi topological_ordering(GRAPH &graph)
    {
        unordered_map<int, int> indegree;
        fc(i, graph)
        {
            fc(j, i.second) { ++indegree[j]; }
        }
        queue<int> ready_nodes;
        fc(it, graph)
        {
            if (!indegree.count(it.first))
                ready_nodes.push(it.first);
        }
        vi ordering;
        while (!ready_nodes.empty())
        {
            if (sz(ready_nodes) > 1) // cus we want a Single Uniqye Ordering
                return vi();
            int cur(ready_nodes.front());
            ready_nodes.pop();
            ordering.emplace_back(cur);
            fc(neighbour, graph[cur])
            {
                if (!(--indegree[neighbour]))
                    ready_nodes.push(neighbour);
            }
        }
        return (sz(ordering) == sz(graph) ? ordering : vi());
    }
    bool sequenceReconstruction(vi &org, vvi &sequences)
    {
        int len(sz(sequences));
        GRAPH graph(len);
        fc(seq, sequences) { graph[seq[0]] = vi(); }
        fc(seq, sequences)
        {
            fr(i, 1, sz(seq)) { add_directed_edge(graph, seq[i - 1], seq[i]); }
        }
        return topological_ordering(graph) == org;
    }
    void TEST()
    {
        vi org{1, 2, 3};
        vvi seqs{{1, 2}, {1, 3}};
        sequenceReconstruction(org, seqs) ? yes : no; // NO
        seqs = {{1, 2}, {1, 3}, {2, 3}};
        sequenceReconstruction(org, seqs) ? yes : no; // YES
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