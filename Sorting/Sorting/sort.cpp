#include <iostream>
#include <string>
#include <vector>
#include <time.h>
using namespace std;
int n=0;
bool flag=true;

template <class Comparable>
void quicksort( vector<Comparable> & a)
{
	quicksort(a,0,a.size()-1);
}
template <class Comparable>
void insertionSort(vector<Comparable> & a)
{
	int move=0;
	
	for(int p =1; p < a.size();p++)
	{
		int mo = 0;
		Comparable tmp = a[p];

		int j;
		for(j = p; j > 0 && tmp < a[j-1]; j--){
			a[j] = a[j-1];
			move++ ;
			mo ++ ;
		}
		a[j] = tmp;
		cout << "After P = "<< p << "\t";
			for(int i=0;i<a.size();i++){
			cout<<a[i]<<"\t"; 
			}
		cout << mo << endl;
	}
	
}
template <class Comparable>
void insertionSort(vector<Comparable> & a, int left, int right ){
	for(int p =1; p < a.size();p++)
	{
		Comparable tmp = a[p];

		int j;
		for(j = p; j > 0 && tmp < a[j-1]; j--)
			a[j] = a[j-1];
		a[j] = tmp;
	}
}
template <class Comparable>
const Comparable & median3(vector<Comparable> & a, int left, int right)
{
	int center = (left + right)/2;
	if(a[center] < a[left])swap(a[left],a[center]);
	if(a[right] < a[left])swap(a[left],a[right]);
	if(a[right] < a[center])swap(a[center],a[right]);

	swap(a[center],a[right-1]);
	return a[right-1];
}
template <class Comparable>
void quicksort(vector<Comparable> & a, int left,int right){
		n++;
	if(left+3<=right){
		Comparable pivot = median3(a,left,right);
		//cout<<pivot;
		int i=left,j=right-1;
		for(;;){
			while(a[++i]<pivot){}
			while(a[--j]>pivot){}
			if(i<j)
				swap(a[i],a[j]);
			
			else{
				break;
				}
		}
		swap(a[i],a[right-1]);
				cout<<"\n  Round "<<n;
		for(int i=0;i<a.size();i++)
			cout<<"    "<<a[i];
		cout<<endl;
		cout<<"      Left = "<<a[left] <<" Right = "<<a[right]<<" Pivot = "<<pivot<<endl;
		quicksort(a,left,i-1);
		quicksort(a,i+1,right);
	}
	else {insertionSort(a,left,right);
	cout<<"\n  Round "<<n;
		for(int i=0;i<a.size();i++)
			cout<<"    "<<a[i];
		cout<<endl;
	}

}
int main(){
int data = 0,menu=0;
	clock_t t1,t2,t3,t4;
	int y[1000];
	bool enter = true;
	bool create = false;

	do{
		system("cls");
		cout<<"=-----------------------------=\n";
		cout<<"=       Assignment 4          =\n";
		cout<<"=-----------------------------=\n";
		cout<<"=     1. Create Input Array   =\n";
		cout<<"=     2. InsertionSort        =\n";
		cout<<"=     3. Quick Sort           =\n";
		cout<<"=     4. Exit                 =\n";
		cout<<"=-----------------------------=\n";
		cout<<"Enter menu >> ";
	cin>>menu;
	cout<<endl;
	if (menu == 1){
			cout<<"**** Create Input ****\n";
			cout<<"How many input :: ";
			cin>>data;
			cout<<"*********************\n";
	}
	n=0;
	vector<int> x(data);
	switch(menu){
	case 1 :
			
			for(int i=0;i<data;i++){
				cout<<"Enter element "<<(i+1)<<" >> ";
				cin>>y[i];
			}
			system("pause");
		break;
	case 2 : cout<<"Original\t";
		for(int i=0;i<data;i++){
				x[i]=y[i];
				cout<<x[i]<<"\t";
			}
			cout<<"P.Moved"<<endl;
			cout<<"---------------------------------------------------------------------"<<endl;
		t1=clock();
		insertionSort(x);
		t2=clock();
		cout<<endl;
		cout<<"Runningtime = "<<((float)t2-(float)t1) <<" second"<<endl;
		cout<<endl;
		system("pause");
		break;
	case 3 : system("cls");
			if (!create)
			{
				for(int i=0;i<data;i++){
					x[i]=y[i];}
				cout<<"          InsertionSort Lower to Higher\n";
				cout<<"  Original   ";
				for(int i=0;i<data;i++)
					cout<<x[i]<<"    ";
				cout<<"\n   ------------------------------";
				t3=clock();
				quicksort(x,0,data-1);
				t4=clock();
				cout<<"\n   ------------------------------";
				cout<<"\n  Final      ";
				for(int i=0;i<data;i++)
					cout<<x[i]<<"    ";
				cout<<endl;
				cout<<"Runningtime = "<<((float)t4-(float)t3) <<" second"<<endl;
				system("PAUSE");
			}
			else
			{
				cout << "\n\t\t\t!!!Must Insert before sort!!!\n\n";
				system("pause");
			}
			break;
	case 4 :cout<<"Program is Exit!!!"<<endl;
			enter = false;
		break;
	default :cout<<"Not have this menu\nPls. Enter again"<<endl;
		system("pause");
		break;
	}
}while(enter);
	return 0 ;

}	