#include <iostream>
#include <fstream>
#include <cmath>


using namespace std; 

int main(){

	double dt = 0.01;
	int tam = 101;
	double tmaximo = 2;
	double ep =  1;
	double dx = 0.01; 
	double b = (ep*dt)/ dx; 
	//double iter = tmaximo/dt;
    double presente [tam];
  	double futuro [tam];
  	double t = 0; 
    
	ofstream outfile;
	outfile.open("datos30.dat");


	//iniciales
	for(int i=0; i<tam; i++){
    	presente[i] = 0.05*sin( 4* M_PI * i/tam );
  	}


  	//iteraciones
  	while(t<tmaximo){

    	for(int j=0;j< tam ;j++){

        	futuro[j] = presente[j] - (b/4*( pow(presente[j+1],2) - pow(presente[j-1],2))) +  ((b*b/8) * ((presente[j+1] + presente[j])*( pow(presente[j+1],2) - pow(presente[j],2)) - (presente[j] + presente[j-1])*(pow(presente[j],2)-pow(presente[j-1],2))));
    }
  
     
    for(int i=0; i<tam; i++){

     	outfile << futuro[i] << " ";
    }
   
    	outfile << "\n";
    
    //actualizo datos
    for(int i=1;i< (tam-1) ;i++){

     		presente[i] = futuro[i];
    
    }
    
    t = t +dt; 

 	}



 	outfile.close();

	return 0; 

}