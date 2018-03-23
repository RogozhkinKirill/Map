#ifndef __LIST_H__
#define __LIST_H__

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
pList Create_List();
void  Destruct_List(pList* lst);


//List_el Functions

//Creator and Destructor
pList_el Create_List_el(void* value);
void     Destruct_List_el(pList_el* lst_el);

//Adding Functions
pList_el Add_List_el_Back(pList* lst , void* value);

#endif //_LIST_H_ 
