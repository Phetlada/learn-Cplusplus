#ifndef LinkList_H
#define  LinkList_H

template<class Object>
class List;
template<class Object>
class ListItr;

template<class Object>
class ListNode{
	ListNode(const Object &theElement = Object(),ListNode*n=NULL):element(theElement),next(n){}

	Object element;
	ListNode *next;

	friend class List<Object>;
	friend class ListItr<Object>;
};
template<class Object>
class ListItr{
	public:
		ListItr():current(){}

		bool isPastEnd() const{return current == NULL;}
		void advance(){
			if(!isPastEnd()){current = current->next;}
		}
		const Object &retrieve() const{
			if(isPastEnd())return NULL;
		return current->element;
		}
	private:
		ListNode<Object>*current;
		ListItr(ListNode<Object> *theNode) : current(theNode){}
		friend class List<Object>;

};
template<class Object>
class List{
	public:
		List();
		List(const List &rhs);
		~List();
		ListItr<Object> zeroth() const;
		ListItr<Object> first() const;
		bool isEmpty() const;
		void makeEmpty();
		void insert(const Object &x,const ListItr<Object>&p);
		void remove(const Object &x);
		ListItr<Object>find(const Object &x)const;
		ListItr<Object>findPrevious(const Object &x)const;
		const List &operator =(const List &rhs);
	private:
		ListNode<Object>*header;
};

#endif