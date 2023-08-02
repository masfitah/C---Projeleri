#include <iostream>

void showBalance(double balance);
double deposit();
double withdraw(double balance);

int main(){
    
    double balance=0;
    int choice=0;
    std::cout << "****************** WELCOME TO ANT BANK ******************\n";
    do{
        std::cout << "------------------\n";
        std::cout << "1.Show my balance\n";
        std::cout << "2.Deposite money\n";
        std::cout << "3.Withdraw money\n";
        std::cout << "4.Exit\n";
        std::cout << "------------------\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cout << "------------------\n";

        //hatalı girişlerle programın bozulmasını engellemek için
        std::cin.clear();
        fflush(stdin);

        switch (choice){
            case 1: showBalance(balance);
                    break;
            case 2: balance += deposit();
                    showBalance(balance);
                    break;
            case 3: balance -= withdraw(balance);
                    showBalance(balance);
                    break;
            case 4: std::cout << "Thanks for your visiting have a nice day.\n";
                    std::cout << "------------------\n";
                    break;
            default: std::cout << "Invalid choice !\n";
    }
    }while(choice !=4);
    
    return 0;
}
void showBalance(double balance){
    std::cout << "Your balance is : " << balance << " TL" << '\n';
}
double deposit(){
    double amount=0;
    std::string currency;
    std::cout << "Which currency do you want to trade ? Dolar or Euro please enter : ";
    std::cin >> currency;
    std::cout << "\nEnter amount to be deposited: ";
    std::cin >> amount;
    if(amount <= 0){
        std::cout << "That's not a valid amount.\n";
        return 0;
    }
    else{
        if(currency == "Dolar"){
            amount *= 27;
            return amount;
        }
        else if(currency == "Euro"){
            amount *= 30;
            return amount;
        }
        else{
            std::cout << "That's not a valid currency.\n";
            return 0;
        }
    }
}
double withdraw(double balance){
    double amount=0;
    std::cout << "Enter amount to be withdrawn: ";
    std::cin >> amount;
    if(amount>balance){
        std::cout << "Insufficient funds.\n";
        return 0;
    }
    else if(amount < 0){
        std::cout << "That's not a valid amount.\n";
        return 0;
    }
    else{
        return amount;
    }
}