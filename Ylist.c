#include "Ylist.h"


static int _list_init(Ylist_t *Ylist)
{
	if (!Ylist)
		return -1;
	Ylist->next = Ylist;
	Ylist->prev = Ylist;
	return 0;
}


Ylist* Ylist_init()
{
	Ylist_t *Ylist = Ymalloc(sizeof(Ylist_t));
	if (_list_init(Ylist))
		return NULL;
	return Ylist;
}

static  void _list_add(Ylist_t *new_node,
			      Ylist_t *prev,
			      Ylist_t *next)
{
	next->prev = new_node;
	new_node->next = next;
	new_node->prev = prev;
	prev->next = new_node;
}

int 	Ylist_add_head(Ylist_t *Ylist, Node_t *node)
{
	Ylist_t *Ynode = NULL;
	
	if (!node)
		return -1;
	
	Ynode = Ymalloc(sizeof(Ylist_t));
	if (!Ynode)
		return -2;
	
	Ynode->node = node;
	_list_add(Ynode, Ylist, Ylist->next);
	return 0;
}

int 	Ylist_add_tail(Ylist_t *Ylist, Node_t *node)
{
	Ylist_t *Ynode = NULL;
	
	if (!node)
		return -1;
	
	Ynode = Ymalloc(sizeof(Ylist_t));
	if (!Ynode)
		return -2;
	
	Ynode->node = node;
	_list_add(Ynode, Ylist->prev, Ylist);
	return 0;
}



static void _list_del(Ylist_t *entry)
{
	Ylist *prev = NULL, *next = NULL;
	prev = entry->prev;
	next = entry->next;
	next->prev = prev;
	prev->next = next;
}

Node_t* Ylist_del_head(Ylist_t *Ylist, int _if_free)
{
	Ylist_t *entry = NULL;
	Node_t *node = NULL;
	if (!Ylist || !Ylist->next)
		return NULL;
	
	entry = Ylist->next;
	if (entry == Ylist)
		return NULL;
	
	node = entry->node;
	Yassert(node);
	
	_list_del(entry);
	if (_if_free)
	{
		Yfree(node);
		node = NULL;
	}
	Yfree(entry);
	
	return node;
}
Node_t* Ylist_del_tail(Ylist_t *Ylist, int _if_free)
{	
	Ylist_t *entry = NULL;
	Node_t *node = NULL;
	if (!Ylist || !Ylist->prev)
		return NULL;
	
	entry = Ylist->prev;
	if (entry == Ylist)
		return NULL;
	
	node = entry->node;
	Yassert(node);
	
	_list_del(entry);
	if (_if_free)
	{
		Yfree(node);
		node = NULL;
	}
	Yfree(entry);
	
	return node;
}


static void _list_replace(Ylist_t *old_node,
				Ylist_t *new_node)
{
	new_node->next = old_node->next;
	new_node->next->prev = new_node;
	new_node->prev = old_node->prev;
	new_node->prev->next = new_node;
}


























