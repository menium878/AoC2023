

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

bool is_digits(const std::string &str)
{
    return str.find_first_not_of("0123456789") == std::string::npos;
}

 std::vector <int> getvalues(std::string &line){

    std::string tomap=line;
    std::stringstream ss(tomap);
    std::vector<int> v;
    while (getline(ss, tomap, ' ')) {
        if(!tomap.empty()&&is_digits(tomap)) {
            v.push_back(stoi(tomap));
        }
    }
    return v;
}
int canit(int time,int distance){
    int count=0;
    for (int hold=0;hold<time;hold++){
        if(distance<hold*(time-hold)) count++;
    }
    return count;

}
int calculater(std::vector<int> time,std::vector<int> distance){
    int temp=1;
    for (int i=0;i<time.size();i++){
        temp*=canit(time[i],distance[i]);
    }
    return temp;
}


int main() {

    std::ifstream MyReadFile("data.txt");
    std::string a;
    std::vector<int> time;
    std::vector<int> distance;
    int sum=0;
    bool pierwsza=true;
    while (std::getline(MyReadFile, a)){
        std::cout<<sum<<"\n";
        if(pierwsza){
            time=getvalues(a);
            pierwsza=false;
            continue;
        }

        distance= getvalues(a);
        }
    std::cout <<"Wynik:"<<calculater(time,distance);


    return 0;

}
