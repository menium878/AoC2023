

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include <algorithm>
#include <unordered_map>
#include <numeric>

long long findLCM(std::vector<int> numbers) {
    long long result = numbers[0];
    for (int i = 1; i < numbers.size(); i++) {
        result = (result * numbers[i]) / std::gcd(result, numbers[i]);
    }
    return result;
}


void filetomap(std::string line,std::unordered_map <std::string,std::vector<std::string>>& m){
    std::string key=line.substr(0,3);
    std::vector <std::string> v;
    v.push_back(line.substr(7,3));
    v.push_back(line.substr(12,3));
    m[key]=v;

}
int main() {

    std::ifstream MyReadFile("C:\\Users\\Menium\\CLionProjects\\untitled111\\data.txt");
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
    int vectorcout=0;
    //std::string at="AAA";
    std::vector <std::string> atvect={"TTA","KJA","BGA","AAA","LTA","NJA"};
    std::vector <int> vectorvynikow={0,0,0,0,0,0};
    while(true){
        for (std::string at:atvect) {
            int stringrounding = sum >= direction.size() ? sum % direction.size() : sum;
            char towhere = direction[stringrounding];
            if (towhere == 'L') {
                atvect[vectorcout] = m[at][0];
            } else {
                atvect[vectorcout] = m[at][1];
            }
            vectorcout++;
        }
        vectorcout=0;
        //std::cout<<sum<<"\n";
        sum++;
        bool isit=true;
        for (std::string checking:atvect) {

            //if (checking[2] != 'Z') isit=false;
            if(checking[2]=='Z'){
                vectorvynikow[vectorcout] =sum;
                if (std::count(vectorvynikow.begin(),vectorvynikow.end(),0)==0){
                    goto koniec;
                }
            }
            vectorcout++;

        }
        vectorcout=0;
        //if(isit) goto koniec;
    }
        koniec:

    std::cout<<findLCM(vectorvynikow);
    //std::cout<<sum;
    return 0;

}
