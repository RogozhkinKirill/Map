#include "debug_log.h"
#include "list/list_iterator.h"
#include "list/list_map.h"


int main()
{	
	pMap map = CreateMap();
	debug_print("0x%p: Create Map \n" , map);

	pList lst = Create_List();
	debug_print("0x%p: Create List \n" , lst);


	DeleteMap(&map);
	debug_print("0x%p: Delete Map\n" , map);

	return 0;
}
