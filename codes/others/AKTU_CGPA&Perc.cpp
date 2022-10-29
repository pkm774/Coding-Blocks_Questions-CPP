#include <iostream>
#include <vector>

namespace percentage
{
	class CGPA
	{
	public:
		float credit = 0;
		float sgpa = 0;
		float result = 0;

		~CGPA() {}
	};
}

int main()
{
	float resultsum = 0, creditsum = 0, average = 0, sgpasum = 0;
	percentage::CGPA *cgpa = new percentage::CGPA[8];

	for (int i = 0; i <= 7; ++i)
	{
		std::cout << "Enter Credit of " << i + 1 << " Semester: ";
		std::cin >> cgpa[i].credit;
		std::cout << "Enter SGPA of " << i + 1 << " Semester: ";
		std::cin >> cgpa[i].sgpa;
		cgpa[i].result = cgpa[i].credit * cgpa[i].sgpa;
	}

	for (int i = 0; i <= 7; ++i)
	{
		creditsum += cgpa[i].credit;
		sgpasum += cgpa[i].result;
	}

	average = sgpasum / creditsum;

	std::cout << '\n';
	std::cout << "CGPA : " << average << std::endl;
	std::cout << "Percentage : " << (average - 0.75) * 10 << "%";

	delete[] cgpa;

	return 0;
}
