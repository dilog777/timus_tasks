#include <iostream>


int main()
{
	int k, n;
	std::cin >> k >> n;

	int a;
	int result = 0;
	while (n > 0)
	{
		--n;
		std::cin >> a;
		result = result + a - k;
		if (result < 0)
		{
			result = 0;
		}
	}

	std::cout << result << std::endl;
	return 0;
}
