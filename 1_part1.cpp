#include <string>
#include <iostream>
#include <sstream>




int extractnumber(std::string line){
    int number_1=int(line.find_first_of("1234567890"));
    int number_2=int(line.find_last_of("1234567890"));
    std::string number_1_str(1,line[number_1]);
    std::string number_2_str(1,line[number_2]);
    int number = stoi(number_1_str + number_2_str);
    return number;
}
int main() {
    std::istringstream text("<input here>");
    std::string a,cos;
    int sum=0;
    while (std::getline(text, a)){

        sum+= extractnumber(a);
    }
    std::cout << sum;
    return 0;
}
