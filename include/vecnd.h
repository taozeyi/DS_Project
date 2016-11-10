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
	typedef value_type*										iterator;
	typedef const value_type*								const_iterator;
	/////////////////
	// Data Member //
	/////////////////
	std::shared_ptr<value_type> _attrs;
	size_t _size;

	public:
	////////////////
	// Constructor//
	////////////////
	vecnd(void);
	vecnd(size_t size);
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

	size_t size(void) const {return _size;};
	///////////////
	// Operators //
	///////////////
	reference operator[](size_t index);
	const_reference operator[](size_t index) const;

	vecnd& operator=(const vecnd& v);
	vecnd& operator=(vecnd&& v);

	bool operator == (const vecnd& v) const;
	//bool operator != (const vecnd& v) const;

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
	value_type squared_length(void) const;
	value_type length(void) const;
	///////////////
	// Modifiers //
	///////////////
	vecnd& abs(void);
	vecnd& normalize(void);
	vecnd& square(void);
	/////////////
	// Friends //
	/////////////
	friend void swap(vecnd& a, vecnd& b){
		return a._swap(b);
	}
	friend vecnd abs(const vecnd& v){
		return vecnd(v).abs();
	}
	friend vecnd normalize(const vecnd& v){
		return vecnd(v).normalize();
	}
	friend vecnd operator*(const_reference scale, const vecnd& v){
		return (v*scale);
	}
	friend std::ostream& operator<<(std::ostream& s, const vecnd& v){
		s<<"[";
		for(const_iterator i=v.begin();i!=v.end();i++){
			s<<*i<<",";
		}
		s<<"]"<<std::endl;
		return s;
	}
	private:
	///////////////
	// Private   //
	///////////////
	void _assign(const vecnd& v);
	void _swap(vecnd& v);
};

#endif