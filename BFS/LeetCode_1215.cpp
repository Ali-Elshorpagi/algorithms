#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define _CRT_SECURE_NO_DEPRECATE
#define __elshorpagi__ (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define fr(i, x, n) for (ll i(x); i < n; ++i)
#define fc(it, v) for (auto &(it) : (v))

class Solution
{

public:
    Solution() { __elshorpagi__; }
    // Brute Force O(N * D) time,
    // N -> no.Numbers between Low and High
    // D -> no.digits of the max number between Low and High
    bool is_stepping_num(ll num)
    {
        int prev(-1);
        while (num)
        {
            int cur(num % 10);
            if (prev == -1)
                prev = cur;
            else if (abs(prev - cur) != 1)
                return false;
            prev = cur;
            num /= 10;
        }
        return true;
    }
    vi countSteppingNumbers_brute(ll low, ll high)
    {
        ++high;
        vi ans;
        fr(i, low, high)
        {
            if (is_stepping_num(i))
                ans.emplace_back(i);
        }
        return ans;
    }
    // multi-source BFS, O(N * log(N)) time,
    void BFS(queue<ll> &nodes, set<int> &ans, ll low, ll high)
    {
        while (!nodes.empty())
        {
            ll cur(nodes.front());
            nodes.pop();
            if (cur > high)
                continue; // if u change it to break; it will push '12' but not '21'
            if (cur >= low)
                ans.insert(cur);
            int last_digit(cur % 10);
            if (last_digit == 0) //  push only 1
                nodes.push(cur * 10 + last_digit + 1);
            else if (last_digit == 9) // push only 8
                nodes.push(cur * 10 + last_digit - 1);
            else // push the both
            {
                nodes.push(cur * 10 + last_digit + 1);
                nodes.push(cur * 10 + last_digit - 1);
            }
        }
    }
    vi countSteppingNumbers(ll low, ll high)
    {
        set<int> ans;
        queue<ll> nodes;
        fr(i, 0, 10) nodes.push(i);
        BFS(nodes, ans, low, high);
        return vi{all(ans)};
    }
    void TEST()
    {
        ll low(0), high(21);
        // vi ans = countSteppingNumbers_brute(low, high);
        vi ans = countSteppingNumbers(low, high);
        fc(it, ans) cout << it << ' ';
        // output : {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 21};
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