#include <cassert>
#include "util.h"
#include "listnd.h"

item::item(void)
{
	_point_id=0;
	_projection=0;
}
item::item(size_t point_id,float proj)
{
	_point_id=point_id;
	_projection=proj;
}

item::item(const item& it)
{
	_point_id=it._point_id;
	_projection=it._projection;
}

item& item::operator=(const item& it)
{
	_point_id=it._point_id;
	_projection=it._projection;
	return *this;
}

bool item::operator<(const item& it) const
{
	if(_projection<it._projection)
	{
		return true;
	}

	return false;
}

bool item::operator>(const item& it) const
{
	if(_projection>it._projection)
	{
		return true;
	}

	return false;
}

size_t item::pointId(void) const
{
	return _point_id;
}

float item::projection(void) const
{
	return _projection;
}

void item::_swap(item& it)
{
	std::swap(_point_id,it._point_id);
	std::swap(_projection,it._projection);
}

listnd::listnd(size_t n)
{
	_items=std::shared_ptr<item>(new item[n],std::default_delete<item>());
	_size=n;
	_index=0;
}

listnd::listnd(const listnd& lt)
{
	std::transform(lt.begin(),lt.end(),begin(),[](const_reference v)
			{
				return v;
			});
}

listnd::listnd(listnd&& lt)
{
	_swap(lt);
}

listnd& listnd::operator=(const listnd& lt)
{
	std::transform(lt.begin(),lt.end(),begin(),[](const_reference v)
			{
				return v;
			});
	return *this;
}

listnd::iterator listnd::begin(void)
{
	return _items.get();
}

listnd::const_iterator listnd::begin(void) const
{
	return _items.get();
}

listnd::iterator listnd::end(void)
{
	return _items.get()+_size;
}

listnd::const_iterator listnd::end(void) const
{
	return _items.get()+_size;
}

listnd::reference listnd::operator[](size_t i)
{
	return _items.get()[i];
}

listnd::const_reference listnd::operator[](size_t i) const
{
	return _items.get()[i];
}
void listnd::append(float projection)
{
	assert(_size-_index);
	_items.get()[_index]=item(_index,projection);
	_index++;
}
size_t listnd::size(void) const
{
	return _size;
}

void listnd::sorted()
{
	_items=sort<item>(begin(),end());
}

void listnd::_swap(listnd& lt)
{
	std::swap(_items,lt._items);
	std::swap(_size,lt._size);
	std::swap(_index,lt._index);
}
