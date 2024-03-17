#include<iostream>
using namespace std;
//Class_2
class Lugar
{
  private:
  int Codi_V , Codi_D , Codi_B; //Codi Via , Codi Districte , Codi Barri
  string Nom_V , Nom_D , Nom_B; //Nom Via , Nom Districte , Nom Barri
  char Tipus_V; //Tipus Via 
  int Num_P; //Numero Postal
  double Long , Lat; //Longitud  Latitud
  public:

Lugar(){
}
Lugar(int Codi_Vc, int Codi_Dc, int Codi_Bc, int Num_Pc, double LongC, double LatC,string Nom_Vc, string Nom_Dc, string Nom_Bc, char Tipus_VC){
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
}

//-----------Get-------------
int GetCodi_V()const {return Codi_V;}
int GetCodi_D()const {return Codi_D;}
int GetCodi_B()const {return Codi_B;}
int GetNum_P()const {return Num_P;}
string GetNom_V()const {return Nom_V;}
string GetNom_D()const {return Nom_D;}
string GetNom_B()const {return Nom_B;}                      
char GetTipus_V()const {return Tipus_V;}
double GetLong()const  {return Long;}
double GetLat()const  {return Lat;}
};
