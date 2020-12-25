#include<iomanip>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

template <class HashedObj>
class HashTable
{
public:
	explicit HashTable(const HashedObj & notFound, int size = 31);

	HashTable(const HashTable & rhs) 
		: currentSize(rhs.currentSize), ITEM_NOT_FOUND(rhs.ITEM_NOT_FOUND), 
		array(rhs.array) {}

	HashedObj find(HashedObj & x);

	void makeEmpty();
	void insert( HashedObj & x);
	void remove( HashedObj & x);

	const HashTable & operator=(const HashTable & rhs);

	enum EntryType { ACTIVE, EMPTY, DELETED };
	//
	void create(int size);
	int nextPrime(int size);
	int beforePrime(int size);
	void printTable();

private:
	struct HashEntry
	{
		HashedObj element;
		EntryType info;
		HashEntry(const HashedObj & e = HashedObj(),
			EntryType i = EMPTY) : element(e), info(i) { }
	};

	vector<HashEntry> array;
	int currentSize;
	const HashedObj ITEM_NOT_FOUND;

	bool isActive(int currentPos) const;
	int findPos(HashedObj & x);
	void rehash();
	int hash(int x, int tableSize);
	int hash2(int x);
};

//consturctor 
template <class HashedObj>
HashTable <HashedObj>::HashTable(const HashedObj & notFound, int size) 
	: ITEM_NOT_FOUND(notFound), array(nextPrime(size))
{
	makeEmpty();
}

//create table
template <class HashedObj>
void HashTable <HashedObj>::create(int size){
	array.resize(size);
	makeEmpty();
}

template <class HashedObj>
void HashTable <HashedObj>::makeEmpty()
{
	currentSize = 0;
	for (int i = 0; i<array.size(); i++){
		array[i].element = 0;
		array[i].info = EMPTY;
	}
}

template <class HashedObj>
bool HashTable <HashedObj>::isActive( int currentPos) const
{
	return array[ currentPos ].info == ACTIVE;
}


template <class HashedObj>
int HashTable <HashedObj>::nextPrime(int  size){
	int prime = 0;
	while(size % 2 == 0 || size == 2)
		size++;

	for(int i = 1; i <= size; i++)
	{
		if(size % i == 0)
			prime++;
	}
	if(prime == 2)
		return size;
	else 
		return nextPrime(size+2);
}

template <class HashedObj>
int HashTable <HashedObj>::beforePrime(int size){
	int prime = 0;
	while(size % 2 == 0)
		size--;

	for(int i = 1; i <= size; i++)
	{
		if(size % i == 0)
			prime++;
	}
	if(prime == 2)
		return size;
	else 
		return beforePrime(size-2);
}

template <class HashedObj>
int HashTable <HashedObj>::hash(int x, int tableSize){
	return x % tableSize;
}

template <class HashedObj>
int HashTable <HashedObj>::hash2(int x){
	int r = beforePrime(array.size()-1);
	return r - (x % r);
}

template <class HashedObj>
int HashTable <HashedObj>::findPos( HashedObj & x ) 
{
	int collisionNum = 0;
	int currentPos = hash(x, array.size());

	while( array[ currentPos ].info != EMPTY && array[ currentPos ].element != x){
		currentPos = 
			( hash(x, array.size()) + (++collisionNum * hash2(x)) ) % array.size();

		if(currentPos >= array.size())
			currentPos -= array.size();
	}
	return currentPos;
}

template <class HashedObj>
void HashTable <HashedObj>::insert( HashedObj & x)
{
	int currentPos = findPos(x);
	if( isActive( currentPos ) ) return;

	array[currentPos] = HashEntry(x, ACTIVE);


	if (++currentSize > (array.size() * 0.7)) 
		rehash();
}

template <class HashedObj>
void HashTable <HashedObj>::rehash(){
	vector<HashEntry> oldTable = array;

	array.resize(nextPrime(2 * oldTable.size()));
	makeEmpty();

	for (int i = 0; i < oldTable.size(); i++)
	if (oldTable[i].info == ACTIVE)
		insert(oldTable[i].element);
}

template <class HashedObj>
void HashTable <HashedObj>::remove(HashedObj & x)
{
	int currentPos = findPos( x );
	if( isActive( currentPos ) )
		array[ currentPos ].info = DELETED;
	currentSize--;
}

template <class HashedObj>
HashedObj HashTable <HashedObj>::find(HashedObj & x)
{
	int currentPos = findPos( x );
	if( isActive( currentPos ) )
		return array[ currentPos ].element;
	else return ITEM_NOT_FOUND;
}

template <class HashedObj>
void HashTable <HashedObj>::printTable(){
	cout << setfill('=') << "\t" << setw(43) << "" << endl << setfill(' ');
	cout << "\t[ " << setw(4) << "N0." << " ]" << setw(5);
	cout << "\t[ " << setw(7) << "Element" << " ]" << setw(5);
	cout << "\t[ " << setw(7) << "Status" << " ]" << endl;
	cout << setfill('=') << "\t" << setw(43) << "" << endl << setfill(' ');

	for(int i = 0; i < array.size(); i++){
		string status = (array[i].info == 0)? "ACTIVE" : 
			(array[i].info == 1)? "EMPTY" : "DELETED";

		cout << "\t[ " << setw(4) << i << " ]" << setw(5);
		cout << "\t[ " << setw(7) << array[i].element << " ]" << setw(5);
		cout << "\t[ " << setw(7) << status << " ]" << endl;
	}
}
void main(){
	const int ITEM_NOT_FOUND = -999;
	HashTable <int> a(ITEM_NOT_FOUND);
	string choice;
	bool exit = false;
	bool createTable = false;
	do{
		system("cls");
		cout << "===============================\n";
		cout << ".::       [ Hashing ]       ::.\n";
		cout << "===============================\n";
		cout << " 1.) Create Hash Table\n";
		cout << " 2.) Insert\n";
		cout << " 3.) Print\n";
		cout << " 4.) Remove\n";
		cout << " 5.) Find\n";
		cout << " 6.) Quit\n";
		cout <<"Enter Choice : ";
		cin >> choice;

		switch(choice[0])
		{
			case '1': 
				int tableSize;
				if(!createTable)
				{
					do{
						cout << "\nEnter TableSize (1 - 30): ";
						cin >> tableSize;
					}while(tableSize > 30 || tableSize < 1);
					a.create(a.nextPrime(tableSize));
					cout << "Prime Number After " << tableSize;
					cout << " is " << a.nextPrime(tableSize) << endl;
					cout << "\nCreate Hash Table Sucessful . . ." << endl;
					createTable = true;
				}
				else 
					cout << "\nYou already have Hash Table !!" << endl;

				system("pause");
				break;

			case '2':
				int insertNum;
				if(createTable){
					cout << "\nEnter Element to insert : ";
					cin >> insertNum;
					if(a.find(insertNum) != ITEM_NOT_FOUND)
					{
						cout << "\n" << insertNum << " are already in the table" << endl;
					}
					else{
						a.insert(insertNum);
						cout << "\nInsert " << insertNum << " is Sucessful . . ." << endl;
					}
				}
				else
					cout << "\nHash Table is unready !!" << endl;

				system("pause");
				break;

			case '3':
				if(createTable){
					cout << setfill('=') << "\t" << setw(43) << "" << endl << setfill(' ');
					cout << "\t.::              Hash Table             ::." << endl;
					a.printTable();
				}
				else
					cout << "\nHash Table is unready !!" << endl;

				system("pause");
				break;
			case '4':
				int removeNum;
				if(createTable){
					cout << "\nEnter Element to Remove : ";
					cin >> removeNum;
					if(a.find(removeNum) != ITEM_NOT_FOUND){
						a.remove(removeNum);
						cout << "\nRemove " << removeNum << " is Sucessful . . ." << endl;
					}
					else
						cout << "\nElement not found" << endl;
				}
				else
					cout << "\nHash Table is unready !!" << endl;

				system("pause");
				break;
			case '5':
				int findNum, found;
				if(createTable){
					cout << "\nEnter Element to Find : ";
					cin >> findNum;
					found = a.find(findNum);
					if(found == ITEM_NOT_FOUND)
						cout << "\nElement not found" << endl;
					else 
						cout << "\nFound " << findNum << " in Hash Table" << endl;
				}
				else
					cout << "\nHash Table is unready !!" << endl;

				cout << endl;
				system("pause");
				break;
			case '6':
				exit = true;
				cout << "\nClose Program . . ." << endl;
				break;
			default:
				cout << "\nNot Choice in menu. Please Try again." << endl;
				system("pause");
				break;
		}
	}while(!exit);
}

