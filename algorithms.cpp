#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pii> vpii;

#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define cl(v) ((v).clear())
#define edl '\n'
#define fr(i, x, n) for (ll i(x); i < n; ++i)
#define fl(i, x, n) for (ll i(x); i >= n; --i)
#define fc(it, v) for (auto &(it) : (v))

ll Binary_Search(vll &arr, ll value)
{
    ll low(0), high(sz(arr) - 1);
    while (low <= high)
    {
        ll mid((low + high) >> 1);
        if (arr[mid] == value)
            return mid;
        else if (arr[mid] < value)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    Mesh_Ali;

    return 0;
}
