#ifndef Hsh_H
#define  Hsh_H
#include<vector>
template<class HashedObj>
class HashTable
{
	public:
		explicit HashTable(const HashedObj & notFound,int size = 101);
		HashTable(const HashTable & rhs): ITEM_NOT_FOUND(rhs.ITEM_NOT_FOUND),
			array(rhs.array),currentSize(rhs.currentSize){}

		const HashedObj & find(const HashedObj & x)const;

		void makeEmpty();
		void insert(const HashedObj & x);
		void remove(const HashedObj & x);
		void print();
		int nextPrime(int x);
		const HashTable & operator = (const HashTable & rhs);
		enum EntryType {ACTIVE,EMPTY,DELETED};
	private:
		struct HashEntry
		{
			HashedObj element;
			EntryType info;
			HashEntry(const HashedObj & e = HashedObj(),
				EntryType i = EMPTY ) : element(e),info(i){}
		};

		vector<HashEntry> array;
		int currentSize;
		const HashedObj ITEM_NOT_FOUND;
		bool isActive(int currentPos )const;
		int findPos(const HashedObj & x) const;
		void rehash();
		
		int hash( int num);
		
};
#endif