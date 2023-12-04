#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

int winnings(std::string &line)
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

    for (std::string cos:v1) {
        if(cos!=" " && !cos.empty()) {
            if (std::find(v.begin(), v.end(), cos) != v.end()) {
                if (points == 0) points += 1;
                else {
                    points *= 2;
                }
            }
        }
    }

    return points;
}

int main() {

    std::ifstream MyReadFile("data.txt");
    std::string a,cos;
    int sum=0;
    while (std::getline(MyReadFile, a)){
        sum+= winnings(a);
    }
    std::cout << sum;

    return 0;

}
