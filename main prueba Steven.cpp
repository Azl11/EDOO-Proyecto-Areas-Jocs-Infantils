void BuscarPorEdad() {
    system("Color E9");
    system("cls");
    Sorting();
    int aux = 0, u = 1, opcion;
    string nDistrito;
    bool encontrado = false;
    cout << endl;
    cout << "Ver la ID de los parques que hay por franja de edad " << endl;
    cout << endl;
    cout << "(1) FINS_A_5_ANYS  " << endl;
    cout << endl;
    cout << "(2) DE_6_A_12_ANYS " << endl;
    cout << endl;
    cout << "(3) MIXTA " << endl;
    cout << endl;
    cin >> opcion;

    switch (opcion) {
        case 1: {
            string uno = "FINS_A_5_ANYS";
            for (int i = 0; i < VPS.size(); i++) {
                if (uno == VPS[i].getVObj(0).getAJ_Edat()) {
                    cout << "ID del objeto num " << u << " de franja de edad " << uno << " " << VPS[i].getLUG().getAJ_Id() << endl;
                    u++;
                    aux++;
                }
            }
            cout << "hay un total de " << aux << " objetos!!!!" << endl;
            break;
        }
        case 2: {
            string dos = "DE_6_A_12_ANYS";
            for (int i = 0; i < VPS.size(); i++) {
                if (dos == VPS[i].getVObj(0).getAJ_Edat()) {
                    cout << "ID del objeto num " << u << " de franja de edad " << dos << " " << VPS[i].getLUG().getAJ_Id() << endl;
                    u++;
                    aux++;
                }
            }
            cout << "hay un total de " << aux << " objetos!!!!" << endl;
            break;
        }
        case 3: {
            string tres = "MIXTA";
            for (int i = 0; i < VPS.size(); i++) {
                if (tres == VPS[i].getVObj(0).getAJ_Edat()) {
                    cout << "ID del objeto num " << u << " de franja de edad " << tres << " " << VPS[i].getLUG().getAJ_Id() << endl;
                    u++;
                    aux++;
                }
            }
            cout << "hay un total de " << aux << " objetos!!!!" << endl;
            break;
        }
        default:
            cout << "Opción no válida." << endl;
            break;
    }
}

