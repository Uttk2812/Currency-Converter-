#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // Rate of November 2023

    // USD
    const double usdToPakRate  = 275.50;
    const double usdToIndRate  = 83.33;
    const double usdToPoundRate= 0.82;
    
    // PAK
    const double pakToUsdRate  = 0.0036;
    const double pakToIndRate  = 0.294;
    const double pakToPoundRate= 0.0029;
    
    // IND
    const double indToUsdRate  = 0.012;
    const double indToPakRate  = 3.37;
    const double indToPoundRate= 0.0099;

    // Pound
    const double poundToUsdRate = 1.22;
    const double poundToIndRate = 101.49;
    const double poundToPakRate = 338.59;

    char convertAgain;

    do {
        again:

        char fromCurrency, toCurrency;
        double amount;

        cout << "\n\nSelect your currency (U for USD, P for PAK, I for IND & G for POUND) : ";
        cin >> fromCurrency;

        cout << "Enter the amount : ";
        cin >> amount;
        
        cout << "Select the currency to convert to (U for USD, P for PAK, I for IND & G for POUND) : ";
        cin >> toCurrency;

        double convertedAmount;

        // USD to Other
        if (fromCurrency == 'U' || fromCurrency == 'u') {
            if (toCurrency == 'P' || toCurrency == 'p') {
                convertedAmount = amount * usdToPakRate;
            } 
            else if (toCurrency == 'I' || toCurrency == 'i') {
                convertedAmount = amount * usdToIndRate;
            }
            else if (toCurrency == 'G' || toCurrency == 'g') {
                convertedAmount = amount * usdToPoundRate;  
            }
            else {
                cout<<"\nPlease Enter U, P, G or I\n\n";
                goto again;
            }           
        } 
        
        // PAK to Other
        else if (fromCurrency == 'P' || fromCurrency == 'p') {
            if (toCurrency == 'U' || toCurrency == 'u') {
                convertedAmount = amount * pakToUsdRate;
            } 
            else if (toCurrency == 'I' || toCurrency == 'i') {
                convertedAmount = amount * pakToIndRate;
            }
            else if (toCurrency == 'G' || toCurrency == 'g') {
                convertedAmount = amount * pakToPoundRate;  
            }
            else {
                cout<<"\nPlease Enter U, P, G or I\n\n";
                goto again;
            }
        } 
        
        // IND to Other
        else if (fromCurrency == 'I' || fromCurrency == 'i') {
            if (toCurrency == 'U' || toCurrency == 'u') {
                convertedAmount = amount * indToUsdRate;
            } 
            else if (toCurrency == 'P' || toCurrency == 'p') {
                convertedAmount = amount * indToPakRate;
            }
            else if (toCurrency == 'G' || toCurrency == 'g') {
                convertedAmount = amount * indToPoundRate;  
            }
            else {
                cout<<"\nPlease Enter U, P, G or I\n\n";
                goto again;
            } 
        } 
        
        // Pound to Other
        else if (fromCurrency == 'G' || fromCurrency == 'g') {
            if (toCurrency == 'P' || toCurrency == 'p') {
                convertedAmount = amount * poundToPakRate;
            } 
            else if (toCurrency == 'I' || toCurrency == 'i') {
                convertedAmount = amount * poundToIndRate;
            }
            else if (toCurrency == 'U' || toCurrency == 'u') {
                convertedAmount = amount * poundToUsdRate;  
            }
            else {
                cout<<"\nPlease Enter U, P, G or I\n\n";
                goto again;
            } 
        } 
        
        else {
            cout<<"\nPlease Enter U, P, G or I\n\n";
            goto again;
        }

        // Output
        cout << fixed << setprecision(2);
        cout << "\nEquivalent amount : ";

        switch (toCurrency) {
            case 'U':
            case 'u':
                cout << "$" << convertedAmount << endl;
                break;
            case 'P':
            case 'p':
                cout << "₨" << convertedAmount << endl;
                break;    
            case 'G':
            case 'g':
                cout << "£" << convertedAmount << endl;
                break;
            case 'I':
            case 'i':
                cout << "₹" << convertedAmount << endl;
                break;
            default:
                cout << convertedAmount << " " << toCurrency << endl;
        }

        // Ask to convert again
        cout << "\nDo you want to convert again? (y or n) : ";
        cin >> convertAgain;

    } while (convertAgain == 'y' || convertAgain == 'Y');

    cout << "Thanks for using the currency converter. Goodbye!\n";

    return 0;
}
