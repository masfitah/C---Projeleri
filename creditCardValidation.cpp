#include <iostream>
/*
Luhn Algoritması
    16 haneli kredi kartının en sağdaki hanesinden başlayarak iki iki sola doğru kay
    her kaydığında gelen sayıy 2 ile çarp
    eğer sayı 2 basamaklı olduysa rakamlarını topla
    şimdiyse bütün rakamlarını topla
    10  ile bölümünden kalan yoksa doğru numaraya sahip
*/
int getDigit(const int number);
int sumOddDigits(const std::string cardNumber);
int sumEvenDigits(const std::string cardNumber);
int main(){

    std::string cardNumber;
    int result=0;

    std::cout << "Enter your card number : ";
    std::cin >> cardNumber;

    result = sumEvenDigits(cardNumber) + sumOddDigits(cardNumber);

    if(result % 10 == 0){
        std::cout << cardNumber << " is valid.";
    }
    else{
        std::cout << cardNumber << " is not valid.";
    }

    return 0;
}
int getDigit(const int number){

    return number % 10 + (number / 10 % 10);
}
int sumOddDigits(const std::string cardNumber){

    int sum=0;

    for(int i = cardNumber.size()-1; i >= 0; i -= 2){
        sum += cardNumber[i]-'0';
    }

    return sum;
}
int sumEvenDigits(const std::string cardNumber){

    int sum=0;

    for(int i = cardNumber.size()-2; i >= 0; i -= 2){
        sum += getDigit((cardNumber[i]-'0') * 2);
    }

    return sum;
}