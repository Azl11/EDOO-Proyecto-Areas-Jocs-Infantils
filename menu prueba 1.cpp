int main()
{
    system("color E0");

    bool t = true, y = true;
    int x;

    ifstream Data("DATA.txt");
    Parques_Barna P(Data);

    while(t)
    {
        cout<<endl;
        cout<<" |-------------------------------------------------------------------------|"<<endl;
        cout<<" Escull una opcio valida:\n" <<endl;
        cout<<" (1): Consultar informacio parc \n"<<endl;
        cout<<" (2):Modificar Informacio parc \n"<<endl;
        cout<<" (3):Eliminar Parc/Objecte \n"<<endl;
        cout<<" (4):Afegir Parc/Objecte \n"<<endl;
        cout<<" (5):Sortir del programa \n"<<endl;
        cout<<" |-------------------------------------------------------------------------|"<<endl<<endl;
        cout<<" ";cin>> x;
        switch (x)
        {
        case 1:
            while(y){
                system("cls");
                cout<<endl;
                cout<<" |-------------------------------------------------------------------------|"<<endl;
                cout<<" Escull una opcio valida:\n" <<endl;
                cout<<" (1):Busqueda per ID \n"<<endl;
                cout<<" (2):Busqueda per Nom del Barri \n"<<endl;
                cout<<" (3):Busqueda per Nom del Districte \n"<<endl;
                cout<<" (4):Busqueda per Codi Postal \n"<<endl;
                cout<<" (5):Busqueda per Edat \n"<<endl;
                cout<<" (6):Tornar enrera \n"<<endl;
                cout<<" |-------------------------------------------------------------------------|"<<endl<<endl;
                cout<<" ";cin>> x;
                switch(x)
                {
                case 1:

                    break;
                case 2:

                    break;
                case 3:

                    break;
                case 4:

                    break;
                case 5:

                    break;
                case 6:
                    system("cls");
                    main();
                }
            }

            break;
        case 2:
            P.Edit();
            break;
        case 3:
            P.Delete();
            break;
        case 4:
            P.Add();
            break;
        case 5:
            return 0;
        default:
            main();
            break;
        }
    }
}
