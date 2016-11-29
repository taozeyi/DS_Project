#ifndef MATRIX_H
#define MATRIX_H

#include <memory>
#include <ostream>
#include "vecnd.h"
class matrix
{
	public:
	typedef vecnd value_type;
	typedef value_type& reference;
	typedef const value_type& const_reference;
	typedef std::unique_ptr<value_type[]>::pointer iterator;
	typedef const std::unique_ptr<value_type[]>::pointer const_iterator;

	matrix(size_t m=0,size_t n=0,vecnd::value_type val=0.0f);
	matrix(const matrix& mat);
	matrix(matrix&& mat);

	~matrix(void)
	{
		_data.reset();
	}
	matrix& operator=(const matrix& mat);
	size_t column() const{return _n;}
	size_t row() const{return _m;}

	iterator begin(void);
	iterator end(void);
	const_iterator begin(void) const;
	const_iterator end(void) const;


	reference operator[](size_t idx);
	const_reference operator[](size_t idx) const;

	friend std::ostream& operator<<(std::ostream& s,const matrix& mat)
	{
		for(size_t i=0;i<mat._m;i++)
		{
			s<<mat[i]<<"\n";
		}
		return s;
	}
	friend void swap(matrix& a,matrix& b)
	{
		a._swap(b);
	}
	private:
	void _assign(const matrix& mat);
	void _swap(matrix& mat);

	size_t _m,_n;
	std::unique_ptr<value_type[]> _data;
};
#endif
