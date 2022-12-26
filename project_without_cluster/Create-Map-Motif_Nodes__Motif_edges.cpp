#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <map>


using namespace std;


int main() {
    map<string, string> Motif_Nodes__Motif_edges;
    
    ifstream List_of_patient("./segna_nome/nametocolumn.txt");
    string ch;
    while(getline(List_of_patient, ch)){
        string bh;
        int first=0;
        ifstream Motif("./MultiMotif/motif/motif-" + ch + ".txt");
        while(getline(Motif, bh)){
            if(first==0) first=1;
            else {
                ofstream File_temp("./MultiMotif/file_temp.txt"); //copio ogni riga cosi da lavorarci sopra ed estrarre i valori interessati, ovvero poter usare i primi 3 elementi
                File_temp <<bh <<endl;
                ifstream File_temp_read("./MultiMotif/file_temp.txt");
                string ah, key,value, score;    
                int p=0;
                while(getline(File_temp_read, ah, '\t') && p<2){
                    if(p==1){
                        key+="-";
                    }
                    key+=ah;
                    p++; 
                }
                
                if(Motif_Nodes__Motif_edges.count(key)>0){}
                else {
                    Motif_Nodes__Motif_edges[key]= key;
                    cout <<"[*] - Aggiungo " <<key << " dentro map..." <<endl;
                }
                
                
            }
        }
        
    }
    //Qui avrò una mappatura di tutti i tipi di "Motif_Nodes-Motif_edges" presenti tra tutti i pazienti
        ofstream Mappatura("./MultiMotif/map-all-Motif_Nodes-Motif_edges.txt");
        for(auto i : Motif_Nodes__Motif_edges){
            Mappatura <<i.second <<endl;
        }
        remove("./MultiMotif/file_temp.txt");

}
