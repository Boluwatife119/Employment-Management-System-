#include <iostream>
#include <string>

using namespace std;

const int maxEmployee = 150;

//Employee structure
struct Employee {
    int id;
    string name;
    float salary;
    float bonus;
};

//An array with a type of Employee
Employee employeeArray[maxEmployee];
int numOfEmployee = 0;

//Main Menu Function
void DisplayMainMenu(){
    cout << "Main Menu\n\n";
    cout << "1. Add new employee\n";
    cout << "2. View all employees\n";
    cout << "3. Check total pay\n";
    cout << "4. Exit\n";
    cout << "Enter a number of your choice (1 - 4): ";
}

//Initialization of other functions
void AddNewEmployee();
void ViewEmployee();
void EmployeeTotalPay();
void ExitApp();

//Main function
int main()
{
    DisplayMainMenu();
    int option = 0;
    cin >> option;

    if(option == 1){
        AddNewEmployee();
    }
    else if(option == 2){
        ViewEmployee();
    }
    else if(option == 3){
        EmployeeTotalPay();
    }
    else if(option == 4){
        void ExitApp();
    }
    else{
        cout << "The option you have selected is not available\n\n\n";
        main();
    }

    return 0;
}

//Add a new employee function
   void AddNewEmployee(){

    if(numOfEmployee >= maxEmployee){
        cout << "We have reached our maximum number of our employee, kindly try again some other time. \nThank You.\n\n\n";
    }else{
        Employee addNewEmployee;
        cout << "\n\n\n=====    ADD A NEW EMPLOYEE    =====\n\n";
        cout << "Enter an ID for the employee: ";
        cin >> addNewEmployee.id;

       for(int i = 0; i < numOfEmployee; i++){
            if(employeeArray[i].id == addNewEmployee.id){
                cout << "There is an profile with this id already";
                AddNewEmployee();
            }
        };

        cout << "Enter employee name: ";
        cin.ignore();
        getline(cin, addNewEmployee.name);

        //Name Validation
        string name;
        name = addNewEmployee.name;
        for(char c : name){
            if(!isalpha(c) && !isspace(c)){
                cout << "you have inputed a wrong value for name";
                AddNewEmployee();
            }
        };

        cout << "Enter employee's salary: ";
        cin >> addNewEmployee.salary;
        cout << "Enter employee's bonus: ";
        cin >> addNewEmployee.bonus;


        employeeArray[numOfEmployee] = addNewEmployee;
        numOfEmployee++;

        cout << "\n\nEmployee Registered Successfully!!!\n\n\n";
    }

    main();
}

//View Employee function
void ViewEmployee(){
    if(numOfEmployee == 0){
        cout << "There is currently not a record on any employee. \nPlease you can check by later. Thank You.\n\n\n";
        main();
    }
        cout << "\n\n\n=====    VIEW ALL EMPLOYEE    =====\n\n";
        for(int i = 0; i < numOfEmployee; i++){
            cout << i+1 << ".1 Employee ID: " << employeeArray[i].id;
            cout << "\n" << i+1 << ".2 Employee Name: " << employeeArray[i].name;
            cout << "\n" << i+1 << ".3 Employee Salary: $" << employeeArray[i].salary;
            cout << "\n" << i+1 << ".4 Employee Bonus: $" << employeeArray[i].bonus;
            cout << "\n" << i+1 << ".5 Total Payment: $" << employeeArray[i].salary + employeeArray[i].bonus << "\n\n\n" << endl;
        }
        cout << "The total number of employee is " << numOfEmployee << "\n\n\n";

        main();

}

//View Employee Total Pay  Function
void EmployeeTotalPay() {
    if(numOfEmployee == 0){
        cout << "There is currently not a record on any employee. \nPlease you can check by later. Thank You.\n\n\n";
        main();
    }
    int employeeId = 0;
    bool foundEmployeeId = false;

    cout << "Please input the employee ID in other to display his/her total payment ";
    cin >> employeeId;

    for(int i = 0; i < numOfEmployee; i++){
        if(employeeArray[i].id == employeeId){
            foundEmployeeId = true;
            cout << "\nYour total pay is: $" << employeeArray[i].salary + employeeArray[i].bonus << "\n\n\n" << endl;
            main();
        }
        else if(!foundEmployeeId){
            cout << "Employee with ID " << employeeId << " not found.\n";
            main();
        }
    }
}


//Exit App Function
void ExitApp(){
