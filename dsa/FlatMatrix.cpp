#include "FlatMatrix.hpp"

inline FlatMatrix::FlatMatrix(size_t rows, size_t cols, int value)
	: data_(rows* cols, value), rows_(rows), cols_(cols)
{
}

inline const int FlatMatrix::operator()(size_t row, size_t col) const
{
	if (row >= rows_ || col >= cols_)
		throw std::out_of_range("Flat Matrix index out of range");
	return data_[row * cols_ + col];
}

inline void FlatMatrix::operator()(size_t row, size_t col, int value)
{
	if (row >= rows_ || col >= cols_)
		throw std::out_of_range("Flat Matrix index out of range");
	data_[row * cols_ + col] = value;
}

inline const int FlatMatrix::back() const
{
	return data_.back();
}