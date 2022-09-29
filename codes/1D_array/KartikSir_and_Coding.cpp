#include <iostream>
#include <vector>

void KatikSir_and_Coding(int size) {
	// Ans vector
	std::vector<int> ans;
	for (int i = 0; i < size; ++i)
	{
		int n1 = 0, n2 = 0;
		std::cin >> n1;

		if (n1 == 2) {
			std::cin >> n2;
			ans.push_back(n2);
		}
		else
		{
			if (ans.empty())
			{
				std::cout << "No Code" << std::endl;
			}
			else
			{
				int val = *(ans.end() - 1);
				std::cout << val << std::endl;
				ans.pop_back();
			}
		}
	}
}

int main()
{
	int size = 0;
	std::cin >> size;

	KatikSir_and_Coding(size);

	return 0;
}
