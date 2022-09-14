#include <iostream>
#include <string>
#include <ctime>
#include <fstream>

void fillATM();

int main() {
    std::srand(std::time(nullptr));

    std::cout << "20.4 ATM \n";
    std::cout << "Fill the ATM (enter '+')" << std::endl;
    std::cout << "Withdraw money - enter '-': ";
    std::string answer;
    std::cin >> answer;

    if(answer == "+"){
        fillATM();
    } else if( answer == "-"){

    } else {
        std::cout << "Unknown operation." << std::endl;
    }

    return 0;
}

void fillATM(){
    int nominal[6] = {100, 200, 500, 1000, 2000, 5000};
    //открыть на чтение, узнать колличество купюр в банкомате
    /*
    std::ofstream atm_out("/home/kate/CLionProjects/20_4_ATM/ATM.txt");
    atm_out.close();
     */
    // открыть на запись  - дописать - либо полностью заполнить?
    std::ifstream atm_in("/home/kate/CLionProjects/20_4_ATM/ATM.txt");
    if(atm_in.is_open()) {
        for (int i = 0; i < 1000; i++) {
            atm_in >> nominal[std::rand() % 6];
        }
        // заполнение файла по типу стека
    } else {
        std::cout << "Error opening file" << std::endl;
    }
    atm_in.close();

    std::ofstream atm_out("/home/kate/CLionProjects/20_4_ATM/ATM.txt");
    if(atm_out.is_open()){
        int cash;
        while(!atm_out.eof()){
            atm_out << cash;
            std::cout << cash;
        }
    } else{
        std::cout << "Error opening file" << std::endl;
    };
    atm_out.close();
}

int withdrow() {
    int n5000 = 0;
    int n2000 = 0;
    int n1000 = 0;
    int n500 = 0;
    int n200 = 0;
    int n100 = 0;

    int N = 0;
    std::cout << "Введите необходимую сумму (не более 150000р):\n";
    std::cin >> N;

    if (N%100 != 0){
        std::cout << "Выдать ровно " << N << " рублей невозможно. Введите сумму, кратную 100:\n";
        std::cin >> N;
    }

    if (N > 150000){
        std::cout << "Банкомат не может выдать за раз более 150 000 рублей. Введите сумму, кратную 100 и не более 150000р:\n";
        std::cin >> N;
    }

    if (N >= 5000){
        n5000 = N/5000;
        N = N%5000;
        std::cout << n5000 << " по 5000 \n";
    }
    if (N >= 2000){
        n2000 = N/2000;
        N = N%2000;
        std::cout << n2000 << " по 2000 \n";
    }
    if (N >= 1000){
        n1000 = N/1000;
        N = N%1000;
        std::cout << n1000 << " по 1000 \n";
    }
    if (N >= 500){
        n500 = N/500;
        N = N%500;
        std::cout << n500 << " по 500 \n";
    }
    if (N >= 200){
        n200 = N/200;
        N = N%200;
        std::cout << n200 << " по 200 \n";
    }
    if (N >= 100){
        n100 = N/100;
        N = N%100;
        std::cout << n100 << " по 100 \n";
    }

}