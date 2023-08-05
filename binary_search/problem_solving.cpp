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

int main()
{
    return (0);
}