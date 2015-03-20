#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>        
#include <ctime>
#include <sstream>
#include <string>
#include <vector>
#include <time.h>



using namespace std;

std::string fechaHora()   // Funcion que retorna la fecha y hora por sistema.
{
     string dS[7] = {"Domingo","Lunes","Martes","Miercoles", "Jueves","Viernes","Sabado"}; //Arreglo estatico de String
     time_t tSac = time(NULL); // Instante actual 
 
     struct tm* tmP = localtime(&tSac); 

     std::stringstream ss;
     ss << tmP->tm_year+1900 << "-" << tmP->tm_mon+1 << "-" << tmP->tm_mday <<" "<< tmP->tm_hour << ":" << tmP->tm_min << ":" << tmP->tm_sec;
     std::string s = ss.str();
     return s; //Retornamos la fecha y hora como String
}

string genumal(int max,int gen){  // Generar "gen" números aleatorios entre 0 y "max"
   vector<int> num;
   string numazar;
   stringstream out;
   // Llenar el vector con los numeros del minimo al máximo
   for(int i=1;i<max;i++){
          num.push_back(i);
       }
   // Generamos los numeros
   for(int i=1;i<=gen;i++){
      if(num.size()>0){
		  /* Generar una posición en el vector de números
             * y coger el número de aquella posicion y borrarlo
             * para que no vuelva a aparecer más.
             */
          int indice = rand()%num.size();
          out<<";"<<num[indice]; // Separamos con ";" los numeros aleatorios generados
          numazar=out.str();
          num.erase(num.begin()+indice);
          }
      }
      return numazar; //Retornamos los numeros aleatorios
}

int main()
{
    const time_t timer = time(NULL); 
    ofstream entrada; // Referenciamos la entrada de datos a un fichero
 
    char selection,v,g;
    string aux= fechaHora();  //Almacenamos Fecha y Hora del sistema
     srand(time(0));

    do
    {
        cout << "  Programa Qno!!!\n";
        cout << "  ====================================\n";
        cout << "  g.  Ingrese una simulacion (Qno) al fichero\n";
        cout << "  v.  Integrantes y fecha de compilacion\n";
        cout << "  ====================================\n";
        cout << "  Ingrese una Opcion: ";
        cin >> selection; //Almacenamos la opcion elegida por el usuario
        cout << endl;
        
       
   

        switch (selection)
        {
            case 'g':
                 entrada.open("Fichero.csv", ios::app);  //Creamos el fichero con extension csv
                 if(entrada.fail()){
                 cout<<"ocurrio un error al abrir o crear el fichero";
                 return 1;
                 } 
                 else
                 entrada<<fechaHora()<<genumal(25,14)<<endl; //Almacenamos en el fichero la fecha, hora y los numeros aleatorios generados
                 entrada.close(); // Cerramos el fichero
                 break;
                
            case 'v':
                 cout<<"+-------------------------------------------------------------------------+"<<endl;                  
                 cout<<"|  INTEGRANTES                                                            |"<<endl;
                 cout<<"+-------------------------------------------------------------------------+"<<endl;
                 cout<<"| Franco Morales Barcelo.                                                 |"<<endl;
                 cout<<"| Cesar Miranda Guajardo.                                                 |"<<endl;  
                 cout<<"| Cristobal Herrera Fuenzalida.                                           |"<<endl;            
                 cout<<"+-------------------------------------------------------------------------+"<<endl;
                 cout << "Fecha y Hora del Sistema: "<<aux<<endl;
                 return 0;
                 break;    
            
}   
                
                
}while (selection != 3);
}
