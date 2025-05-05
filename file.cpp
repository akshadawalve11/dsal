#include <iostream>
#include <fstream>
using namespace std;
class student
{
    int rn;
    char name[50];
    char div;
    char adr[100];

public:
    void get();
    void show();
    void add();
    void del();
    void search();
    void append();
    void display();
};
void student::get()
{

    cout << "Enter roll no of student : ";
    cin >> rn;
    cin.ignore();
    cout << "Enter name of student : ";
    cin.getline(name, 50);
    cout << "Enter division of student : ";
    cin >> div;
    cin.ignore();
    cout << "Enter addres of student : ";
    cin.getline(adr, 100);
}
void student::show()
{
    cout << "\nRoll no : " << rn << endl;
    cout << "Name : " << name << endl;
    cout << "Division : " << div << endl;
    cout << "Address : " << adr << endl;
    cout<<"------------------------------------";
}
void student::add()
{
    student s;
    ofstream f1("file1.txt", ios::out | ios::binary | ios::app);
    s.get();
    f1.write((char *)&s, sizeof(s));
    f1.close();
    cout << "Student information added successfully.\n" << endl;
}
void student::display()
{
    student s;
    ifstream f1("file1.txt", ios::in | ios::binary);
    cout<<"\nDisplaying all student information \n";
    while (f1.read((char *)&s, sizeof(s)))
    {
        s.show();
    }
    f1.close();
}
void student::search()
{

    student s;
    ifstream f1("file1.txt", ios::in | ios::binary);
    int f = 0;
    int r;
    cout << "Enter roll no of student to search : ";
    cin >> r;
    while (f1.read((char *)&s, sizeof(s)))
    {
        if (s.rn == r)
        {
            s.show();
            f = 1;
            break;
        }
    }
    if (f == 0)
    {
        cout << "Student not found." << endl;
    }
    f1.close();
}
void student::append()
{
    student s;
    ofstream f1("file1.txt", ios::out | ios::binary | ios::app);

    int n;
    cout << "Enter no of students to append : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter information of student " << i + 1 << " : " << endl;
        s.get();
        f1.write((char *)&s, sizeof(s));
    }
    f1.close();
    cout << "Students information added successfully." << endl;
}
void student::del()
{
    student s;
    int r;
    cout << "Enter roll no of student to delete : ";
    cin >> r;
    int f = 0;
    ifstream f1("file1.txt", ios::in | ios::binary);
    ofstream f2("file2.txt", ios::out | ios::binary);
    while (f1.read((char *)&s, sizeof(s)))
    {
        if (s.rn == r)
        {
            f = 1;
            cout << "Student found and deleted ";
        }
        else
        {
            f2.write((char *)&s, sizeof(s));
        }
    }
    f1.close();
    f2.close();
    if (f == 0)
    {
        cout << "student not found";
    }
    else
    {
        remove("file1.txt");
        rename("file2.txt", "file1.txt");
        
    }
}

int main()
{
    int choice;
    student s;
    do
    {
        cout << "\n1.Add Student \n2.Display all students \n3.Search Student \n4.Delete Student Record \n5.Append Student Data  \n6.Exit\n";
        cout << "enter your choice : ";
        cin >> choice;
        cout<<endl;
        switch (choice)
        {
        case 1:
            s.add();
            break;

        case 2:
            s.display();
            break;
        case 3:
            s.search();
            break;

        case 4:
            s.del();
            break;

        case 5:
            s.append();
            break;

        case 6:
        cout<<"Exited..............";
            break;
        default:
            cout << "\ninvalid choice \n";
            break;
        }

    } while (choice != 6);
    return 0;
}