#include <iostream>
#include <string>
using namespace std;


struct account {
    string svdName;
    string svdAccNum;
    double svdBalance;
};


class BankAccount {
    private:
        string ownerName;
        string accountNumber;
        double balance;

    public:
        BankAccount(string name, string accN, double blnc){
            ownerName = name;
            accountNumber = accN;
            balance = blnc;
        };

        void showDetails(){
            cout << "Owner Name: " << ownerName << endl;
            cout << "Account Number: " << accountNumber << endl;
            cout << "Balance: " << balance << endl;
        };
        
        void depositeMoney(){
            int depositeAmount;
            
            cout << "--- Deposite Money ---" << endl;
            cout << "Deposite Amount: ";
            cin >> depositeAmount;

            int newAmount =  balance + depositeAmount;
            cout << "New Amount: " << newAmount << endl;
        };
        
        void withdrawMoney(){
            int widthrawAmount;
            
            cout << "--- Withdraw Money ---" << endl;
            cout << "Withdraw Amount: \n";
            cin >> widthrawAmount;

            int newAmount = balance - widthrawAmount;
            cout << "New Amount: " << newAmount << endl;
        };
};


int main(){

    string name;
    string accNum;
    double blnc;

    cout << "Type Your Name: \n";
    cin >> name;
    cout << "Type Your AC: \n";    
    cin >> accNum;
    cout << "Initial Balance: \n";
    cin >> blnc;


    BankAccount account(name, accNum, blnc);

    account.showDetails();

    int choice;
    do{
        cout << "Menu" << endl;
        cout << "1. Deposite Money" << endl;
        cout << "2. Withdraw Money" << endl;
        cin >> choice;
        
        switch(choice){
            case 1: {
                account.depositeMoney();
                break;
            };
            case 2: {
                account.withdrawMoney();
                break;
            };
            default: 
                cout << "Invalid Choice!! Try Again" << endl;
        }
    }while (choice < 3);
    
    return 0;
}





// g++ main.cpp -o main
// ./main