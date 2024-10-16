#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    int id;
    string name;
    string shift;
    string startHour;
    string endHour;

public:
    void inputBasicInfo() {
        cout << "Enter Employee ID: ";
        cin >> id;
        cout << "Enter Employee Name: ";
        cin.ignore();
        getline(cin, name);
    }

    void inputShift() {
        int shiftChoice;
        cout << "Select Shift (1 for Day, 2 for Night): ";
        cin >> shiftChoice;

        if (shiftChoice == 1) {
            shift = "Day";
            startHour = "9 AM";
            endHour = "5 PM";
        } else if (shiftChoice == 2) {
            shift = "Night";
            startHour = "8 PM";
            endHour = "3 AM";
        } else {
            cout << "Invalid choice, defaulting to Day shift.\n";
            shift = "Day";
            startHour = "9 AM";
            endHour = "5 PM";
        }
    }

    void displayBasicInfo() const {
        cout << "\n------ Basic Info ------\n";
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Shift: " << shift << " (" << startHour << " to " << endHour << ")\n";
    }

    virtual void inputDetails() = 0;
    virtual void showSalary() const = 0;
};

class VisitingEmp : public Employee {
private:
    int days;
    float wage;

public:
    void inputDetails() override {
        cout << "Enter Daily Wage: ";
        cin >> wage;
        cout << "Enter Number of Days: ";
        cin >> days;
    }

    void showSalary() const override {
        cout << "Salary: " << wage * days << endl;
    }
};

class PermanentEmp : public Employee {
private:
    int monthlySalary;

public:
    void inputDetails() override {
        cout << "Enter Monthly Salary: ";
        cin >> monthlySalary;
    }

    void showSalary() const override {
        cout << "Salary: " << monthlySalary << " per month" << endl;
    }
};

int main() {
    Employee* emp;
    int choice;

    do {
        cout << "\n------ Menu ------\n";
        cout << "1. Create Visiting Employee\n";
        cout << "2. Create Permanent Employee\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {
            case 1:
                emp = new VisitingEmp();
                break;
            case 2:
                emp = new PermanentEmp();
                break;
            case 0:
                cout << "Exiting...\n";
                continue;
            default:
                cout << "Invalid choice, try again.\n";
                continue;
        }

        if (choice != 0) {
            emp->inputBasicInfo();
            emp->inputShift();  // New feature for selecting office shift
            emp->inputDetails();
            emp->displayBasicInfo();
            emp->showSalary();
            delete emp;
        }

    } while (choice != 0);

    return 0;
}
