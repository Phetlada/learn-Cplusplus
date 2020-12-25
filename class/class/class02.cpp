/*#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    string first_name, last_name;
public:
    string getFullname();
    string getCountry(int);
};

string Person::getFullname()
{
    return first_name + " " + last_name;
}

string Person::getCountry(int n)
{
    if (n == 1)
        return "US";
    else if (n == 2)
        return "Canada";
    else if (n == 3)
        return "Ukraine";
    else
        return "Unknown country";
}

int main()
{
    Person p1;
    p1.first_name = "Mateo";
    p1.last_name = "Marcus";

    Person p2;
    p2.first_name = "Thomas";
    p2.last_name = "Monte";

    Person p3;
    p3.first_name = "Dennis";
    p3.last_name = "Ritchie";

    cout << p1.getFullname() << " is in " << p1.getCountry(3) << endl;
    cout << p2.getFullname() << " is in " << p2.getCountry(2) << endl;
    cout << p3.getFullname() << " is in " << p3.getCountry(5) << endl;

    return 0;
}*/