#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <map>


using namespace std;

int main() {
  
 

  ifstream OpenMainFile("signature_Main_Classification.txt");
  ofstream WriteMainFile("./reti-pazienti/duerighe.txt");
  ofstream WritesecondFile("./reti-pazienti/secondariga.txt");

  string ch,bh,ah;
  int num_p=0;
  int n=0;
  int m=0;
  int b=0;
  int a=0;
  while(getline(OpenMainFile,ch) && num_p<2){
    if(b==1){
      WritesecondFile <<ch <<endl;
    }
    num_p++;
    if(b==0){
    WriteMainFile <<ch <<endl;}
     b=1;
  }
  ifstream OpenFile("./reti-pazienti/duerighe.txt");
  
  while(getline(OpenFile,ch,'\t')){
    n++;
  }
  ifstream OpensecondFile("./reti-pazienti/secondariga.txt");
  while(getline(OpensecondFile,bh,'\t')){
    m++;
  }
  ifstream OpenNodesFile("./MetaPathway/meta_nodes.txt");
  while(getline(OpenNodesFile,ah)){
    a++;
  }
  cout <<"Numeri geni: " <<n <<"\tNumero elem paziente: " <<m <<"\tNumero geni inte: " <<a <<endl;


}
