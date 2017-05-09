#include "Ybasis.h"

typedef void Node_t;

typedef struct _Ylist_t{
        struct _Ylist_t *next, *prev;
		Node_t *node;
} Ylist_t;

Ylist* Ylist_init();

int 	Ylist_add_head(Ylist_t *, Node_t *);
int 	Ylist_add_tail(Ylist_t *, Node_t *);

Node_t* Ylist_del_head(Ylist_t *, int);
Node_t* Ylist_del_tail(Ylist_t *, int);
