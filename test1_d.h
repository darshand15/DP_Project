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


//LIST

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


//STACK

#define init_stack(TYPE, variable)								\
{																\
	variable.head = NULL;										\
	variable.top = NULL;										\
	TYPE a;														\
	variable.type_ = typename(a);								\
	variable.push = push_##TYPE;								\
	variable.pop = pop_##TYPE;									\
	variable.disp_stack = disp_stack_##TYPE;					\
}


#define STACK(stack_t, TYPE)      										\
struct stack_node_##TYPE                     									\
{                               										\
	TYPE key;                   										\
	struct stack_node_##TYPE *prev;          									\
	struct stack_node_##TYPE *next;          									\
																		\
};                              										\
typedef struct stack_node_##TYPE stack_node_##TYPE##_t;     						\
																		\
struct stack_##TYPE														\
{                               										\
	stack_node_##TYPE##_t *head;               								\
	stack_node_##TYPE##_t *top;   											\
	int type_; 															\
	void (*push) (struct stack_##TYPE *ptr_s, TYPE key);           \
	void (*pop) (struct stack_##TYPE *ptr_s);					\
	void (*disp_stack) (const struct stack_##TYPE *ptr_s);					\
																		\
};                              										\
typedef struct stack_##TYPE stack_t;     									\
																		\
																		\
																		\
																		\
void push_##TYPE(stack_t* ptr_s, TYPE key)							\
{																		\
	stack_node_##TYPE##_t *temp = (stack_node_##TYPE##_t*)malloc(sizeof(stack_node_##TYPE##_t));						\
	temp->key = key;													\
	temp->prev = NULL;													\
	temp->next = NULL;													\
																		\
	/*stack is empty*/													\
	if(ptr_s->head == NULL)												\
	{																	\
		ptr_s->head = temp;												\
		ptr_s->top = temp;												\
	}																	\
																		\
	else																\
	{																	\
		ptr_s->top->next = temp;											\
		temp->prev = ptr_s->top;											\
		ptr_s->top = temp;												\
	}																	\
}																		\
																		\
                                                    			\
																		\
void pop_##TYPE(stack_t *ptr_s)                              			\
{                                                           			\
	/*stack is not empty	*/												\
	if(ptr_s->head != NULL)												\
	{						                                			\
		stack_node_##TYPE##_t *temp = ptr_s->top;                            			\
																		\
		/* stack contains only one element	*/							\
		if(ptr_s->head == ptr_s->top)                            			\
		{                                                   			\
			free(temp);                                     			\
			ptr_s->head = NULL;                                			\
			ptr_s->top = NULL;                                			\
		}			                                        			\
																		\
		else                                                			\
		{                                                   			\
		   ptr_s->top->prev->next = NULL;                     			\
		   ptr_s->top = ptr_s->top->prev;                       			\
		   free(temp);                                      			\
																		\
		}                                                   			\
	}                                                       			\
}                                                           			\
																		\
																		\
																		\
void disp_stack_##TYPE(const stack_t *ptr_s)									\
{																		\
	if(ptr_s->head!=NULL)													\
	{																	\
		stack_node_##TYPE##_t *trav = ptr_s->head;								\
		while(trav != NULL)												\
		{																\
			if( ptr_s->type_ == 0 )										\
				printf("%c\n", trav->key);								\
			else if( ptr_s->type_ == 1)									\
				printf("%f\n", trav->key);								\
			else if( ptr_s->type_ == 2 )									\
				printf("%d\n", trav->key);								\
			else if( ptr_s->type_ == 3 )									\
				printf("%lf\n", trav->key);								\
																		\
			trav = trav->next;											\
		}																\
	}																	\
}


//QUEUE

#define init_queue(TYPE, variable)								\
{																\
	variable.front = NULL;										\
	variable.tail = NULL;										\
	TYPE a;														\
	variable.type_ = typename(a);								\
	variable.enqueue = enqueue_##TYPE;							\
	variable.dequeue = dequeue_##TYPE;							\
	variable.disp_queue = disp_queue_##TYPE;					\
}


#define QUEUE(queue_t, TYPE)      										\
struct queue_node_##TYPE                     									\
{                               										\
	TYPE key;                   										\
	struct queue_node_##TYPE *prev;          									\
	struct queue_node_##TYPE *next;          									\
																		\
};                              										\
typedef struct queue_node_##TYPE queue_node_##TYPE##_t;     						\
																		\
struct queue_##TYPE														\
{                               										\
	queue_node_##TYPE##_t *front;               								\
	queue_node_##TYPE##_t *tail;   											\
	int type_; 															\
	void (*enqueue) (struct queue_##TYPE *ptr_q, TYPE key);           \
	void (*dequeue) (struct queue_##TYPE *ptr_q);					\
	void (*disp_queue) (const struct queue_##TYPE *ptr_q);					\
																		\
};                              										\
typedef struct queue_##TYPE queue_t;     									\
																		\
																		\
																		\
																		\
void enqueue_##TYPE(queue_t* ptr_q, TYPE key)							\
{																		\
	queue_node_##TYPE##_t *temp = (queue_node_##TYPE##_t*)malloc(sizeof(queue_node_##TYPE##_t));						\
	temp->key = key;													\
	temp->prev = NULL;													\
	temp->next = NULL;													\
																		\
	/*queue is empty*/													\
	if(ptr_q->front == NULL)												\
	{																	\
		ptr_q->front = temp;												\
		ptr_q->tail = temp;												\
	}																	\
																		\
	else																\
	{																	\
		ptr_q->tail->next = temp;											\
		temp->prev = ptr_q->tail;											\
		ptr_q->tail = temp;												\
	}																	\
}																		\
																		\
																\
																		\
void dequeue_##TYPE(queue_t *ptr_q)											\
{																		\
	/*queue is not empty*/												\
	if(ptr_q->front != NULL)												\
	{						                                			\
		queue_node_##TYPE##_t *temp = ptr_q->front;                            			\
																		\
		/*queue contains only one element*/								\
		if(ptr_q->front == ptr_q->tail)                            			\
		{                                                   			\
			free(temp);                                     			\
			ptr_q->front = NULL;                                			\
			ptr_q->tail = NULL;                                			\
		}			                                        			\
																		\
		else                                                			\
		{                                                  				\
		   ptr_q->front->next->prev = NULL;                     			\
		   ptr_q->front = ptr_q->front->next;                       			\
		   free(temp);                                      			\
																		\
		}                                                   			\
	}																	\
}	                                                        			\
																		\
															\
																		\
void disp_queue_##TYPE(const queue_t *ptr_q)									\
{																		\
	if(ptr_q->front!=NULL)													\
	{																	\
		queue_node_##TYPE##_t *trav = ptr_q->front;								\
		while(trav != NULL)												\
		{																\
			if( ptr_q->type_ == 0 )										\
				printf("%c\n", trav->key);								\
			else if( ptr_q->type_ == 1)									\
				printf("%f\n", trav->key);								\
			else if( ptr_q->type_ == 2 )									\
				printf("%d\n", trav->key);								\
			else if( ptr_q->type_ == 3 )									\
				printf("%lf\n", trav->key);								\
																		\
			trav = trav->next;											\
		}																\
	}																	\
}