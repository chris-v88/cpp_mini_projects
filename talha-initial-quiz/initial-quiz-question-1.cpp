#include <iostream>
#include <limits>

int read_user_int(std::string text) {
    std::cout << text << std::endl;
    int input;
    std::cin >> input;
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input, try again" << std::endl;
        std::cin >> input;
    }
    return input;
}

int power_to(int num, int pw) {
    switch(pw) {
        case 2:
            return num*num;
        case 3:
            return num*num*num;
        default:
            std::cout << "Error at \"power_to\" - Unsupport arguments : num (" << num << ") and pw (" << pw << ").";
            return 0;
    }
}

int main() {
    int a = read_user_int("Enter your first number: ");
    int b = read_user_int("Enter your second number: ");

    int num_plus = a + b;
    int num_minus = a - b;

    // (a + b)^2 = a^2 + 2ab + b^2
    int formula_1 = power_to(a, 2) + (2*a*b) + power_to(b, 2);
    std::cout << "(a + b)^2 = a^2 + 2ab + b^2 = " << formula_1 << std::endl;

    // (a - b)^2 = a^2 - 2ab + b^2
    int formula_2 = power_to(a, 2) - (2*a*b) + power_to(b, 2);
    std::cout << "(a - b)^2 = a^2 - 2ab + b^2 = " << formula_2 << std::endl;
    
    // (a + b)^3 = a^3 + 3a^2b + 3ab^2 + b^3
    int formula_3 = power_to(a, 3) + (3*(power_to(a, 2))*b) + (3*a*(power_to(b, 2))) + power_to(b, 3);
    std::cout << "(a + b)^3 = a^3 + 3a^2b + 3ab^2 + b^3 = " << formula_3 << std::endl;

    // (a - b)^3 = a^3 - 3a^2b + 3ab^2 - b^3
    int formula_4 = power_to(a, 3) - (3*(power_to(a, 2))*b) + (3*a*(power_to(b, 2))) - power_to(b, 3);
    std::cout << "(a - b)^3 = a^3 - 3a^2b + 3ab^2 - b^3 = " << formula_4 << std::endl;

    // a^2 - b^2 = (a - b) (a + b)
    int formula_5 = num_plus * num_minus;
    std::cout << "a^2 - b^2 = (a - b) (a + b) = " << formula_5 << std::endl;

    // a^3 - b^3 = (a - b)^3 + 3ab (a - b)
    int formula_6 = power_to(num_minus, 3) + (3*a*b*num_minus);
    std::cout << "a^3 - b^3 = (a - b)^3 + 3ab (a - b) = " << formula_6 << std::endl;

    // a^3 - b^3 = (a - b) (a^2 + ab + b^2)
    int formula_7 = num_minus * (power_to(a, 2) + a*b + power_to(b, 2));
    std::cout << "a^3 - b^3 = (a - b) (a^2 + ab + b^2) = " << formula_7 << std::endl;

    // a^3 + b^3 = (a + b) (a^2 - ab + b^2)
    int formula_8 = num_plus * (power_to(a, 2) - a*b + power_to(b, 2));
    std::cout << "a^3 + b^3 = (a + b) (a^2 - ab + b^2) = " << formula_8 << std::endl;

    // a^3 + b^3 = (a + b)^3 - 3ab (a + b)
    int formula_9 = power_to(num_plus, 3) - 3*a*b*num_plus;
    std::cout << "a^3 + b^3 = (a + b)^3 - 3ab (a + b) = " << formula_9 << std::endl;

    return 0;
}