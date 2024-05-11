
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

typedef vector<string> VStr;

///-----------------------------------> CLASSE

class ObjetoParque
{
    private:

    int AJ_Id , AJ_Edat_Id; //Area de Joc Id , Area de Joc M2 , Area de Joc Edat Id
    string AJ_Edat ; //Area de Joc Edat
    string Codi , Tipus; //Codi , Tipus d'objecte
    double AJ_M2;

    public:

///--------------------------------> CONSTRUCTORS

    ObjetoParque(){}

    ObjetoParque(int AJ_Id , double AJ_M2 , int AJ_Edat_Id, string AJ_Edat , string Codi , string Tipus)
    {
    this -> AJ_Id = AJ_Id;
    this -> AJ_M2 = AJ_M2;
    this -> AJ_Edat_Id = AJ_Edat_Id;
    this -> AJ_Edat = AJ_Edat;
    this -> Codi = Codi;
    this -> Tipus = Tipus;
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
    os<<" -------------------------------"<<endl;
    os<<" Area de Jocs ID: "<< Obj.AJ_Id<<endl;
    os<<" Area de Jocs M2: "<< Obj.AJ_M2<<endl;
    os<<" Area de Jocs Edat ID: "<< Obj.AJ_Edat_Id<<endl;
    os<<" Area de Jocs Edat: "<< Obj.AJ_Edat<<endl;
    os<<" Codi: "<< Obj.Codi<< endl;
    os<<" Tipus: "<< Obj.Tipus<< endl;

    return os;
}

                    ///OPERATOR CIN

friend istream & operator>>(istream & is, ObjetoParque & Obj)
{
    cout<<" - Area de Jocs ID: "; is>>Obj.AJ_Id;
    cout<<" - Area de Jocs M2: "; is>>Obj.AJ_M2;
    cout<<" - Area de Jocs Edat ID: "; is>>Obj.AJ_Edat_Id;
    cout<<" - Area de Jocs Edat: "; is>>Obj.AJ_Edat;
    cout<<" - Codi: "; is>>Obj.Codi;
    cout<<" - Tipus: "; is>>Obj.Tipus;

    return is;
}
    ObjetoParque & operator = (const ObjetoParque & Obj)
    {
        if(this != & Obj)
        {
            AJ_Id = Obj.AJ_Id;
            AJ_M2 = Obj.AJ_M2;
            AJ_Edat_Id = Obj.AJ_Edat_Id;
            AJ_Edat = Obj.AJ_Edat;
            Codi = Obj.Codi;
            Tipus = Obj.Tipus;
        }
        return *this;
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
  int Num_P,SPVC; //Numero Postal
  string Long , Lat ,X9,Y9,SPVN; //Longitud  Latitud


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
int getSPVC()const {return SPVC;}
string getNom_V()const {return Nom_V;}
string getNom_D()const {return Nom_D;}
string getNom_B()const {return Nom_B;}
string getTipus_V()const {return Tipus_V;}
string getLong()const  {return Long;}
string getLat()const  {return Lat;}
string getX9()const {return X9;}
string getY9 ()const {return Y9;}
string getSPVN () const {return SPVN;}

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
void setX9(string X9){this -> X9 = X9;}
void setY9(string Y9){this -> Y9 = Y9;}
void setSPVC(int SPVC){this -> SPVC = SPVC;}
void setSPVN(string SPVN){this -> SPVN = SPVN;}

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
        if(PA.getLUG().getAJ_Id() != PB.getLUG().getAJ_Id())
        {
            return PA.getLUG().getAJ_Id() < PB.getLUG().getAJ_Id();
        }

        if(PA.getLUG().getNom_B() != PB.getLUG().getNom_B())
        {
            return PA.getLUG().getNom_B() < PB.getLUG().getNom_B();
        }

        if(PA.getLUG().getNom_D() != PB.getLUG().getNom_D())
        {
            return PA.getLUG().getNom_D() < PB.getLUG().getNom_D();
        }

        if(PA.getLUG().getNum_P() != PB.getLUG().getNum_P())
        {
            return PA.getLUG().getNum_P() < PB.getLUG().getNum_P();
        }

        if(PA.getVObj(0).getAJ_Edat() != PB.getVObj(0).getAJ_Edat())
        {
            return PA.getVObj(0).getAJ_Edat() < PB.getVObj(0).getAJ_Edat();
        }

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
        //P.VLongLatCompletiser();
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
            L.setX9(x_etrs89);
            L.setY9(y_etrs89);
            L.setSPVC(SPVC);
            L.setSPVN(SPVN);

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

    void Save_File()
    {
        ofstream Datout("DATA_PARQUES_BARNA_SAFE.txt");
        for(int i = 0; i < VPS.size();i++)
        {
            for(int j = 0; j < VPS[i].GetVOP().size();j++)
            {
                Datout<<" "<<VPS[i].getVObj(j).getCodi()<<" "<<VPS[i].getLUG().getAJ_Id()<<" "<<VPS[i].getVObj(j).getTipus()
                <<" "<<VPS[i].getVObj(j).getAJ_M2()<<" "<<VPS[i].getVObj(j).getAJ_Edat_Id()<<" "<<VPS[i].getVObj(j).getAJ_Edat()
                <<" "<<VPS[i].getLUG().getCodi_V()<<" "<<VPS[i].getLUG().getTipus_V()<<" "<<VPS[i].getLUG().getNom_V()
                <<" "<<VPS[i].getLUG().getNum_P()<<" "<<VPS[i].getLUG().getCodi_D()<<" "<<VPS[i].getLUG().getNom_D()
                <<" "<<VPS[i].getLUG().getCodi_B()<<" "<<VPS[i].getLUG().getNom_B()<<" "<<VPS[i].getLUG().getX9()
                <<" "<<VPS[i].getLUG().getY9()<<" "<<VPS[i].getLUG().getLong()<<" "<<VPS[i].getLUG().getLat()
                <<" "<<VPS[i].getLUG().getSPVC()<<" "<<VPS[i].getLUG().getSPVN()<<endl;
            }
        }

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

    int Delete()
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
                else if(asc == 2)
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
                            cout<<" - Eliminar un altre objecte (1)"<<endl<<endl<<" - Sortir de l'editor (2) "<<endl<<endl;cin>>asc;
                            if(asc == 2){system("cls");system("Color E0");return 0;}
                        }
                    }
                }
                else if(asc == 3){system("Color E0");system("cls");return 0;}
            }
            else
            {
                cout<<endl<<" El valor insertat no existeix, torna a insertar un valor existent: "<<endl;
            }
    }

 void buscarPorIDLugar() {


 int id,Buscador,aux;
 Sorting();
system("Color E9");system("cls");

        cout << " Introduce el ID del lugar: ";
        cin >>id;
        Buscador=Comparator(0,VPS.size(),id);


   if(Buscador != -1)
            {
                cout << " Los datos del lugar con ID " << id << " son los siguientes: " << endl;
                  cout<<VPS[Buscador]<<endl;}

            else {
        cout << " No se encontro ningun lugar con el ID especificado." << endl;
    }
}

 void BuscarPorDistrito() {
    system("Color E9");
    system("cls");
    Sorting();
    int aux=0,u=1;
    string nDistrito;
    bool encontrado=false;
    cout << " Introduce el nombre del distrito para ver los parques que hay: " << endl;
    cout << " Ejemplo: Sant_Marti" << endl;
    cin >> nDistrito;

    for (int i = 0; i < VPS.size(); i++) {

        if (nDistrito == VPS[i].getLUG().getNom_D()) {

            cout << " ID del parque num "<<u<<" en el distrito _ " << VPS[i].getLUG().getAJ_Id() << endl;
            u++;
             aux++;

        }

        }

        cout<<" hay un total de "<<aux<<" parques!!!!"<<endl;
    }


 void BuscarPorBarrio() {
    system("Color E9");
    system("cls");
    Sorting();
    int aux=0,u=1;
    string nBarrio;
    bool encontrado=false;
    cout << " Introduce el nombre del barrio para ver los parques que hay: " << endl;
    cout << " Ejemplo: la_Verneda_i_la_Pau" << endl;
    cin >> nBarrio;

    for (int i = 0; i < VPS.size(); i++) {

        if (nBarrio == VPS[i].getLUG().getNom_B()) {

            cout << " ID del parque num "<<u<<" en el barrio " << VPS[i].getLUG().getAJ_Id() << endl;
            u++;
             aux++;

        }

    }

        cout<<" hay un total de "<<aux<<" parques!!!!"<<endl;
    }

    void BuscarPorCP() {
    system("Color E9");
    system("cls");
    Sorting();
    int aux=0,u=1,CP;
    string nDistrito;
    bool encontrado=false;
    cout << " Introduce el codigo postal para ver los parques que hay: " << endl;
    cin >> CP;

    for (int i = 0; i < VPS.size(); i++) {

        if (CP == VPS[i].getLUG().getNum_P()) {

            cout << " ID del parque num "<<u<<" con codigo postal :" << VPS[i].getLUG().getAJ_Id() << endl;
            u++;
             aux++;

        }

    }
}

void BuscarPorEdad() {
    system("Color E9");
    system("cls");
    Sorting();
    int aux = 0, u = 1, opcion;
    string nDistrito;
    bool encontrado = false;
    cout << endl;
    cout << " Ver la ID de los parques que hay por franja de edad " << endl;
    cout << endl;
    cout << " (1) FINS_A_5_ANYS  " << endl;
    cout << endl;
    cout << " (2) DE_6_A_12_ANYS " << endl;
    cout << endl;
    cout << " (3) MIXTA " << endl;
    cout << endl;
    cin >> opcion;

    switch (opcion) {
        case 1: {
            string uno = " FINS_A_5_ANYS";
            for (int i = 0; i < VPS.size(); i++) {
                if (uno == VPS[i].getVObj(0).getAJ_Edat()) {
                    cout << " ID del objeto num " << u << " de franja de edad " << uno << " " << VPS[i].getLUG().getAJ_Id() << endl;
                    u++;
                    aux++;
                }
            }
            cout << " hay un total de " << aux << " objetos!!!!" << endl;
            break;
        }
        case 2: {
            string dos = " DE_6_A_12_ANYS";
            for (int i = 0; i < VPS.size(); i++) {
                if (dos == VPS[i].getVObj(0).getAJ_Edat()) {
                    cout << " ID del objeto num " << u << " de franja de edad " << dos << " " << VPS[i].getLUG().getAJ_Id() << endl;
                    u++;
                    aux++;
                }
            }
            cout << " hay un total de " << aux << " objetos!!!!" << endl;
            break;
        }
        case 3: {
            string tres = " MIXTA";
            for (int i = 0; i < VPS.size(); i++) {
                if (tres == VPS[i].getVObj(0).getAJ_Edat()) {
                    cout << " ID del objeto num " << u << " de franja de edad " << tres << " " << VPS[i].getLUG().getAJ_Id() << endl;
                    u++;
                    aux++;
                }
            }
            cout << " hay un total de " << aux << " objetos!!!!" << endl;
            break;
        }
        default:
            cout << " Opción no válida." << endl;
            break;
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

    bool t = true, y = true;
    int x,j;

    ifstream Data("DATA.txt");
    Parques_Barna P(Data);

    while(t)
    {
        system("cls");
        y = true;
        cout<<endl;
        cout<<" |-------------------------------------------------------------------------|"<<endl;
        cout<<" Escull una opcio valida:\n" <<endl;
        cout<<" (1): Consultar informacio parc \n"<<endl;
        cout<<" (2):Modificar Informacio parc \n"<<endl;
        cout<<" (3):Eliminar Parc/Objecte \n"<<endl;
        cout<<" (4):Afegir Parc/Objecte \n"<<endl;
        cout<<" (5):Guardar \n"<<endl;
        cout<<" (6):Sortir del programa \n"<<endl;
        cout<<" |-------------------------------------------------------------------------|"<<endl<<endl;
        cout<<" ";cin>> x;

        switch (x)
        {
        case 1:
            while(y){
                    system("cls");
                int z;
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
                cout<<" ";cin>> j;
                switch(j)
                {
                case 1:
                    P.buscarPorIDLugar();
                    cout<<" (1) Tornar a buscar: "<<endl<<endl;
                    cout<<" (2) Tornar enrera: "<<endl<<endl;
                    cin>>x;
                    switch(z)
                    {
                    case 1:
                    P.buscarPorIDLugar();
                        break;
                    case 2:
                        main();
                        break;
                    }
                    break;
                case 2:
                    P.BuscarPorBarrio();
                    cout<<" (1) Tornar a buscar: "<<endl<<endl;
                    cout<<" (2) Tornar enrera: "<<endl<<endl;
                    cin>>x;
                    switch(z)
                    {
                    case 1:
                    P.BuscarPorBarrio();
                        break;
                    case 2:
                        main();
                        break;
                    }
                    break;
                case 3:
                    P.BuscarPorDistrito();
                    cout<<" (1) Tornar a buscar: "<<endl<<endl;
                    cout<<" (2) Tornar enrera: "<<endl<<endl;
                    cin>>x;
                    switch(z)
                    {
                    case 1:
                    P.BuscarPorDistrito();
                        break;
                    case 2:
                        main();
                        break;
                    }
                    break;
                case 4:
                    P.BuscarPorCP();
                    int x;
                    cout<<" (1) Tornar a buscar: "<<endl<<endl;
                    cout<<" (2) Tornar enrera: "<<endl<<endl;
                    cin>>x;
                    switch(z)
                    {
                    case 1:
                    P.BuscarPorCP();
                        break;
                    case 2:
                        main();
                        break;
                    }
                    break;
                case 5:
                    P.BuscarPorEdad();
                    cout<<" (1) Tornar a buscar: "<<endl<<endl;
                    cout<<" (2) Tornar enrera: "<<endl<<endl;
                    cin>>x;
                    switch(z)
                    {
                    case 1:
                    P.BuscarPorEdad();
                        break;
                    case 2:
                        main();
                        break;
                    }
                    break;
                case 6:
                    system("cls");
                    main();
                default:
                    y = false;
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
            P.Save_File();
            system("cls");
            break;
        case 6:
            y = false;
            t = false;
            return 0;
            break;
        default:
            main();
            break;
        }
    }
}
