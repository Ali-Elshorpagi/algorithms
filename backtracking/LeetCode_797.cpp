#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define _CRT_SECURE_NO_DEPRECATE
#define Sukuna (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define fc(it, v) for (auto &(it) : (v))

class Solution
{
public:
    Solution() { Sukuna; }
    void backtracking(vvi &graph, vi &current_path, vvi &ans, int node)
    {
        current_path.push_back(node); // update the state
        if (node == sz(graph) - 1)
            ans.push_back(current_path);
        fc(it, graph[node]) { backtracking(graph, current_path, ans, it); }
        current_path.pop_back(); // undo the state
    }
    vvi allPathsSourceTarget(vvi &graph)
    {
        vvi ans;
        vi current_path;
        backtracking(graph, current_path, ans, 0);
        return ans;
    }
    void TEST()
    {
        vvi graph{{1, 2}, {3}, {3}, {}};
        vvi result = allPathsSourceTarget(graph);
        fc(it, result)
        {
            fc(jt, it) { cout << jt << ' '; } // [[0, 1, 3], [0, 2, 3]]
            cout << edl;
        }
        cout << edl << "**************" << edl << edl;
        graph = {{4, 3, 1}, {3, 2, 4}, {3}, {4}, {}};
        result = allPathsSourceTarget(graph);
        fc(it, result)
        {
            fc(jt, it) { cout << jt << ' '; }
            //[[0, 4], [0, 3, 4], [0, 1, 3, 4], [0, 1, 2, 3, 4], [0, 1, 4]]
            cout << edl;
        }
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
        cout << "Case #" << tc + 1 << edl, sol.TEST();
    cout << edl << "DONE" << edl;
    return (0);
}