#include <iostream>
#include <fstream>

#include <vector>
#include <sstream>

#include <cmath>
struct cos1{
    int x;
    int y;
};

bool point_in_polygon(cos1 point, std::vector<cos1> polygon) {

    int num_vertices = polygon.size();

    double x = point.x, y = point.y;

    bool inside = false;

    cos1 p1 = polygon[0], p2;

    for (int i = 1; i <= num_vertices; i++) {

        p2 = polygon[i % num_vertices];

        if (y > std::min(p1.y, p2.y)) {

            if (y <= std::max(p1.y, p2.y)) {
                if (x <= std::max(p1.x, p2.x)) {
                    double x_intersection = (y - p1.y) * (p2.x - p1.x) / (p2.y - p1.y) + p1.x;

                    if (p1.x == p2.x || x <= x_intersection) {
                        inside = !inside;
                    }
                }
            }
        }

        p1 = p2;
    }
    return inside;
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
        cos1 ha={possition[0],possition[1]};
        k.push_back(ha);
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
    std::cout<<"Zaczyna sie"<<"\n";
    for(auto nnnn:k){
        std::cout<<nnnn.x<<" "<<nnnn.y<<"\n";
    }

    std::vector<cos1> pkt ;
    for (int l=0;l<maping.size()+1;l++){
        for (int n=0;n<140;n++){

                cos1 ha={n,l};
                pkt.push_back(ha);

        }
    }
    int llll=0;
    std::vector <int> zliczanie;
    std::vector<cos1> polygon = k;
    for (auto pk: pkt) {
        cos1 point = pk;

        if (point_in_polygon(point, polygon)) {
            std::cout << "Point is inside the polygon" <<point.x<<point.y<< std::endl;
            llll++;
        }
    }
    std::cout<<"\n"<<"\n"<<llll-std::ceil(cos)+2; //+2 because S and last not included
    return 0;
}
