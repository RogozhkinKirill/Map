#include "list_map.h"


pMap CreateMap()
{
	pMap map = (pMap)malloc(sizeof(Map));
	map->data = CreateList();

    debug_print("0x%p: Create Map\n" , map);

	return map;
}

void DeleteMap(pMap* map)
{
    debug_print("0x%p: Delete Map\n" , *map);
    if (map && (*map) && (*map)->data)
	{
        pMap_el tmp = 0;
        pListIterator lst_itr = CreateListIterator((*map)->data);
        while (lst_itr)
		{
            tmp = (pMap_el)GetListIterator(&lst_itr);
            ListIteratorNext(&lst_itr);
            free(tmp);
        }

        pList lst = (*map)->data;
        DeleteList(&lst);

        free(*map);
    }

    if (map) {
        *map = NULL;
    }
}


void AddToMap(pMap map , MapKeyType key , MapValueType value)
{
    pMap_el element = GetMapEl(map , key);

    if(element)
    {
        element->value = value;
        return;
    }

    pMap_el map_el = (pMap_el)malloc(sizeof(Map_el));
    map_el->key   = key;
    map_el->value = value;

    AddList_elBack(&(map->data) , map_el);
}

int IsInMap (pMap map, MapKeyType key)
{
	pMap_el element = GetMapEl(map , key);
	
	if (element)
        return 1;
    else
        return 0;
}

MapValueType GetFromMap(pMap map , MapKeyType key)
{
	pMap_el element = GetMapEl(map , key);
	
	return element ? element->value : 0;
}

pMap_el GetMapEl(pMap map , MapKeyType key)
{
	pMap_el tmp_map_el = NULL;
    pListIterator lst_itr = CreateListIterator(map->data);


	while(lst_itr) 
	{
		tmp_map_el = (pMap_el)GetListIterator(&lst_itr);

		if(tmp_map_el && tmp_map_el->key == key)
        {
            DeleteListIterator(&lst_itr);
			return tmp_map_el;
        }

        ListIteratorNext(&lst_itr);
	}

    DeleteListIterator(&lst_itr);

	return 0;
}
