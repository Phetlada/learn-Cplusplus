#include <iostream>

using namespace std;

#include "Hsh.h"

template<class HashedObj>
HashTable<HashedObj>::HashTable(const HashedObj & notFound, int size) : ITEM_NOT_FOUND(notFound),array(nextPrime(size))
{
	makeEmpty();
}
template<class HashedObj>
void HashTable<HashedObj>::makeEmpty()
{
	currentSize = 0;
	for(int i = 0; i < array.size();i++){
		array[i].info = EMPTY;
	}
}
template<class HashedObj>
int HashTable<HashedObj>::nextPrime(int x){
	int num = 0;
	do{
	for(int  i = 1; i <=x; i++){
		if(x % i == 0) num++; 
	}
	if(num != 2){
		num = 0;
		x++;
	}
	}while(num != 2);

	return(x);
}
template <class HashedObj>
bool HashTable<HashedObj>::isActive(int currentPos )const
{
	return array[currentPos].info==ACTIVE;
}
template <class HashedObj>
int HashTable<HashedObj>::findPos(const HashedObj & x) const{
	int collisionNum = 0;
	cout << x <<"  ";
	cout << array.size()<< "  ";
	cout << x % array.size();
	int currentPos = (x % array.size());

	while( array[currentPos].info != EMPTY && array[currentPos].element != x){
		//currentPos = ++collisionNum*(array.size()-(x %array.size()));
		currentPos += 2*++collisionNum-1;
		if(currentPos >= array.size()){
			currentPos = currentPos%array.size();
		}
	}
	return currentPos;
}
template <class HashedObj>
void HashTable<HashedObj>::insert(const HashedObj & x){
	int currentPos = findPos(x);
	if(isActive(currentPos)) return;

	array[currentPos] = HashEntry(x,ACTIVE);
	cout << array[currentPos].element <<endl;
}
template <class HashedObj>
const HashedObj & HashTable<HashedObj>::find(const HashedObj & x)const{
	int currentPos = findPos(x);
	if(isActive(currentPos)) return array[currentPos].element;
	else return ITEW_NOT_FOUND;
}
template <class HashedObj>
void HashTable<HashedObj>::remove(const HashedObj & x){
	int currentPos = findPos(x);
	if(isActive(currentPos))array[ currentPos].info = DELETED;
	currentSize--;
}
template <class HashedObj>
const HashTable<HashedObj> & HashTable<HashedObj>::operator = (const HashTable & rhs){
	if(this != rhs)
	{
		array = rhs.array;
		currentSize = rhs.currentSize;
	}
	return *this;
}
template <class HashedObj>
void HashTable<HashedObj>::print(){
	for(int i= 0;i < array.size();i++){
		cout << "["<< i <<"]  "<< array[i].element <<"   "<<array[i].info << endl;
	}

}
void main(){ 
	 char Wait; 
	HashTable<int> a(-999);
	 char menu;
	 do{
		 system("cls");
		 cout <<"======{   HASHING   }======\n";
		 cout <<"|  1. Ceate HashTable     | \n";
		 cout <<"|  2. Insert              |\n";
		 cout <<"|  3. Print               |\n";
		 cout <<"|  4. Find                |\n";
		 cout <<"|  5. Remove              |\n";
		 cout <<"|  6. Exit/Quit           |\n";
		 cout <<"===========================\n";
		 cout <<"Enter choice Menu : ";
		 cin >> menu;

		 if(menu == '1'){
			int size;
	
			 cout <<"======{   Ceate HashTable   }======\n";
			 do{
			 cout <<"Enter TableSize [1-30] : ";
			 cin >> size;
			 }while(size > 30);
			 cout <<"===================================\n";
			 a.nextPrime(size);
		 }
		 if(menu == '2'){
			 int x;
			 cout <<"======{     Insert     }======\n";
			 cout <<"Enter Number : ";
			 cin >> x;

			 a.insert(x);	
		 }
		  if(menu == '3'){
			 cout <<"======{     Print     }======\n";
			 a.print();

		 }
		  	cin.get(Wait);
			cout << "\nPress Enter to back";
			cin.get(Wait);	
	 }while(menu != '6');
}
