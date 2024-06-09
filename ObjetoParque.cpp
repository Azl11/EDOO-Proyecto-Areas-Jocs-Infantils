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
    Data D;
    vector<ObjetoParque>v_Obj ;
    public:

///--------------------------------> CONSTRUCTORS

    ObjetoParque(){}
//Constructor amb fitxers
DATA (ifstream& fDATA)
    {
    int AJ_Id , AJ_Edat_Id;
    string AJ_Edat ;
    string Codi , Tipus;
    double AJ_M2;

        while (fDATA >> AJ_Id  >>  AJ_Edat_Id  >> AJ_Edat  >> Codi >> Tipus >> AJ_M2)
         {
            getline(fDATA,AJ_Id,';');
            getline(fDATA,AJ_Edat_Id,';');
            getline(fDATA,codi, ';');
            getline(fDATA,Tipus, ';');
            getline(fDATA,AJ_M2, ';');

            DATA DA (AJ_Id, AJ_Edat_Id, AJ_Edat, Codi, Tipus, AJ_M2);

            v_DA.push_back(DA);
            l_AJ_Id.push_back(AJ_Id);
            l_AJ_Edat_Id.push_back(AJ_Edat_Id);
            l_AJ_Edat.push_back(AJ_Edat);
            l_Codi.push_back(Codi);
            l_Tipus.push_back(Tipus);
            l_AJ_M2.push_back(AJ_M2);
         }
    }
//Constructors per parámetres
    ObjetoParque(int AJ_Id , double AJ_M2 , int AJ_Edat_Id, string AJ_Edat , string Codi , string Tipus)
    {
    this -> AJ_Id = AJ_Id;
    this -> AJ_M2 = AJ_M2;
    this -> AJ_Edat_Id = AJ_Edat_Id;
    this -> AJ_Edat = AJ_Edat;
    this -> Codi = Codi;
    this -> Tipus = Tipus;
    this-> D = D;

//Constructor de copia

    ObjetoParque(const ObjetoParque & Obj)
    {
    AJ_Id = Obj.AJ_Id;
    AJ_M2 = Obj.AJ_M2;
    AJ_Edat_Id = Obj.AJ_Edat_Id;
    AJ_Edat = Obj.AJ_Edat;
    Codi = Obj.Codi;
    Tipus = Obj.Tipus;
    D = Obj.D;
    }
//Operador d'assignacio
ObjetoParque& operator = (const ObjetoParque& Obj)
	{
		if (this != &Obj)
		{
    AJ_Id = Obj.AJ_Id;
    AJ_M2 = Obj.AJ_M2;
    AJ_Edat_Id = Obj.AJ_Edat_Id;
    AJ_Edat = Obj.AJ_Edat;
    Codi = Obj.Codi;
    Tipus = Obj.Tipus;
    D = Obj.D;
		}
		return (*this);
	}

///---------------------------------------------------> METODES
//Metodes get

    int getAJ_Id()const{return AJ_Id;}
    double getAJ_M2()const{return AJ_M2;}
    int getAJ_Edat_Id()const{return AJ_Edat_Id;}
    string getAJ_Edat()const{return AJ_Edat;}
    string getCodi()const{return Codi;}
    string getTipus()const{return Tipus;}
    Data getD()const{return D;}

//Metodes set

    void setAJ_Id(int AJ_Id){this -> AJ_Id = AJ_Id;}
    void setAJ_M2(double AJ_M2){this -> AJ_M2 = AJ_M2;}
    void setAJ_Edat_Id(int AJ_Edat_Id){this -> AJ_Edat_Id = AJ_Edat_Id;}
    void setAJ_Edat(string AJ_Edat){this -> AJ_Edat = AJ_Edat;}
    void setCodi(string Codi){this -> Codi = Codi;}
    void setTipus(string Tipus){this -> Tipus = Tipus;}
    void setD(Data D){this-> D = D;}

//Metodes Afegir

bool afegir(const ObjetoParque& Obj )
    {
        cout << "Objecte del parc a afegir: " << Obj.getCodi() << endl;
        map<string,Tipus>::iterator it = MObj.find(Obj.getCodi());
        if (it == MObj.end())
        {
            pair<string,Tipus> pObjetoParque(Obj.getCodi(), Obj);
            MObj.insert(pObjetoParque);
            cout << "Objecte afegit!" << endl;
            return true;
        }
        else
        {
            cout << "Aquest objecte ja existeix!" << endl;
            return false;
        }

    }

///--------------------------------------------------------->OPERADORS
//Operador sortida

friend ostream & operator <<(ostream & os , const ObjetoParque & Obj)
{
    os<<" -------------------------------"<<endl;
    os<<" Area de Jocs ID: "<< Obj.AJ_Id<<endl;
    os<<" Area de Jocs M2: "<< Obj.AJ_M2<<endl;
    os<<" Area de Jocs Edat ID: "<< Obj.AJ_Edat_Id<<endl;
    os<<" Area de Jocs Edat: "<< Obj.AJ_Edat<<endl;
    os<<" Codi: "<< Obj.Codi<< endl;
    os<<" Tipus: "<< Obj.Tipus<< endl;
    os<<"D: "<<obj.D<< endl;

    return os;
}
//Operador de comparació ==
friend bool operator == (const ObjetoParque& AJ_Id , const Objetoparque& AJ_M2 )
	{
		return (AJ_Id.causa == AJ_M2.causa);
	}
//Operador de comparació <
friend bool operator == (const ObjetoParque& AJ_Id , const Objetoparque& AJ_M2 )
	{
		return (AJ_Id.causa < AJ_M2.causa);
	}
//Operrador CIN

friend istream & operator>>(istream & is, ObjetoParque & Obj)
{
    cout<<" - Area de Jocs ID: "; is>>Obj.AJ_Id;
    cout<<" - Area de Jocs M2: "; is>>Obj.AJ_M2;
    cout<<" - Area de Jocs Edat ID: "; is>>Obj.AJ_Edat_Id;
    cout<<" - Area de Jocs Edat: "; is>>Obj.AJ_Edat;
    cout<<" - Codi: "; is>>Obj.Codi;
    cout<<" - Tipus: "; is>>Obj.Tipus;
    cout<<" - D: "; is>>Obj.D;

    return is;
}

};

typedef vector<ObjetoParque> v_Obj;
