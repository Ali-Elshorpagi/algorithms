#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef vector<int> vi;
typedef unordered_map<int, vi> GRAPH;
typedef unordered_set<int> unsi;

#define _CRT_SECURE_NO_DEPRECATE
#define __elshorpagi__ (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define fc(it, v) for (auto &(it) : (v))

class Solution // O(N) time, O(N) space
{
public:
    Solution() { __elshorpagi__; }
    int dfs(GRAPH &graph, unsi &visited, int node)
    {
        visited.insert(node);
        fc(it, graph[node])
        {
            if (!visited.count(it))
                return 1 + dfs(graph, visited, it);
        }
        return 1;
    }
    int longestConsecutive(vi &nums)
    {
        unsi uniq_nums(all(nums)); // to remove the duplicate numbers, and it's O(1);
        if (!sz(uniq_nums))
            return 0;
        GRAPH graph;
        fc(it, uniq_nums)
        {
            if (uniq_nums.count(it + 1))
            {
                graph[it].emplace_back(it + 1);
                graph[it + 1].emplace_back(it);
            }
        }
        unsi visited;
        int ans(1);
        fc(it, graph)
        {
            if (!visited.count(it.first) && sz(it.second) == 1)
                ans = max(ans, dfs(graph, visited, it.first));
        }
        return ans;
    }
    void TEST()
    {
        vi nums{100, 4, 200, 1, 3, 2};
        cout << longestConsecutive(nums) << ' ';
        nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
        cout << longestConsecutive(nums) << edl;
        // output 1: 4 9
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