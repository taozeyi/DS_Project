#ifndef _LISTND_H
#define _LISTND_H

#include <iostream>
#include <vector>

#include "vecnd.h"

class item
{
	public:
	item(vecnd data,float proj);
	item(const item& it);

	item& operator=(const item& it);
	bool operator<(const item& it) const;
	bool operator>(const item& it) const;

	const vecnd& data() const;
	float projection() const;

        friend void swap(item& a,item& b)
	{
	}
	friend std::ostream& operator<<(const item& it)
	{
	}
	private:
        
	void _swap(item& it);

	vecnd _data;
	float _projection;

};
class listnd
{
	typedef item value_type;
	typedef value_type& reference;
	typedef 
	public:
	listnd(size_t n);
	listnd(const listnd& lt);
	listnd(listnd&& lt);





};
#endif
