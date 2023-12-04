#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <deque>

void winnings(std::string &line,std::deque<int>& howmany,bool koniec)
{
    std::string num_win,num_picked;
    num_win=line.substr(line.find(':')+1,line.find('|')-(line.find(':')+1));
    num_picked=line.substr(line.find('|')+1);
    std::stringstream ss(num_win);
    std::vector<std::string> v;
    while (getline(ss, num_win, ' ')) {
        v.push_back(num_win);
    }
    std::stringstream ss1(num_picked);
    std::vector<std::string> v1;
    while (getline(ss1, num_picked, ' ')) {
        v1.push_back(num_picked);
    }
    int points=0;
    int count=0;
    for (std::string cos:v1) {
        if(cos!=" " && !cos.empty()) {
            if (std::find(v.begin(), v.end(), cos) != v.end()) {
                count++;
                if (points == 0) points += 1;
                else {
                    points *= 2;
                }
            }
        }
    }
    int i=koniec?0:1;
    int start=i;
    for (i;i<count+start;i++) {
        if(i>howmany.size()+start) howmany.push_back(2);
        howmany[i] = howmany[i]+1;
    }
    //return points;
}

int main() {

    std::ifstream MyReadFile("data.txt");
    std::string a;
    int sum=0;
    bool koniec=false;
    std::deque<int> howmany={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    int wiersz=0;
    while (std::getline(MyReadFile, a)){
        wiersz++;
        std::cout<<"wiersz:"<<wiersz<<'\n';
        for (int i=0;i<howmany[0];) {
            sum++;
            howmany[0]-=1;
            if(howmany[0]==0){
                howmany.pop_front();
                koniec=true;
            }
            winnings(a, howmany,koniec);
            std::cout <<"suma:"<< sum <<'\n';
            if(koniec){
                koniec=false;
                break;
            }
        }
    }
    std::cout << sum;

    return 0;

}
