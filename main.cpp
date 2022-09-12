#include <iostream>
#include <string>

int sum_of (int* arr){
    int sum = 0;
    int size = sizeof(arr);
    std::cout << size << " ";
    for(int i = 0; i < 6 - 1 ; i++){
        sum += arr[i] + arr[i + 1];
    }
    return sum;
}

int main() {
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
    //0 - 100, 1 - 200, 2 - 500, 3 - 1000, 4 - 2000, 5 - 5000;
    int nominal[6] = {0, 0, 0, 0, 0, 0};

    while(sum_of(nominal) <= 1000){
        nominal[std::rand()%6]++;
    }
    for(int i = 0; i < 6; i++){
        std::cout << nominal[i] << " " ;
    }
    // заполнение файла по типу стека
    //открыть на чтение, узнать колличество купюр в банкомате
    // открыть на запись  - дописать - либо полностью заполнить?
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