

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <ranges>
#include <algorithm>
#include <map>

struct handy{
    std::string hand;
    int rodzaj;
    int value;
};
handy count(std::string &line) {
    std::string cards=line.substr(0,5);
    int value=stoi(line.substr(6));
    std::vector<int> handcount;
    handy cos;
    for (char a:cards) {
        handcount.push_back(std::ranges::count(cards, a));
    }
    int rodzaj=0;
    switch (std::ranges::max(handcount)){
        case 4:
            rodzaj=5;
            break;
        case 5:
            rodzaj=6;
            break;
        case 3:
            if(std::find(handcount.begin(), handcount.end(), 2) != handcount.end()) rodzaj=4;
            else rodzaj=3;
            break;
        case 2:
            if(std::ranges::count(handcount,2)>2) rodzaj=2;
            else rodzaj=1;
            break;
        case 1:
            rodzaj=0;
    }

    cos.hand=cards;
    cos.rodzaj=rodzaj;
    cos.value=value;
    std::cout<<cos.hand<<" "<<cos.rodzaj<<" "<<cos.value<<"\n";
    return cos;
}
bool comparestructs(handy a,handy b){
    std::map<char,int> m{{'A',14},{'K',13},{'Q',12},{'J',11},{'T',10}};
    if (a.rodzaj==b.rodzaj) {
        for (int i=0;i<a.hand.size();i++) {
            if((isdigit(a.hand[i]) ? int(a.hand[i])- 48 : m[a.hand[i]]) == (isdigit(b.hand[i]) ? int(b.hand[i])- 48 : m[b.hand[i]])) continue;
            return (isdigit(a.hand[i]) ? int(a.hand[i])- 48 : m[a.hand[i]]) < (isdigit(b.hand[i]) ? int(b.hand[i])- 48 : m[b.hand[i]]);
        }
    }
        return a.rodzaj<b.rodzaj;
}
int main() {

    std::ifstream MyReadFile("data.txt");
    std::string a;
    std::vector<handy> playing;
    long sum=0;
    while (std::getline(MyReadFile, a)){
        playing.push_back(count(a));
        //std::cout<<sum<<"\n";

    }
    std::cout <<"Brakowo: "<<'\n';
    std::sort(playing.begin(),playing.end(), comparestructs);
    int counting=1;
    for (auto ha:playing){

        std::cout<<ha.hand<<" "<<ha.rodzaj<<" "<<ha.value<<"\n";
        sum+=ha.value*counting;
        counting++;
    }
    std::cout <<"Wynik: "<<sum<<'\n';

    return 0;

}
