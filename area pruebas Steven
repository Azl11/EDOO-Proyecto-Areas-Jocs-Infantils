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


   void Parques_Barna::editarLugar(int id) {
    int index = -1;
    for (int i = 0; i < Lug.size(); ++i) {
        if (Lug[i].getAJ_Id() == id) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        editarLugar(Lug[index]);
    } else {
        cout << "No se encontró ningún lugar con el ID especificado." << endl;
    }
}

void editarLugar(Lugar &lugar) {
    int opcion;
    cout << "¿Qué atributo desea editar?" << endl;
    cout << "1. Código de la vía" << endl;
    cout << "2. Código del distrito" << endl;
    cout << "3. Código del barrio" << endl;
    cout << "4. Número postal" << endl;
    cout << "5. Nombre de la vía" << endl;
    cout << "6. Tipo de vía" << endl;
    cout << "7. Longitud" << endl;
    cout << "8. Latitud" << endl;
    cout << "9. Volver al menú anterior" << endl;
    cout << "Seleccione una opción: ";
    cin >> opcion;
    switch (opcion) {
        case 1:
            cout << "Nuevo código de la vía: ";
            int nuevoCodigoVia;
            cin >> nuevoCodigoVia;
            lugar.setCodi_V(nuevoCodigoVia);
            break;
        case 2:
            cout << "Nuevo código del distrito: ";
            int nuevoCodigoDistrito;
            cin >> nuevoCodigoDistrito;
            lugar.setCodi_D(nuevoCodigoDistrito);
            break;
        case 3:
            cout << "Nuevo código del barrio: ";
            int nuevoCodigoBarrio;
            cin >> nuevoCodigoBarrio;
            lugar.setCodi_B(nuevoCodigoBarrio);
            break;
        case 4:
            cout << "Nuevo número postal: ";
            int nuevoNumeroPostal;
            cin >> nuevoNumeroPostal;
            lugar.setNum_P(nuevoNumeroPostal);
            break;
        case 5:
            cout << "Nuevo nombre de la vía: ";
            string nuevoNombreVia;
            cin >> nuevoNombreVia;
            lugar.setNom_V(nuevoNombreVia);
            break;
        case 6:
            cout << "Nuevo tipo de vía: ";
            string nuevoTipoVia;
            cin >> nuevoTipoVia;
            lugar.setTipus_V(nuevoTipoVia);
            break;
        case 7:
            cout << "Nueva longitud: ";
            string nuevaLongitud;
            cin >> nuevaLongitud;
            lugar.setLong(nuevaLongitud);
            break;
        case 8:
            cout << "Nueva latitud: ";
            string nuevaLatitud;
            cin >> nuevaLatitud;
            lugar.setLat(nuevaLatitud);
            break;
        case 9:
            break;
        default:
            cout << "Opción no válida. Inténtelo de nuevo." << endl;
            break;
    }
}

    
