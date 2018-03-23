#ifndef ___LIST_ITERATOR_H__
#define ___LIST_ITERATOR_H__

#include "../list/list.h"

typedef struct ListIterator
{
	pList_el value;
	pList_el next;
}ListIterator , *pListIterator; 


//ListIterator Functions

//Creator and destructor
pListIterator CreateListIterator (pList  lst);
void          DestroyListIterator(pListIterator* lst_itr);

//Main Functions
void  ListIteratorNext(pListIterator* lst_itr);
void* GetListIterator (pListIterator* lst_itr);

#endif // ___LIST_ITERATOR_H__
