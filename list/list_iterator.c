#include "list_iterator.h"

#include <stdlib.h>

//ListIterator Functions

//Creator and destructor
pListIterator CreateListIterator(pList lst)
{
	pListIterator lst_itr = (pListIterator)malloc(sizeof(ListIterator));	
	lst_itr->next = lst_itr->value = NULL;
    if (lst)
        if(lst->head)
        {
            lst_itr->value = lst->head;
            lst_itr->next  = lst->head->next;
            return lst_itr;
        }

    free(lst_itr);
    return NULL;
}

void DeleteListIterator(pListIterator *lst_itr)
{
	if (lst_itr && *lst_itr)
	{
		free(*lst_itr);	
	}

    if (lst_itr)
        *lst_itr = NULL;
}

//Main Functions
void  ListIteratorNext(pListIterator* lst_itr)
{


    if(lst_itr)
        if(*lst_itr)
        {
            if ((*lst_itr)->next != NULL)
            {
                (*lst_itr)->value = (*lst_itr)->next;
                (*lst_itr)->next = (*lst_itr)->value->next;
            }
            else
            {
                DeleteListIterator(lst_itr);
            }
        }


}


void* GetListIterator (pListIterator* lst_itr)
{
    void* value = NULL;

    if(lst_itr)
        if(*lst_itr)
            value = (*lst_itr)->value->value;



    return value;
}
