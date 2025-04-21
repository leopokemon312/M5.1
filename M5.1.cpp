#include <iostream>
#include <string>
using namespace std;

// Part 1: Employee Class
class Employee {
protected:
    string name;
    string employeeNumber;
    string hireDate;

public:
    Employee(string n = "", string num = "", string date = "")
        : name(n), employeeNumber(num), hireDate(date) {
    }

    void setName(string n) { name = n; }
    void setEmployeeNumber(string num) { employeeNumber = num; }
    void setHireDate(string date) { hireDate = date; }

    string getName() const { return name; }
    string getEmployeeNumber() const { return employeeNumber; }
    string getHireDate() const { return hireDate; }

    void printEmployee() const {
        cout << "Name: " << name << endl;
        cout << "Employee Number: " << employeeNumber << endl;
        cout << "Hire Date: " << hireDate << endl;
    }
};

// Part 2: ProductionWorker Class
class ProductionWorker : public Employee {
protected:
    int shift; // 1 = Day, 2 = Night
    double hourlyPayRate;

public:
    ProductionWorker(string n = "", string num = "", string date = "", int s = 1, double rate = 0.0)
        : Employee(n, num, date), shift(s), hourlyPayRate(rate) {
    }

    void setShift(int s) { shift = s; }
    void setHourlyPayRate(double rate) { hourlyPayRate = rate; }

    int getShift() const { return shift; }
    double getHourlyPayRate() const { return hourlyPayRate; }

    void printProductionWorker() const {
        printEmployee();
        cout << "Shift: " << (shift == 1 ? "Day" : "Night") << endl;
        cout << "Hourly Pay Rate: $" << hourlyPayRate << endl;
    }
};

// Part 3: ShiftSupervisor Class
class ShiftSupervisor : public Employee {
protected:
    double annualSalary;
    double annualBonus;

public:
    ShiftSupervisor(string n = "", string num = "", string date = "", double salary = 0.0, double bonus = 0.0)
        : Employee(n, num, date), annualSalary(salary), annualBonus(bonus) {
    }

    void setAnnualSalary(double salary) { annualSalary = salary; }
    void setAnnualBonus(double bonus) { annualBonus = bonus; }

    double getAnnualSalary() const { return annualSalary; }
    double getAnnualBonus() const { return annualBonus; }

    void printShiftSupervisor() const {
        printEmployee();
        cout << "Annual Salary: $" << annualSalary << endl;
        cout << "Annual Bonus: $" << annualBonus << endl;
    }
};

// Part 4: TeamLeader Class
class TeamLeader : public ProductionWorker {
private:
    double monthlyBonus;
    int requiredTrainingHours;
    int attendedTrainingHours;

public:
    TeamLeader(string n = "", string num = "", string date = "", int s = 1, double rate = 0.0,
        double bonus = 0.0, int required = 0, int attended = 0)
        : ProductionWorker(n, num, date, s, rate),
        monthlyBonus(bonus), requiredTrainingHours(required), attendedTrainingHours(attended) {
    }

    void setMonthlyBonus(double bonus) { monthlyBonus = bonus; }
    void setRequiredTrainingHours(int hours) { requiredTrainingHours = hours; }
    void setAttendedTrainingHours(int hours) { attendedTrainingHours = hours; }

    double getMonthlyBonus() const { return monthlyBonus; }
    int getRequiredTrainingHours() const { return requiredTrainingHours; }
    int getAttendedTrainingHours() const { return attendedTrainingHours; }

    void printTeamLeader() const {
        printProductionWorker();
        cout << "Monthly Bonus: $" << monthlyBonus << endl;
        cout << "Required Training Hours: " << requiredTrainingHours << endl;
        cout << "Attended Training Hours: " << attendedTrainingHours << endl;
    }
};

// Main program to create and display objects
int main() {
    // Two ProductionWorkers
    ProductionWorker pw1("Alice Johnson", "P001", "01/15/2020", 1, 22.5);
    ProductionWorker pw2("Bob Smith", "P002", "03/12/2019", 2, 24.0);

    pw1.printProductionWorker();
    cout << endl;
    pw2.printProductionWorker();
    cout << "\n------------------------\n";

    // One ShiftSupervisor
    ShiftSupervisor ss("Carol Williams", "S001", "07/01/2018", 65000, 5000);
    ss.printShiftSupervisor();
    cout << "\n------------------------\n";

    // One TeamLeader
    TeamLeader tl("David Brown", "T001", "11/23/2021", 1, 27.0, 1200, 40, 36);
    tl.printTeamLeader();

    return 0;
}
