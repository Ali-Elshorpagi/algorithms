#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vpii = vector<pii>;
using vc = vector<char>;

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
#define yes cout << "YES\n"
#define no cout << "NO\n"

int length_3n_plus_1(int n)
{
    if (n == 1)
        return 1;
    if (n & 1)
        return 1 + length_3n_plus_1(3 * n + 1);
    return 1 + length_3n_plus_1(n / 2);
}

int my_pow(int val, int p = 2)
{
    if (!p)
        return 1;
    return val * my_pow(val, p - 1);
}

int arr_max(vi &arr, int len)
{
    if (len == 1)
        return arr[0];
    int sub_ans(arr_max(arr, len - 1));
    return max(sub_ans, arr[len - 1]);
}

int arr_sum(vi &arr, int len)
{
    if (len == 1)
        return arr[0];
    int sub_ans(arr_sum(arr, len - 1));
    return sub_ans + arr[len - 1];
}

double arr_average(vector<double> &arr, int len)
{
    if (len == 1)
        return arr[0];
    double sub_ans(arr_average(arr, len - 1));
    // Now this was average of len-1. So sum / (len-1);
    sub_ans *= (len - 1); // when we times it by (len-1), we get back the sum;
    return (sub_ans + arr[len - 1]) / len;
}

void array_increment(vi &arr, int len)
{
    if (!len)
        return;
    array_increment(arr, len - 1);
    arr[len - 1] += len - 1;
}

void accumulate_arr(vi &arr, int len)
{
    if (len == 1)
        return;
    accumulate_arr(arr, len - 1);
    arr[len - 1] += arr[len - 2];
}

void left_max_0(vi &arr, int len)
{
    if (len == 1)
        return;
    left_max_0(arr, len - 1);
    arr[len - 1] = max(arr[len - 1], arr[len - 2]);
}

int left_max_1(vi &arr, int len)
{
    if (!len)
        return arr[0];
    return arr[len - 1] = max(arr[len - 1], left_max_1(arr, len - 1));
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
    return (0);
}