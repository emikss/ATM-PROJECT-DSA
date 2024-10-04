#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

void mainMenu();

struct link{
    string accNum;
    string pincode;
    link *next;
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

        link *accountsLink;
    public:
        UserAccount() : accountsLink(NULL){}; // constructor

        bool isEmpty(){
            return (accountsLink == NULL);
        }


        string generateCardNum(){   //generating random 10-digit num
            string cardNum="";
            srand(time(0));
            for(int i=0;i<10;i++){
                cardNum+=to_string(rand()%10);
            }return cardNum;
        }

        //gayahin ko lang kay ku
        void saveToFile(){     //save user info
            ofstream file("accounts.txt",ios::app);
            if(file.is_open()){
                file<<name<<" "<<pin<<" "<< cardNumber;
                file.close();
            }else{
                cout<<"Unable to open file.";
            }
        }

        void displayInfo(){
            cout<<"Account created successfully!\n";
            cout<<"Your card number is: "<< cardNumber;
        }

        void filetoLink(string fileName, string filePin, string fileCardNumber){ // pushes data of file to a linked list
            link *newLink;
            newLink = new link();
            newLink->accNum = fileCardNumber;
            newLink->pincode = filePin;

            if (isEmpty()){
                accountsLink = newLink;
            } else {
                accountsLink->next = newLink;
                accountsLink = newLink;
            }
        }

        void retrieve (){ // TO BE MODIFIED, DAPAT PATI YUNG AMOUNT NG CASH NG ATM KASAMA SA MASASAVE
            ifstream file("accounts.txt");
            string fileName, filePin, fileCardNumber;

            if(file.is_open()){
                while(file>>fileName>>filePin>>fileCardNumber){
                    filetoLink(fileName, filePin, fileCardNumber);
                }
            }else{
                cout<<"Unable to open file.";
            } 
        }


        void userLogin(){
            string acc_num, pin;
            cout<<"Enter your account number: ";
            cin>>acc_num;
            cout<<"Enter your pin: ";
            cin>>pin;
            
            retrieve();

            if(LoginResult(acc_num, pin) == 1){
                    cout<<"Login successfull!\n";
                } else {
                    cout<<"Invalid name or pin.";
                }
        }

        int LoginResult(string acc_num, string pin){
            link *p = accountsLink;

            while (p!=NULL){
                if (p->accNum == acc_num){
                    if(p->pincode == pin){
                        return 1;
                    }
                    return 0;
                } 
                p = p->next;
            }
            return 0;
        }

};

void mainMenu(){
    cout<<"\n***************************";
    cout<<"\n\tATM MACHINE\n";
    cout<<"***************************";
    cout<<"\n1.) Login";
    cout<<"\n0.) Exit";
    cout<<"\nEnter your choice: ";
}


int main(){
    UserAccount login;
    int choice;
    while(1){
        system("cls");
        mainMenu();
        cin>>choice;
            switch(choice){
                case 1:
                    system("cls");
                    login.userLogin();
                    break;
                case 0:
                    system("cls");
                    cout<<"Thank you for using this ATM.";
                    exit(0);
                    break;
                
                default:
                    cout<<"Invalid choice, Please try again.";
                    system("pause");
            }
    } 
}
















































