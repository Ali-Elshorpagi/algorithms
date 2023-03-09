#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef vector<char> vc;

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
#define yes printf("YES\n")
#define no printf("NO\n")

vi searchRange(vi &nums, int target) // O(log(n))
{
    int left(0), right(sz(nums) - 1), flag(0);
    vi ans;
    while (left <= right)
    {
        int mid(left + ((right - left) >> 1));
        if (nums[mid] == target)
            ans.emplace_back(mid), flag = 1;
        else if (nums[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return (flag ? vi{*min_element(all(ans)), *max_element(all(ans))} : vi{-1, -1});
    // return vi{-1, -1};
}

void Solve()
{
    vi arr{5, 7, 7, 8, 8, 10};
    int val(8);
    vi res = searchRange(arr, val);
    fc(it, res) cout << it << ' ';
    // test functions here;
    cout << edl << "DONE" << edl;
}

int main()
{
    Mesh_Ali;
    // freopen("test/input.txt", "r", stdin);
    freopen("test/output.txt", "w", stdout);
    int tc(1);
    // scanf("%d", &tc);
    while (tc--)
        Solve();
    return (0);
}