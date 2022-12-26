#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

int main() {
    map<string,string> type_of_tumor;
    
    ifstream OpenFile("clinical.txt");
    string ch;
    int first=0;
    while(getline(OpenFile,ch)) {
        if(first==0) first++;
        else {
            ofstream file_temp("temporal_file_of_tumor.txt");
            file_temp <<ch <<endl;
            ifstream file_temp_read("temporal_file_of_tumor.txt");
            string bh,str;
            int n=0;
            while(getline(file_temp_read,bh,'\t')) {
                n++;
                if(n==10){
                    str=bh;
                    break;
                }
            }
            if(type_of_tumor.count(str)>0){}
            else {
                type_of_tumor[str]= str;
                cout <<"[*] - Aggiungo " <<str << " dentro map..." <<endl;
            }
        }
    }
    
    first=0;
    ofstream map_k_tumor("number-subtumor_for_tumor.txt");
    ofstream map_tumor_subtumor("map_subtumor_tumor.txt");
    for(auto i : type_of_tumor){
        ifstream OpenNewFile("clinical.txt");
        map<string,string> sub_tumor;
        map<string,int> tumor;
        int num=0;
        while(getline(OpenNewFile,ch)){
            int n=0;
            if(first==0) first++;
            else {
                ofstream file_temporal("temp_file_of_tumor.txt");
                file_temporal <<ch <<endl;
                ifstream file_temporal_read("temp_file_of_tumor.txt");
                string ah;
                while(getline(file_temporal_read,ah,'\t')){
                    n++;
                    if(n==10 && i.first!=ah){
                        break;
                    }
                    if(n==38){
                        if(sub_tumor.count(ah)>0){}
                        else {
                            if(ah=="NA") break; //tramite questa riga non prenderà quelli nulli e non analizzerà di conseguenza 6 tumori: "DLBC" - "KICH" - "KIRC" - "LUSC" - "MESO" - "PAAD"
                            sub_tumor[ah]=i.first;
                            num++;
                            tumor[i.first]= num;
                            cout <<"[*] - Aggiungo " <<ah << " dentro la map di " <<i.first  <<endl;
                        }
                        break;
                    }
                    
                }
            }
            
        }
        num=0;
        for(auto i : tumor){
            map_k_tumor <<i.first <<": " <<i.second <<endl;
        }
        for(auto i : sub_tumor){
            map_tumor_subtumor <<i.first <<": " <<i.second <<endl;
        }
    }
    
    
    
    
    remove("temporal_file_of_tumor.txt");
    remove("temp_file_of_tumor.txt");
}


