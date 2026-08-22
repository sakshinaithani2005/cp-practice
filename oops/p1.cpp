#include<bits/stdc++.h>
using namespace std;
class  Student{
    private:
    string name;
    int age;
    float marks;

    public :
    void setData(string n, int a , float m ){
        name =n;
        age=a;
        marks=m;
    }
    void display(){
        cout<<"name: "<<name<<endl<<"age: "<<age<<endl <<"marks: "<<marks<<endl<<endl;
    }
};
int main(){
    Student s1;
    Student s2;
    s1.setData("s", 23, 45.5);
    s2.setData("ss", 34, 78.0);
    s1.display();
    s2.display();

 }
