#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>

using namespace std;

typedef vector<int> vi;
typedef map<int, vi> GRAPH; // u can use unordered_map, but there's a bug in this problem in LeetCode

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
    int dfs_recursive(GRAPH &graph, int node)
    {
        fc(it, graph[node]) { return 1 + dfs_recursive(graph, it); }
        return 1;
    }
    int dfs_iterative(GRAPH &graph, int node)
    {
        int len(1);
        while (sz(graph[node]))
            node = graph[node][0], ++len;
        return len;
    }
    int longestConsecutive(vi &nums)
    {
        unordered_set<int> uniq_nums(all(nums));
        if (!sz(uniq_nums))
            return 0;
        GRAPH graph;
        fc(it, uniq_nums)
        {
            if (uniq_nums.count(it + 1))
                graph[it].emplace_back(it + 1);
        }
        int ans(1);
        fc(it, graph)
        {
            if (!uniq_nums.count(it.first - 1))
                ans = max(ans, dfs_iterative(graph, it.first));
        }
        return ans;
    }
    void TEST()
    {
        vi nums{100, 4, 200, 1, 3, 2};
        cout << longestConsecutive(nums) << ' ';
        nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
        cout << longestConsecutive(nums) << edl;
        // output : 4 9
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