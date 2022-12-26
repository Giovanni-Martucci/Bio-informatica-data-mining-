#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <map>


using namespace std;

int main() {
    map<string,int> gen;
    string ch,bh,ah; 
    int i=0; 

    ifstream List_of_patient("./segna_nome/nametocolumn.txt");
    ifstream List_of_Motif("./MultiMotif/map-all-Motif_Nodes-Motif_edges.txt");
    
    ofstream Matrix_to_File("./Matrix/Analysis_Matrix.txt");
    if(getline(List_of_Motif,bh)){
        gen[bh]=i;
        i++;
        Matrix_to_File <<'"' <<bh <<'"';
    }
    while(getline(List_of_Motif,bh)){
      gen[bh]=i;
      i++;
      Matrix_to_File <<"\t" <<'"' <<bh <<'"' ;
    }
    Matrix_to_File <<endl;

    int cont = 1;
    cout <<endl <<endl <<"List of patient:" <<endl;
    int ind=0;
    while(getline(List_of_patient, ah)){
        string *motif = new string[1726];
        for(int i=0;i<1726;i++){
            motif[i]="0";
        }
        cout <<cont <<") " <<ah <<";" <<endl;
        Matrix_to_File <<'"' <<ah <<'"';
        cont++;
        
        
        int first=0;
        string dh;
        int found=0;
        ifstream Motif_patient("./MultiMotif/motif/motif-" + ah + ".txt");
        while(getline(Motif_patient,dh)){
            if(first==0) first++;
            else {
                ofstream File_temp("./Matrix/file_temp.txt"); 
                File_temp <<dh <<endl;
                ifstream File_temp_read("./Matrix/file_temp.txt");
                string eh, key,value, score;
                int p=0;
                while(getline(File_temp_read, eh, '\t') && p<3){
                    if(p==2){
                        value=eh;
                        break;
                    }
                    if(p==1){
                        key+="-";
                    }
                    key+=eh;
                    p++;
                }
                
                ind=gen.find(key)->second;
                motif[ind]=value;
            }
                
        }
        for(int k=0;k<1726;k++){
            Matrix_to_File <<"\t" <<motif[k];
        } 
        Matrix_to_File <<endl;

        
    }
    
    
    
}
