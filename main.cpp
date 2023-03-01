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
#define fl(i, x, n) for (int i(x); i >= n; --i)
#define fc(it, v) for (auto &(it) : (v))
#define sq(x) (x) * (x)
#define yes cout << "YES" << edl
#define no cout << "NO" << edl

int my_pow(int value, int p = 2)
{
    if (!p)
        return 1;
    return value * my_pow(value, p - 1);
}

int arr_max(int arr[], int len)
{
    if (len == 1)
        return arr[0];
    int mx(arr_max(arr, len - 1));
    return max(mx, arr[len - 1]);
}

int sum(int arr[], int len)
{
    if (len == 1)
        return arr[0];
    int ans(sum(arr, len - 1));
    return ans + arr[len - 1];
}
double average(int arr[], int len)
{
    if (len == 1)
        return arr[0];
    double ans(average(arr, len - 1));
    ans *= len - 1;
    return (ans + arr[len - 1]) / len;
}

void array_increment(int arr[], int len)
{
    if (!len)
        return;
    arr[len - 1] += len - 1;
    array_increment(arr, len - 1);
}

void accumulate_arr(int arr[], int len)
{
    if (len == 1)
        return;
    accumulate_arr(arr, len - 1);
    arr[len - 1] += arr[len - 2];
}

void left_max_0(int arr[], int len)
{
    if (len == 1)
        return;
    left_max_0(arr, len - 1);
    arr[len - 1] = max(arr[len - 1], arr[len - 2]);
}

int left_max_1(int arr[], int len)
{
    if (!len)
        return arr[0];
    return arr[len - 1] = max(arr[len - 1], left_max_1(arr, len - 1));
}

void right_max(int arr[], int len, int str = 0)
{
    if (str == len - 1)
        return;
    right_max(arr, len, str + 1);
    arr[str] = max(arr[str], arr[str + 1]);
}

int suffix_sum(int arr[], int len, int n)
{
    if (!n)
        return 0;
    int sum = suffix_sum(arr, len - 1, n - 1);
    return sum + arr[len - 1];
}

int prefix_sum(int arr[], int n, int str = 0)
{
    if (!n)
        return 0;
    int sum = prefix_sum(arr, n - 1, str + 1);
    return sum + arr[str];
}

bool is_palindrome(int arr[], int len, int str = 0)
{
    if (str == len - 1 || str == len)
        return true;
    if (arr[str] == arr[len - 1])
        return is_palindrome(arr, len - 1, str + 1);
    else
        return false;
}

bool is_prefix(string main, string prefix, int str = 0)
{
    if (!sz(prefix) || str == sz(prefix))
        return true;
    if (main[str] == prefix[str])
        return is_prefix(main, prefix, str + 1);
    else
        return false;
}

int fibonacci(int n)
{
    if (n == 1 || !n)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void Solve()
{

    cout << edl << "DONE" << edl;
}

int main()
{
    Mesh_Ali;
    // freopen("test/input.txt", "r", stdin);
    freopen("test/output.txt", "w", stdout);
    int tc(1);
    // cin >> tc;
    while (tc--)
        Solve();
    return 0;
}