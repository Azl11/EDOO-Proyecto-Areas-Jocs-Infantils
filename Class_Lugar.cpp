#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

using namespace std;

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
    os<<"Codi via :"<<Loc.Codi_V<<endl;
    os<<"Codi districte :"<<Loc.Codi_D<<endl;
    os<<"Codi barri :"<<Loc.Codi_B<<endl;
    os<<"nom de via: "<<Loc.Nom_V<<endl;
    os<<"nom de barri: "<<Loc.Nom_B<<endl;
    os<<"nom de districte: "<<Loc.Nom_D<<endl;
    os<<"tipus de via: "<<Loc.Tipus_V<<endl;
    os<<"numero postal: "<<Loc.Num_P<<endl;
    os<<" Latitud: "<<Loc.Lat<<endl;
    os<<"Longitud: "<<Loc.Long<<endl;

  return os;
}

};

typedef vector<Lugar> VL;

