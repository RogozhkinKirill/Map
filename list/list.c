#include "list.h"

#include <stdio.h>
#include <stdlib.h>

//List Functions

//Creator and Destructor
pList Create_List()
{
	pList lst = (pList)malloc(sizeof(List));
	
	lst->head = lst->tail = NULL;
	lst->num_el = 0;
	
	return lst;
}

void  Destruct_List(pList* lst)
{
	if(lst && *lst)
	{
		if((*lst)->head)
		{
			pList_el next    = NULL;
			pList_el current =  (*lst)->head;
			
			do
			{
				next = current->next;
				free(current);
				current = next;
			} while(next);
		}
		
		free(*lst);
	}
}


//List_el Functions

//Creator and Destructor
pList_el Create_List_el(void* value)
{
	pList_el lst_el = (pList_el)malloc(sizeof(List_el));
	
	lst_el->value = value;
	
	lst_el->next = lst_el->prev = NULL;
	
	return lst_el;
}

void     Destruct_List_el(pList_el* lst_el)
{
	free(*lst_el);
	*lst_el = NULL;
}

//Adding Functions
pList_el Add_List_el_Back(pList* lst , void* value)
{
	pList_el lst_el = Create_List_el(value);
	
	if((*lst)->head)
	{
		lst_el->prev = (*lst)->tail;
		(*lst)->tail->next = lst_el;
		(*lst)->tail = lst_el;
	}
	else
	{
		(*lst)->head = (*lst)->tail = lst_el;
	}
	
	return lst_el;
}
