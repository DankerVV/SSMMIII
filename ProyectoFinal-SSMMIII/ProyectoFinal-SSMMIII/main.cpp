#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main(){
    float x[50],y[50],z,l, valor=0;
    int n, opc, aux;
    do{
        cout<<"Calculadora de Interpolación de Lagrange, elige una opción\n";
        cout<<"1)Calcular una interpolación\n";
        cout<<"0)Salir\n";
        cout<<"Ingrese su opción: ";
        cin>>opc;
        cout<<endl;
        switch(opc){
            case 1:
                cout<<"Ingrese el número de elementos de su tabla: "; cin>>n;
                for(int i=0; i<n; i++){
                    cout<<"Ingrese el valor de x"<< i <<": ";
                    cin>>x[i];
                }
                cout<<endl;

                for(int i=0; i<n; i++){
                    cout<<"Ingrese el valor de f(x"<< i <<"): ";
                    cin>>y[i];
                }
                cout<<endl;
                //Cuadro, a ver si me sale
                cout<< setw(10)<<"    Puntos";
                for(int i=0; i<n; i++){
                    cout<< setw(10) <<i;
                }
                cout<<endl;
                cout<<setw(10)<<"f(x)";
                for(int i=0; i<n; i++){
                    cout<<setw(10)<<y[i];
                }

                cout<<endl;
                cout<<setw(10)<<"x";
                for(int i=0; i<n; i++){
                    cout<<setw(10)<<x[i];
                }
                cout<<endl;

                cout<<endl<<"Ingrese el valor de x que desea interpolar: "; cin>>z;
                for(int i=0; i<n ;i++){
                    l=y[i];
                    for(int j=0; j<n; j++){
                        if(i!=j){
                            l=(l*(z-x[j]))/(x[i]-x[j]);
                        }
                    }
                    valor=valor+l;
                 }

                cout<<endl<<"El valor del polinomio de interpolación en x = "<< z <<" es: "<<valor<<endl<<endl;

                //Cuadro 2, a ver si me sale
                cout<< setw(10)<<"    Puntos";
                for(int i=0; i<=n; i++){
                    cout<< setw(10) <<i;
                }
                aux=-1;
                cout<<endl;//imprimir f(x)/////////////
                cout<<setw(10)<<"f(x)";
                for(int i=0; i<n; i++){
                    aux++;
                    if(y[i] > valor){
                        break;
                    }
                    cout<<setw(10)<<y[i];
                }
                cout<<setw(10)<<valor;
                for(int i=aux; i<n; i++){
                    cout<<setw(10)<<y[i];
                }
                cout<<endl;//imprimir x/////////////
                aux=-1;
                cout<<setw(10)<<"x";
                for(int i=0; i<n; i++){
                    aux++;
                    if(x[i] > z){
                        break;
                    }
                    cout<<setw(10)<<x[i];
                }
                cout<<setw(10)<<z;
                for(int i=aux; i<n; i++){
                    cout<<setw(10)<<x[i];
                }

                cout<<endl<<endl;
                break;

            case 0:
            {
                cout << "Gracias por usar el programa" << endl;
                break;
            }
            default:
            {
                cout << "Opción no válida, ingrese otro número" << endl;
                break;
            }
        }
    }
    while(opc!=0);
 }

