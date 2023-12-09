#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <numeric>

std::vector<int> lowerline(std::vector<int> tempvec,int &sum){
    std::vector<int>tempvec_1;
    for(int i=0;i<tempvec.size()-1;i++){
        tempvec_1.push_back(tempvec[i]-tempvec[i+1]);
    }
    sum+=tempvec[0];
    if(std::count(tempvec_1.begin(),tempvec_1.end(),0)==tempvec_1.size()) return tempvec_1;
    lowerline(tempvec_1,sum);
}
int calculate(std::string &line){
    std::stringstream ss(line);
    int sum=0;
    std::vector <int> wholesentece;
    while (getline(ss, line, ' ')) {
        wholesentece.push_back(stoi(line));
    }
    std::reverse(wholesentece.begin(),wholesentece.end());
    lowerline(wholesentece,sum);
    return sum;
}
int main() {

    std::ifstream MyReadFile("data.txt");
    std::string a;
    long sum=0;
    while (std::getline(MyReadFile, a)){

        sum+=calculate(a);
        }
    std::cout<<sum;
    return 0;
}
