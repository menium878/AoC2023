

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>


std::vector<std::string> seed_vector(std::string &line)
{
    std::string seeds;
    seeds=line.substr(line.find(':')+1);
    std::stringstream ss(seeds);
    std::vector<std::string> v;
    while (getline(ss, seeds, ' ')) {
        if(seeds=="") continue;
        v.push_back(seeds);
    }
    std::vector<std::string> v1;
    for (long i=0;i<v.size();i+=2) {
        long long startingval = stoll(v[i]);
        for (long long j = 0; j < stoll(v[i + 1]); j++) {
            v1.push_back(std::to_string(startingval+j));
        }
    }

    return v1;
}
std::map<std::string,std::string> maping(std::string &line){
    std::map<std::string,std::string> m1;
    std::string tomap=line;
    std::stringstream ss(tomap);
    std::vector<std::string> v;
    while (getline(ss, tomap, ' ')) {
        v.push_back(tomap);
    }
    long long starting_1=stoll(v[0]);
    long long starting_2=stoll(v[1]);
    long long  count = stoll(v[2]);
    for (long long i=0;i<count;i++){
        m1[std::to_string(starting_2+i)]=std::to_string(starting_1+i);
    }

    return m1;
}

int main() {

    std::ifstream MyReadFile("data.txt");
    std::string a;
    std::vector<std::string> seed;
    std::map<std::string,std::string> seed_to_soil;
    std::map<std::string,std::string> soil_to_fertilizer;
    std::map<std::string,std::string> fertilizer_to_water;
    std::map<std::string,std::string> water_to_light;
    std::map<std::string,std::string> light_to_temperature;
    std::map<std::string,std::string> temperature_to_humidity;
    std::map<std::string,std::string> humidity_to_location;
    std::map<std::string,std::string> temp;
    int sum=0;
    while (std::getline(MyReadFile, a)){
        std::cout<<sum<<"\n";
        if(a=="")continue;
        if(a=="seed-to-soil map:"||a=="soil-to-fertilizer map:"||a=="fertilizer-to-water map:"||a=="water-to-light map:"||a=="light-to-temperature map:"||a=="temperature-to-humidity map:"||a=="humidity-to-location map:") sum++;
        if (sum==0) {
            seed=seed_vector(a);
            sum++;
        }
        if(sum==2&&a!="seed-to-soil map:") {
            temp = maping(a);
            seed_to_soil.insert(temp.begin(),temp.end());
        }
        if(sum==3&&a!="soil-to-fertilizer map:") {
            temp = maping(a);
            soil_to_fertilizer.insert(temp.begin(),temp.end());
        }
        if(sum==4&&a!="fertilizer-to-water map:") {
            temp = maping(a);
            fertilizer_to_water.insert(temp.begin(),temp.end());
        }
        if(sum==5&&a!="water-to-light map:") {
            temp = maping(a);
            water_to_light.insert(temp.begin(),temp.end());
        }
        if(sum==6&&a!="light-to-temperature map:") {
            temp = maping(a);
            light_to_temperature.insert(temp.begin(),temp.end());
        }
        if(sum==7&&a!="temperature-to-humidity map:") {
            temp = maping(a);
            temperature_to_humidity.insert(temp.begin(),temp.end());
        }
        if(sum==8&&a!="humidity-to-location map:") {
            temp = maping(a);
            humidity_to_location.insert(temp.begin(),temp.end());
        }
        }

    for (std::string se:seed)
    std::cout<<se<<" " <<"\n";


   
    std::string temp1,temp2,temp3,temp4,temp5,temp6,temp7;
    long long wynik=-1;
    for (std::string se:seed) {
        std::cout << se << "\n";
        temp1=seed_to_soil[se]!=""?seed_to_soil[se]:se;
        temp2=soil_to_fertilizer[temp1]!=""?soil_to_fertilizer[temp1]:temp1;
        temp3=fertilizer_to_water[temp2]!=""?fertilizer_to_water[temp2]:temp2;
        temp4=water_to_light[temp3]!=""?water_to_light[temp3]:temp3;
        temp5=light_to_temperature[temp4]!=""?light_to_temperature[temp4]:temp4;
        temp6=temperature_to_humidity[temp5]!=""?temperature_to_humidity[temp5]:temp5;
        temp7=humidity_to_location[temp6]!=""?humidity_to_location[temp6]:temp6;
        if(wynik==-1) wynik=stoll(temp7);
        if (wynik>stoll(temp7)) wynik=stoll(temp7);



    }
    std::cout <<"Wynik"<<wynik <<"\n";
    return 0;

}
