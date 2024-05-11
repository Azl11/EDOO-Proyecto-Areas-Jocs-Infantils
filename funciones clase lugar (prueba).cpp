aqui ire poniendo cositas mientras hago lo mio

// funcion para bucar  lugar con id

--------------------la función 
int Search() {         
        int searchId;
        cout << "Inserta el ID del lugar que quieres buscar: ";
        cin >> searchId;
        int index = SearchLugar(searchId);
        if (index != -1) {
            cout << "Lugar encontrado: " << endl;
            cout << Lug[index]; 
        } else {
            cout << "El lugar con el ID " << searchId << " no fue encontrado." << endl;
        }
        return index;
    }
----------------------- el subprograma SearchLugar
int SearchLugar(int searchId) {
        for (int i = 0; i < Lug.size(); ++i) {
            if (Lug[i].getAJ_Id() == searchId) {
                return i; 
            } }
----------------------------clase lugar con sus nuevas funcionalidades

 bool operator==(const Lugar& otro) const {    //compara id de lugares 

        return this->AJ_Id == otro.AJ_Id;}

    void editarLugar(const Lugar& nuevoLugar) {       //para editar el lugar 

        this->Codi_V = nuevoLugar.Codi_V;
        this->Codi_D = nuevoLugar.Codi_D;
        this->Codi_B = nuevoLugar.Codi_B;
        this->Num_P = nuevoLugar.Num_P;
        this->Nom_V = nuevoLugar.Nom_V;
        this->Nom_D = nuevoLugar.Nom_D;
        this->Nom_B = nuevoLugar.Nom_B;
        this->Tipus_V = nuevoLugar.Tipus_V;
        this->Long = nuevoLugar.Long;
        this->Lat = nuevoLugar.Lat;
    }



--------------------------------- menu del lugar y para consultar sus funciones


       void mostrarMenuLugar() {

int opcion,codigoID;
    cout << "Menú de clase lugar :" << endl;
    cout << "1. Mostrar información del lugar" << endl;
    cout << "2. Editar información del lugar" << endl;
    cout << "3. Salir" << endl;
    cout << "Seleccione una opción: ";

cin >> opcion;
        switch (opcion) {
            case 1:
                cout<<"Introduzca el ID del parque: "<<endl;
                cin>>codigoID;
                 Lug.Search(codigoID);
                break;
            case 2:
                Lug.editarLugar(lugar);
                break;
            case 3:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción no válida. Inténtelo de nuevo." << endl

------------------------------------------------------



 void buscarPorIDLugar() {


 int id,Buscador,aux;
system("Color E9");system("cls");

        cout << "Introduce el ID del lugar: ";
        cin >>id;
        Buscador=Comparator(0,VPS.size(),id);


   if(Buscador != -1)
            {
                cout << "Los datos del lugar con ID " << id << " son los siguientes: " << endl;
                  cout<<VPS[Buscador]<<endl;}

            else {
        cout << "No se encontro ningun lugar con el ID especificado." << endl;
    }
                        
                        
                        
    
}


void BuscarPorDistrito() {
    system("Color E9");
    system("cls");
    Sorting();
    int aux=0,u=1;
    string nDistrito;
    bool encontrado=false;
    cout << "Introduce el nombre del distrito para ver los parques que hay: " << endl;
    cout << "Ejemplo: Sant_Marti" << endl;
    cin >> nDistrito;

    for (int i = 0; i < VPS.size(); i++) {

        if (nDistrito == VPS[i].getLUG().getNom_D()) {

            cout << "ID del parque num "<<u<<" en el distrito " << VPS[i].getLUG().getAJ_Id() << endl;
            u++;
             aux++;

        }

        }

        cout<<" hay un total de "<<aux<<" parques!!!!"<<endl;
    }

    
}


 void BuscarPorBarrio() {
    system("Color E9");
    system("cls");
    Sorting();
    int aux=0,u=1;
    string nBarrio;
    bool encontrado=false;
    cout << "Introduce el nombre del barrio para ver los parques que hay: " << endl;
    cout << "Ejemplo: la_Verneda_i_la_Pau" << endl;
    cin >> nBarrio;

    for (int i = 0; i < VPS.size(); i++) {

        if (nBarrio == VPS[i].getLUG().getNom_B()) {

            cout << "ID del parque num "<<u<<" en el barrio " << VPS[i].getLUG().getAJ_Id() << endl;
            u++;
             aux++;

        }

        }

        cout<<" hay un total de "<<aux<<" parques!!!!"<<endl;
    }



void buscarPorEdad(const Parques_Barna &PB) {
    int edad;
    cout << "Introduce la edad: ";
    cin >> edad;
   
}


void menuPrincipal(const Parques_Barna &PB) {
    char opcion;
    while (true) {
        cout << "Menú Principal" << endl;
        cout << "1. Buscar por ID de lugar" << endl;
        cout << "2. Buscar por distrito" << endl;
        cout << "3. Buscar por barrio" << endl;
        cout << "4. Buscar por edad" << endl;
        cout << "5. Salir" << endl;
        cout << "Elige una opción: ";
        cin >> opcion;

        switch (opcion) {
            case '1':
                buscarPorIDLugar(PB);
                break;
            case '2':
                buscarPorDistrito(PB);
                break;
            case '3':
                buscarPorBarrio(PB);
                break;
            case '4':
                buscarPorEdad(PB);
                break;
            case '5':
                cout << "Saliendo..." << endl;
                return;
            default:
                cout << "Opción inválida. Inténtalo de nuevo." << endl;
        }
    }
}


int main() {
    ifstream Data("DATA.txt");
    Parques_Barna PB(Data);
    menuPrincipal(PB);
    return 0;
}

    
