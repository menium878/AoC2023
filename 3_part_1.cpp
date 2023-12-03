#include <string>
#include <iostream>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iostream>
#include <fstream>
#include <vector>

int liczby_przynalezne(int x,int y,char arr[1000][1000])
{
    std::string doliczby;
    for (int a = -1; a < 2; a++) {
        for (int b = -1; b < 2; b++) {
            if (isdigit(arr[x - b][y - a])) {
                char liczba= arr[x - b][y - a];
                int i=0;
                while (isdigit(arr[x - b - i][y - a])) {
                    if (!isdigit(arr[x - b - i][y - a])) break;
                    if (x - b - i == 0) {
                        i++;
                        break;
                    }
                    i++;
                }
                int k=1;
                while(isdigit(arr[x-b-i+k][y - a])){
                    doliczby.push_back(arr[x-b-i+k][y - a]);
                    arr[x-b-i+k][y - a]='.';
                    k++;
                }
                doliczby.push_back(' ');
//                if (isdigit(arr[x - b - 1][y - a])) doliczby.push_back(arr[x - b - 1][y - a]);
//                doliczby.push_back(arr[x - b][y - a]);
//                if (isdigit(arr[x - b + 1][y - a])) doliczby.push_back(arr[x - b + 1][y - a]);
            }
        }
    }
    int suma=0;
    std::cout <<doliczby<<"\n";
    std::stringstream ss(doliczby);
    std::vector<std::string> v;
    while (getline(ss, doliczby, ' ')) {

        v.push_back(doliczby);
    }
    for (std::string liczba:v){
        suma+=stoi(liczba);
    }
    return suma;
}

int main() {

    std::ifstream MyReadFile("data.txt");
   char  a[1000][1000];
   std::vector<char> wekt;
   char b;
    int sum=0;

    while (MyReadFile.get(b)){
        wekt.push_back(b);
    }
    MyReadFile.close();
    int x=0,y=0;
    for (auto i:wekt){
        std::cout<<i;
        a[x][y]=i;
        if(int(i) == 10){
            y++;
            x=0;
            continue;
        }
        x++;
    }
    std::cout<<"\n"<<a[0][0]<<"\n";
    for(y=0;y<140;y++) {
        for (x = 0; x < 140; x++) {
            if((!isdigit(a[x][y])) && int(a[x][y]) != 46) {
               //std::cout<<a[x][y];
                sum+=liczby_przynalezne(x, y, a);
            }
        }
        //std::cout<<"\n";
    }
    std::cout << sum;
    return 0;

}
