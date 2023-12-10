

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <numeric>
#include <unordered_map>
#include <cmath>

int main() {

    std::ifstream MyReadFile("data.txt");
    char a;
    long sum=0;
    int i=0;


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

    std::cout<<maping[95][74]<<"\n";
    int possition[2]={74,95};
    char validinput;

    cos1:
    int prev [2];
    prev[0]=74;
    prev[1]=95;
    possition[0]=74;
    possition[1]=94;
    validinput='F';
    while(true) {
        switch (validinput) {
        case '|':

            if (possition[1]-prev[1]==1) {
                prev[0]=possition[0];
                prev[1]=possition[1];
                possition[1] += 1;

            } else {
                prev[0]=possition[0];
                prev[1]=possition[1];
                possition[1] -= 1;
            }
                break;
            case '-':
                if (possition[0]-prev[0] == 1) {
                    prev[0]=possition[0];
                    prev[1]=possition[1];
                    possition[0] += 1;
                } else {
                    prev[0]=possition[0];
                    prev[1]=possition[1];
                    possition[0] -= 1;
                }
                break;
        case 'L':
            if (possition[0]-prev[0]==-1) {
                prev[0]=possition[0];
                prev[1]=possition[1];
                possition[1] -=1;
            } else {
                prev[0]=possition[0];
                prev[1]=possition[1];
                possition[0] += 1;
            }
                break;
        case 'J':
            if (possition[0]-prev[0]==1) {
                prev[0]=possition[0];
                prev[1]=possition[1];
                possition[1] -=1;
            } else {
                prev[0]=possition[0];
                prev[1]=possition[1];
                possition[0] -= 1;
            }
            break;
        case '7':
            if (possition[0]-prev[0]==1) {
                prev[0]=possition[0];
                prev[1]=possition[1];
                possition[1] +=1;
            } else {
                prev[0]=possition[0];
                prev[1]=possition[1];
                possition[0] -= 1;
            }
                break;
        case 'F':
            if (possition[0]-prev[0]==-1) {
                prev[0]=possition[0];
                prev[1]=possition[1];
                possition[1] +=1;
            } else {
                prev[0]=possition[0];
                prev[1]=possition[1];
                possition[0] += 1;
            }
        }
        validinput=maping[possition[1]][possition[0]];
        std::cout<<validinput;
        sum+=1;
        if(validinput=='S')break;

    }
    float cos =(double)sum/2;
    std::cout<<std::ceil(cos);
    return 0;
}
