/*
#include <time.h>


int main(){
    int elapTicks;
    double elapMilli, elapSeconds, elapMinutes;
    clock_t Begin, End;

    Begin = clock() * CLK_TCK;      //start the timer
    
	
    
    End = clock() * CLK_TCK;        //stop the timer

    elapTicks = End - Begin;        //the number of ticks from Begin to End
    elapMilli = elapTicks/1000;     //milliseconds from Begin to End
    elapSeconds = elapMilli/1000;   //seconds from Begin to End
    elapMinutes = elapSeconds/60;   //minutes from Begin to End


    if(elapSeconds < 1)
        cout<<"\nIt took "<<elapMilli<<" milliseconds.";
    else if(elapSeconds == 1)
        cout<<"\nIt took  1 second.";
    else if(elapSeconds > 1 && elapSeconds < 60)
        cout<<"\nIt took  "<<elapSeconds<<" seconds.";
    else if(elapSeconds >= 60)
        cout<<"\nIt took  "<<elapMinutes<<" minutes.";

    return 0;
}
#include <iostream>
#include <ctime>
using namespace std;
int main(){
      time_t Begin,End;
      time(&Begin);
	  for(int i = 0;i<100;i++){
		cout << 0;
	  }
      time(&End);
      cout<<"\nIt took  "<< End-Begin <<" sec.";
      cout<<"\nIt took (with diff)  "<< difftime(End,Begin)<<" sec.";
}*/