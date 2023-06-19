
#include <iostream>
#include <bitset>
#include <string>

//сама функция смены битов
void swapBits(unsigned long long int& n, int p1, int p2) {
    int bit1 = (n >> p1) & 1;//получение значения бита 
    int bit2 = (n >> p2) & 1;

    if (bit1 != bit2) {
        n ^= (1 << p1) | (1 << p2); 
        //если значения битов не одинаковые, то меняем их местами («^» операция побитового исключающего или)
    }
}

//просто для красивого вывода
void printBinary(unsigned long long int& n) {
    std::bitset<64> binary(n);
    std::string binary_str = binary.to_string();
    int pos = binary_str.find_first_not_of('0');
    if (pos != -1) {
        binary_str = binary_str.substr(pos);
    }
    else {
        binary_str = "0";
    }
    std::cout << binary_str << std::endl;
}

int main(int argc, char* argv[]) {
    //это тоже проверка корректности ввода
    if (argc != 4) {
        std::cout << "Usage: " << argv[0] << " <number> <position 1> <position 2>" << std::endl;
        return 1;
    }

    unsigned long long int n;
    int p1, p2;

    /*
    * если ввод идет не из командной строки, то функция main не будет получать аргументы
    * а сами аргументы будут просто считаны с клавиатуры std::cin 
    */


    //проверка на дурака
    try {
        n = std::stoull(argv[1]);
        p1 = std::stoi(argv[2]);
        p2 = std::stoi(argv[3]);
    }
    catch (const std::exception& e) {
        std::cerr << "Invalid input: " << e.what() << "\n";
        return 1;
    }
    int num_bits = (int)log2(n) + 1;

    if (p1 < 0 or p2 < 0 or p1 > num_bits || p2 > num_bits) {
        std::cout << "Invalid positions" << std::endl;
        return 1;
    }
    //проверка закончилась

    

    std::cout << "Original number in binary: ";
    printBinary(n);
    std::cout << "Original number in decimal: " << n << std::endl;

    swapBits(n, p1, p2);
    std::cout << "Modified number in binary: ";
    printBinary(n);
    std::cout << "Modified number in decimal: " << n << std::endl;
}

