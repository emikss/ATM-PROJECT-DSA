#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

void mainMenu();

struct accounts{
    string acc_num;
    string pin_code;
    accounts *next;
};
struct LoginResult{       //storing login results
    bool success;
    string cardNumber;
};

class UserAccount{  //user info and storing it to file handling keme
    private:
        string name;
        string pin;
        string cardNumber;
    public:
        
        UserAccount(string _name, string _pin){   //constructor kuno (sumunod lang ako tutorial bai)
            name = _name;
            pin = _pin;
            // cardNumber = generateCardNum();  //generating random card num
        }


    /*    string generateCardNum(){   //generating random 16-digit num
            string cardNum = "";
            srand(time(0)); 
            for (int i = 0; i < 16 ; i++){
                cardNum += to_string (rand()%10);
            } return cardNum;
        }*/

        //gayahin ko lang kay ku
        void saveToFile(){     //save user info
            ofstream file("accounts.txt", ios::app);
            if (file.is_open()){
                file << name << endl << pin << endl << cardNumber << endl;
                file.close();
            }else{
                cout << "Unable to open file.";
            }
        }

        void retrieveToFile(){     //save user info
        string account_number; string pin;
            ifstream file("accounts.txt", ios::app);
            if (file.is_open()){
                while (!file.eof()){
                    file >> account_number;
                    file >> pin;
                    link(account_number, pin);
                };
            } else{
                cout << "Unable to open file.";
            }
            file.close();
}

        
      /* void displayInfo(){
            system("cls");
            cout << "Account created successfully!\n";
            cout << "Your card number is: " << cardNumber;
        }*/
       void link(string account_number, string pin){
        accounts *newNode = new accounts();
        newNode->acc_num=account_number;
        newNode->pin_code=pin;
        newNode=newNode->next;
       }
        //static LoginResult login(string _name, string _pin){
            /*ifstream file ("accounts.txt");
            string fileName, filePin, fileCardNumber;
            LoginResult result = {false,""};        //initialize daw

            if (file.is_open()){
                while (file>>fileName>>filePin>>fileCardNumber){
                    if (fileName == _name && filePin == _pin){
                        result.success = true;
                        result.cardNumber = fileCardNumber;
                        break;
                    }
                }
            }else{
                cout << "Unable to open file.";
            }return result;*/ 
        //}
};
/*void createAccount(){
    string name, pin;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter a 4-digit pin: ";
    cin >> pin;

    UserAccount newUser(name,pin);
    newUser.saveToFile();
    newUser.displayInfo();
}*/


void userLogin(){
    string name, pin;
    cout << "Enter your number: ";
    cin >> name;
    cout << "Enter your pin: ";
    cin >> pin;

    /*LoginResult loginResult = UserAccount::login(name, pin);

    if(loginResult.success){
        cout << "Login successfull!\n";
        cout << "Your card number is: " << loginResult.cardNumber;
    }else{
        cout << "Invalid name or pin.";
    }*/
}

int main(){

    int choice;

    while(1){
        mainMenu();
        cin >> choice;
        switch(choice){
            case 1:
            system("cls");
            userLogin();
                break;
            case 2:
            system("cls");
            cout << "Thank you for using this ATM";
            default:
                cout << "Invalid choice, Please try again.";
        }
    } 
}

void mainMenu(){
    cout << "\n***************************";
    cout << "\n\tATM MACHINE\n";
    cout << "***************************";
    cout << "\n1.) Login";
    cout << "\n2.) Exit";
    cout << "\nEnter your choice: ";
}
















































