#include <iostream>

using namespace std;

int main()
{
	int num, sum = 0;
	while (true)
	{
		cin >> num;
		sum += num;
		if (num >= -1000 && num <= 1000)
		{
			if (sum >= 0)
			{
				cout << num << endl;
			}
			else
			{
				return 0;
			}
		}
	};
	return 0;
}