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

/*
 * # Complexities
 *
 * Best-Case Time      O(N)
 * Worst-Case Time     O(N + K), where K is the size of frequency array
 * Worst-Case Space    O(K)
 */

void count_sort_0(vi &arr)
{
    int len(sz(arr));
    int max_val(*max_element(all(arr))); // O(N)

    vi freq(max_val + 1);
    for (auto &it : arr)
        ++freq[it];

    int idx(0);
    for (int i(0); i <= max_val; ++i)
    {
        if (freq[i])
        {
            for (int j(0); j < freq[i]; ++j)
                arr[idx++] = i;
        }
    }
}

void count_sort_1(vi &arr) // work with negative numbers, but with min trick
{
    int mn(*min_element(all(arr))), shift(50000);

    vi freq(shift + 1 - mn); // -50000 <= arr[i] <= 50000
    for (auto &it : arr)
        ++freq[it - mn];

    int idx(0);
    for (int i(0); i < (shift + 1 - mn); ++i)
    {
        if (freq[i])
        {
            for (int j(0); j < freq[i]; ++j)
                arr[idx++] = i + mn;
        }
    }
}

void count_sort_2(vi &arr) // work with negative numbers, but with max trick
{
    int mx(*max_element(all(arr))), shift(50000);

    vi freq(shift + mx); // -50000 <= arr[i] <= 50000;
    for (auto &it : arr)
        ++freq[it + shift];

    int idx(0);
    for (int i(0); i < (shift + mx + 1); ++i)
    {
        if (freq[i])
        {
            for (int j(0); j < freq[i]; ++j)
                arr[idx++] = i - shift;
        }
    }
}

void count_sort_3(vi &arr) // work with negative numbers
{
    // -10 ^ 9 <= arr[i] <= 10 ^ 9;
    // However : max value - min value <= 500;
    int mn(*min_element(all(arr))), mx(*max_element(all(arr)));
    int sze(mx - mn);

    vi freq(sze + 1);
    for (auto &it : arr)
        ++freq[it - mn];

    int idx(0);
    for (int i(0); i <= sze; ++i)
    {
        if (freq[i])
        {
            for (int j(0); j < freq[i]; ++j)
                arr[idx++] = i + mn;
        }
    }
}

void count_sort_with_string_0(vector<string> &arr)
{ // the sorting depends on first letter in the string and it's stable algorithm
    int len(sz(arr)), letter_sz(26);
    vector<vector<string>> letter_to_string(letter_sz);
    for (int i(0); i < len; ++i)
        letter_to_string[arr[i][0] - 'a'].emplace_back(arr[i]);

    int idx(0);
    for (int i(0); i < letter_sz; ++i)
    {
        if (sz(letter_to_string[i]))
        {
            int size(sz(letter_to_string[i]));
            for (int j(0); j < size; ++j)
                arr[idx++] = letter_to_string[i][j];
        }
    }
}

int idx_convertor(const string &str, int letter_sz)
{
    assert(str.size() >= 2);
    int first_letter(str[0] - 'a');
    int second_letter(str[1] - 'a');
    return first_letter * letter_sz + second_letter;
    // like convert from 2D to 1D we use this equation(i * col + j), the same idea here;
}

void count_sort_with_string_1(vector<string> &arr)
{ // the sorting depends on first two letters in the string and it's stable algorithm
    int range(26 * 26), len(sz(arr));
    vector<vector<string>> letter_to_string(range);
    for (int i(0); i < len; ++i)
        letter_to_string[idx_convertor(arr[i], 26)].emplace_back(arr[i]);

    int idx(0);
    for (int i(0); i < range; ++i)
    {
        if (sz(letter_to_string[i]))
        {
            int size(sz(letter_to_string[i]));
            for (int j(0); j < size; ++j)
                arr[idx++] = letter_to_string[i][j];
        }
    }
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