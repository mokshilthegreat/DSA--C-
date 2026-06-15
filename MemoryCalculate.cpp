#include <iostream>
#include <vector>
using namespace std;

template <class T>
        class Student
{
private:
    T id;
    string name;

public:
    Student(T i, string n)
    {
        id = i;
        name = n;
    }

    void display()
    {
                  cout << "\nStudent ID   : " << id; 


        cout << "\nStudent Name : " << name << endl;
    }

    T  getId()  {
        return id;
       }
};

int main()
{
   
    vector<Student<int>> students;

    int choice;

    do
    {
        cout << "\n\n===== STUDENT MANAGEMENT SYSTEM =====";

        cout << "\n1. Add Student";

            cout << "\n2. Display All Students";
                cout << "\n3. Remove Student By ID";
                    cout << "\n4. Search Student By ID";
                        cout << "\n5. Exit";

        cout << "\n\nEnter Choice : ";
                    cin >> choice;

        switch (choice)
        {case 1:
        {
            int id;
            string name;

            cout << "\nEnter Student ID : ";
            cin >> id;

            cin.ignore();

            cout << "Enter Student Name : ";
            getline(cin, name);

            students.push_back(Student<int>(id, name));

                            cout << "\nStudent Added Successfully!";
                            break;
        }

        case 2:
        {
            if (students.empty())
            {
                cout << "\nNo Students Found!";
            }
            else
            {
                cout << "\n\n--- Student List ---";

                for (int i = 0; i < students.size(); i++)
                {
                    students[i].display();
                }
            }

            break;
        }

       
        case 3:
        {
            int searchId;
                bool found = false;

            cout << "\nEnter Student ID To Remove : ";
            cin >> searchId;

                    for (int i = 0; i < students.size(); i++)
            {
                        if (students[i].getId() == searchId)
                {
                    students.erase(students.begin() + i);

                         cout << "\nStudent Removed Successfully!";

                    found = true;
                    break;
                }
            }

            if (!found){
                cout << "\nStudent Not Found!";
            }

            break;}

        
        case 4:
        {
            int searchId;
            bool found = false;

            cout << "\nEnter Student ID To Search : ";
            cin >> searchId;

            for (int i = 0; i < students.size(); i++)
            {
                if (students[i].getId() == searchId)
                {
                    cout << "\nStudent Found:";
                    students[i].display();

                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "\nStudent Not Found!";
            }

            break;
        }

   
        case 5:
        {
            cout << "\nThank You!";
            break;
        }

        default:
        {
            cout << "\nInvalid Choice!";
        }
        }

    } while (choice != 5);

    return 0;
}