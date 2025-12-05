#pragma once

#include <stdexcept>
#include <vector>

class FlatMatrix
{
private:
	std::vector<int> data_;
	size_t rows_, cols_;
public:
	FlatMatrix(size_t rows, size_t cols, int value = 0);

	const int operator()(size_t row, size_t col) const;

	void operator()(size_t row, size_t col, int value);

	const int back() const;
};
