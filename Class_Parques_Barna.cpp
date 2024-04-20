#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

class Parques_Barna
{
    private:

    VOP Obj;
    VL Lug;
    Lugar L;
    ObjetoParque O;
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
        VPS.push_back(P);
        P.Clear();
        }
    }

    public:

///-------------------------------------------> CONSTRUCTORS

    Parques_Barna(ifstream & Data)
    {
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

                        ///OPERADOR COUT

    friend ostream & operator<<(ostream & os, const Parques_Barna & PB){
        for(int x = 0; x < PB.VPS.size(); x++)
        {
          os<<PB.VPS[x];
        }
    return os;
    }
};
