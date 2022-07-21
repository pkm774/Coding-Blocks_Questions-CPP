#include <iostream>

using namespace std;

int main() {
    int totalrow,rownum,space,symbol;
    cout << "Enter Number of rows to print: ";
    cin >> totalrow;
    for(rownum = 1;rownum <= totalrow;rownum++){
        for(space=1;space <=(totalrow-rownum);space++){
            cout<<" ";
        }
        for(symbol=1;symbol<=((2*rownum)-1);symbol++){
            cout<<"*";
        }
        cout<<"\n";
    }
    getchar();
    return 0;
}
