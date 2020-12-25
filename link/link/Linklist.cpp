#include "Linklist.h"

template<class Object>
List<Object>::List()
{
	header = new ListNode<Object>;
}
template<class Object>
bool List<Object>::isEmpty() const
{
	return (header->next) == NULL;
}

template<class Object>
ListItr<Object> List<Object>::zeroth() const
{
	return ListItr<Object>(header);
}

template<class Object>
ListItr<Object> List<Object>::first() const
{
	return ListItr<Object>(header->next);
}

template<class Object>
void List<Object>::insert(const Object &x,const ListItr<Object>&p) 
{
	if(p.current != NULL)
		p.current->next = new ListNode<Object>(x,p.current->next);
}
