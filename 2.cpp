#include <string>
#include <iostream>
#include <sstream>
#include <vector>


bool can_be_game(std::string &withoutgame){

    bool mozna=true;
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
            int blue=14;
            int red=12;
            int green=13;
        std::string sub = s.substr(s.find(" ")+1);
        std::cout<<sub<<"\n";
        std::string ilosc_str = sub.substr(0,sub.find(" "));
        std::string jaki_str = sub.substr(sub.find(" ")+1);
       std::cout<<"ilosc_str:"<<ilosc_str<<"\n";
        std::cout<<"jaki_str:"<<jaki_str<<"\n";
        if (jaki_str=="blue"){
            blue-=stoi(ilosc_str);
        }
        if (jaki_str=="red"){
            red-=stoi(ilosc_str);
        }
        if (jaki_str=="green")
            green-=stoi(ilosc_str);
        mozna=blue>=0&&red>=0&&green>=0;
        if (!mozna) return false;
    }
    }
    //std::cout<<"green"<<green<<"red"<<red<<"blue"<<blue<<std::endl;
    return mozna;

}

int extractnumber(std::string &line){
    std::string id=line.substr(line.find(" ")+1,line.find(":")-(line.find(" ")+1));
    std::cout<<"Id:"<<id<<"\n";
    std::string withoutgame = line.substr(line.find(":")+1);

   // std::cout<<withoutgame<<"\n";
   bool czy=can_be_game(withoutgame);
    return czy?stoi(id):0;
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
