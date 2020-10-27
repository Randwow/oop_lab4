//
//  main.cpp
//  taskA
//  а) Создать класс студент, у которого есть имя, специальность, год обучения и средний балл. Определить функции установки, изменения данных, сравнения. Для задания текстовых полей использовать оператор new. Определить конструкторы, деструктор и другие необходимые функции. Создать производный класс студент-дипломник, для которого определена тема дипломной работы. Так же, необходимо определить все необходимые функции.
//  Created by Nikita Makeev on 10/16/20.
//
#include <iostream>
using namespace std;
    class Student{
        char* name{nullptr}, *speciality{nullptr}, *year_of_studing{nullptr};
        float average_score;
        public:
        Student(){};
        ~Student(){
            delete [] name;
            delete [] speciality;
            delete [] year_of_studing;
        };
        void set_name (char* new_name){
            if (name != nullptr) { delete[] name; }

            name = new char[strlen(new_name) + 1];
            strcpy(name, new_name);
            
        }
        
        void set_speciality(char* new_speciality){
            if (speciality != nullptr) { delete[] speciality; }

            speciality = new char[strlen(new_speciality) + 1];
            strcpy(speciality, new_speciality);
            
        }
        
        void set_year_of_studing(char* new_year_of_studing){
            if (year_of_studing != nullptr) { delete[] year_of_studing; }

            year_of_studing = new char[strlen(new_year_of_studing) + 1];
            strcpy(year_of_studing, new_year_of_studing);
            
        }
    
        void set_average_score(float average_score){
            this->average_score = average_score;
            
        }
        
        float get_average_score(){return average_score;};
        
        char* get_name(){return name;};
        
        char* get_speciality(){return speciality;};
        
        char* get_year_of_studing(){return year_of_studing;};
        
        
        
        void print_data_of_student(){
       
        cout << "\t Name of Student: " << get_name() << endl;
        
        cout << "\t Speciality of Student: " << get_speciality()<< endl;
        
        cout << "\t Year of studing of Student: " << get_year_of_studing() << endl;
            
        cout << "\t Average score of Student: " << get_average_score() << endl;
        }
        
        void initialization_function(){
            char new_name[100], new_speciality[100], new_year_of_studing[100];
            float new_average_score;
            cout << " Name of student: ";
            cin >> new_name;
            set_name(new_name);
                                
            cout << " Speciality of Student example TI or RM or etc: ";
            cin >> new_speciality;
            set_speciality(new_speciality);
                                
            cout << " Year of studing of Student example yyyy-mm-dd: ";
            cin >> new_year_of_studing;
            set_year_of_studing(new_year_of_studing);
            
            cout << " Average score of Student example 5.5 or other : ";
            cin >> new_average_score;
            set_average_score(new_average_score);
                            
        }
        
        void change_data_function(){
            int your_choice = 0;
            char new_name[100], new_speciality[100], new_year_of_studing[100];
            float new_average_score;
            cout << " Which field should be changed " << endl;
                                cout << "1. Name of student: " << endl;
                                cout << "2. Speciality of Student:" << endl;
                                cout << "3. Year of studing of Student:" << endl;
                                cout << "4. Average score of Student:"<<endl;
                                cout << "5. Nothing:"<<endl;
                                cin >> your_choice;
            switch (your_choice) {
                case 1:
                    cout << " Enter new name of student: ";
                    cin >> new_name;
                    set_name(new_name);
                    break;
                case 2:
                    cout << " Enter new speciality of student: ";
                    cin >> new_speciality;
                    set_speciality(new_speciality);
                    break;
                case 3:
                    cout << " Enter new year of studing of Student (yyyy-mm-dd): ";
                    cin >> new_year_of_studing;
                    set_year_of_studing(new_year_of_studing);
                    break;
                case 4:
                    cout << " Enter new average score of Student (exaple 5.5 or 8): ";
                    cin >> new_average_score;
                    set_average_score(new_average_score);
                    break;
                default:
                    break;
            }
        }
        
        void compare_fuction(float first, float second ){

            if (first > second)cout<<"The first student has a higher score than the second\n";
            if (first < second)cout<<"The second student has a higher score than the first\n";
            if(first == second )cout<<"Average student scores are equal\n";
        }
        
    };

    class Student_graduate: public Student{
        char* name_of_diplom{nullptr};
        public :
        Student_graduate(){};
        ~Student_graduate(){
            delete [] name_of_diplom;
        };
        void set_name_of_diplom(char *new_name_of_diplom){
            if (name_of_diplom == nullptr) { delete[] name_of_diplom; }
            name_of_diplom = new char[strlen(new_name_of_diplom) + 1];
            strcpy(name_of_diplom, new_name_of_diplom);}
        char* get_name_of_diplom(){return name_of_diplom;};
        void init_name_of_diplom(){
            char new_name_of_diplom[100];
            cout<<"Enter new name of diplom: ";
            cin>>new_name_of_diplom;
            set_name_of_diplom(new_name_of_diplom);
        }
        
    };

void menu(){
    cout<<"1) Compare student and graduate student by GPA"<<endl;
    cout<<"2) Display information on the screen "<<endl;
    cout<<"3) Change value one of the studens  "<<endl;
    cout<<"4) Exiting the program and deleting memory"<<endl;
}
int main(int argc, const char * argv[]) {
    Student student;
    Student_graduate student_graduate;
    
    int choice{0},choice1{0},choice2{0};
    
    cout<<"Enter value for first student \n";
    student.initialization_function();
    
    cout<<"Enter value for second student \n";
    student_graduate.initialization_function();
    
    cout<<"Enter theme of diplome for second student \n";
    student_graduate.init_name_of_diplom();
    
    menu();
    while (choice != 4){
        cin>>choice;
    switch (choice) {
        case 1:
            student.compare_fuction(student.get_average_score(), student_graduate.get_average_score());
            menu();
            break;
        case 2:
            student.print_data_of_student();
            cout<<endl;
            student_graduate.print_data_of_student();
            cout<<"\t Theme of diplome: "<<student_graduate.get_name_of_diplom()<<endl;
            menu();
            break;
        case 3:
            cout<<"Which student's values you want to change?"<<endl;
            cout<<"1)Student"<<endl;
            cout<<"2)Student - graduate"<<endl;
            cout<<"3)Nothing"<<endl;
            while (choice1 != 3){
                cin>>choice1;
                switch (choice1) {
                    case 1:
                        student.change_data_function();
                        break;
                    case 2:
                        cout<<"Do you want to change theme of diplome or other parameters ?"<<endl;
                        cout<<"1)Change theme of diplome "<<endl;
                        cout<<"2)Chane other parameters "<<endl;
                        cin>>choice2;
                        if(choice2 == 1 )student_graduate.init_name_of_diplom();
                        if(choice2 == 2 )student_graduate.change_data_function();
                        break;
                    default:
                        break;
                }
            break;
                menu();
        default:
            break;
            }
        }
    }
    return 0;
}
