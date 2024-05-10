
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;
//Classe Data
class Data{

    int dia, mes, any;

    //Comprovar si la data pertany a un any bissest. Mètode privat. S'utilitza només en la classe
    //Hi ha un altre mètode public amb el mateix nom però sense el paràmetre any.
    bool de_traspas(int any) {
        return ((any % 4 == 0 && any % 100 != 0) or any%400 == 0);
    }

    //Consultar dies d'un mes i any donats. Mètode privat. S'utilitza només en la classe
    int dias_mes(int mes, int any) {
        int dies = 31;
        if (mes == 4 or mes == 6 or mes == 9 or mes == 11) {
            dies = 30;
        }
        else if (mes == 2) {
            if (de_traspas(any) == true) {
                dies = 29;
            }
            else {
                dies = 28;
            }
        }
        return dies;
    }

public:

    //Constructor per defecte amb la data actual, que dóna el sistema, llibreria time.h
    Data(){
        time_t t; //time_t és una tupla de temps (dia, mes any, hora, mins, segs) definit en time.h
        time( &t );
        struct tm* info = localtime( &t );
        dia = info -> tm_mday;
        mes = info -> tm_mon + 1;
        any = 1900+ info -> tm_year; // l'any es comença a comptar a partir del 1900
    }

    //Constructor amb tres paràmetres enters
    Data(int d, int m, int a){
        dia=d;
        mes=m;
        any=a;
    }

    //Constructor amb un paràmetre enter ddmmaaaa
    Data(int ddmmaaaa){
        dia=ddmmaaaa/1000000;
        mes=(ddmmaaaa/10000)%100;
        any=ddmmaaaa%10000;
    }

    //Constructor amb un paràmetre string en format dd:mm:aaaa o dd-mm-aaaa
    //stoi és una funció per converir un string (p.ex "12") en un enter (p.ex. 12)
    Data(string sd){
        string c1 = sd.substr (0,2);//el string dels caràcters dd
        dia=stoi(c1);
        string c2 = sd.substr (3,2);//el string dels caràcters mm
        mes=stoi(c2);
        string c3 = sd.substr (6); //el substring de la 6à posició fins al final
        any=stoi(c3);
    }

    //Mètodes consultors
    int getDia(){
        return dia;
    }
    int getMes(){
        return mes;
    }
    int getAny(){
        return any;
    }

    //Comprovar si la data que s'està construïnt es d'un any de traspàs
    bool de_traspas() {
        return ((any % 4 == 0 && any % 100 != 0) or any%400 == 0);
    }

    //Mètodes modificadors. Se suposa que d, m i a són vàlids
    void setDia (int d){
        dia=d;
    }
    void setMes (int m){
        mes=m;
    }
    void setAny (int a){
        any=a;
    }

    //Incrementar la data amb una quantitat de dies
    void incrementaData (int dd){
        dia=dia+dd;
        if (dia > dias_mes(mes, any)) {
            dia = dia-dias_mes(mes,any);
            mes++;
            if (mes > 12) {
                mes = 1;
                any++;
            }
        }
    }

    //Comparar dues dates <
    friend bool operator < (Data& d1, Data& d2)
    {
        return (d1.any*10000+d1.mes*100+d1.dia < d2.any*10000+d2.mes*100+d2.dia);
    }

    //Comparar dues dates ==
    friend bool operator == (Data& d1, Data& d2)
    {
        return (d1.any*10000+d1.mes*100+d1.dia == d2.any*10000+d2.mes*100+d2.dia);
    }


    //Escriure una data per canal de sortida dd/mm/aaaa
   friend ostream& operator << (ostream& os, Data d)
    {
        os << "Data: ";
        if (d.dia < 10){
            os << "0";
        }
        os << d.dia <<"/";

        if (d.mes < 10){
            os << "0";
        }
        os<< d.mes << "/" << d.any<<endl;

        return os;
    }

};
typedef vector<string> VStr;

///-----------------------------------> CLASSE

class ObjetoParque
{ 
    private:

    int AJ_Id , AJ_Edat_Id; //Area de Joc Id , Area de Joc M2 , Area de Joc Edat Id
    string AJ_Edat ; //Area de Joc Edat
    string Codi , Tipus; //Codi , Tipus d'objecte
    double AJ_M2;
    vector<int> v_AJ_Id;
    vector<int> v_AJ_Edat_Id;
    public:

///--------------------------------> CONSTRUCTORS

    ObjetoParque(){}

    ObjetoParque(int AJ_Id , double AJ_M2 , int AJ_Edat_Id, string AJ_Edat , string Codi , string Tipus, int v_AJ_Edat_Id, int v_AJ_Id)
    {
    this -> AJ_Id = AJ_Id;
    this -> AJ_M2 = AJ_M2;
    this -> AJ_Edat_Id = AJ_Edat_Id;
    this -> AJ_Edat = AJ_Edat;
    this -> Codi = Codi;
    this -> Tipus = Tipus;
    this-> v_AJ_Id = v_AJ_Id;
    this-> v_AJ_Edat_Id = v_AJ_Edat_Id;
    }

                ///CONSTRUCTOR CÒPIA

    ObjetoParque(const ObjetoParque & Obj)
    {
    AJ_Id = Obj.AJ_Id;
    AJ_M2 = Obj.AJ_M2;
    AJ_Edat_Id = Obj.AJ_Edat_Id;
    AJ_Edat = Obj.AJ_Edat;
    Codi = Obj.Codi;
    Tipus = Obj.Tipus;
    v_AJ_Id = Obj.v_AJ_Id;
    v_AJ_Edat_Id = Obj.v_AJ_Edat_Id;
    }

///---------------------------------------------------> METODES

                    ///METODES GET

    int getAJ_Id()const{return AJ_Id;}
    double getAJ_M2()const{return AJ_M2;}
    int getAJ_Edat_Id()const{return AJ_Edat_Id;}
    string getAJ_Edat()const{return AJ_Edat;}
    string getCodi()const{return Codi;}
    string getTipus()const{return Tipus;}

                    ///METODES SET

    void setAJ_Id(int AJ_Id){this -> AJ_Id = AJ_Id;}
    void setAJ_M2(double AJ_M2){this -> AJ_M2 = AJ_M2;}
    void setAJ_Edat_Id(int AJ_Edat_Id){this -> AJ_Edat_Id = AJ_Edat_Id;}
    void setAJ_Edat(string AJ_Edat){this -> AJ_Edat = AJ_Edat;}
    void setCodi(string Codi){this -> Codi = Codi;}
    void setTipus(string Tipus){this -> Tipus = Tipus;}

                    ///OPERADOR COUT

friend ostream & operator <<(ostream & os , const ObjetoParque & Obj)
{
    os<<"-------------------------------"<<endl;
    os<<"Area de Jocs ID: "<< Obj.AJ_Id<<endl;
    os<<"Area de Jocs M2: "<< Obj.AJ_M2<<endl;
    os<<"Area de Jocs Edat ID: "<< Obj.AJ_Edat_Id<<endl;
    os<<"Area de Jocs Edat: "<< Obj.AJ_Edat<<endl;
    os<<"Codi: "<< Obj.Codi<< endl;
    os<<"Tipus: "<< Obj.Tipus<< endl;

    return os;
}

};

typedef vector<ObjetoParque> VOP;

///--------------------------------------------> CLASSE

class Lugar
{
  private:

  int  Codi_V , Codi_D , Codi_B , AJ_Id ; //Codi Via , Codi Districte , Codi Barri
  string Nom_V , Nom_D , Nom_B ; //Nom Via , Nom Districte , Nom Barri
  string Tipus_V; //Tipus Via
  int Num_P; //Numero Postal
  string Long , Lat; //Longitud  Latitud

  public:

///------------------------------> CONSTRUCTORS

Lugar(){}

Lugar(int Codi_V, int Codi_D, int Codi_B, int Num_P, string Long, string Lat,string Nom_V, string Nom_D, string Nom_B, string Tipus_V , int AJ_Id){
    this -> AJ_Id = AJ_Id;
    this -> Codi_V=Codi_V;
    this -> Codi_D=Codi_D;
    this -> Codi_B=Codi_B;
    this -> Nom_V= Nom_V;
    this -> Nom_D=Nom_D;
    this -> Nom_B=Nom_B;
    this -> Tipus_V=Tipus_V;
    this -> Num_P=Num_P;
    this -> Long=Long;
    this -> Lat=Lat;
}

Lugar(const Lugar & Loc){
    AJ_Id = Loc.AJ_Id;
    Codi_V=Loc.Codi_V;
    Codi_D=Loc.Codi_D;
    Codi_B=Loc.Codi_B;
    Nom_V=Loc.Nom_V;
    Nom_D=Loc.Nom_D;
    Nom_B=Loc.Nom_B;
    Tipus_V=Loc.Tipus_V;
    Num_P=Loc.Num_P;
    Long=Loc.Long;
    Lat=Loc.Lat;
}

///-----------------------------------------------> METODES

                ///METODES GET

int getAJ_Id()const {return AJ_Id;}
int getCodi_V()const {return Codi_V;}
int getCodi_D()const {return Codi_D;}
int getCodi_B()const {return Codi_B;}
int getNum_P()const {return Num_P;}
string getNom_V()const {return Nom_V;}
string getNom_D()const {return Nom_D;}
string getNom_B()const {return Nom_B;}
string getTipus_V()const {return Tipus_V;}
string getLong()const  {return Long;}
string getLat()const  {return Lat;}

                ///METODES SET

void setAJ_Id(int AJ_Id){this -> AJ_Id = AJ_Id;}
void setCodi_V(int Codi_V){ this -> Codi_V=Codi_V;}
void setCodi_D(int Codi_D){ this -> Codi_D=Codi_D;}
void setCodi_B(int Codi_B){ this -> Codi_B=Codi_B;}
void setNum_P(int Num_P){ this -> Num_P=Num_P;}
void setNom_V(string Nom_V){ this -> Nom_V=Nom_V;}
void setNom_D(string Nom_D){this -> Nom_D=Nom_D;}
void setNom_B(string Nom_B){ this -> Nom_B=Nom_B;}
void setTipus_V(string Tipus_V){this -> Tipus_V=Tipus_V;}
void setLong(string Long){this -> Long = Long;}
void setLat(string Lat){this -> Lat = Lat;}

                ///OPERADOR COUT

friend ostream & operator<<(ostream & os, const Lugar & Loc){

    os<<" -------------------------------"<<endl;
    os<<" ººººººººººººººººººººººººººººººº"<<endl;
    os<<" -------------------------------"<<endl;
    os<<" Id de l'area de joc :"<<Loc.AJ_Id<<endl;
    os<<" Codi de la via :"<<Loc.Codi_V<<endl;
    os<<" Codi del districte :"<<Loc.Codi_D<<endl;
    os<<" Codi del barri :"<<Loc.Codi_B<<endl;
    os<<" nom de la via: "<<Loc.Nom_V<<endl;
    os<<" nom del barri: "<<Loc.Nom_B<<endl;
    os<<" nom del districte: "<<Loc.Nom_D<<endl;
    os<<" tipus de via: "<<Loc.Tipus_V<<endl;
    os<<" numero postal: "<<Loc.Num_P<<endl;
    os<<" Latitud: "<<Loc.Lat<<endl;
    os<<" Longitud: "<<Loc.Long<<endl;

  return os;
}

                ///OPERADOR CIN

friend istream & operator>>(istream & is, Lugar & Loc)
{

    cout<<" - Id de l'area de joc: "; is>>Loc.AJ_Id;
    cout<<" - Nom del Districte: "; is>>Loc.Nom_D;
    cout<<" - Codi del Districte: "; is>>Loc.Codi_D;
    cout<<" - Nom del Barri: "; is>>Loc.Nom_B;
    cout<<" - Codi del Barri: "; is>>Loc.Codi_B;
    cout<<" - Nom de la Via: "; is>>Loc.Nom_V;
    cout<<" - Codi de la Via: "; is>>Loc.Codi_V;
    cout<<" - Tipus de Via: "; is>>Loc.Tipus_V;
    cout<<" - Numero Postal: "; is>>Loc.Num_P;
    cout<<" - Longitud: "; is>>Loc.Long;
    cout<<" - Latitud: "; is>>Loc.Lat;

    return is;
}

Lugar & operator = (const Lugar & Lug)
    {
        if(this != & Lug)
        {
            AJ_Id = Lug.AJ_Id;
            Nom_D = Lug.Nom_D;
             Codi_D= Lug.Codi_D;
            Nom_B = Lug.Nom_B;
            Codi_B = Lug.Codi_B;
            Nom_V = Lug.Nom_V;
            Codi_V = Lug.Codi_V;
            Tipus_V = Lug.Tipus_V;
            Num_P = Lug.Num_P;
            Long = Lug.Long;
            Lat = Lug.Lat;
        }
        return *this;
    }

};

typedef vector<Lugar> VL;

///----------------------------------> CLASSE

class Parque
{
private:

    Lugar LUG;
    VOP Obj;
    vector<VStr> Vs;
    VOP::iterator itVOP = Obj.begin();


                ///METODES PRIVATS

     void VectorizingLongLat(string Str, vector<VStr> & Vs) ///Vectoritza els String de Longitud o Latitud
    {
        VStr V;
        string Num = "";
        for(int x = 0; Str.size()>x; x++)
        {
            if(Str[x] == '.')
            {
            V.push_back(Num);
            Num = "";
            }
            if(Str[x] != '.')
            {
                Num = Num+Str[x];
            }
        }
        V.push_back(Num);
        Vs.push_back(V);
    }

public:

///-----------------------------------------> CONSTRUCTORS

    Parque(){}

///----------------------------------------------------------> METODES

    void Insertar_En_Vector_Objeto(const ObjetoParque & OBJ)
    {
        Obj.push_back(OBJ);
    }

    int ObjSize()const{return Obj.size();}

    ObjetoParque getVObj(int q)const {return Obj[q];}

    void SetLUG(Lugar & LUG){this -> LUG = LUG;}

     void Clear(){Obj.clear();}

     void SetVOP(int numerin,ObjetoParque & Obj){this -> Obj[numerin] = Obj;}

     Lugar getLUG()const {return LUG;}

     VOP GetVOP()const{return Obj;}

     void ERASE( vector<ObjetoParque>::iterator & It){Obj.erase(It);}

    int Converter(char S) ///Converteix Chars Numerics a Ints
    {
        int N;
        vector<char> Lista{'0','1','2','3','4','5','6','7','8','9'};
        for(int x = 0; x<=Lista.size();x++)
        {
            if(S ==  Lista[x])
            {
                N = x;
            }

        }
        return N;
    }

    void VLongLatCompletiser()
    {

        VectorizingLongLat(LUG.getLong(),Vs);
        VectorizingLongLat(LUG.getLat(),Vs);

    }

    string geTvll(int q,int r)const {return Vs[q][r];}

    void pushObj(ObjetoParque & ob){Obj.push_back(ob);}

                    ///OPERADOR COUT

     friend ostream & operator<<(ostream & os, const Parque & Pp){
        os<<Pp.LUG;
        for(int x = 0; x < Pp.Obj.size(); x++)
        {
            os<<Pp.Obj[x];
        }

    return os;
    }

    friend bool operator < (const Parque & PA, const Parque & PB)
    {
        return PA.getLUG().getAJ_Id() < PB.getLUG().getAJ_Id();
    }
};

///-----------------------------------------------> CLASSE GLOBAL

class Parques_Barna
{
    private:

    VOP Obj;
    VL Lug;
    vector<Parque>VPS;

            ///METODES PRIVATS

    void Ordenar(vector<Parque> & VPS)
    {
        Parque P;
        int x = 0;
        for(int l = 0; l < Lug.size();l++)
        {
        P.SetLUG(Lug[l]);
        if(Obj[x].getAJ_Id() == Lug[l].getAJ_Id())
            {
                while(Obj[x].getAJ_Id() == Lug[l].getAJ_Id())
                {
                    P.Insertar_En_Vector_Objeto(Obj[x]);
                    x++;
                }
            }
        P.VLongLatCompletiser();
        VPS.push_back(P);
        P.Clear();
        }
    }

    public:

///-------------------------------------------> CONSTRUCTORS

    Parques_Barna(ifstream & Data)
    {

        Lugar L;
        ObjetoParque O;

        int AJ_Id , AJ_Edat_Id;
        string AJ_Edat ;
        string Codi /**Codi de l'objecte*/, Tipus /**Tipus d'objecte*/;
        int Codi_V , Codi_D , Codi_B , Num_P ;
        string Nom_V , Nom_D , Nom_B ;
        string Tipus_V , SPVN/**Espai Verd Codi*/;
        int  SPVC/**Espai Verd Nom*/;
        string Long , Lat ;
        string x_etrs89 , y_etrs89;
        double AJ_M2 ;

        getline(Data,Codi);

        while(Data>>Codi>>AJ_Id>>Tipus>>AJ_M2>>AJ_Edat_Id>>AJ_Edat>>Codi_V>>Tipus_V>>Nom_V>>Num_P>>Codi_D>>Nom_D>>
                                                          Codi_B>>Nom_B>>x_etrs89>>y_etrs89>>Long>>Lat>>SPVC>>SPVN)
        {
            L.setAJ_Id(AJ_Id);
            L.setCodi_V(Codi_V);
            L.setCodi_D(Codi_D);
            L.setCodi_B(Codi_B);
            L.setLat(Lat);
            L.setLong(Long);
            L.setTipus_V(Tipus_V);
            L.setNum_P(Num_P);
            L.setNom_V(Nom_V);
            L.setNom_D(Nom_D);
            L.setNom_B(Nom_B);

            if(L.getAJ_Id() != O.getAJ_Id())
                {
                    Lug.push_back(L);
                }

            O.setAJ_Id(AJ_Id);
            O.setAJ_M2(AJ_M2);
            O.setAJ_Edat_Id(AJ_Edat_Id);
            O.setAJ_Edat(AJ_Edat);
            O.setCodi(Codi);
            O.setTipus(Tipus);

            Obj.push_back(O);
        }
        Ordenar(VPS);
        Sorting();
    }

///---------------------------------------------------------> METODES

    Parque getParque(int q)const {return VPS[q];}

     int Converter(char S) ///Converteix Chars Numerics a Ints
    {
        int N;
        vector<char> Lista{'0','1','2','3','4','5','6','7','8','9'};
        for(int x = 0; x<=Lista.size();x++)
        {
            if(S ==  Lista[x])
            {
                N = x;
            }

        }
        return N;
    }

    void Sorting()
    {
        sort(VPS.begin(),VPS.end());
    }

    int Comparator(int Start,int Final,int Q)
    {
        while(Start <= Final){
            int mid = (Start+Final)/2;
            if(Q > VPS[mid].getLUG().getAJ_Id())
            {
                Start = mid + 1;
            }
            else if(Q < VPS[mid].getLUG().getAJ_Id())
            {
                Final = mid -1;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }

   int Edit()
    {
        Sorting();
        bool TotCorrecte = false, adv = false;
        Lugar L;
        ObjetoParque O;
        vector<Parque>::iterator itVP = VPS.begin();

        while(TotCorrecte == false)
        {
            system("Color E9");system("cls");
            int Search,asc,numerin,Editor;
            cout<<endl<<" Inserta el ID de l'area de Joc que vols editar: ";cin>>Search; Editor = Search;
            Search = Comparator(0,VPS.size(),Search);
            if(Search != -1)
            {
                    cout<<endl<<" - Editar la localitzacio (1)"<<endl<<endl<<" - Editar els objectes (2)"<<endl<<endl<<" - Surt de l'editor (3)"<<endl<<endl<<" ---> ";cin>>asc;;

                    if(asc == 2)
                        {
                            system("cls");
                            cout<<endl<<" Pots editar "<<VPS[Search].ObjSize()<<", inserta el seguent objecte que vulguis editar, o surt de l'editor d'objectes insertan cualsevol tecla: "<<endl<<endl<<" ---> ";cin>>numerin;
                            if(numerin > VPS[Search].ObjSize() || numerin <= 0){system("Color E0");return 0;}
                            else
                            {
                                numerin--;
                                cout<<VPS[Search].getVObj(numerin)<<endl;
                                cout<<" As escollit aquest objecte. "<<endl<<endl;
                                if (adv == false){advance(itVP,Search);adv = true;}
                                cin>>O;
                                O.setAJ_Id(Editor);
                                itVP->SetVOP(numerin,O);
                            }
                        }

                    if(asc == 1)
                    {
                        system("cls");
                        advance(itVP,Search);
                        cout<<endl;cin>>L;
                        L.setAJ_Id(Editor);
                        itVP->SetLUG(L);
                        cout<<endl<<" - Editar un altre objecte (1)"<<endl<<endl<<" - Sortir de l'editor (2)"<<endl<<endl<<" ---> "; cin>>asc;
                        if(asc == 1){Edit();}
                        else {system("Color E0");system("cls");return 0;}
                    }

                    else if(asc == 3){system("Color E0");system("cls");return 0;}

                    else {system("cls");cout<<endl<<" Inserta un valor correcte: "<<endl<<endl;}
            }
        }
    }

    void AddO(int numerin,int Editor, ObjetoParque & O,Parque & P)
    {system("cls");
        cout<<endl<<endl<<" Vols afegir un nou objecte: "<<endl<<endl<<" - Si (1)"<<endl<<endl<<" - No (2)"<<endl<<endl<<" ---> ";cin>>numerin;cout<<endl;
                if(numerin == 1)
                {
                    cin>>O;
                    O.setAJ_Id(Editor);
                    P.pushObj(O);
                    AddO(numerin,Editor,O,P);

                }
    }

    int Add()
    {
        system("color EA");system("cls");
        Lugar L;
        ObjetoParque O;
        Parque P;
        int Editor = 0,numerin = 0;
        bool correcte = true;
        vector<Parque>::iterator itVP = VPS.begin();

        cout<<endl<<" - Afegir un nou parc (1)"<<endl<<endl<<" - Afegir un nou objecte a un parc existent (2)"<<endl<<
        endl<<" - Sortir de l'editor (3)"<<endl<<endl<<" ---> ";cin>>numerin;cout<<endl;

        if(numerin == 1)
        {
            system("cls");
            cout<<endl<<" Inserta la localitzacio del parc que vols afegir: "<<endl<<endl;cin>>L;
            if(Comparator(0,VPS.size(),L.getAJ_Id()) == -1)
            {
                P.SetLUG(L);
                Editor = P.getLUG().getAJ_Id();
                AddO(numerin,Editor,O,P);
                if(P.GetVOP().size()== 0){cout<<endl<<endl<<" !! Al no tenir cap objecte no s'ha guardat correctament !!"<<endl<<endl;}
                VPS.insert(itVP,P);
            }
            Add();
        }
        else if(numerin == 2)
        {
            system("cls");
            while(correcte == true)
            {
                cout<<endl<<" Inserta el ID de l'area de Joc que vols afegir un objecte: ";cin>>numerin;cout<<endl;Editor = numerin;
                numerin = Comparator(0,VPS.size(),numerin);
                if(numerin != -1)
                {
                    L = VPS[numerin].getLUG();
                    P = VPS[numerin];
                    AddO(numerin,Editor,O,P);
                    advance(itVP,numerin);
                    *itVP = P;
                    correcte = false;
                }
                else{system("cls");cout<<endl<<" El valor insertat no existeix, torna a insertar un valor existent: "<<endl;}
            }
            Add();
        }
        system("cls");
        system("Color E0");
        return 0;
    }

    int Delete() /// MIRAR QUE FALLA
    {
        Sorting();
        vector<Parque>::iterator itVP = VPS.begin();
        vector<ObjetoParque>::iterator itVOP;
        system ("cls");
        system("Color E4");
        int Search,asc;

            cout<<endl<<" Inserta el ID de l'area de Joc que vols eliminar: ";cin>>Search;
            Search = Comparator(0,VPS.size(),Search);
            if(Search != -1)
            {
                cout<<endl<<" - Eliminar el parc (1) "<<endl<<endl<<" - Eliminar un objecte (2) "<<endl<<endl<<" - Sortir de l'editor (3)"<<endl<<endl;cin>>asc;
                if(asc == 1)
                {
                    system ("cls");
                    advance(itVP,Search);
                    VPS.erase(itVP);
                    Delete();
                }
                else if(asc == 2) ///NO FUNCIONA BIEN
                {
                    while(true)
                    {

                        system ("cls");
                        cout<<endl<<" Pots eliminar "<<VPS[Search].ObjSize()<<", inserta el seguent objecte que vulguis eliminar, o surt de l'editor d'objectes insertan cualsevol tecla: "<<endl<<endl<<" ---> ";cin>>asc;
                        if(asc > VPS[Search].ObjSize() || asc <= 0){system("cls");system("Color E0");return 0;}
                        else
                        {
                            asc--;
                            cout<<endl<<VPS[Search].getVObj(asc)<<endl;
                            cout<<endl<<" As escollit aquest objecte. "<<endl<<endl;
                            itVOP = VPS[Search].GetVOP().begin();
                            advance(itVOP,asc);
                            cout<<" ";
                            VPS[Search].ERASE(itVOP);
                            cout<<"- Eliminar un altre objecte (1)"<<endl<<endl<<" - Sortir de l'editor (2) "<<endl<<endl;cin>>asc;
                            if(asc == 2){system("cls");system("Color E0");return 0;}
                        }
                    }
                }
                else if(asc == 3){system("Color E0");system("cls");return 0;}
            }
            else
            {
                cout<<endl<<"El valor insertat no existeix, torna a insertar un valor existent: "<<endl;
            }
    }

                        ///OPERADOR COUT

    friend ostream & operator<<(ostream & os, const Parques_Barna & PB){
        for(int x = 0; x < PB.VPS.size(); x++)
        {
          os<<PB.VPS[x];
        }
    return os;
    }
};

///-------------------------------------------------> MAIN

int main()
{
    system("color E0");
    bool t = true;
    ifstream Data("DATA.txt");
    Parques_Barna P(Data);
    char esc;
    while(t == true)
    {
        cout<<" - SEARCH (a)"<<endl<<endl;
        cout<<" - ADD/EDIT/DELET (b)"<<endl<<endl;
        cout<<" - DELETE (c)"<<endl<<endl;cin>>esc;
        if(esc == 'b')
        {
            P.Add();
        }
        if(esc == 'a')
        {
            P.Edit();
        }
        if(esc == 'c')
            P.Delete();
    }
}
