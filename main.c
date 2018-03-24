#include "debug_log.h"
#include "list/list_iterator.h"
#include "list/list_map.h"


int main()
{
    //Test on correct work ListMap
    pMap map = CreateMap();

    AddToMap(map , 1 , 1);
    AddToMap(map , 2 , 2);
    AddToMap(map , 3 , 3);


    pMap_el map_el = (pMap_el)(map->data->tail->value);
    printf ("elem value %d\n"
                    "elem key %d\n" , map_el->value , map_el->key);

    printf ("IsInMap %d\n" , IsInMap(map , 2));

    DeleteMap(&map);

	return 0;
}
