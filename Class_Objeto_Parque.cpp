#include<iostream>
#include<fstream>
#include<vector>

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

};

typedef vector<ObjetoParque> VOP;


int main()
{
    ObjetoParque P;
    P.setAJ_Edat("hola");
    cout<< P;
    P.setAJ_Edat("34");
    cout<< P;
}
