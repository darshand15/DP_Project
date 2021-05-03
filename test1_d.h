#include <stdlib.h>
#include <stdio.h>
#define Vector( TYPE , type2)          									\
  type2 type2##_MAX( type2 a, type2 b ) 								\
  {                                  									\
	return (a > b) ? a : b;          									\
  }

#define LIST(list_t, TYPE)      										\
struct node                     										\
{                               										\
	TYPE key;                   										\
	struct node *prev;          										\
	struct node *next;          										\
																		\
};                              										\
typedef struct node node_t;     										\
																		\
struct list																\
{                               										\
	node_t *head;               										\
	node_t *tail;               										\
};                              										\
typedef struct list list_t;     										\
																		\
void init_list(list_t *l1)												\
{																		\
	l1->head = NULL;													\
	l1->tail = NULL;													\
}																		\
																		\
																		\
void insert_at_end(list_t* l1, TYPE key)								\
{																		\
	node_t *temp = (node_t*)malloc(sizeof(node_t));						\
	temp->key = key;													\
	temp->prev = NULL;													\
	temp->next = NULL;													\
																		\
	/*list is empty*/													\
	if(l1->head == NULL)												\
	{																	\
		l1->head = temp;												\
		l1->tail = temp;												\
	}																	\
																		\
	else																\
	{																	\
		l1->tail->next = temp;											\
		temp->prev = l1->tail;											\
		l1->tail = temp;												\
	}																	\
}																		\
																		\
void insert_at_beg(list_t *l1, TYPE key)								\
{																		\
	node_t *temp = (node_t*)malloc(sizeof(node_t));						\
	temp->key = key;													\
	temp->prev = NULL;													\
	temp->next = NULL;													\
																		\
	/*list is empty		*/												\
	if(l1->head == NULL)												\
	{																	\
		l1->head = temp;												\
		l1->tail = temp;												\
	}																	\
																		\
	else																\
	{																	\
		temp->next = l1->head;											\
		l1->head->prev = temp;											\
		l1->head = temp;												\
	}																	\
}																		\
																		\
void delete_from_beg(list_t *l1)											\
{																		\
	/*list is not empty	*/												\
	if(l1->head != NULL)												\
	{						                                			\
		node_t *temp = l1->head;                            			\
																		\
		/*list contains only one element*/								\
		if(l1->head == l1->tail)                            			\
		{                                                   			\
			free(temp);                                     			\
			l1->head = NULL;                                			\
			l1->tail = NULL;                                			\
		}			                                        			\
																		\
		else                                                			\
		{                                                  				\
		   l1->head->next->prev = NULL;                     			\
		   l1->head = l1->head->next;                       			\
		   free(temp);                                      			\
																		\
		}                                                   			\
	}																	\
}	                                                        			\
																		\
void delete_from_end(list_t *l1)                              			\
{                                                           			\
	/*list is not empty	*/												\
	if(l1->head != NULL)												\
	{						                                			\
		node_t *temp = l1->tail;                            			\
																		\
		/* list contains only one element	*/							\
		if(l1->head == l1->tail)                            			\
		{                                                   			\
			free(temp);                                     			\
			l1->head = NULL;                                			\
			l1->tail = NULL;                                			\
		}			                                        			\
																		\
		else                                                			\
		{                                                   			\
		   l1->tail->prev->next = NULL;                     			\
		   l1->tail = l1->tail->prev;                       			\
		   free(temp);                                      			\
																		\
		}                                                   			\
	}                                                       			\
}                                                           			\
																		\
void delete_key(list_t *l1, TYPE key)                         			\
{                                                           			\
	if(l1->head->key == key)                                			\
	{                                                       			\
		delete_from_beg(l1);                                			\
	}                                                                   \
																		\
	else                                                                \
	{                                                                   \
		node_t *trav = l1->head;                                        \
																		\
		while(trav != NULL && trav->key != key)                         \
		{                                                               \
			trav = trav->next;                                          \
		}                                                               \
																		\
		if(trav)                                                        \
		{                                                               \
			/*element to be deleted is the last element */              \
			if(trav == l1->tail)                                        \
			{                                                           \
				delete_from_end(l1);                                    \
			}                                                           \
																		\
			else                                                        \
			{                                                           \
				if(trav->prev != NULL)                                  \
				{                                                       \
					trav->prev->next = trav->next;                      \
				}                                                       \
																		\
				if(trav->next != NULL)                                  \
				{                                                       \
					trav->next->prev = trav->prev;                      \
				}                                                       \
																		\
				free(trav);                                             \
			}                                                           \
		}                                                               \
	}                                                                   \
}																		\
																		\
void disp_list(const list_t *l1)												\
{																		\
	if(l1->head!=NULL)													\
	{\
		node_t *trav = l1->head;\
		while(trav != NULL)\
		{	\
			printf("%f\n", trav->key);\
			trav = trav->next;\
		}\
	}\
}
