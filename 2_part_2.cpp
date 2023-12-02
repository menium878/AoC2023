#include <string>
#include <iostream>
#include <sstream>
#include <vector>

int can_be_game_int(std::string &withoutgame){
    int blue=0;
    int red=0;
    int green=0;

    std::stringstream stringStream(withoutgame);
    std::string line;
    std::vector <std::string>wordVector;
    while(std::getline(stringStream, line))
    {
        std::size_t prev = 0, pos;
        while ((pos = line.find_first_of(";", prev)) != std::string::npos)
        {
            if (pos > prev)
                wordVector.push_back(line.substr(prev, pos-prev));
            prev = pos+1;
        }
        if (prev < line.length())
            wordVector.push_back(line.substr(prev, std::string::npos));
    }
    for (const auto& halo:wordVector){

        std::stringstream cos(halo);
        std::string graline;
        std::vector <std::string>graVector;
        while(std::getline(cos, graline))
        {
            std::size_t prev = 0, pos;
            while ((pos = graline.find_first_of(",", prev)) != std::string::npos)
            {
                if (pos > prev)
                    graVector.push_back(graline.substr(prev, pos-prev));
                prev = pos+1;
            }
            if (prev < line.length())
                graVector.push_back(graline.substr(prev, std::string::npos));
        }
        for (const auto& s: graVector){

            std::string sub = s.substr(s.find(" ")+1);
            std::cout<<sub<<"\n";
            std::string ilosc_str = sub.substr(0,sub.find(" "));
            std::string jaki_str = sub.substr(sub.find(" ")+1);
            std::cout<<"ilosc_str:"<<ilosc_str<<"\n";
            std::cout<<"jaki_str:"<<jaki_str<<"\n";
            if (jaki_str=="blue"){
                blue=stoi(ilosc_str)>blue?stoi(ilosc_str):blue;
            }
            if (jaki_str=="red"){

                red=stoi(ilosc_str)>red?stoi(ilosc_str):red;
            }
            if (jaki_str=="green")
                green=stoi(ilosc_str)>green?stoi(ilosc_str):green;


        }
    }
    return green*red*blue;
}


int extractnumber(std::string &line){
    std::string id=line.substr(line.find(" ")+1,line.find(":")-(line.find(" ")+1));
    std::cout<<"Id:"<<id<<"\n";
    std::string withoutgame = line.substr(line.find(":")+1);

    can_be_game_int(withoutgame);
    return can_be_game_int(withoutgame);;
}

int main() {
    std::istringstream tekst("<input here>");
    std::string a,cos;
    int sum=0;
    while (std::getline(tekst, a)){
        sum+= extractnumber(a);
        std::cout <<"Sum:" <<sum <<"\n";
    }
    std::cout << sum;
    return 0;
}
