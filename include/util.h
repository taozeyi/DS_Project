#include <iostream>
#include <memory>
#include <algorithm>
#include <random>

#include "vecnd.h"

static std::random_device rd;
static std::mt19937 rnd;

template <typename T>
static std::shared_ptr<T> copy(T* begin,
		T* end)
{
	std::shared_ptr<T> result(new T[std::distance(begin,end)],std::default_delete<T>());
	std::transform(begin,end,result.get(),[](T& v)
			{
				return v;
			});
	return result;
}
template <typename T>
static std::shared_ptr<T> sort(T* begin,
		T* end)
{
	size_t size=std::distance(begin,end);
	std::shared_ptr<T> result(new T[size],std::default_delete<T>());
	if(size==1)
	{
		result.get()[0]=*begin;
		return result;
	}
	std::shared_ptr<T> left=copy<T>(begin,begin+size/2);
	std::shared_ptr<T> right=copy<T>(begin+size/2,end);
	left=sort<T>(left.get(),left.get()+size/2);
	right=sort<T>(right.get(),right.get()+size-size/2);
	T *left_begin=left.get(),
          *left_end=left_begin+size/2,
	  *right_begin=right.get(),
          *right_end=right_begin+(size-size/2);
	T *result_begin=result.get(),
          *result_end=result_begin+size;
	T *p=left_begin, *q=right_begin, *r=result_begin;
	while(p!=left_end&&q!=right_end)
	{
		if(*p<*q)
		{
			*r=*p;
			p++;
		}
		else
		{
			*r=*q;
			q++;
		}
		r++;
	}
	while(p!=left_end)
	{
		*r=*p;
		p++;
		r++;
	}
	while(q!=right_end)
	{
		*r=*q;
		q++;
		r++;
	}
	return result;
}

static float randomFloat(float lower=0.0f, float upper=1.0f)
{
	std::uniform_real_distribution<float> dist(lower,upper);
	return dist(rnd);
}
static int randomInt(int lower=0,int upper=1)
{
	std::uniform_int_distribution<int> dist(lower,upper);
	return dist(rnd);
}
static vecnd randomVector(size_t n,float lower=0.0f,float upper=1.0f)
{
	vecnd v(n);
	for(int i=0;i<n;i++)
	{
		v[i]=randomFloat(lower,upper);
	}
	return v;
}
