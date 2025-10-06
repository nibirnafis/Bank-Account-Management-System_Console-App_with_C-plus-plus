#include <iostream>
#include <string>
#include <vector>
#include <fstream> //----for file handling
using namespace std;


class BankAccount {
    private:
        string ownerName;
        string accountNumber;
        double balance = 0;


    public:

        void createAccount(){
            cout << "--- Create Bank Account ---" << endl;

            cout << "Type Your Name: " << endl;
            cin >> ownerName;
            cout << "Account Number: " << endl;
            cin >> accountNumber;

            showDetails();
            saveAccount();
        }


        void showDetails(){
            cout << "--- Bank Account Details ---" << endl;

            cout << "Account Holder Name: " << ownerName << endl;
            cout << "Account Number: " << accountNumber << endl;
            cout << "Balance: " << balance << endl;
        };
        

        void saveAccount(){
            ofstream allAccounts("all_accounts.txt");

            allAccounts << "Account Holder Name: " << ownerName << endl;
            allAccounts << "Account Number: " << accountNumber << endl;
            allAccounts << "Balance: " << balance << endl;

            allAccounts.close();
        };
        
        
        void loadAllAccounts(){
            string lines;
            fstream Accounts("all_accounts.txt");

            while(getline(Accounts, lines)){
                cout << lines;
            };

            Accounts.close();
        };


        void depositeMoney(){
            int depositeAmount;
            
            cout << "--- Deposite Money ---" << endl;

            cout << "Deposite Amount: ";
            cin >> depositeAmount;

            balance =  balance + depositeAmount;
            cout << "New Amount: " << balance << endl;

            showDetails();
        };
        

        void withdrawMoney(){
            int widthrawAmount;
            
            cout << "--- Withdraw Money ---" << endl;
            cout << "Withdraw Amount: \n";
            cin >> widthrawAmount;

            balance = balance - widthrawAmount;
            cout << "New Amount: " << balance << endl;

            showDetails();
        };

};





int main(){

    string name;
    string accNum;
    double blnc;

    BankAccount account;

    account.loadAllAccounts();

    int choice;

    cout << "\nMenu" << endl;
    cout << "1. Create New Account" << endl;
    cout << "2. Deposite Money" << endl;
    cout << "3. Withdraw Money" << endl;
    cout << "4. Show All Accounts" << endl;
    cout << "Enter Your Choice: " << endl;
    cin >> choice;


    if(choice == 1){
        account.createAccount();
    }else if(choice == 2){
        account.depositeMoney();
    }else if(choice == 3){
        account.withdrawMoney();
    }else{
        cout << "Invalid Choice!! Try Again" << endl;
    };
    
    return 0;
}




// g++ main.cpp -o main
// ./main
