#include<iostream>

using namespace std;

class Lugar
{
  private:

  int Codi_V , Codi_D , Codi_B ; //Codi Via , Codi Districte , Codi Barri , Codi
  string Nom_V , Nom_D , Nom_B,Codi; //Nom Via , Nom Districte , Nom Barri
  string Tipus_V; //Tipus Via 
  int Num_P; //Numero Postal
  double Long , Lat; //Longitud  Latitud

  public:

Lugar(){}

Lugar(int Codi_Vc, int Codi_Dc, int Codi_Bc, int Num_Pc, double LongC, double LatC,string Nom_Vc, string Nom_Dc, string Nom_Bc, char Tipus_VC,string CodiC){
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
  Codi=CodiC;
}

Lugar(const Lugar &Loc){
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
  Codi=Loc.Codi;
}

//-----------Get-------------

int GetCodi_V()const {return Codi_V;}
int GetCodi_D()const {return Codi_D;}
int GetCodi_B()const {return Codi_B;}
int GetNum_P()const {return Num_P;}
string GetCodi()const  {return Codi;}
string GetNom_V()const {return Nom_V;}
string GetNom_D()const {return Nom_D;}
string GetNom_B()const {return Nom_B;}                      
string GetTipus_V()const {return Tipus_V;}
double GetLong()const  {return Long;}
double GetLat()const  {return Lat;}

//----------Set--------------

void SetCodi_V(int Codi_Vs){ Codi_V=Codi_Vs;}
void SetCodi_D(int Codi_Ds){ Codi_D=Codi_Ds;}
void SetCodi_B(int Codi_Bs){ Codi_B=Codi_Bs;}
void SetNum_P(int Num_Ps){ Num_P=Num_Ps;}
void SetNom_V(string Nom_Vs){ Nom_V=Nom_Vs;}
void SetNom_D(string Nom_Ds){ Nom_D=Nom_Ds;}
void SetNom_B(string Nom_Bs){ Nom_B=Nom_Bs;}
void SetTipus_V(char Tipus_Vs){Tipus_V=Tipus_Vs;}
void SetLong(double LongS){Long=LongS;}
void SetLat(double LatS){Lat=LatS;}
void SetCodi(string CodiS){Codi=CodiS;}

friend ostream & operator<<(ostream & os, const Lugar & Loc){

os<<"---------------------------"<<endl;
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
  os<<"codigo: "<<Loc.Codi<<endl;
  os<<"-------------------------------"<<endl;
  os<<endl;
  return os;
}

friend istream & operator>>(istream & is, Lugar & Loc){

  is>>Loc.Codi_V;
 is>>Loc.Codi_D;
  is>>Loc.Codi_B;
  is>>Loc.Nom_V;
  is>>Loc.Nom_B;
  is>>Loc.Nom_D;
  is>>Loc.Tipus_V;
  is>>Loc.Num_P;
  is>>Loc.Lat;
  is>>Loc.Long;
  is>>Loc.Codi;
 
  return is;
}
  

};

