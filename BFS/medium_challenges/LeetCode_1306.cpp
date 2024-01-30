#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;

#define _CRT_SECURE_NO_DEPRECATE
#define Sukuna (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define yes cout << "YES\n"
#define no cout << "NO\n"

class Solution
{
public:
    Solution() { Sukuna; }
    bool is_valid(vi &arr, int idx)
    {
        if (idx >= sz(arr) || idx < 0)
            return false;
        return true;
    }
    bool BFS(vi &arr, int start, vi &visited)
    {
        queue<int> nodes;
        visited[start] = 1;
        nodes.push(start);
        while (!nodes.empty())
        {
            int cur_idx(nodes.front());
            nodes.pop();
            if (!arr[cur_idx])
                return true;
            int forward_idx(cur_idx + arr[cur_idx]), backward_idx(cur_idx - arr[cur_idx]);
            if (is_valid(arr, forward_idx) && !visited[forward_idx])
                visited[forward_idx] = 1, nodes.push(forward_idx);
            if (is_valid(arr, backward_idx) && !visited[backward_idx])
                visited[backward_idx] = 1, nodes.push(backward_idx);
        }
        return false;
    }
    bool canReach(vi &arr, int start)
    {
        if (!arr[start])
            return true;
        vi visited(sz(arr));
        return BFS(arr, start, visited);
    }
    void TEST()
    {
        vi arr{4, 2, 3, 0, 3, 1, 2};
        int start(5);
        canReach(arr, start) ? yes : no; // YES
        arr = {3, 0, 2, 1, 2};
        start = 2;
        canReach(arr, start) ? yes : no; // NO
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