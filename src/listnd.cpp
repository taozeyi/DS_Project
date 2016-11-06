#include "listnd.h"

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
	_items.reset(new value_type[n]);
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
	return _items.get()+_size();
}

void listnd::append(float projection)
{
	assert(_size-index);
	items[index]=item(index,projection);
	index++;
}
size_t listnd::size(void) const
{
	return _size;
}

listnd::iterator listnd::sort()
{
	std::shared_ptr<value_type[]> sorted(new value_type[_size]);
	std::shared_ptr<value_type[]> left.reset();
}
