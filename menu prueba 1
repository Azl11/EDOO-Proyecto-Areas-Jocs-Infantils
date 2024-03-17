// voy intentar hacer el menu mas o menos solo para tener una idea *^* casi todo son pegotes del trabajo pasado

void Colores();{
system("color E4");
}

void gotoxy(int x,int y){
    HANDLE consola; COORD posicion;
    consola = GetStdHandle(STD_OUTPUT_HANDLE);
    posicion.X= x; posicion.Y= y;
    SetConsoleCursorPosition(consola, posicion);
}

void Menu_Place(int & Opcion_Buscar_Parque,int & Opcion_Modificar, int & Opcion_Anadir,int & Opcion_Eliminar){
    gotoxy(1,2);cout<<"Escoja que valores quiere mostrar:\n\n\n"<<endl;
                cout<<" (a) Buscar parque deseado:\n"<<endl;
                cout<<" (b) Modificar datos parque:\n "<<endl;
                cout<<" (c) Anadir parque: \n"<<endl;
                cout<<" (d) Eliminar parque: \n"<<endl;
                cout<<"\n\n\n  Escoje una opcion: ";
                Pick(Opcion_Buscar_Parque,Opcion_Modificar,Opcion_Anadir,Opcion_Eliminar,0);

}


void Pick(int & Opcion_Buscar_Parque,int & Opcion_Modificar,int & Opcion_Anadir,int & Opcion_Eliminar ,int next){
    bool no_echo1 = false, no_echo2 = false, no_echo3 = false, no_echo4 = false;
    string data="inicial";
    if(next == 0){
        while(next==0){
            Opcion_Datos = getche();
            if(Opcion_Datos>=97 && Opcion_Datos<=100){
                next =1;
                system("cls");
                gotoxy(2,2);
               // aqui iria el subprograma de consultar parque;
            }
            else{
                next=0;
                gotoxy(2,16);cout<<"Escoje una opcion valida:  ";
                gotoxy(26,16);cout<<" ";
            }
        }
    }

// no hago mas pq tendriamos que tener los subprogramas primero creo tampoco la quiero liar xd
 
