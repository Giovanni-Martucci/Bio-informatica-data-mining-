#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <map>


using namespace std;

int main() {
  //Apro in lettura il file principale
  ifstream OpenMainFile("signature_Main_Classification.txt");

  string hh,gh,dh,ch,bh,ah,person;
  int n=0;

  int num_p=0;
  //Leggo riga x riga il file principale
  while(getline(OpenMainFile,ch)){
    map<string, string> geni;
      if(n==0){
        //Genero, solo una volta, il file dei geni presenti nel file principale.
        ofstream OutputGeniFile("./reti-pazienti/geni.txt");
        OutputGeniFile <<"Name" <<"\t" <<ch <<endl;
      }
      else {
        //Dalla seconda volta in poi entrerà sempre qui,
        ifstream OpenGeniFile("./reti-pazienti/geni.txt");
        ofstream OutputRowFile("./reti-pazienti/riga.txt");

        OutputRowFile <<ch <<endl;
        ifstream OpenRowFile("./reti-pazienti/riga.txt");
        int primo=0;
        //Per ogni gene assegno il corrispettivo valore , per ogni singolo paziente
        while(getline(OpenGeniFile, bh , '\t') && getline(OpenRowFile, ah, '\t')){
              if(primo==0){
                //Prendo il nome del paziente, essendo la prima parola di ogni riga.
               person = ah;
               primo=1;
               cout <<"[*] - " <<++num_p <<") " <<person <<endl;
              }
              geni[bh]= ah; //map del gene-valore 
            
        }
        

        int inside=0;
        ifstream OpenNodesFile("./MetaPathway/meta_nodes.txt");
        ofstream OutputNodes("./reti-pazienti/risultati-map/nodes-"+person+".txt");
        ofstream PPUPNP("./reti-pazienti/PPUPNP.txt");
        PPUPNP <<"directed" <<endl <<"3913" <<endl;
        while(getline(OpenNodesFile, gh)){//per ogni gene atteso
          inside=0;
          for(auto i : geni){
               if(i.first=='"'+gh+'"'){ //se per ogni gene richiesto(gh) esiste un chiave nella map ,allora li segna ed esegue il calcolo
                 OutputNodes <<i.first <<" = " <<i.second <<endl;
                 stringstream invert(i.second); 
                 double x = 0; 
                 invert >> x; 
                 if(x>0){
                   PPUPNP <<"PP" <<endl ;
                 }
                 else if(x<0){
                   PPUPNP <<"NP" <<endl ;
                 }
                 else if(x==0) {
                   PPUPNP <<"UP" <<endl ;
                 }
                 inside=1;
                 break;
               }                                                
          }
          if(inside==0){//se non vi è presente il gene richiesto nella map ,settalo a 0 
            OutputNodes <<'"'+gh+'"' <<" = 0" <<endl;
            PPUPNP <<"UP" <<endl ;
          }
          
        }
        ifstream Meta_net("./MetaPathway/meta_net.txt"); //copio il file meta_net sotto ogni meta_pathway dei pazienti
        while(getline(Meta_net,hh)){
          PPUPNP <<hh <<endl;
        }
                        
      }

      n=1;
      ofstream Output("./reti-pazienti/risultati-ppupnp/"+person+".txt");
      ifstream upppnp("./reti-pazienti/PPUPNP.txt");
      while(getline(upppnp,gh)){ //Copio il risultato del singolo paziente nel suo file di destinazione.
        Output <<gh <<endl;
      }                                              
      geni.clear();
  }


}
