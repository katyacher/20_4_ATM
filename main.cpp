#include <iostream>
#include <string>
#include <ctime>
#include <fstream>

int main() {
    std::cout << "20.4 ATM \n";
    std::srand(std::time(nullptr));

    int nominals[6] = {100, 200, 500, 1000, 2000, 5000};
    int money[1000];

    std::cout << "Your operation (' + ' -  fill ATM, ' - ' - withdraw money ): ";
    std::string answer;
    std::cin >> answer;

    std::ifstream atm_in("atm.bin", std::ios::binary);
    if(atm_in.is_open()){
        atm_in.read((char *)money, sizeof(money));
        atm_in.close();
    } else {
        for (int i = 0; i < 1000; i++){
            money[i] = 0;
        }
    }

    if(answer == "+"){
        for (int i = 0; i < 1000; i++) {
            if(money[i] == 0){
                money[i] = nominals[std::rand() % 6];
            }
        }

        std::ofstream atm_out("atm.bin");
        if(atm_out.is_open()){
            atm_out.write((char *)money, sizeof(money));
        } else {
            std::cout << "Error opening file" << std::endl;
        }
        return 0;

    } else if( answer == "-"){
        std::cout << "Amount: ";
        int amount;
        std::cin >> amount;

        if (amount%100 != 0){
            std::cerr << "Invalid amount " << amount << std::endl;
            return 1;
        }

        int amount_to_collect = amount;
        for(int i = 5; i >= 0; --i ){
            int nominal = nominals[i];
            for(int j = 0; j < 1000; j++){
                if(money[j] == nominal){
                    if (amount_to_collect >= nominal){
                        money[j] = 0;
                        amount_to_collect -= nominal;
                        if(amount_to_collect == 0){
                            std::cout << "Amount taken:" << amount << std::endl;
                            std::ofstream atm_out("atm.bin");
                            if(atm_out.is_open()){
                                atm_out.write((char *)money, sizeof(money));
                                atm_out.close();
                            } else {
                                std::cout << "Error opening file" << std::endl;
                            }
                            return 0;
                        }
                    }
                }
            }
        }
    } else {
        std::cout << "Unknown operation." << std::endl;
    }
    return 0;
}
