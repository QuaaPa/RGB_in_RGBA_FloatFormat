#include <iostream>
#include <sstream>
#include <string>

double convertToNormalizedRange(int number) {
    return static_cast<double>(number) / 255.0;
}

int main() {
    int numbers[3];
    std::string input;
    std::cout <<"-----"<< "https://www.w3schools.com/colors/colors_rgb.asp"<<"-----"<<std::endl;
    std::cout << "--------------Enter 3 numbers from 0 to 255--------------"<<std::endl;
    std::getline(std::cin, input);

    std::stringstream ss(input);
    char comma;
    for (int i = 0; i < 3; ++i) {
        if (!(ss >> numbers[i])) {
            std::cerr << "Error inputting number " << i + 1 << std::endl;
            return 1;
        }
        if (i < 2 && !(ss >> comma) && comma != ',') {
            std::cerr << "Delimiter error" << std::endl;
            return 1;
        }
        if (numbers[i] < 0 || numbers[i] > 255) {
            std::cerr << "Number must be in the range of 0 to 255" << std::endl;
            return 1;
        }
    }

    std::cout << "Numbers in the rgba" << std::endl;
    for (int i = 0; i < 3; ++i) {
        double normalizedNumber = convertToNormalizedRange(numbers[i]);
        std::cout << normalizedNumber << ","  << " ";
    }
    std::cout << "1.0"  << std::endl;

    while (true){}
}
