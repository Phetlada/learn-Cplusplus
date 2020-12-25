#include <iostream>
using namespace std;
#include "Bst.h"

//------------ public
template<class Comparable>
bool BinarySearchTree<Comparable>::isEmpty()const{
	return root == NULL;
}
template<class Comparable>
BinarySearchTree<Comparable>::BinarySearchTree(const Comparable &notFound)
{
	root = NULL;
	ITEM_NOT_FOUND = notFound;
}
template<class Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable &x)
{
	 insert(x,root);
}
template<class Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable &x)
{
	if(isEmpty()){
		 cout << "Empty tree"<<endl;
	 }else remove(x,root);
}
template<class Comparable>
void BinarySearchTree<Comparable>::printTree()const
{
	 if(isEmpty()){
		 cout << "Empty tree"<<endl;
	 }
	 else{
		 printTree(root);
		 cout<<endl;
	 }
}
template<class Comparable>
void BinarySearchTree<Comparable>::printTreePre()const
{
	if(isEmpty()){
		 cout << "Empty tree"<<endl;
	 }
	 else{
		 printTreePre(root);
		 cout<<endl;
	 }
}
template<class Comparable>
void BinarySearchTree<Comparable>::printTreePost()const
{
	  if(isEmpty()){
		 cout << "Empty tree"<<endl;
	 }
	 else{
		 printTreePost(root);
		 cout<<endl;
	 }
}
template<class Comparable>
const Comparable & BinarySearchTree<Comparable>::findMin()const{
	if(elementAt(findMin(root)) == ITEM_NOT_FOUND){
		cout <<"Empty tree"<<endl;
	}
	return elementAt(findMin(root));

}
template<class Comparable>
const Comparable & BinarySearchTree<Comparable>::findMax()const{
	if(elementAt(findMax(root)) == ITEM_NOT_FOUND){
		cout <<"Empty tree"<<endl;
	}
	return elementAt(findMax(root));
}
template<class Comparable>	
const Comparable & BinarySearchTree<Comparable>::find(const Comparable &x)const{
	cout <<"Position is "<< find(x,root)<<endl;
	return elementAt(find(x,root));
	
}
//------------ private
template<class Comparable>
const Comparable & BinarySearchTree<Comparable>::elementAt(BinaryNode<Comparable>*t)const
{
	if(t == NULL) return ITEM_NOT_FOUND;
	else return t->element;
}
template<class Comparable>
void BinarySearchTree<Comparable>::printTree(BinaryNode<Comparable>*t)const{
	if(t != NULL){
		printTree(t->left);
		cout << t->element<< "  ";
		printTree(t->right);
	}
	else if(isEmpty()){
		cout << "Empty tree"<<endl;
	}
}
template<class Comparable>
void BinarySearchTree<Comparable>::printTreePost(BinaryNode<Comparable>*t)const{
	if(t != NULL){
	
		printTreePost(t->left);
		printTreePost(t->right);
		cout << t->element<< "  ";
	
	}
	else if(isEmpty()){
		cout << "Empty tree"<<endl;
	}
}

template<class Comparable>
void BinarySearchTree<Comparable>::printTreePre(BinaryNode<Comparable>*t)const{
	if(t != NULL){
		cout << t->element<< "  ";
		printTreePre(t->left);
		printTreePre(t->right);	
	}
	else if(isEmpty()){
		cout << "Empty tree"<<endl;
	}
}
template<class Comparable>
BinaryNode<Comparable>*BinarySearchTree<Comparable>::find(const Comparable &x,BinaryNode<Comparable>*t)const
{
	if(t == NULL)return NULL;
	else if(x < t->element)return find(x,t->left);
	else if(t->element < x)return find(x,t->right);
	else return t;
}
template<class Comparable>
BinaryNode<Comparable>*BinarySearchTree<Comparable>::findMin(BinaryNode<Comparable>*t)const
{
	if(t == NULL)return NULL;
	else if(t->left == NULL)return t;
	return findMin(t->left);
}
template<class Comparable>
BinaryNode<Comparable>*BinarySearchTree<Comparable>::findMax(BinaryNode<Comparable>*t)const
{
	if(t != NULL){
		while(t->right != NULL){
		t =  t->right;
		}
	}return t;
}
template<class Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable &x,BinaryNode<Comparable>*&t)const
{
	if(t == NULL)
		{
			t = new BinaryNode<Comparable>(x,NULL,NULL);
		}
	else if(x < t->element){insert(x,t->left);}
	else if(t->element < x){insert(x,t->right);}
	else ; //not thing
}
template<class Comparable> 
void BinarySearchTree<Comparable>::remove(const Comparable &x,BinaryNode<Comparable>*&t)const
{
	if(t == NULL)return ;
	if(x<t->element)remove(x,t->left);
	else if(t ->element<x)remove(x,t->right);
	else if(t ->left != NULL && t->right != NULL){
		t->element = findMin(t->right)->element;
		remove(t->element,t->right);
	}
	else{
		BinaryNode<Comparable>*oldNode = t; 
		t = (t->left != NULL)? t->left : t->right;
		delete oldNode;
	}
}
int main(){
	BinarySearchTree<int> a(-999);
	int menu;
	do{
	system("cls");
	cout << "===={ BINARY SEARCH TREE }====\n";
	cout << "|| 1. Insert                ||\n";
	cout << "|| 2. PrintTree             ||\n";
	cout << "|| 3. Find                  ||\n";
	cout << "|| 4. Remove                ||\n";
	cout << "|| 5. Exit                  ||\n";
	cout << "==============================\n";
	cout << "Enter choice : ";
	cin  >> menu;
	if(menu == 1){
		int num; int count;
		cout <<"====={  INSERT  }=====\n";
		cout<<"Amount Insert : ";
		cin>>count;
		for(int i = 1;i<=count;i++){
		cout <<"Enter number : ";
		cin >> num;
		a.insert(num);
		}

		
	}
	if(menu == 2){
		int menu1;
		do{
			
			system("cls");
			cout << "===={      PRINTTREE     }====\n";
			cout << "|| 1. Preorder              ||\n";
			cout << "|| 2. Inorder               ||\n";
			cout << "|| 3. Postorder             ||\n";
			cout << "|| 4. Exit                  ||\n";
			cout << "==============================\n";
			cout << "Enter choice : ";
			cin  >> menu1;
			if(menu1 == 1){
				char Wait;
				cout<<" Postorder : ";
				 a.printTreePre();

				cin.get(Wait);
				cout << "\nPress to back";
				cin.get(Wait);	
			}
			if(menu1 == 2){
				char Wait;
				cout<<" Inorder : ";
				 a.printTree();

				cin.get(Wait);
				cout << "\nPress to back";
				cin.get(Wait);	
			}
			if(menu1 == 3){
				char Wait;
				cout<<" Postorder : ";
				 a.printTreePost();

				cin.get(Wait);
				cout << "\nPress to back";
				cin.get(Wait);	

			}
		}while(menu1!=4);
	}
	if(menu == 3){
		int menu1;
		do{
			
			system("cls");
			cout << "===={        FIND        }====\n";
			cout << "|| 1. Find                  ||\n";
			cout << "|| 2. FindMin               ||\n";
			cout << "|| 3. FindMax               ||\n";
			cout << "|| 4. Exit                  ||\n";
			cout << "==============================\n";
			cout << "Enter choice : ";
			cin  >> menu1;
			if(menu1 == 1){
				char Wait;
				int y; 
				cout<<" Find Number : ";
				cin >> y;
				if(a.find(y)==y){
					cout << "Found Numder "<<y<<endl;
				}else cout << "Not Found"<<endl;
				
				cin.get(Wait);
				cout << "\nPress to back";
				cin.get(Wait);	
			}
			if(menu1 == 2){
				char Wait;
				int x;
				x = a.findMin();
				


				cin.get(Wait);
				cout << "\nPress to back";
				cin.get(Wait);	
			}
			if(menu1 == 3){
				char Wait;
				int x;
				x = a.findMax();
				cout<<"Max Number is "<< x ;

				cin.get(Wait);
				cout << "\nPress to back";
				cin.get(Wait);	

			}
		}while(menu1!=4);
	}
	if(menu == 4){
		int num;
		cout <<"====={  REMOVE  }=====\n";
		cout <<"Enter number : ";
		cin >> num;
		a.remove(num);
	}
	}while(menu != 5);
	return(0);
}