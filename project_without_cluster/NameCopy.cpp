#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
  ifstream OpenMainFile("signature_Main_Classification.txt");
  ofstream File_Destinazione("./segna_nome/nametocolumn.txt");
  string hh,gh,dh,ch,bh,ah,person;
  int n=0;

  int num_p=0;

  while(getline(OpenMainFile,ch)){
    
      if(n==0){
        ofstream OutputGeniFile("./segna_nome/geni.txt");
        OutputGeniFile <<"Name" <<"\t" <<ch <<endl;
      }
      else {
        ifstream OpenGeniFile("./segna_nome/geni.txt");
        ofstream OutputRowFile("./segna_nome/riga.txt");

        OutputRowFile <<ch <<endl; 
        ifstream OpenRowFile("./segna_nome/riga.txt");
        int primo=0;
        while(getline(OpenGeniFile, bh , '\t') && getline(OpenRowFile, ah, '\t')){
              if(primo==0){
               person = ah;
               primo=1;
               cout <<"[*] - " <<++num_p <<") " <<person <<endl;
               File_Destinazione <<person <<endl;
              }            
        }               
      }
      n=1;                                            
  }
}
