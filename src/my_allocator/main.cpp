#include <map>
#include <vector>

#include "MyAllocator.hpp"



int main()
{
	std::vector<int, MyAllocator<int> > v = {1, 2, 3, 4, 5};
	std::list<int, MyAllocator<int> > l;
	l.push_back(3);

	std::list<int, MyAllocator<int> > l2;
	l2 = std::move(l);

	std::map<int, int, std::less<int>, MyAllocator<std::pair<const int, int> > > m;
	m[1] = 1;

	return 0;
}
