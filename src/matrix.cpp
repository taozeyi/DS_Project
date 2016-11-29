#include <algorithm>
#include <cassert>
#include "matrix.h"

matrix::matrix(size_t m,size_t n,vecnd::value_type val)
{
	_data.reset(new vecnd[m]);
	for(size_t i=0;i<m;i++)
	{
		_data[i]=vecnd(n,val);
	}
	_m=m;
	_n=n;
}
matrix::matrix(const matrix& mat):matrix(mat.row(),mat.column())
{
	std::copy(mat.begin(),mat.end(),begin());
}
matrix::matrix(matrix&& mat)
{
	_swap(mat);
}

matrix& matrix::operator=(const matrix& mat)
{
	_assign(mat);
	return *this;
}

matrix::reference matrix::operator[](size_t idx)
{
	assert(idx<_m);
	return *(_data.get()+idx);
}
matrix::const_reference matrix::operator[](size_t idx) const
{
	assert(idx<_m);
	return *(_data.get()+idx);
}
matrix::iterator matrix::begin(void)
{
	return _data.get();
}
matrix::iterator matrix::end(void)
{
	return _data.get()+_m;
}
matrix::const_iterator matrix::begin(void) const
{
	return _data.get();
}
matrix::const_iterator matrix::end(void) const
{
	return _data.get()+_m;
}

void matrix::_assign(const matrix& mat)
{
	matrix temp(mat);
	_swap(temp);
}
void matrix::_swap(matrix& mat)
{
	std::swap(_data,mat._data);
	std::swap(_m,mat._m);
	std::swap(_n,mat._n);
}

