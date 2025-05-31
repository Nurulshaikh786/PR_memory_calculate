#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>

class Template{
    protected:
        vector<T> student_id;
        vector<string> student_name;
    public:
       Template(){
        int size;
        cout << "Enter the number of students: ";
        cin >> size;
        student_id.resize(size);
        student_name.resize(size);
        for(int i = 0; i < size; i++){
            cout << "Enter ID for student " << i+1 << ": ";
            cin >> student_id[i];
            cout << "Enter student_name for student " << i+1 << ": ";
            cin >> student_name[i];
        }
       }
};
class Task : public Template<int>
{
    public:
    void add(){
            int studentID;
            string studentName;
            cout << "Enter Student ID: ";
            cin >> studentID;
            cout << "Enter Student Name: ";
            cin >> studentName;
            student_id.push_back(studentID);
            student_name.push_back(studentName);
        }
        void display(){
            cout << "Student ID\tStudent Name" << endl;
            for(int i = 0; i < student_id.size(); i++){
                cout << student_id[i] << "\t\t" << student_name[i] << endl;
            }
        }
        void search(int studentID){
            for(int i = 0; i < student_id.size(); i++){
                if(student_id[i] == studentID){
                    cout << "Student ID: " << student_id[i] << ", Name: " << student_name[i] << endl;
                    return;
                }
            }
            cout << "Student not found!" << endl;
        }
        void remove(int studentID){
            for(int i = 0; i < student_id.size(); i++){
                if(student_id[i] == studentID){
                    student_id.erase(student_id.begin() + i);
                    student_name.erase(student_name.begin() + i);
                    cout << "Student removed successfully!" << endl;
                    return;
                }
            }
            cout << "Student not found!" << endl;
        }
};
int main()
{
    Task task;
    int choice;
    do{
        cout << "===========================" << endl;
        cout << "Student Management System" << endl;
        cout << "===========================" << endl;
        cout << "1 . Add Student" << endl;
        cout << "2 . Display All Students" << endl;
        cout << "3 . Search For Student" << endl;
        cout << "4 . Remove Student" << endl;
        cout << "0 . Exit " << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                task.add();
                break;
            case 2:
                task.display();
                break;
            case 3:
                int searchID;
                cout << "Enter Student ID to search: ";
                cin >> searchID;
                task.search(searchID);
                break;
            case 4:
                int removeID;
                cout << "Enter Student ID to remove: ";
                cin >> removeID;
                task.remove(removeID);
                break;
            case 0: 
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalstudent_id choice! Please try again." << endl;
        }
    }while(choice != 0);
    return 0;
}