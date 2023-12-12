#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#include <cmath>
struct cos1{
    int x;
    int y;
};


unsigned long long licz(cos1 a, cos1 b) {


    return abs(b.y - a.y) + abs(b.x - a.x);
}

int main() {

    std::ifstream MyReadFile("data.txt");
    char a;
    unsigned long long sum=0;
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


    for (int row = 0; row < maping.size(); ++row) {
        std::vector<char>b=maping[row];
        if(std::count(b.begin(),b.end(),'#')==0){

                maping[row]=std::vector<char>(140,'F');

        }
    }

    int column=0;
    int ile=0;
    for (column;column<maping[0].size();column++){
        bool czydodac=true;
        for(int p=0;p<maping.size();p++) {

            if(maping[p][column]=='#') {
                czydodac=false;
                break;
            }
        }

        if(!czydodac)continue;
        for(int d=0;d<maping.size();d++){
            if(maping[d][column]=='.') {
                maping[d][column] = 'K';
            }
            if(maping[d][column]=='F') {
                maping[d][column] = 'H';
            }
            ile++;
        }


    }

    std::vector<cos1> wspo;
    int row=0;
    column=0;
    int udawan_row=0;
    int udawan_colum=0;
    for(auto b:maping){
        for(auto c:b){

            if(c=='F') {
                udawan_row++;
                break;
            }
            if(c=='K') udawan_colum++;
            if(c=='H') {
                udawan_colum++;
                udawan_row++;
                break;
            }
            if(c=='#') {
                int udawan_colum_temp=udawan_colum==0?0:udawan_colum*1000000-1*udawan_colum;
                int udawan_row_temp=udawan_row==0?0:udawan_row*1000000-1*udawan_row;
                cos1 stru={row+udawan_row_temp,column+udawan_colum_temp};
                wspo.push_back(stru);
            }
            column++;
        }
        row++;
        column=0;
        udawan_colum=0;
    }
    for (int o=0;o<wspo.size();o++){
        for(int h=(o+1);h<wspo.size();h++){
           sum+=licz(wspo[o],wspo[h]);
        }


    }
    std::cout<<"Suma:"<<sum<<"\n";

    return 0;
}
