#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Employee {
public:
    int id;
    string name;
    string role;
    double salary;

    Employee(int employeeId, string employeeName, string employeeRole, double employeeSalary) 
        : id(employeeId), name(employeeName), role(employeeRole), salary(employeeSalary) {}

    void displayDetails() {
        cout << "ID: " << id
             << " | Name: " << name
             << " | Role: " << role
             << " | Salary: $" << salary << endl;
    }
};

class EmployeeManagementSystem {
private:
    vector<Employee> employees;
    int nextId;

public:
    EmployeeManagementSystem() : nextId(1) {}

    void addEmployee(string name, string role, double salary) {
        employees.push_back(Employee(nextId, name, role, salary));
        cout << "Employee added with ID: " << nextId << endl;
        nextId++;
    }

    void displayEmployees() {
        if (employees.empty()) {
            cout << "No employees in the system.\n";
            return;
        }
        for (auto& employee : employees) {
            employee.displayDetails();
        }
    }

    void updateEmployee(int id, string newName, string newRole, double newSalary) {
        for (auto& employee : employees) {
            if (employee.id == id) {
                employee.name = newName;
                employee.role = newRole;
                employee.salary = newSalary;
                cout << "Employee details updated successfully.\n";
                return;
            }
        }
        cout << "Employee with ID " << id << " not found.\n";
    }

    void removeEmployee(int id) {
        for (auto it = employees.begin(); it != employees.end(); ++it) {
            if (it->id == id) {
                employees.erase(it);
                cout << "Employee removed successfully.\n";
                return;
            }
        }
        cout << "Employee with ID " << id << " not found.\n";
    }
};

int main() {
    EmployeeManagementSystem ems;
    int choice, id;
    string name, role;
    double salary;

    while (true) {
        cout << "\nEmployee Management System Menu\n";
        cout << "1. Add Employee\n";
        cout << "2. Display Employees\n";
        cout << "3. Update Employee\n";
        cout << "4. Remove Employee\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Role: ";
            cin >> role;
            cout << "Enter Salary: ";
            cin >> salary;
            ems.addEmployee(name, role, salary);
            break;

        case 2:
            ems.displayEmployees();
            break;

        case 3:
            cout << "Enter Employee ID to Update: ";
            cin >> id;
            cout << "Enter New Name: ";
            cin >> name;
            cout << "Enter New Role: ";
            cin >> role;
            cout << "Enter New Salary: ";
            cin >> salary;
            ems.updateEmployee(id, name, role, salary);
            break;

        case 4:
            cout << "Enter Employee ID to Remove: ";
            cin >> id;
            ems.removeEmployee(id);
            break;

        case 5:
            cout << "Exiting system.\n";
            return 0;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}
