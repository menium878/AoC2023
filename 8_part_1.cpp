

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include <algorithm>
#include <unordered_map>

void filetomap(std::string line,std::unordered_map <std::string,std::vector<std::string>>& m){
    std::string key=line.substr(0,3);
    std::vector <std::string> v;
    v.push_back(line.substr(7,3));
    v.push_back(line.substr(12,3));
    m[key]=v;

}
int main() {

    std::ifstream MyReadFile("data.txt");
    std::string a;
    std::unordered_map <std::string,std::vector<std::string>>m;
    long sum=0;
    int line=0;
    std::string direction;
    while (std::getline(MyReadFile, a)){
        if(line==1) {
            line++;
            continue;
        }
        if(line==0) {
            direction=a;
            line++;
            continue;
        }
        filetomap(a,m);
        }
    std::string at="AAA";
    while(at!="ZZZ"){
        int stringrounding=sum>=direction.size()?sum%direction.size():sum;
        char towhere =direction[stringrounding];
        if(towhere=='L'){
            at=m[at][0];
        }
        else{
            at=m[at][1];
        }

        sum++;
    }
    std::cout<<sum;
    return 0;

}
