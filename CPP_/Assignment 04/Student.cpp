#include <iostream>
#include <string.h>
using namespace std;
class Student
{
public:
    string name;
    char gender;
    int rollno;
    double *marks;
    double percentage;

public:
    inline double CalculatePercentage()
    {
        double sum = 0;
        for (int i = 0; i < 3; i++)
        {
            sum += marks[i];
        }
        percentage = sum / 3.0;
        return percentage;
    }
    void PrintStudents()
    {
        cout << "Name:" << name << endl;
        cout << "Gender:" << gender << endl;
        cout << "Roll No:" << rollno << endl;
        cout << "Percentage:" << percentage << "%" << endl;
    }
};
void SortRecord(Student arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j].percentage < arr[j + 1].percentage)
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
int SearchRecord(Student arr[], int size, int rollno)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i].rollno = rollno)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int numberofstudent;
    cout << "How many Students Data You want to Fill" << endl;
    cin >> numberofstudent;
    Student s1[numberofstudent];
    int countStudents = 0;
    while (true)
    {
        cout << "_____Menu____ " << endl;
        cout << "1.Accept Student " << endl;
        cout << "2.Print  Student  " << endl;
        cout << "3.Search Students " << endl;
        cout << "4.Sort   Studenrs by Percentage " << endl;
        cout << "5.Exit" << endl;
        int choice;
        cout << "Enter choice" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            if (countStudents < numberofstudent)
            {
                Student s2;
                cout << "Enter Name " << endl;
                cin >> s2.name;
                cout << "Enter Gender " << endl;
                cin >> s2.gender;
                cout << "Enter Roll No " << endl;
                cin >> s2.rollno;
                cout << "Enter Marks " << endl;
                for (int i = 0; i < 3; i++)
                {
                    cout << "Enter" << i << "Subject Marks" << endl;
                    cin >> s2.marks[i];
                }
                s2.CalculatePercentage();
                s1[countStudents] = s2;
                countStudents++;
                cout << "Student Added Succesfully" << endl;
            }
            else
            {
                cout << " List is Full" << endl;
            }
            break;
        case 2:
            for (int i = 0; i < numberofstudent; i++)
            {
                s1[i].PrintStudents();
                cout << endl;
            }
            break;
        case 3:
            int rlno;
            cout << "Enter the Roll No:" << endl;
            cin >> rlno;
            int found = SearchRecord(s1, countStudents, rlno);
            if (found != -1)
            {
                s1[found].PrintStudents();
            }
            else
            {
                cout << "Student Data Not Found" << endl;
            }
            break;
        case 4:
            SortRecord(s1, countStudents);
            cout << "Record sorted By Percentage Successfully" << endl;
            break;
        case  5:
            cout << "Your Exiting " << endl;
            return 0;
            break;
        default:
            cout << "You Entered Invalid Choice" << endl;
            break;
        }
    }
    return 0;
}