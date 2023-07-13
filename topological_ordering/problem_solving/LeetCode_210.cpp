#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define cl(v) ((v).clear())
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)
#define fl(i, x, n) for (int i(x); i > n; --i)
#define fc(it, v) for (auto &(it) : (v))
#define sq(x) (x) * (x)
#define yes cout << "YES\n"
#define no cout << "NO\n"

class Solution
{
public:
    Solution() { Mesh_Ali; }
    void add_directed_edge(vvi &graph, int from, int to)
    {
        graph[from].emplace_back(to);
    }
    vi topological_ordering(vvi &graph)
    {
        vi indegree(sz(graph));
        
    }
    vi findOrder(int numCourses, vvi &prerequisites)
    {
        vvi graph(numCourses);
        fc(pair, prerequisites) { add_directed_edge(graph, pair[0], pair[1]); }
        return topological_ordering(graph);
    }
    void TEST() {}
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