/*

Author: Jonathan Felix
Github: https://github.com/JonaThFelix

*/

#include <iostream>
using namespace std;

class Rainhas{
  public:
      int contador;
      int rainha[8];
      bool imprimeTabuleiros;
      
      Rainhas(){
             contador = 0;
             imprimeTabuleiros = false;
             
             
             rainha[0] = 0;
             for (int i = 1; i<8;i++){
                 rainha[i] = 8;
                 }
      }

void start(){
       char x;
       cout<<"\nDeseja visualizar o tabuleiro 8x8 ? (s/n)\n"<<endl;
       cin>>x;
       if (x == 's'){imprimeTabuleiros = true;}
       //inicio da busca      
       busca (rainha,0);
       //impressao do numero de solucoes
       cout << "Total de solucoes: " << contador << endl;
       }


void busca (int rainha[], int k)
{
	
	if (rainha[0]>7) return;

	if (rainha[k]>7)
	{

		k--; 
		rainha[k]++;
		busca(rainha, k);
	}
	

	if ((k==7)&&(funciona(rainha,k)))
	{

	   contador++; 
		impressao(rainha); 
		rainha[k]++;
		busca(rainha,k);
	}

 
	if (funciona(rainha,k)){
		k++;
		rainha[k]=0; 
	}
	else{
		rainha[k]++;
	}
	busca(rainha,k);
  }

private:          
bool funciona (int rainha[], int k)
{
	for (int i=0; i<k; i++){
		if (ataca(i, rainha[i], k, rainha[k])) return false;
    }
	return true;
}



void impressao(int rainha[])
{
   cout<<" Solucao Nº: \n"<<contador<<endl;
	for (int i=0; i<8; i++) cout << i + 1 << (1 + rainha[i]) << " | ";
	cout<<endl;
  
	char x ='n';

  
	if (imprimeTabuleiros){
	cout<<"Imprimir matriz (s/n)?"<<endl;
	cin>>x;
   }
	if (x =='s'){
      for (int i=0; i<8; i++){
          for (int j=0; j<8; j++){
              if (j == rainha[i]){
                 cout<<" O"; 
                 }
               else{
                    cout<<" x";
                    }  
          }
          cout<<endl;
      
          }
      cout << endl;
   }
}


bool ataca(int x1, int y1, int x2, int y2)
{
     if ((x1==x2)||(y1==y2)) return true;
     
     if (x1>x2){
		  if ((x1-x2 == y1-y2)||(x1-x2 == y2-y1)) return true;
       }
     if (x2>x1){
		if ((x2-x1 == y2-y1)||(x2-x1 == y1-y2)) return true;
    }
	
	return false;
}
};


int main()
{
   Rainhas r;
   r.start();
	system("pause");
	return EXIT_SUCCESS;
}
