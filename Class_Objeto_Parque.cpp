#include<iostream>
#include<vector>

using namespace std;

class ObjetoParque
{
    private:

    int AJ_Id , AJ_Edat_Id; //Area de Joc Id , Area de Joc M2 , Area de Joc Edat Id
    double AJ_M2 ;
    string AJ_Edat; //Area de Joc Edat
    string Codi , Tipus; //Codi , Tipus d'objecte

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
    os<<"-------------------------------"<<endl;
    os<<endl;

    return os;
}

friend istream & operator>>(istream & is, ObjetoParque & Obj){

    
    is>> Obj.AJ_Id;
    is>> Obj.AJ_M2;
    is>> Obj.AJ_Edat_Id;
    is>>Obj.AJ_Edat;
    is>>Obj.Codi;
    is>> Obj.Tipus;
   

    return is;
}

};


int main()
{
    ObjetoParque P;
    P.setAJ_Edat("hola");
    cout<< P;
    P.setAJ_Edat("34");
    cout<< P;
}
