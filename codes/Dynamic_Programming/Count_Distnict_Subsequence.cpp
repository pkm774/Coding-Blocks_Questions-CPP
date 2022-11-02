/*input
1
ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ
*/
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define boost ios_base::sync_with_stdio(false);
#define endl '\n'
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define ll long long
#define ull unsigned long long
#define pii pair<ll, ll>
#define f(i, a, b) for (ll i = (ll)(a); i <= (ll)(b); i++)
#define rf(i, a, b) for (ll i = (ll)(a); i >= (ll)(b); i--)
#define ms(a, b) memset((a), (b), sizeof(a))
#define max(a, b) ((a > b) ? (a) : (b))
#define min(a, b) ((a < b) ? (a) : (b))

#define abs(x) ((x < 0) ? (-(x)) : (x))
#define MAX 100005
#define inf LLONG_MAX
#define MIN INT_MIN

// typedef
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int mod = 1e9 + 7;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll powmod(ll a, ll b)
{
    ll res = 1;
    if (a >= mod)
        a %= mod;
    for (; b; b >>= 1)
    {
        if (b & 1)
            res = res * a;
        if (res >= mod)
            res %= mod;
        a = a * a;
        if (a >= mod)
            a %= mod;
    }
    return res;
}

/*..................................................................................................................................*/
char s[MAX];
ll dp[MAX];
int previous_count[200];

int main()
{
    boost;
    cin.tie(0);

    int n, t;
    cin >> t;
    while (t--)
    {
        cin >> s;

        // fill previous_count with -1
        ms(previous_count, -1);

        // Get length of s string
        n = strlen(s);

        // fill dp with 0
        ms(dp, 0);

        // Set 0th index of dp to 1
        // which will hold the count of empty substring.
        dp[0] = 1;

        // set previous_count at s[0] index to 0
        previous_count[s[0]] = 0;

        // Start from 1 to length of the string
        f(i, 1, n)
        {
            // Number of subsequences with substring
            // str[0..i-1]
            dp[i] = (2 * dp[i - 1]) % mod;

            // If current character has appeared
            // before, then remove all subsequences
            // ending with previous occurrence.
            if (previous_count[s[i - 1]] != -1) {
                dp[i] = (dp[i] - dp[previous_count[s[i - 1]] - 1] + mod) % mod;
            }

            // Mark occurrence of current character
            previous_count[s[i - 1]] = i;
        }

        cout << dp[n] << endl;
    }
    return 0;
}