#ifndef _VECND_H_
#define _VECND_H_

#include <ostream>
#include <vector>
#include <cmath>
#include <algorithm>

class vecnd{
	public:
	/////////////
	// Typedef //
	/////////////
	typedef float											value_type;
	typedef value_type&										reference;
	typedef const value_type								const_reference;
	typedef std::unique_ptr<value_type[]>::pointer			iterator;
	typedef std::unique_ptr<const value_type[]>::pointer	const_iterator;
	/////////////////
	// Data Member //
	/////////////////
	std::unique_ptr<value_type[]> _attrs;

	public:
	////////////////
	// Constructor//
	////////////////
	vecnd(void);
	vecnd(int size);
	vecnd(const vecnd& v);

	//vecnd(std::unique_ptr<value_type[]> v);
	//vecnd(std::unique_ptr<value_type[]> v, int entry, float value);

	///////////////
	// Inspector //
	///////////////
	iterator begin(void);
	const_iterator begin(void) const;
	iterator end(void);
	const_iterator end(void)const;	
	///////////////
	// Operators //
	///////////////
	vecnd& operator=(const vecnd& v);

	bool operator == (const vecnd& v) const;
	bool operator != (const vecnd& v) const;

	vecnd operator-(void) const;

	vecnd operator+(const vecnd& v) const;
	vecnd operator-(const vecnd& v) const;
	vecnd operator*(const vecnd& v) const;
	vecnd operator*(const_reference scale) const;
	vecnd operator/(const vecnd& v) const;
	vecnd operator/(const_reference scale) const;

	vecnd& operator+=(const vecnd& v);
	vecnd& operator-=(const vecnd& v);
	vecnd& operator*=(const vecnd& v);
	vecnd& operator*=(const_reference scale);
	vecnd& operator/=(const vecnd& v);
	vecnd& operator/=(const_reference scale);

	///////////////
	// Methods   //
	///////////////
	value_type dot(const vecnd& v) const;

	vecnd cross(const vecnd& v) const;
	///////////////
	// Modifiers //
	///////////////
	vecnd& abs(void);
	vecnd& normalize(void);
	private:
	///////////////
	// Private   //
	///////////////
};

#endif