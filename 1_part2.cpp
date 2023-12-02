#include <string>
#include <iostream>
#include <sstream>
#include <regex>

void halo(std::string &cos){
    cos=std::regex_replace(cos,std::regex("one"),"1");
    cos=std::regex_replace(cos,std::regex("two"),"2");
    cos=std::regex_replace(cos,std::regex("three"),"3");
    cos=std::regex_replace(cos,std::regex("four"),"4");
    cos=std::regex_replace(cos,std::regex("five"),"5");
    cos=std::regex_replace(cos,std::regex("six"),"6");
    cos=std::regex_replace(cos,std::regex("seven"),"7");
    cos=std::regex_replace(cos,std::regex("eight"),"8");
    cos=std::regex_replace(cos,std::regex("nine"),"9");
}
std::string find_index(std::string  line,int &index_first,int &index_last){
    std::string pierwsza,druga;
    std::string arr[18] = {"1","2","3","4","5","6","7","8","9","one","two","three","four","five","six","seven","eight","nine"};
    for (const auto& cos:arr){
        if (line.find(cos) < index_first) {
            index_first = line.find(cos);
            pierwsza=cos;
        } else {
            index_first = index_first;
        }
        if (int(line.rfind(cos)) > index_last) {
            index_last = int(line.rfind(cos));
            druga=cos;
        } else {
            index_last = index_last;
        }

    }
    pierwsza=pierwsza.empty()?druga:pierwsza;
    druga=druga.empty()?pierwsza:druga;
    halo(pierwsza);
    halo(druga);
    return pierwsza+druga;
}

int extractnumber(std::string &line){
    int index_first;
    int index_last=0;
    std::string cala;
    cala=find_index(line,index_first,index_last);
    std::cout<<cala<<'\n';
    int number=0;
    number = stoi(cala);
    return number;
}
int main() {
    std::istringstream tekst("<input here>");
    std::string a,cos;
    int sum=0;
    while (std::getline(tekst, a)){
        sum+= extractnumber(a);
    }
    std::cout << sum;
    return 0;
}
