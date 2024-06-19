#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {   
    double degrees;
    string conversionType;
    double celsius, fahrenheit;

    cout << "Введіть температуру: ";
    cin >> degrees;
    cin.ignore();  

    cout << "Введіть тип перетворення, З фаренгейт або З цельсія: ";
    getline(cin, conversionType);

    if (conversionType == "З фаренгейт") {
        fahrenheit = degrees;
        celsius = (fahrenheit - 32) / 1.8;
        cout << fixed << setprecision(2);
        cout << degrees << " градусів фаренгейт у цельсії буде - " << celsius << endl;
    } else if (conversionType == "З цельсія") {
        celsius = degrees;
        fahrenheit = celsius * 1.8 + 32;
        cout << fixed << setprecision(2);
        cout << degrees << " градусів цельсію у фаренгейт буде - " << fahrenheit << endl;
    } else {
        cout << "Введено неправильний тип перетворення" << endl;
    }

    return 0;
}