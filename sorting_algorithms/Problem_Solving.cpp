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

vvi minimumAbsDifference(vi &arr) // O(N * log(N))
{
    // link : https://leetcode.com/problems/minimum-absolute-difference/
    // code : leetcode 1200
    sort(all(arr));
    int abs_diff(arr[1] - arr[0]), len(sz(arr));
    fr(i, 1, len)
    {
        if (arr[i] - arr[i - 1] < abs_diff)
            abs_diff = arr[i] - arr[i - 1];
    }
    vvi ans;
    fr(i, 0, len - 1)
    {
        if (arr[i + 1] - arr[i] == abs_diff)
            ans.push_back({arr[i], arr[i + 1]});
    }
    return ans;
}

int largestPerimeter(vi &nums) // O(N * log(N))
{
    // link : https://leetcode.com/problems/largest-perimeter-triangle/
    // code : leetcode 976
    int len(sz(nums));
    sort(all(nums));
    fl(i, len - 3, -1)
    {
        if (nums[i + 1] + nums[i] > nums[i + 2])
            return (nums[i + 2] + nums[i] + nums[i + 1]);
    }
    return 0;
}

int arrayPairSum(vi &nums) // O(N * log(N))
{
    // link : https://leetcode.com/problems/array-partition/
    // code : leetcode 561
    sort(all(nums));
    int ans(0), len(sz(nums));
    for (int i(0); i < len; i += 2)
        ans += nums[i];
    return ans;
}

void wiggleSort(vi &arr) // O(N * log(N))
{
    // link : https://leetcode.com/problems/wiggle-sort/
    // code : leetcode 280
    sort(all(arr));
    int len(sz(arr));
    for (int i(1); i < len - 1; i += 2)
        swap(arr[i], arr[i + 1]);
}

void Solve()
{
    // test functions here;
    cout << edl << "DONE" << edl;
}

int main()
{
    Mesh_Ali;
    // freopen("../test/input.txt", "r", stdin);
    freopen("../test/output.txt", "w", stdout);
    int tc(1);
    // scanf("%d", &tc);
    while (tc--)
        Solve();
    return 0;
}