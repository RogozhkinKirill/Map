#ifndef __LIST_H__
#define __LIST_H__

#include "../debug_log.h"

typedef struct List_el
{
	void* value;
	
	struct List_el* prev;
	struct List_el* next;
} List_el , *pList_el;

typedef struct List
{
	pList_el head;
	pList_el tail;
	int num_el;
} List , *pList;

//List Functions

//Creator and Destructor
pList CreateList();
void  DeleteList(pList *lst);


//List_el Functions

//Creator and Destructor
pList_el CreateList_el(void *value);
void     DeleteList_el(pList_el *lst_el);

//Adding Functions
pList_el AddList_elBack(pList *lst, void *value);

#endif //_LIST_H_ 
