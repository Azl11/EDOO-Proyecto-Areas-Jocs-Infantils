#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

class ObjetoParque
{
    private:

    int AJ_Id , AJ_M2 , AJ_Edat_Id; //Area de Joc Id , Area de Joc M2 , Area de Joc Edat Id
    string AJ_Edat; //Area de Joc Edat
    string Codi , Tipus; //Codi , Tipus d'objecte

    public:

//-------CONSTRUCTORS--------

    ObjetoParque()
    {
    AJ_Id = 0;
    AJ_M2 = 0;
    AJ_Edat_Id = 0;
    AJ_Edat = "-";
    Codi = "-";
    Tipus = "-";
    }

    ObjetoParque(int C_AJ_Id , int C_AJ_M2 , int C_AJ_Edat_Id, string C_AJ_Edat , string C_Codi , string C_Tipus)
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
    int getAJ_M2()const{return AJ_M2;}
    int getAJ_Edat_Id()const{return AJ_Edat_Id;}
    string getAJ_Edat()const{return AJ_Edat;}
    string getCodi()const{return Codi;}
    string getTipus()const{return Tipus;}

//----------Set--------------

    void setAJ_Id(int S_AJ_Id){AJ_Id = S_AJ_Id;}
    void setAJ_M2(int S_AJ_M2){AJ_M2 = S_AJ_M2;}
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
    os<<"-------------------------------"<<endl;
    os<<endl;

    return os;
}

};

class Lugar{};

typedef vector<ObjetoParque> VOP;
typedef vector<Lugar> VL;

class Parques_Barna
{
VOP Obj;
VL L;
string label;
int N=0;
string a1,a2,a3,a4,a5,a6,a7;
string b1,b2,b3,b4,b5,b6,b7,b8,b9,b10;
string c1;
string d1,d2,d3,d4;

public:
    Parques_Barna(const VOP C_Obj ,const VL C_L){Obj = C_Obj; L = C_L;}

    Parques_Barna( ifstream & Data, VOP & C_Obj)
    {
        ObjetoParque C;
        getline(Data,label);
        while(Data>>b1>>a1>>a2>>a3>>b2>>b3)
        {
            C.setAJ_Id(a1);
            C.setAJ_M2(a3);
            C.setAJ_Edat_Id(b2);
            C.setAJ_Edat(b3);
            C.setCodi(b1);
            C.setTipus(a2);
            N++;
            C_Obj.push_back(C);
            cout<<C;
            cout<<endl<<N<<endl;
        }
    }
};

int main()
{
    VOP C;
    ifstream Data("OBJETOPARQUE.txt");
    Parques_Barna CC(Data,C);
}
