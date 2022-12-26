#include <fstream>
#include <iostream>
#include <string>
#include <sstream>



using namespace std;

int main() {
  
  ifstream OpenFile("clinical.txt");
    int m=0;
  string ch;
  while(getline(OpenFile,ch)){
      int n=0;
      m++;
      ofstream OutputFile("../clinical_cont.txt");
      OutputFile <<ch <<endl;
      ifstream OpenFile("../clinical_cont.txt");
      string bh;
      while(getline(OpenFile,bh,'\t')){
          n++;
      }
      cout <<endl <<m <<") " <<n <<endl;

  }
}
