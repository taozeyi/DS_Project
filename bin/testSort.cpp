#include "listnd.h"
#include "util.h"

int main()
{
	std::shared_ptr<item> items(new item[10],std::default_delete<item>());
        items.get()[0]=item(1,10);
        items.get()[1]=item(2,9);      
        items.get()[2]=item(3,8);
        items.get()[3]=item(4,7);
        items.get()[4]=item(5,6);
        items.get()[5]=item(6,11);
        items.get()[6]=item(7,4);
        items.get()[7]=item(8,3);
        items.get()[8]=item(9,25);
	items.get()[9]=item(10,1);
	items=sort<item>(items.get(),items.get()+10);
	for(int i=0;i<10;i++)
	{
		std::cout<<items.get()[i]<<" ";
	}
	std::cout<<std::endl;
}
