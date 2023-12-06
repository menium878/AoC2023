

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>


bool is_digits(const std::string &str)
{
    return str.find_first_not_of("0123456789") == std::string::npos;
}

std::vector <long long> getvalues(std::string &line){

    std::string tomap=line;
    std::string temp;
    std::stringstream ss(tomap);
    std::vector<long long> v;
    while (getline(ss, tomap, ' ')) {
        if(!tomap.empty()&&is_digits(tomap)) {
            temp+=tomap;

        }
    }
    v.push_back(stoll(temp));
    return v;
}
long long canit(long long time,long long distance){
    long long count=0;
    for (long long hold=0;hold<time;hold++){
        if(distance<hold*(time-hold)) count++;
    }
    return count;

}
long long calculater(std::vector<long long> time,std::vector<long long> distance){
    long long temp=1;
    for (long long i=0;i<time.size();i++){
        temp*=canit(time[i],distance[i]);
    }
    return temp;
}


int main() {

    std::ifstream MyReadFile("data.txt");
    std::string a;
    std::vector<long long> time;
    std::vector<long long> distance;
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
    std::cout <<"Wynik: "<<calculater(time,distance);
    
    return 0;

}
