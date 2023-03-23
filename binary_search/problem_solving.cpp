#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;

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

vi findrightInterval_0(vvi &intervals) // O(N * log(N)) time, O(N) space
{
    // link : https://leetcode.com/problems/find-right-interval/
    // code : leetcode 436
    vpii startings;
    int len(sz(intervals));
    fr(i, 0, len)
        startings.push_back({intervals[i][0], i}); // push the start and his idx;
    sort(all(startings));                          // array of startings;
    vi ans(len, -1);
    fr(i, 0, len)
    {
        int left(0), right(sz(startings) - 1), position(-1), key(intervals[i][1]);
        while (left <= right)
        {
            int mid(left + ((right - left) >> 1));
            if (startings[mid].first < key)
                left = mid + 1;
            else if (startings[mid].first >= key) // >= cus we search for greater than or equal val;
                position = mid, right = mid - 1;
        }
        if (position != -1)
            ans[i] = startings[position].second;
    }
    return ans;
}

vi findrightInterval_1(vvi &intervals) // O(N * log(N)) time, O(N) space
{
    // link : https://leetcode.com/problems/find-right-interval/
    // code : leetcode 436
    int len(sz(intervals));
    vpii startings;
    fr(i, 0, len)
        startings.push_back({intervals[i][0], i});
    sort(all(startings));
    vi ans(len, -1);
    fr(i, 0, len)
    {
        pii val{intervals[i][1], 0};
        auto it(lower_bound(all(startings), val));
        if (it != startings.end())
        {
            int idx(it - startings.begin());
            ans[i] = startings[idx].second;
        }
    }
    return ans;
}

vi findrightInterval_2(vvi &intervals) // O(N * log(N)) time, O(N) space
{
    // this code only works cus the input numbers are unique;
    // link : https://leetcode.com/problems/find-right-interval/
    // code : leetcode 436
    map<int, int> start_to_idx;
    int len(sz(intervals));
    fr(i, 0, len)
        start_to_idx[intervals[i][0]] = i;

    vi ans(len, -1);
    fr(i, 0, len)
    {
        auto it(start_to_idx.lower_bound(intervals[i][1]));
        if (it != start_to_idx.end())
            ans[i] = it->second;
    }
    return ans;
}

int triangleNumber_0(vi &nums) // O(N^2) time, O(1) space
{
    // link : https://leetcode.com/problems/valid-triangle-number/
    // code : leetcode 611
    int cnt(0), len(sz(nums));
    sort(all(nums));
    fr(i, 0, len - 2)
    {
        int k(i + 2);
        for (int j(i + 1); j < len - 1 && nums[i] != 0; ++j)
        {
            while (k < len && nums[i] + nums[j] > nums[k])
                ++k;
            cnt += k - j - 1;
        }
    }
    return cnt;
}

int triangleNumber_1(vi &nums) // O(N^2 * log(N)) time, O(1) space
{
    // link : https://leetcode.com/problems/valid-triangle-number/
    // code : leetcode 611
    int cnt(0), len(sz(nums));
    sort(all(nums));
    fr(i, 0, len - 2)
    {
        int k(i + 2);
        for (int j(i + 1); j < len - 1 && nums[i] != 0; ++j)
        {
            int left(k), right(len - 1), val(nums[i] + nums[j]), idx(len);
            while (left <= right) // u can use lefter_bound func instead of binary search
            {
                int mid(left + ((right - left) >> 1));
                if (nums[mid] >= val)
                    idx = mid, right = mid - 1;
                else
                    left = mid + 1;
            }
            // All values starting from idx are invalid
            cnt += idx - j - 1; // The values between j and (idx - 1) are the possible ones
        }
    }
    return cnt;
}

int arrangeCoins_0(int n) // O(log(N)) time, O(1) space
{
    // link : https://leetcode.com/problems/arranging-coins/
    // code : leetcode 441
    // 1 + 2 + 3 + 4 + ... + X = N;
    // (1 + X) * (X / 2) = N;
    // (1 + X) * X = 2 * N;
    // X^2 + X = 2 * N;
    // X^2 + X + 0.25 = 2 * N + 0.25;
    // (X + 0.5)^2 = 2 * N + 0.25;
    // X = sqrt(2 * N + 0.25) - 0.5;
    return floor(sqrt((ll)2 * n + 0.25) - 0.5);
}

bool possible_0(int n, ll rows)
{
    ll sum((rows * (rows + 1)) >> 1); // the sum formula
    return n >= sum;
}

int arrangeCoins_1(int n) // O(log(N)) time, O(1) space
{
    // link : https://leetcode.com/problems/arranging-coins/
    // code : leetcode 441
    // 1 + 2 + 3 + 4 + ... + X = N;
    // ((1 + X) * X) / 2 = N;
    int left(0), right(n), ans(0);
    while (left <= right)
    {
        int mid(left + ((right - left) >> 1));
        if (possible_0(n, mid))
            ans = mid, left = mid + 1;
        else
            right = mid - 1;
    }
    return ans;
}

bool possible_1(vi &arr, int mid, int th)
{
    int len(sz(arr)), sum(0);
    fr(i, 0, len)
        sum += (arr[i] + mid - 1) / mid; // u can use the ceil func
    return sum <= th;
}

int smallestDivisor(vi &nums, int threshold) // O(N * log(N))  time, O(1) space
{
    // link : https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
    // code : leetcode 1283
    int left(1), right(*max_element(all(nums))), ans(0);
    while (left <= right)
    {
        int mid(left + ((right - left) >> 1));
        if (possible_1(nums, mid, threshold))
            ans = mid, right = mid - 1;
        else
            left = mid + 1;
    }
    return ans;
}

bool possible_2(vi &arr, int mid, int m, int k)
{
    int len(sz(arr)), cnt(0), boq(0);
    fr(i, 0, len)
    {
        if (arr[i] - mid < 1)
        {
            ++cnt;
            if (cnt >= k)
                cnt = 0, ++boq;
            if (boq == m)
                return true;
        }
        else
            cnt = 0;
    }

    return false;
}

int minDays(vi &bloomDay, int m, int k) // O(N * log(N))  time, O(1) space
{
    // link : https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
    // code : leetcode 1482
    int ans(-1), left(*min_element(all(bloomDay))), right(*max_element(all(bloomDay)));
    while (left <= right)
    {
        int mid(left + ((right - left) >> 1)); // the mid == days;
        if (possible_2(bloomDay, mid, m, k))
            ans = mid, right = mid - 1;
        else
            left = mid + 1;
    }
    return ans;
}

bool possible_3(vi &houses, vi &heaters, int mid)
{
    int j(0), len_s(sz(houses)), len_t(sz(heaters));
    fr(i, 0, len_t)
    {
        int leftC(heaters[i] - mid), rightC(heaters[i] + mid);
        while (j < len_s && houses[j] >= leftC && houses[j] <= rightC)
            ++j;
    }
    return j == len_s;
}

int findRadius_0(vi &houses, vi &heaters) // O(N * log(N) + N * log(M)) (M = 1e9) time, O(1) space
{
    // link : https://leetcode.com/problems/heaters/
    // code : leetcode 475
    sort(all(houses)), sort(all(heaters));
    // u can make the right = max(max(houses), max(heaters));
    int left(0), right(1e9), ans(-1);
    while (left <= right)
    {
        int mid(left + ((right - left) >> 1));
        if (possible_3(houses, heaters, mid))
            ans = mid, right = mid - 1;
        else
            left = mid + 1;
    }
    return ans;
}

int findRadius_1(vi &houses, vi &heaters) // O(N * log(N)) time, O(1) space
{
    // link : https://leetcode.com/problems/heaters/
    // code : leetcode 475
    sort(all(heaters));
    int radius(INT_MIN), len_s(sz(houses)), len_t(sz(heaters));
    fr(i, 0, len_s)
    {
        int idx(lower_bound(all(heaters), houses[i]) - heaters.begin());
        if (idx == len_t) // after heaters
            radius = max(radius, abs(heaters[idx - 1] - houses[i]));
        else if (!idx) // before heaters
            radius = max(radius, abs(heaters[idx] - houses[i]));
        else
        { // surrounded by heaters: comapr idx and idx-1
            int besti_r(min(abs(heaters[idx] - houses[i]), abs(heaters[idx - 1] - houses[i])));
            radius = max(radius, besti_r);
        }
    }
    return radius;
}

int mySqrt_0(int x) // O(log(N)) time, O(1) space
{
    // link : https://leetcode.com/problems/sqrtx/
    // code : leetcode 69
    double left(0), right(x), EPS(1e-9);
    while (right - left > EPS)
    {
        double mid(left + (right - left) / 2);
        if (sq(mid) < x) // it;s equal to (sq(mid) - x < 0.0 )
            left = mid;
        else
            right = mid;
    }
    return left + EPS; // we add EPS cus the result wil be 1.99999999 or something like that;
}

int mySqrt_1(int x) // O(log(N)) time, O(1) space
{
    // link : https://leetcode.com/problems/sqrtx/
    // code : leetcode 69
    if (!x || x == 1)
        return x;
    ll left(1), right(x >> 1), ans(-1);
    while (left <= right)
    {
        ll mid(left + ((right - left) >> 1));
        if (sq(mid) == x)
            return mid;
        else if (sq(mid) < x)
            left = mid + 1, ans = mid;
        else
            right = mid - 1;
    }
    return ans;
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
    // cin >> tc;
    while (tc--)
        Solve();
    return (0);
}