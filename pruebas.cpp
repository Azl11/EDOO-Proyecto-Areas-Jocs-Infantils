
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
    os<<"-------------------------------"<<endl;
    os<<"Area de Jocs ID: "<< Obj.AJ_Id<<endl;
    os<<"Area de Jocs M2: "<< Obj.AJ_M2<<endl;
    os<<"Area de Jocs Edat ID: "<< Obj.AJ_Edat_Id<<endl;
    os<<"Area de Jocs Edat: "<< Obj.AJ_Edat<<endl;
    os<<"Codi: "<< Obj.Codi<< endl;
    os<<"Tipus: "<< Obj.Tipus<< endl;

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

    os<<"-------------------------------"<<endl;
    os<<"ººººººººººººººººººººººººººººººº"<<endl;
    os<<"-------------------------------"<<endl;
    os<<"Id de l'area de joc :"<<Loc.AJ_Id<<endl;
    os<<"Codi de la via :"<<Loc.Codi_V<<endl;
    os<<"Codi del districte :"<<Loc.Codi_D<<endl;
    os<<"Codi del barri :"<<Loc.Codi_B<<endl;
    os<<"nom de la via: "<<Loc.Nom_V<<endl;
    os<<"nom del barri: "<<Loc.Nom_B<<endl;
    os<<"nom del districte: "<<Loc.Nom_D<<endl;
    os<<"tipus de via: "<<Loc.Tipus_V<<endl;
    os<<"numero postal: "<<Loc.Num_P<<endl;
    os<<" Latitud: "<<Loc.Lat<<endl;
    os<<"Longitud: "<<Loc.Long<<endl;

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

                ///METODES PRIVATS

    ObjetoParque getVObj(int q)const {return Obj[q];}

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

    void SetLUG(Lugar & LUG){this -> LUG = LUG;}

     void Clear(){Obj.clear();}

     Lugar getLUG()const {return LUG;}

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
        AJL.push_back(Lug[l].getAJ_Id());
        if(Obj[x].getAJ_Id() == Lug[l].getAJ_Id())
            {
                while(Obj[x].getAJ_Id() == Lug[l].getAJ_Id())
                {
                    AJO.push_back(Obj[x].getAJ_Id());
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
/**
    void SortVOP()
    {
        VOP O;
        int z = 0;
        sort(AJO.begin(),AJO.end());
        for(int x = 0; x < Obj.size();x++)
        {
            while(AJO[z] != Obj[x].getAJ_Id())
            {
                z++;
            }
            if(AJO[z] == Obj[x].getAJ_Id())
            {
                while(AJO[z] == Obj[x].getAJ_Id())
                {
                    O.push_back(Obj[z]);
                z = 0;
                }
            }
        }
        Obj = O;
    }

    void SortVL()
    {
        VL L;
        int z = 0;
        sort(AJL.begin(),AJL.end());
        for(int x = 0; x < Lug.size();x++)
        {
            while(AJL[z] != Lug[x].getAJ_Id())
            {
                z++;
            }
            if(AJL[z] == Lug[x].getAJ_Id())
            {
                L.push_back(Lug[z]);
                z = 0;
            }
        }
        Lug = L;
    }

**/
    void S()
    {
        vector<Parque> Vp;
        for(int x = 0; x < VPS.size();x++)
        {

        }
    }

    void Comparator(int Start,int Final,int Q)
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
        int Id;
        cout<<"Inserta el Id del parc que vols editar: "<<endl<<endl;
        cin>>Id;

        return Comparator(1,Lug.size(),Id);

    }

    void Add()
    {
        Lugar L;
        ObjetoParque O;
        Parque p;
        bool afegir = true;
        int x = 0;
        system("color E9");
        cout<<"Parametres de la localitzacio: "<<endl<<endl;
        cin>>L;
        p.SetLUG(L);
        while(afegir == true)
        {
            cout<<endl<<"Parametres d'un objecte del Parc: "<<endl<<endl;
            cin>>O;
            p.pushObj(O);
            cout<<endl<<"Vols afegir algun objecte mes? "<<endl<<" - (0)Si "<<endl<<" - (1)No "<<endl;
            cin>>x;
            if(x == 0){afegir = true;}
            else if (x == 1){afegir = false;}
        }
    }
    void Delete()
    {

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
    int z;
    system("color E0");
    VStr V;
    ifstream Data("DATA.txt");
    Parques_Barna P(Data);
    P.Edit();
}
