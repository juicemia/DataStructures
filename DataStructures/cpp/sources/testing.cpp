#include "../headers/Heap.h"
#include <cstdio>

class Comparator
{
	public:
		static bool compare(int a, int b)
		{
			return a > b;
		}
};

int main(int argc, char* argv[])
{
	Heap<int, Comparator> h = Heap<int, Comparator>(10);

	return 0;
}
