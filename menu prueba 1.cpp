#include <iostream>
using namespace std;


void MENU(){
cout<<"|-------------------------------------------------------------------------|"<<endl;
cout<<"Escull una opcio:\n" <<endl;
cout<<"(1): Consultar informacio parc \n"<<endl;
cout<<"(2):Modificar Informacio parc \n"<<endl;
cout<<"(3):Eliminar Parc/Objecte \n"<<endl;
cout<<"(4):Afegir Parc/Objecte \n"<<endl; 
cout<<"(5):Comparar Parcs \n"<<endl;
cout<<"(6):Identificar Parcs en zona\n"<<endl;
cout<<"|-------------------------------------------------------------------------|"<<endl;    
}

void Repetir(int OPb){

cin>>OPb;
selecM1(int OPb);
}

void selecM1(int OP){
switch (OP){
case 1: cout<<"Consulta informacio de parc escollida! "<<endl;
    //aqui iria un subprograma para esta opcion
    break;
case 2: cout<<"Modificar Informacio parc escollida! "<<endl;
     //aqui iria un subprograma para esta opcion
    break;
case 3: cout<<" Eliminar Parc/Objecte escollida! "<<endl;
     //aqui iria un subprograma para esta opcion
    break;
case 4: cout<<"Afegir Parc/Objecte escollida! "<<endl;
     //aqui iria un subprograma para esta opcion
    break;
case 5: cout<< " Comparar parcs escollida! "<<endl;
     //aqui iria un subprograma para esta opcion
    break;
case 6: cout<<" Identificar Parcs en zona escollida! "<<endl;
     //aqui iria un subprograma para esta opcion
    break;
    default:
      cout<<"Elije una opcion del menu!!! "<<endl;
        Repetir(OPb);
        break;
}





int main(){
int opcion;
MENU();
selecM1(opcion);



    
}
