#include <iostream>
#include <vector>
#include <chrono>

#include "leetcode/Binary Search/q4.cpp"
#include "dsa/FlatMatrix.hpp"
#include "dsa/LinkedList.hpp"

static int mazeProblem(int rows, int cols)
{
	FlatMatrix maze(rows, cols);

	for (size_t row = 0; row < rows; row++)
	{
		for (size_t col = 0; col < cols; col++)
		{
			if (row == 0 || col == 0)
				maze(row, col, 1);
			else
				maze(row, col, maze(row - 1, col) + maze(row, col - 1));
		}
	}
	return maze.back();
}

int main()
{
	return 0;
}

static void mazeProblemTest()
{
	int rows = 18, cols = 6;
	std::chrono::steady_clock::time_point start = std::chrono::high_resolution_clock::now();
	printf("How many ways for %d x %d grid: %d", rows, cols, mazeProblem(rows, cols));
	std::chrono::steady_clock::time_point end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = end - start;
	std::cout << "Time Taken: " << duration.count() << std::endl;
}

static void linkedListTest() {
	LinkedList list;
	std::cout << "List size when empty " << list.size() << " \n";
	std::cout << "List isEmpty when empty " << list.isEmpty() << " \n";
	list.insertFirst(1);
	list.insertLast(100);
	list.insertAt(1, 10);
	list.insertAt(3, 5);
	list.print();
	list.removeLast();
	list.removeAt(1);
	list.removeFirst();
	std::cout << "List indexOf when element is present " << list.indexOf(100) << " \n";
	list.removeValue(100);
	std::cout << "List contains when element is absent " << std::boolalpha << list.contains(100) << " \n";
	list.print();
}
