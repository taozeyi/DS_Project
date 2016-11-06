#include <algorithm>
#include "vecnd.h"

/////////////////
// Constructor //
/////////////////
vecnd::vecnd(void){
	_attrs = NULL;
}

vecnd::vecnd(int size){
	_attrs.reset(new value_type[size]);
}
vecnd::vecnd(const vecnd& v){
	std::copy(v.begin(), v.end(), begin());
}

////////////////
// Inspectors //
////////////////
vecnd::iterator vecnd::begin(void){
	return _attrs.begin();
}
vecnd::iterator vecnd::end(void){
	return _attrs.end();
}

vecnd::const_iterator vecnd::begin(void) const{
	return _attrs.begin();
}
vecnd::const_iterator vecnd::end(void) const{
	return _attrs.end();
}

//////////////
// Operator //
//////////////
vecnd vecnd::operator+(const vecnd& v) const {
	vecnd result;
	std::transform(begin(), end(), v.begin(), result.begin(),[](const_reference a, const_reference b)
	{
		return a+b;
	});
	return result;

}
vecnd vecnd::operator-(const vecnd& v) const {
	vecnd result;
	std::transform(begin(), end(), v.begin(), result.begin(),[](const_reference a, const_reference b)
	{
		return a-b;
	});
	return result;

}
vecnd vecnd::operator*(const vecnd& v) const {
	vecnd result;
	std::transform(begin(), end(), v.begin(), result.begin(),[](const_reference a, const_reference b)
	{
		return a*b;
	});
	return result;

}
vecnd vecnd::operator/(const vecnd& v) const {
	vecnd result;
	std::transform(begin(), end(), v.begin(), result.begin(),[](const_reference a, const_reference b)
	{
		return a/b;
	});
	return result;

}
vecnd vecnd::operator*(vecnd::value_type scale) const{
	vecnd result;
	std::transform(begin(), end(), result.begin(),[&](const_reference a)
	{
		return a*scale;
	});
	return result;
}
vecnd vecnd::operator/(vecnd::value_type scale) const{
	vecnd result;
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
	std::for_each(begin(), end(), [&](const_reference a)
	{
		return a*scale;
	});
	return *this;
}
vecnd& vecnd::operator/=(vecnd::value_type scale){
	std::for_each(begin(), end(), [&](const_reference a)
	{
		return a/scale;
	});
	return *this;
}

//////////////
// Modifier //
//////////////


/////////////
// Private //
/////////////