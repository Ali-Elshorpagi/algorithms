#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;

#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define fc(it, v) for (auto &(it) : (v))

// link : https://leetcode.com/problems/minimum-operations-to-convert-number/
// code : leetcode 2059

class Solution
{
public:
    Solution() { Mesh_Ali; }
    int BFS(vi &arr, vi &visited, int start, int goal)
    {
        queue<int> nodes;
        nodes.push(start);
        // visited[start] = 1; // cus we need to push elements in the first loop
        int cnt(0);
        for (int sze(sz(nodes)); !nodes.empty(); sze = sz(nodes))
        {
            while (sze--)
            {
                int cur(nodes.front());
                nodes.pop();
                if (cur == goal)
                    return cnt;
                if (cur < 0 || cur > 1000 || visited[cur])
                    continue;
                visited[cur] = 1;
                fc(it, arr) // doing the operations on the whole array;
                {
                    nodes.push(cur + it);
                    nodes.push(cur - it);
                    nodes.push(cur ^ it);
                }
            }
            ++cnt;
        }
        return -1;
    }
    int minimumOperations(vi &arr, int start, int goal)
    {
        vi visited(1005);
        return BFS(arr, visited, start, goal);
    }
    void TEST()
    {
        vi arr{2, 4, 12};
        int start(2), goal(12);
        cout << minimumOperations(arr, start, goal) << edl; // 2
        arr = {2, 8, 16};
        start = 0, goal = 1;
        cout << minimumOperations(arr, start, goal) << edl; // -1
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