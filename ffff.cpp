#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

class ObjetoParque
{
    private:

    int AJ_Id , AJ_Edat_Id; //Area de Joc Id , Area de Joc M2 , Area de Joc Edat Id
    string AJ_Edat ; //Area de Joc Edat
    string Codi , Tipus; //Codi , Tipus d'objecte
    double AJ_M2;

    public:

//-------CONSTRUCTORS--------

    ObjetoParque(){}

    ObjetoParque(int C_AJ_Id , double C_AJ_M2 , int C_AJ_Edat_Id, string C_AJ_Edat , string C_Codi , string C_Tipus)
    {
    AJ_Id = C_AJ_Id;
    AJ_M2 = C_AJ_M2;
    AJ_Edat_Id = C_AJ_Edat_Id;
    AJ_Edat = C_AJ_Edat;
    Codi = C_Codi;
    Tipus = C_Tipus;
    }

//----Constructor Còpia------

    ObjetoParque(const ObjetoParque & Obj)
    {
    AJ_Id = Obj.AJ_Id;
    AJ_M2 = Obj.AJ_M2;
    AJ_Edat_Id = Obj.AJ_Edat_Id;
    AJ_Edat = Obj.AJ_Edat;
    Codi = Obj.Codi;
    Tipus = Obj.Tipus;
    }

//---------MÉTODES-----------

//-----------Get-------------

    int getAJ_Id()const{return AJ_Id;}
    double getAJ_M2()const{return AJ_M2;}
    int getAJ_Edat_Id()const{return AJ_Edat_Id;}
    string getAJ_Edat()const{return AJ_Edat;}
    string getCodi()const{return Codi;}
    string getTipus()const{return Tipus;}

//----------Set--------------

    void setAJ_Id(int S_AJ_Id){AJ_Id = S_AJ_Id;}
    void setAJ_M2(double S_AJ_M2){AJ_M2 = S_AJ_M2;}
    void setAJ_Edat_Id(int S_AJ_Edat_Id){AJ_Edat_Id = S_AJ_Edat_Id;}
    void setAJ_Edat(string S_AJ_Edat){AJ_Edat = S_AJ_Edat;}
    void setCodi(string S_Codi){Codi = S_Codi;}
    void setTipus(string S_Tipus){Tipus = S_Tipus;}

//---------Altres--------------

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

class Lugar
{
  private:

  int  Codi_V , Codi_D , Codi_B , AJ_Id ; //Codi Via , Codi Districte , Codi Barri
  string Nom_V , Nom_D , Nom_B ; //Nom Via , Nom Districte , Nom Barri
  string Tipus_V; //Tipus Via
  int Num_P; //Numero Postal
  string Long , Lat; //Longitud  Latitud

  public:

Lugar(){}

Lugar(int Codi_Vc, int Codi_Dc, int Codi_Bc, int Num_Pc, string LongC, string LatC,string Nom_Vc, string Nom_Dc, string Nom_Bc, string Tipus_VC , int AJ_Idc){
    AJ_Id = AJ_Idc;
    Codi_V=Codi_Vc;
    Codi_D=Codi_Dc;
    Codi_B=Codi_Bc;
    Nom_V= Nom_Vc;
    Nom_D=Nom_Dc;
    Nom_B=Nom_Bc;
    Tipus_V=Tipus_VC;
    Num_P=Num_Pc;
    Long=LongC;
    Lat=LatC;
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

//-----------Get-------------

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

//----------Set--------------

void setAJ_Id(int sAJ_Id){AJ_Id = sAJ_Id;}
void setCodi_V(int Codi_Vs){ Codi_V=Codi_Vs;}
void setCodi_D(int Codi_Ds){ Codi_D=Codi_Ds;}
void setCodi_B(int Codi_Bs){ Codi_B=Codi_Bs;}
void setNum_P(int Num_Ps){ Num_P=Num_Ps;}
void setNom_V(string Nom_Vs){ Nom_V=Nom_Vs;}
void setNom_D(string Nom_Ds){ Nom_D=Nom_Ds;}
void setNom_B(string Nom_Bs){ Nom_B=Nom_Bs;}
void setTipus_V(string Tipus_Vs){Tipus_V=Tipus_Vs;}
void setLong(string LongS){Long = LongS;}
void setLat(string LatS){Lat = LatS;}

friend ostream & operator<<(ostream & os, const Lugar & Loc){

    os<<"-------------------------------"<<endl;
    os<<"ººººººººººººººººººººººººººººººº"<<endl;
    os<<"-------------------------------"<<endl;
    os<<"Codi via :"<<Loc.Codi_V<<endl;
    os<<"Codi districte :"<<Loc.Codi_D<<endl;
    os<<"Codi barri :"<<Loc.Codi_B<<endl;
    os<<"nom de via: "<<Loc.Nom_V<<endl;
    os<<"nom de barri: "<<Loc.Nom_B<<endl;
    os<<"nom de districte: "<<Loc.Nom_D<<endl;
    os<<"tipus de via: "<<Loc.Tipus_V<<endl;
    os<<"numero postal: "<<Loc.Num_P<<endl;
    os<<" Laltitud: "<<Loc.Lat<<endl;
    os<<"Longitud: "<<Loc.Long<<endl;

  return os;
}

};

typedef vector<ObjetoParque> VOP;
typedef vector<Lugar> VL;


class Parque
{
private:

    VOP Obj;
    VL Lug;

public:

    Parque(){}

    Parque(VOP & C_Obj , VL & C_Lug)
    {
        Obj = C_Obj;
        Lug = C_Lug;
    }
    //altres mètrodes de l'API

};

typedef vector<Parque> VPB;

class Parques_Barna
{

VPB PB;
VOP Obj;
VL Lug;

public:

    Parques_Barna(ifstream & Data , VOP & C_Obj , VL & C_Lug)
    {
        int AJ_Id , AJ_Edat_Id ; //Area de Joc Id , Area de Joc Edat Id
        string AJ_Edat; //Area de Joc Edat
        string Codi , Tipus ; //Codi , Tipus d'objecte
        int Codi_V , Codi_D , Codi_B , Num_P; //Codi Via , Codi Districte , Codi Barri
        string Nom_V , Nom_D , Nom_B; //Nom Via , Nom Districte , Nom Barri
        string Tipus_V , Espai_Verd_Nom; //Tipus Via , Espai Verd Nom
        int  Espai_Verd_Codi; //Numero Postal , Espai Verd Codi
        string Long , Lat ; //Longitud , Latitud ,  Area de Joc M2
        string x_etrs89 , y_etrs89; // xetrs89 , yetrs89
        double AJ_M2;

        ObjetoParque C;
        Lugar L;

        getline(Data,Codi);

        while(Data>>Codi>>AJ_Id>>Tipus>>AJ_M2>>AJ_Edat_Id>>AJ_Edat>>Codi_V>>Tipus_V>>Nom_V>>Num_P>>Codi_D>>Nom_D>>Codi_B>>Nom_B>>x_etrs89>>y_etrs89>>Long>>Lat>>Espai_Verd_Codi>>Espai_Verd_Nom)
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

            if(L.getAJ_Id() != C.getAJ_Id())
            {
                Lug.push_back(L);
                cout<<L;
            }

            C.setAJ_Id(AJ_Id);
            C.setAJ_M2(AJ_M2);
            C.setAJ_Edat_Id(AJ_Edat_Id);
            C.setAJ_Edat(AJ_Edat);
            C.setCodi(Codi);
            C.setTipus(Tipus);

            Obj.push_back(C);
            cout<<C;



        }
        C_Obj = Obj;
        C_Lug = Lug;
        Parque P(C_Obj,C_Lug);
        VPB.push_back(P); //omplim el vector de parques
    }
};

int main()
{
    VOP C;
    VL L;

    ifstream Data("DATA.txt");
    Parques_Barna Parque1(Data,C,L);

}
