//DS Q3.
#include <iostream>

using namespace std;

struct Student
{
    int roll_no;
    string name;
    float marks;
};

int main()
{
    Student student1;
    student1.roll_no = 18;
    student1.name = "He";
    student1.marks = 60.9;

    Student student2;
    student2.roll_no = 28;
    student2.name = "She";
    student2.marks = 42.99;

    Student student3;
    student3.roll_no = 38;
    student3.name = "Me";
    student3.marks = 11.11;


    cout << "Student 1" << endl;
    cout << "Roll no.: " << student1.roll_no << endl;
    cout << "Name: " << student1.name << endl;
    cout << "Marks: " << student1.marks << endl;

    cout << endl;

    cout << "Student 2" << endl;
    cout << "Roll no.: " << student2.roll_no << endl;
    cout << "Name: "<< student2.name << endl;
    cout << "Marks: " << student2.marks << endl;

    cout << endl;

    cout << "Student 3" << endl;
    cout << "Roll no.: " << student3.roll_no << endl;
    cout << "Name: " << student3.name << endl;
    cout << "Marks: " << student3.marks << endl;

    return 0;
}