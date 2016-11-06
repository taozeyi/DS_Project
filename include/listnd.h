#ifndef _LISTND_H
#define _LISTND_H

#include <iostream>
#include <vector>

class item
{
	public:
	item(size_t point_id,float proj);
	item(const item& it);

	item& operator=(const item& it);
	bool operator<(const item& it) const;
	bool operator>(const item& it) const;

	size_t pointId(void) const;
	float projection(void) const;

        friend void swap(item& a,item& b)
	{
		a._swap(b);
	}
	friend std::ostream& operator<<(std::ostream& s,const item& it)
	{
		s<<"#"<<it._point_id<<", projection:"<<it._projection<<std::endl;
		return s;
	}
	private:
        
	void _swap(item& it);

	size_t _point_id;
	float _projection;

};
class listnd
{
	typedef item value_type;
	typedef value_type& reference;
	typedef const value_type& const_reference;
	typedef std::shared_ptr<value_type[]>::pointer iterator;
	typedef std::shared_ptr<const value_type[]>::pointer const_iterator;
	typedef size_t difference_type;
	typedef size_t size_type;

	public:
	listnd(size_t n);
	listnd(const listnd& lt);
	listnd(listnd&& lt);

	list& operator=(const listnd& lt);
        
	iterator begin(void);
	const_iterator begin(void) const;

	iterator end(void);
	const_iterator end(void) const;
	
	void append(float projection);
	size_t size(void) const;
	iterator sort();

        friend std::ostream& operator<<(std::ostream& s,const listnd& lt)
	{
		s<<"list: Has"<<lt.size()<<"items";
		return s;
	}

	private:
	void _swap(listnd& lt);

	std::shared_ptr<value_type[]> _items; 
        size_t _size;
        size_t _index;
};
#endif
