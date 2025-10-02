#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

double get_user_input(string msg) {
    double inp;
    cout << msg;
    cin >> inp;
    while(cin.fail()) {
        cout << "\nInvalid input. Please try again : ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> inp;
    }
    return inp;
};

void print(string msg, double num) {
    cout << msg << fixed << setprecision(2) << num << endl;
};

double perc(double num) {
    return num / 100.00;
};


int main() {
    cout << "- - - Welcome to CarsNLoans - - -\n";

    double interest_rate;
    int installment_month;

    cout << "Please fill out your form below:" << endl;

    double vehicle_price=get_user_input("Vehicle Price (Total cost of car) : ");
    double downpayment=get_user_input("Down Payment (First payment made while purchasing the car) : ");
    installment_month=(int)get_user_input("Installment Months (Number of months for which loan is required) : ");

    if (installment_month <= 12) {
        interest_rate = perc(10.00);
    } else if (installment_month > 12 && installment_month <= 24) {
        interest_rate = perc(15.00);
    } else if (installment_month > 24 && installment_month <= 36) {
        interest_rate = perc(20.00);
    } else if (installment_month > 36 && installment_month <= 48){
        interest_rate = perc(25.00);
    } else if (installment_month > 48 && installment_month <= 60) {
        interest_rate = perc(30.00);
    }
    
    // Payable Amount = Vehicle Price – Down Payment 
    double payable_amount = vehicle_price - downpayment;
    print("•	Payable Amount = ", payable_amount);

    // New Payable Amount = (Payable Amount + (Payable Amount* Interest Rate)) 
    double new_payable = (payable_amount + (payable_amount * interest_rate));
    print("•	New Payable Amount = ", new_payable);

    // Monthly Installment = New Payable Amount / Installment Months 
    double monthly_installment = new_payable / installment_month;
    print("•	Monthly Installment = ", monthly_installment);

    return 0;
};