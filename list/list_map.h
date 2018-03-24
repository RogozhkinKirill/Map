#ifndef __LIST_MAP_H__
#define __LIST_MAP_H__

typedef int MapKeyType;
typedef int MapValueType;


#include <stdlib.h>

#include "list.h"
#include "list_iterator.h"
#include "../debug_log.h"

typedef struct _map_elem
{
	MapKeyType   key;
	MapValueType value;
}Map_el, *pMap_el;

typedef struct _map
{
	pList data;
}Map , *pMap;

pMap CreateMap();
void DeleteMap(pMap*);

void AddToMap(pMap , MapKeyType , MapValueType);

int          IsInMap   (pMap , MapKeyType);
MapValueType GetFromMap(pMap , MapKeyType);
pMap_el      GetMapEl  (pMap , MapKeyType);

#endif //__LIST_MAP_H__
