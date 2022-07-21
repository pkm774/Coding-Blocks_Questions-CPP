#include <iostream>
#include <limits.h>
using namespace std;


int main()
{

    int n, curr, prev = INT_MAX, Seq_no = 1;

    int i;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> curr;

        if(Seq_no == 1) // for stricly decreasing
        {
            if(prev <= curr)
            {
                Seq_no++;
            }

        }
        else  // for stricly decreasing
        {
            if(prev >= curr)
            {
                Seq_no++;
                break;
            }

        }
        prev = curr;
    }

    if(Seq_no == 2 || (Seq_no == 1 && n != 1))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}