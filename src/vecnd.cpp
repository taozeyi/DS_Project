#include <algorithm>
#include <iostream>
#include "vecnd.h"

/////////////////
// Constructor //
/////////////////
vecnd::vecnd(void){
	_attrs = NULL;
	_size =0;
}

vecnd::vecnd(size_t size){
	_attrs = std::shared_ptr<value_type>(new value_type[size], std::default_delete<value_type>());
	_size = size;
}
vecnd::vecnd(const vecnd& v){
	std::copy(v.begin(), v.end(), begin());
	_size = v._size;
}

////////////////
// Inspectors //
////////////////
vecnd::iterator vecnd::begin(void){
	return _attrs.get();
}
vecnd::iterator vecnd::end(void){
	return begin()+size();
}

vecnd::const_iterator vecnd::begin(void) const{
	return _attrs.get();
}
vecnd::const_iterator vecnd::end(void) const{
	return begin()+size();
}

//////////////
// Operator //
//////////////
vecnd::reference vecnd::operator[](size_t index){
	return _attrs.get()[index];
}

vecnd::const_reference vecnd::operator[](size_t index) const
{
	return _attrs.get()[index];
}

vecnd& vecnd::operator=(const vecnd& v){
	_assign(v);
	return *this;
}

vecnd& vecnd::operator=(vecnd&& v){
	_swap(v);
	return*this;
}

bool vecnd::operator==(const vecnd& v) const{
	if(size() != v.size()){
		return false;
	}
	for(size_t i=0; i < size(); i++){
		if(_attrs.get()[i] != v._attrs.get()[i]){
			return false;
		}
	}
	return true;
}

vecnd vecnd::operator-(void) const{
	vecnd result(size());
	for (int i = 0; i < size(); i++){
		result._attrs.get()[i] = _attrs.get()[i] * -1;
	}
	return result;
}

vecnd vecnd::operator+(const vecnd& v) const {
	vecnd result(size());
	std::transform(begin(), end(), v.begin(), result.begin(),[](const_reference a, const_reference b)
	{
		return a+b;
	});
	return result;

}
vecnd vecnd::operator-(const vecnd& v) const {
	vecnd result(size());
	std::transform(begin(), end(), v.begin(), result.begin(),[](const_reference a, const_reference b)
	{
		return a-b;
	});
	return result;

}
vecnd vecnd::operator*(const vecnd& v) const {
	vecnd result(size());
	std::transform(begin(), end(), v.begin(), result.begin(),[](const_reference a, const_reference b)
	{
		return a*b;
	});
	return result;

}
vecnd vecnd::operator/(const vecnd& v) const {
	vecnd result(size());
	std::transform(begin(), end(), v.begin(), result.begin(),[](const_reference a, const_reference b)
	{
		return a/b;
	});
	return result;

}
vecnd vecnd::operator*(vecnd::value_type scale) const{
	vecnd result(size());
	std::transform(begin(), end(), result.begin(),[&](const_reference a)
	{
		return a*scale;
	});
	return result;
}
vecnd vecnd::operator/(vecnd::value_type scale) const{
	vecnd result(size());
	std::transform(begin(), end(), result.begin(),[&](const_reference a)
	{
		return a/scale;
	});
	return result;
}

vecnd& vecnd::operator+=(const vecnd& v){
	std::transform(begin(), end(), v.begin(), begin(),[](const_reference a, const_reference b)
	{
		return a+b;
	});
	return *this;
}
vecnd& vecnd::operator-=(const vecnd& v){
	std::transform(begin(), end(), v.begin(), begin(),[](const_reference a, const_reference b)
	{
		return a-b;
	});
	return *this;
}
vecnd& vecnd::operator*=(const vecnd& v){
	std::transform(begin(), end(), v.begin(), begin(),[](const_reference a, const_reference b)
	{
		return a*b;
	});
	return *this;
}
vecnd& vecnd::operator/=(const vecnd& v){
	std::transform(begin(), end(), v.begin(), begin(),[](const_reference a, const_reference b)
	{
		return a/b;
	});
	return *this;
}
vecnd& vecnd::operator*=(vecnd::value_type scale){
	std::for_each(begin(), end(), [&](reference a)
	{
		a*=scale;
	});
	return *this;
}
vecnd& vecnd::operator/=(vecnd::value_type scale){
	std::for_each(begin(), end(), [&](reference a)
	{
		a/=scale;
	});
	return *this;
}
/////////////
// Method  //
/////////////
vecnd::value_type vecnd::dot(const vecnd& v) const{
	vecnd::value_type dot_value=0.0f;
	vecnd result(size());

	std::transform(begin(), end(), v.begin(), result.begin(),[](const_reference a, const_reference b)
	{
		return a*b;
	});

	std::for_each(result.begin(), result.end(), [&](reference a)
	{
		dot_value+=a;
	});

	return dot_value;
}

vecnd::value_type vecnd::squared_length(void) const{
	return dot(*this);
}

vecnd::value_type vecnd::length(void) const{
	return sqrt(squared_length());
}

//////////////
// Modifier //
//////////////
vecnd& vecnd::abs(void){
	std::for_each(begin(), end(), [](reference val){
		if(val < 0) val = -val;
	});
	return *this;
}

vecnd& vecnd::normalize(void){
	*this /= length();
	return *this;
}

vecnd& vecnd::square(void){
	std::for_each(begin(), end(), [](reference val){
		val = val*val;
	});
	return *this;
}

/////////////
// Private //
/////////////
void vecnd::_assign(const vecnd& v){

	_attrs = std::shared_ptr<value_type>(new value_type[v.size()], std::default_delete<value_type>());
	std::transform(v.begin(), v.end(), begin(),[](const_reference a)
	{
		return a;
	});
	_size = v._size;
}
void vecnd::_swap(vecnd& v){
	std::swap(_attrs,v._attrs);
	std::swap(_size, v._size);
}
