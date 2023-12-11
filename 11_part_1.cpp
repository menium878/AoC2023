

#include <iostream>
#include <fstream>

#include <vector>
#include <sstream>

#include <cmath>
struct cos1{
    int x;
    int y;
};


int licz(cos1 a, cos1 b) {
    int tempy=abs(b.y - a.y);
    int tempx= abs(b.x - a.x);
    int co=0;
    while(true) {
        if(tempy==0 && tempx==0) break;
        if(tempy!=0) {
            tempy--;
            co++;
        }
        if(tempx!=0) {
         tempx--;
        co++;
        }
    }
    return co;
}

int main() {

    std::ifstream MyReadFile("data.txt");
    char a;
    long sum=0;
    int i=0;

    std::vector<cos1> k ;

    std::vector <std::vector <char>> maping;
    maping.push_back(std::vector <char>());
    while (MyReadFile.get(a)){
        if('\n'==a) {
            maping.push_back(std::vector <char>());
            i++;
            continue;
        }
        maping[i].push_back(a);

    }

    bool change =true;
    for (int row = 0; row < maping.size(); ++row) {
        std::vector<char>b=maping[row];


        if(std::count(b.begin(),b.end(),'#')==0){
            //std::cout<<"ROW"<<row;
            if(change) {
                maping.insert(maping.begin() + row,
// I know it's dump but didn't wa
                              std::vector<char>{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.','.', '.', '.', '.', '.', '.', '.', '.', '.', '.','.', '.', '.', '.', '.', '.', '.', '.', '.', '.','.', '.', '.', '.', '.', '.', '.', '.', '.', '.','.', '.', '.', '.', '.', '.', '.', '.', '.', '.','.', '.', '.', '.', '.', '.', '.', '.', '.', '.','.', '.', '.', '.', '.', '.', '.', '.', '.', '.','.', '.', '.', '.', '.', '.', '.', '.', '.', '.','.', '.', '.', '.', '.', '.', '.', '.', '.', '.','.', '.', '.', '.', '.', '.', '.', '.', '.', '.','.', '.', '.', '.', '.', '.', '.', '.', '.', '.','.', '.', '.', '.', '.', '.', '.', '.', '.', '.','.', '.', '.', '.', '.', '.', '.', '.', '.', '.','.', '.', '.', '.', '.', '.', '.', '.', '.', '.'});
                change =false;
            }
            else change =true;
        }
        for(auto c:b){
            std::cout<<c;
        }

        std::cout<<"\n";
    }
    std::cout<<"aaaaaaaaaaaaaa"<<"\n";
    int column=0;
    int ile=0;
    for (column;column<maping[0].size();column++){
        std::cout<<column;
        bool czydodac=true;

        for(int p=0;p<maping.size();p++) {
            char xd=maping[p][column];
            if(maping[p][column]!='.') {
                czydodac=false;
                break;
            }
        }

        if(!czydodac)continue;
        for(int d=0;d<maping.size();d++){
            maping[d].insert(maping[d].begin() + column, '.');
            ile++;
        }
        column++;

    }
    std::cout<<"HHAHAHAHA"<<"\n";
    for(auto b:maping){
        for(auto c:b){
            std::cout<<c;
        }
        std::cout<<"\n";
    }
    std::vector<cos1> wspo;
    int row=0;
    column=0;
    for(auto b:maping){
        for(auto c:b){
            if(c=='#') {
                cos1 stru={row,column};
                wspo.push_back(stru);
            }
            column++;
        }
        row++;
        column=0;
    }
    for (int o=0;o<wspo.size();o++){
        for(int h=(o+1);h<wspo.size();h++){
           sum+=licz(wspo[o],wspo[h]);
        }
    }

    std::cout<<"Suma:"<<sum;
    return 0;
}
