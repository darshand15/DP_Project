#include <stdlib.h>
#include <stdio.h>
#define Vector( TYPE , type2)          									\
  type2 type2##_MAX( type2 a, type2 b ) 								\
  {                                  									\
	return (a > b) ? a : b;          									\
  }


#define typename(x) _Generic((x),                   \
        char: TYPENAME_CHAR,                       \
        int: TYPENAME_INT,                        \
        float: TYPENAME_FLOAT,                      \
		double: TYPENAME_DOUBLE,                 	\
        char*: TYPENAME_POINTER_TO_CHAR,        	\       
		double*: TYPENAME_POINTER_TO_DOUBLE,		\
		float*: TYPENAME_POINTER_TO_FLOAT,			\
       void*: TYPENAME_POINTER_TO_VOID,        		\        
	   int*: TYPENAME_POINTER_TO_INT,         		\
      default: TYPENAME_OTHER)


 enum t_typename {
        TYPENAME_CHAR,                  //0
        TYPENAME_FLOAT,                 //1
        TYPENAME_INT,                   //2
        TYPENAME_DOUBLE,                //3
		TYPENAME_POINTER_TO_INT,		//4
		TYPENAME_POINTER_TO_FLOAT,		//5
		TYPENAME_POINTER_TO_CHAR,		//6
        TYPENAME_POINTER_TO_DOUBLE,     //7
        TYPENAME_POINTER_TO_VOID,       //8
        TYPENAME_OTHER                  //9
    };



#define init_list(TYPE, variable)								\
{																\
	variable.head = NULL;										\
	variable.tail = NULL;										\
	TYPE a;														\
	variable.type_ = typename(a);								\
	variable.insert_at_end = insert_at_end_##TYPE;				\
	variable.insert_at_beg = insert_at_beg_##TYPE;				\
	variable.delete_from_beg = delete_from_beg_##TYPE;			\
	variable.delete_from_end = delete_from_end_##TYPE;			\
	variable.delete_key = delete_key_##TYPE;					\
	variable.disp_list = disp_list_##TYPE;						\
}


#define LIST(list_t, TYPE)      										\
struct node_##TYPE                     									\
{                               										\
	TYPE key;                   										\
	struct node_##TYPE *prev;          									\
	struct node_##TYPE *next;          									\
																		\
};                              										\
typedef struct node_##TYPE node_##TYPE##_t;     						\
																		\
struct list_##TYPE														\
{                               										\
	node_##TYPE##_t *head;               								\
	node_##TYPE##_t *tail;   											\
	int type_; 															\
	void (*insert_at_end) (struct list_##TYPE *l1, TYPE key);           \
	void (*insert_at_beg) (struct list_##TYPE *l1, TYPE key);			\
	void (*delete_from_beg) (struct list_##TYPE *l1);					\
	void (*delete_from_end) (struct list_##TYPE *l1);					\
	void (*delete_key) (struct list_##TYPE *l1, TYPE key);				\
	void (*disp_list) (const struct list_##TYPE *l1);					\
																		\
};                              										\
typedef struct list_##TYPE list_t;     									\
																		\
																		\
																		\
																		\
void insert_at_end_##TYPE(list_t* l1, TYPE key)							\
{																		\
	node_##TYPE##_t *temp = (node_##TYPE##_t*)malloc(sizeof(node_##TYPE##_t));						\
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
void insert_at_beg_##TYPE(list_t *l1, TYPE key)								\
{																		\
	node_##TYPE##_t *temp = (node_##TYPE##_t*)malloc(sizeof(node_##TYPE##_t));						\
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
void delete_from_beg_##TYPE(list_t *l1)											\
{																		\
	/*list is not empty	*/												\
	if(l1->head != NULL)												\
	{						                                			\
		node_##TYPE##_t *temp = l1->head;                            			\
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
void delete_from_end_##TYPE(list_t *l1)                              			\
{                                                           			\
	/*list is not empty	*/												\
	if(l1->head != NULL)												\
	{						                                			\
		node_##TYPE##_t *temp = l1->tail;                            			\
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
void delete_key_##TYPE(list_t *l1, TYPE key)                         			\
{                                                           			\
	if(l1->head->key == key)                                			\
	{                                                       			\
		delete_from_beg_##TYPE(l1);                                			\
	}                                                                   \
																		\
	else                                                                \
	{                                                                   \
		node_##TYPE##_t *trav = l1->head;                                        \
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
				delete_from_end_##TYPE(l1);                                    \
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
void disp_list_##TYPE(const list_t *l1)									\
{																		\
	if(l1->head!=NULL)													\
	{																	\
		node_##TYPE##_t *trav = l1->head;								\
		while(trav != NULL)												\
		{																\
			if( l1->type_ == 0 )										\
				printf("%c\n", trav->key);								\
			else if( l1->type_ == 1)									\
				printf("%f\n", trav->key);								\
			else if( l1->type_ == 2 )									\
				printf("%d\n", trav->key);								\
			else if( l1->type_ == 3 )									\
				printf("%lf\n", trav->key);								\
																		\
			trav = trav->next;											\
		}																\
	}																	\
}
