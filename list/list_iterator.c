#include "list_iterator.h"

#include <stdlib.h>

//ListIterator Functions

//Creator and destructor
pListIterator CreateListIterator(pList lst)
{
	pListIterator lst_itr = (pListIterator)malloc(sizeof(ListIterator));	
	lst_itr->next = NULL;
	if(lst->head)
		lst_itr->value = lst->head;
	else
	{
		free(lst_itr);
		return NULL;
	}
	
	return lst_itr;
}

void DestroyListIterator(pListIterator* lst_itr)
{
	if (lst_itr && *lst_itr)
	{
		free(*lst_itr);	
		*lst_itr = NULL;
	}
}

//Main Functions
void  ListIteratorNext(pListIterator* lst_itr)
{
	if(lst_itr && *lst_itr)
	{
		if((*lst_itr)->next)
		{
			(*lst_itr)->value = (*lst_itr)->next;
			(*lst_itr)->next = (*lst_itr)->next;
		}	
		else
			DestroyListIterator(lst_itr);
	}
}


void* GetListIterator (pListIterator* lst_itr)
{
    void* value = NULL;

    if(lst_itr)
        value = (*lst_itr)->value->value;

    return value;

}
