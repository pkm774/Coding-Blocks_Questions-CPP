#include <iostream>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define MOD 1000000007
#define mod 9982444353

void solve()
{
    int lens;
    cin >> lens;
    string* vals{ new string[lens] {""} };
    for (int i = 0; i < lens; i++) cin >> vals[i];
    for (int i = 0; i < lens; i++)
    {
        for (int j = i + 1; j < lens; j++)
        {

            if (vals[i] + vals[j] < vals[j] + vals[i])
            {
                string temp = vals[i];
                vals[i] = vals[j];
                vals[j] = temp;
                //cout<<vals[i] <<" "<<vals[j]<<endl;
            }
        }
    }
    //for(int i = 0; i < lens; i++) cout << vals[i]<<" ";
    string rets = "";
    for (int i = 0; i < lens; i++) rets += vals[i];
    cout << rets << endl;

}

int main()
{
    FIO;
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
