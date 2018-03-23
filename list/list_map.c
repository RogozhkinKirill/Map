#include "list_map.h"


pMap CreateMap()
{
	pMap map = (pMap)malloc(sizeof(Map));
	map->data = 0;
	
	return map;
}

void DeleteMap(pMap* map)
{
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
		
		free(*map);
	}

    *map = NULL;
}


void AddToMap(pMap map , MapKeyType key , MapValueType value)
{
	pMap_el map_el = (pMap_el)malloc(sizeof(Map_el));
	map_el->key   = key;
	map_el->value = value;
	
	if(map)
		Add_List_el_Back(&map->data , (void*)map_el);
}

int IsInMaps (pMap map, MapKeyType key)
{
	pMap_el element = GetMapEl(map , key);
	
	return element != NULL;
}

MapValueType GetFromMap(pMap map , MapKeyType key)
{
	pMap_el element = GetMapEl(map , key);
	
	return element ? element->value : NULL;
}

pMap_el GetMapEl(pMap map , MapKeyType key)
{
	pMap_el tmp_map_el = NULL;
	pListIterator lst_itr = CreateListIterator(map->data);
	
	while(lst_itr) 
	{
		tmp_map_el = (pMap_el)GetListIterator(&lst_itr);
		
		debug_print("Line = %d:\ntmp_map_el 0x%p\n" , __LINE__ , tmp_map_el);
		
		if(tmp_map_el && tmp_map_el->key == key)
		{
			DestroyListIterator(&lst_itr);
			return tmp_map_el;
		}
		else
			ListIteratorNext(&lst_itr);
	}
	
	DestroyListIterator(&lst_itr);
	return 0;
}
