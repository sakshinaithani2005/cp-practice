#include<bits/stdc++.h>
using namespace std;
class Employee{
    private :
    string name ;
    int id;
    double salary;
    public:
    Employee(){
        // name =n;
        // id=i;
        // salary=s;
       cout<<" Employee Created"<<endl ;

    }
     Employee(string n, int i, double s){
        name =n;
        id=i;
        salary=s;
       

    }

    void display(){
        cout<<"name: "<<name<<endl<<"id: "<<id<<endl <<"salary: "<<salary<<endl<<endl;
    }
};
int main(){
    Employee e1;
    Employee e2("s", 87, 9789453);
    e2.display();
  

}