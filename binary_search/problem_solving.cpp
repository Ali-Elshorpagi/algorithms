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

vi searchRange_0(vi &nums, int target) // O(log(n)), O(1) space
{
    // link : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
    // code : leetcode 34
    auto ans(equal_range(all(nums), target));
    int left(ans.first - nums.begin()), right(ans.second - nums.begin());
    if (binary_search(all(nums), target))
        return {left, right - 1};
    return {-1, -1};
}

vi searchRange_1(vi &nums, int target) // O(log(n)), O(1) space
{
    // link : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
    // code : leetcode 34
    auto ans(equal_range(all(nums), target));
    if (ans.first == nums.end())
        return {-1, -1};
    int left(ans.first - nums.begin()), right(ans.second - nums.begin());
    if (nums[left] != target)
        return {-1, -1};
    return {left, right - 1};
}

vi searchRange_2(vi &nums, int target) // O(log(n)), O(1) space
{
    // link : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
    // code : leetcode 34
    int left(0), right(sz(nums) - 1);
    int first_idx(-1), last_idx(-1);
    while (left <= right)
    {
        int mid(left + ((right - left) >> 1));
        if (nums[mid] == target)
            first_idx = mid, right = mid - 1;
        else if (nums[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    left = 0, right = sz(nums) - 1;
    while (left <= right)
    {
        int mid(left + ((right - left) >> 1));
        if (nums[mid] == target)
            last_idx = mid, left = mid + 1;
        else if (nums[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return {first_idx, last_idx};
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