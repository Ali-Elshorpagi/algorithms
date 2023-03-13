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

void right_max_0(int arr[], int len, int str = 0)
{
    if (str == len - 1)
        return;
    right_max_0(arr, len, str + 1);
    arr[str] = max(arr[str], arr[str + 1]);
}

void right_max_1(int arr[], int len)
{
    if (len == 1)
        return;
    right_max_1(arr + 1, len - 1);
    arr[0] = max(arr[0], arr[1]);
}

int sufix_sum(int arr[], int len, int cnt)
{
    if (!cnt)
        return 0;
    return arr[len - 1] + sufix_sum(arr, len - 1, cnt - 1);
}

int prefix_sum_0(int arr[], int len, int cnt)
{
    if (!cnt)
        return 0;
    return arr[cnt - 1] + prefix_sum_0(arr, len - 1, cnt - 1);
}

int prefix_sum_1(int arr[], int cnt)
{
    if (!cnt)
        return 0;
    return arr[0] + prefix_sum_1(arr + 1, cnt - 1);
}

bool is_palindrome_0(int arr[], int start, int end)
{
    if (start >= end)
        return true;
    if (arr[start] != arr[end])
        return false;
    return is_palindrome_0(arr, start + 1, end - 1);
}

bool is_palindrome_1(int arr[], int end)
{
    if (end <= 0)
        return true;
    if (arr[0] != arr[end])
        return false;
    return is_palindrome_1(arr + 1, end - 2);
}

bool is_prefix(string main, string prefix, int str = 0)
{
    if (str == sz(prefix))
        return true;
    if (main[str] != prefix[str])
        return false;
    return is_prefix(main, prefix, str + 1);
}

bool is_prime(int m, int cur_test_number = 3)
{
    if (m == 2)
        return true;
    if (m <= 1 || m % 2 == 0)
        return false;
    if (m == cur_test_number)
        return true;
    if (m % cur_test_number == 0)
        return false;
    return is_prime(m, cur_test_number + 1);
}

int count_primes(int start, int end)
{
    if (start > end)
        return 0;
    int result(count_primes(start + 1, end));
    if (is_prime(start))
        ++result;
    return result;
}

int di[]{1, 0, 1};
int dj[]{0, 1, 1};
int path_sum(int grid[100][100], int ROWS, int COLS, int row = 0, int col = 0)
{
    int sum(grid[row][col]);
    if (row == ROWS - 1 && col == COLS - 1)
        return sum;
    int max_idx(-1), max_val(0);
    fr(d, 0, 3)
    {
        int new_row(row + di[d]), new_col(col + dj[d]);
        if (new_row >= ROWS || new_col >= COLS)
            continue;
        if (max_val < grid[new_row][new_col])
            max_val = grid[new_row][new_col], max_idx = d;
    }
    int new_row(row + di[max_idx]), new_col(col + dj[max_idx]);
    return sum + path_sum(grid, ROWS, COLS, new_row, new_col);
}

int fibonacci_0(int n)
{
    if (n <= 1)
        return 1;
    return fibonacci_0(n - 1) + fibonacci_0(n - 2);
}

vi dp(1e2);
int fibonacci_1(int n)
{
    if (n <= 1)
        return 1;
    int first, second;
    if (dp[n - 1])
        first = dp[n - 1];
    else
        first = fibonacci_1(n - 1);

    if (dp[n - 2])
        second = dp[n - 2];
    else
        second = fibonacci_1(n - 2);
    return dp[n] = first + second;
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