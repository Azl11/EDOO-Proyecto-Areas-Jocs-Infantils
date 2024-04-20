#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

typedef vector<string> VStr;

class Parque
{
private:

    ObjetoParque OBJ;
    Lugar LUG;
    VOP Obj;

                ///METODES PRIVATS

    Lugar getLUG()const {return LUG;}
    ObjetoParque getVObj(int q)const {return Obj[q];}

public:

///-----------------------------------------> CONSTRUCTORS

    Parque(){}

///----------------------------------------------------------> METODES

    void Insertar_En_Vector_Objeto(const ObjetoParque & OBJ)
    {
        this -> OBJ = OBJ;
        Obj.push_back(OBJ);
    }

    void SetLUG(Lugar & LUG){this -> LUG = LUG;}

     void Clear(){Obj.clear();}

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
