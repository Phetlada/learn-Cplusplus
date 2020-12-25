#include <iostream>
using namespace std;

#include "LinkList.h"
template<class Object>
List<Object>::List()
{
	header = new ListNode<Object>;
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
template<class Object>
bool List<Object>::isEmpty()const
{
	return header->next==NULL;
}
template<class Object>
void printList(const List<Object> &theList){
	if(theList.isEmpty())cout<<"Empty list"<<endl;
	else
	{
		ListItr<Object>itr = theList.first();
		for(; !itr.isPastEnd();itr.advance())cout<< itr.retrieve()<<"  ";
	}
	cout<<endl;
}
template<class Object>
void List<Object>::remove(const Object &x)
{
	ListItr<Object> p = findPrevious(x);
	if(p.current->next != NULL)
	{
		ListNode<Object> *oldNode = p.current->next;
		p.current->next = p.current->next->next;
		delete oldNode;
	}
}
template<class Object>
ListItr<Object>List<Object>::findPrevious(const Object &x)const{
	ListNode<Object>*itr = header;
	while (itr->next != NULL && itr->next->element != x)itr = itr->next; 
	return ListItr<Object>(itr);
}
template<class Object>
ListItr<Object>List<Object>::find(const Object &x)const
{
	int count = 1;
	ListNode<Object>*itr = header->next;
	while(itr != NULL && itr->element != x){count++;itr =itr->next; }	
	cout << "Position is "<< count<<endl;
	cout << "ListNode Address is "<<itr<<endl;
	return ListItr<Object>(itr);
}
template<class Object>
void List<Object>::makeEmpty()
{
	while(!isEmpty()){
		remove(first().retrieve());
	}
}
template<class Object>
List<Object>::~List()
{
	makeEmpty();
	delete header;
}
void main()
{
	char Wait;
	int num = 0;
	List<int> a;
	ListItr<int> b;
	b = a.zeroth();
	char ch;
	do{
	system("cls");
	cout<<"==================================="<<endl;
	cout<<"|           Linked List           |"<<endl;
	cout<<"==================================="<<endl;
	cout<<"| 1. Insert                       |"<<endl;
	cout<<"| 2. PrintList                    |"<<endl;
	cout<<"| 3. Find                         |"<<endl;
	cout<<"| 4. Findkth                      |"<<endl;
	cout<<"| 5. Remove                       |"<<endl;
	cout<<"| 6. Quit                         |"<<endl;
	cout<<"==================================="<<endl;
	
	cout<<"Enter choice : ";
	cin >> ch;
	if(ch == '1'){
		int x, l;
		do{
			system("cls");
			cout<<"==================================="<<endl;
			cout<<"|              Insert             |"<<endl;
			cout<<"==================================="<<endl;
			cout<<"| 1. Font Insert                  |"<<endl;
			cout<<"| 2. Back Insert                  |"<<endl;
			cout<<"| 3. Position Insert              |"<<endl;
			cout<<"| 4. Quit                         |"<<endl;
			cout<<"==================================="<<endl;

			cout<<"Enter choice : ";
			cin >> l;
			if(l == 1){
				cout<<"Plase Enter Element : ";
				cin >> x;
				b=a.zeroth();
				a.insert(x,b);
				num++;
				cout << num;
				cout<<"Successful Insert"<<endl;
				
			}
			else if(l == 2){
				cout<<"Plase Enter Element : ";
				cin >> x;
				b=a.zeroth();
				for(int i = 0;i<num;i++){
				b.advance();
				}
				a.insert(x,b);
				num++;
				cout<<"Successful Insert"<<endl;
			}
			else if(l == 3){
				int p;
				cout<<"Plase Enter Position [1-"<<num<<"] : ";
				cin >> p;
				cout<<"Plase Enter Element : ";
				cin >> x;
				b=a.zeroth();
				for(int i = 0;i<p;i++){
				b.advance();
				}
				a.insert(x,b);
				num++;
				cout<<"Successful Insert"<<endl;

			}		
			cin.get(Wait);
			cout << "\nPress Enter to back";
			cin.get(Wait);	
		}while(l != 4);
	}else if(ch == '2'){
		cout << "Data of List : "; 
		printList(a);


		cin.get(Wait);
		cout << "\nPress Enter to back";
		cin.get(Wait);	
	}else if(ch == '3'){
		int find;
		if(num == 0){
			cout << "ERROR NOT HAVE DATA";

			cin.get(Wait);
			cout << "\nPress Enter to back";
			cin.get(Wait);
		}
		else{
		int c;
		b = a.zeroth();
		cout<<"Plase Enter Element : ";
		cin >> find;
		b=a.find(find);
		if(b.retrieve()==find){
			cout <<"Found"<<endl;

		}else cout <<"Not Found!"<<endl;
		cin.get(Wait);
		cout << "\nPress Enter to back";
		cin.get(Wait);
		}
	}else if(ch == '4'){
		int p;
		b=a.zeroth();
		if(num == 0){
			cout << "ERROR NOT HAVE DATA";
		}else{
			cout<<"Plase Enter Position [1-"<<num<<"] : ";
			cin >> p;
			if(p>=1&&p<=num){
			int ans;
			for(int i = 0;i < p;i++){
				b.advance();
			}
			ans =b.retrieve();
			cout <<"Element of position "<< p <<" is "<<ans;
			}
		}

		cin.get(Wait);
		cout << "\nPress Enter to back";
		cin.get(Wait);	

	}else if(ch == '5'){
		int u;
		do{

			system("cls");
			cout<<"==================================="<<endl;
			cout<<"|              Insert             |"<<endl;
			cout<<"==================================="<<endl;
			cout<<"| 1. Remove Data                  |"<<endl;
			cout<<"| 2. MakeEmpty                    |"<<endl;
			cout<<"| 3. Quit                         |"<<endl;
			cout<<"==================================="<<endl;

			cout<<"Enter choice : ";
			cin >> u;
			if(u == 1){
				if(num == 0){
				cout << "ERROR NOT HAVE DATA";
				}
				else{
				int re;
				cout << "Data of List : "; 
				printList(a);
				cout<<"Plase Enter Element : ";
				cin >> re;
				a.remove(re);
				}		
			}
			else if(u == 2){
				if(num == 0){
				cout << "ERROR NOT HAVE DATA";
				}
				else{
				a.makeEmpty();
				cout<<"remove Successful \n";
				b=a.zeroth();
				num = 0;
				}		
			}
		}while(u != 3);		
		cin.get(Wait);
		cout << "\nPress Enter to back";
		cin.get(Wait);
	}
	}while(ch != '6');
	
	
	


}