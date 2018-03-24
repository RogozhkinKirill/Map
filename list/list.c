#include "list.h"
#include "list_iterator.h"


#include <stdio.h>
#include <stdlib.h>

//List Functions

//Creator and Destructor
pList CreateList()
{
	pList lst = (pList)malloc(sizeof(List));

    lst->head = lst->tail = NULL;
    lst->num_el = 0;
    debug_creator_print("0x%p: Create List\n" , lst);

    return lst;
}

void  DeleteList(pList *lst)
{
	if(lst)
    {
        if (*lst)
        {
            if ((*lst)->head)
            {
                pListIterator lst_itr = CreateListIterator(*lst);

                do
                {
                    void* tmp = GetListIterator(&lst_itr);
                    free(&tmp);
                    ListIteratorNext(&lst_itr);

                } while (lst_itr);
            }

            free(*lst);
        }
	}

    if (lst)
        *lst = NULL;

    debug_creator_print("0x%p: Delete List\n" , *lst);
}


//List_el Functions

//Creator and Destructor
pList_el CreateList_el(void *value)
{
	pList_el lst_el = (pList_el)malloc(sizeof(List_el));
	
	lst_el->value = value;
	lst_el->next = lst_el->prev = NULL;

    debug_creator_print("0x%p: Create List_el\n" , lst_el);

	return lst_el;
}

void     DeleteList_el(pList_el *lst_el)
{
    if (lst_el && *lst_el)
	    free(*lst_el);

    if (lst_el)
	    *lst_el = NULL;

    debug_creator_print("0x%p: Delete List\n" , *lst_el);
}



//Adding Functions
pList_el AddList_elBack(pList *lst, void *value)
{
	pList_el lst_el = CreateList_el(value);


    if(lst)
	{
        if (*lst)
        {
            if ((*lst)->head)
            {
                lst_el->prev = (*lst)->tail;
                (*lst)->tail->next = lst_el;
                (*lst)->tail = lst_el;
                (*lst)->tail = lst_el;

                return lst_el;
            }
            else
            {
                (*lst)->head = (*lst)->tail = lst_el;
                return lst_el;
            }
        }
    }

    DeleteList_el(&lst_el);

	
	return NULL;
}
