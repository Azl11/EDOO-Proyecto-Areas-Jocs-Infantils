
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<time.h>

using namespace std;

///-----------------------------------------------> CLASSE DATA I HORA

class Hora{

    int h, m, s; //Hora, minuts i segons

public:

    //Constructor per defecte amb l'hora actual, que dóna el sistema
    Hora(){
        time_t t;
        time( &t );
        struct tm* info = localtime( &t );
        h = info -> tm_hour;
        m = info -> tm_min;
        s = info -> tm_sec;
    }

    //Constructor amb tres paràmetres enters
    Hora(int h, int m, int s){
        this->h=h;
        this->m=m;
        this->s=s;
    }

    //Constructor amb un paràmetre enter quantitat de segons, ha de ser <= 24x3600=84600
    //Se suposa que segons <= 24x3600=84600 segons d'un dia
    Hora(int secs){
        s = secs%60;
        secs = secs/60;
        m = secs%60;
        h = secs/60;
    }
    //Constructor amb un paràmetre string en format hh:mm:ss o hh-mm-ss
    Hora(string sh){
        string c1 = sh.substr (0,2);//el string dels caràcters hh
        h=stoi(c1); //stoi és la funció que converteix el string en enter
        string c2 = sh.substr (3,2);//el string dels caràcters mm
        m=stoi(c2);
        string c3 = sh.substr (6); //el substring de la 6à posició fins al final
        s=stoi(c3);
    }

    //Mètodes consultors
    int getHora() const
    {
        return h;
    }
    int getMinuts() const
    {
        return m;
    }
    int getSegons() const
    {
        return s;
    }

    //Mètodes modificadors. Se suposa que h, m i s són vàlids
    void setHora (int hh){
        h=hh;
    }
    void setMinuts (int mm){
        m=mm;
    }
    void setSegons (int ss){
        s=ss;
    }

    //Incrementar l'hora amb una quantitat de segons
    void incrementaHora (int ss){
        int segs = s + ss; //sumem els segons totals resultants
        if (segs > 59) {
            int hh=segs/3600;
            h+=hh;
            int mm =(segs - hh*3600)/60;
            m+=mm;
            if (m > 59) //m pot tenir vàries hores...
            {
                h += m/60;;
                m = m%60;
            }
            s=segs- hh*3600-mm*60;
        }
        else
        {
            s += ss;
        }
    }
    //Transforma una hora en quantitat total de segons
    int aSegons()
    {
            return h*3600 + m*60 + s;
    }
    //Transforma una hora en quantitat total de minuts (double)
    double aMinuts()
    {
            return double (h*60 + m + s/60.0);
    }

    //L'operador incrementa l'hora amb una quantitat de segons ss
    friend Hora& operator + (Hora& H, int ss)
    {
        int segs= H.s + ss;
        if (segs > 59) {
            int hh=segs/3600;
            H.h+=hh;
            int mm =(segs - hh*3600)/60;
            H.m+=mm;
            if (H.m > 59)
            {
                H.h++;
                H.m-=60;
            }
            H.s=segs- hh*3600-mm*60;
        }
        return H;
    }

    //L'operador - resta dues hores, dóna una hora com a resultats
    friend Hora operator - (const Hora H1, const Hora H2)
    {
        int s1 = H1.getHora()*3600 + H1.getMinuts()*60 + H1.getSegons();
         int s2 = H2.getHora()*3600 + H2.getMinuts()*60 + H2.getSegons();

        if (H1 < H2)
        {
            int sdif = s2 - s1;
            Hora Hdif(sdif);
            return Hdif;
        }
        else
        {
            int sdif = s1 - s2;
            Hora Hdif(sdif);
            return Hdif;
        }
    }

    //Operador < per comparar dues hores
    friend bool operator < (const Hora& h1, const Hora& h2)
    {
        if ( h1.h < h2.h)
        {
            return true;
        }
        else if (h1.h == h2.h and h1.m < h2.m)
        {
            return true;
        }
        else if ( h1.h == h2.h and h1.m == h2.m and h1.s < h2.s)
        {
            return true;
        }
        return false;
    }

    //Comparar dues hores ==
    friend bool operator == (const Hora& h1, const Hora& h2)
    {
        return ( h1.h == h2.h and h1.m == h2.m and h1.s == h2.s);
    }

    //Escriure una hora per canal de sortida hh:mm:ss format 24h
    friend ostream& operator << (ostream& os, Hora hora)
    {
        os << "Hora: ";
        if (hora.h < 10){
            os << "0";
        }
        os << hora.h <<":";

        if (hora.m < 10){
            os << "0";
        }
        os<< hora.m <<":";

        if (hora.s < 10){
            os << "0";
        }
        os<< hora.s << endl;

        return os;
    }

};

class Data{

    int dia, mes, any;

    //Comprovar si la data pertany a un any bissest. Mètode privat. S'utilitza només en la classe
    //Hi ha un altre mètode public amb el mateix nom però sense el paràmetre any.
    bool de_traspas(int any) const
    {
        return ((any % 4 == 0 && any % 100 != 0) or any%400 == 0);
    }

    //Consultar dies d'un mes i any donats. Mètode privat. S'utilitza només en la classe
    int dias_mes(int mes, int any) const
    {
        int dies = 31;
        if (mes == 4 or mes == 6 or mes == 9 or mes == 11) {
            dies = 30;
        }
        else if (mes == 2) {
            if (de_traspas(any) == true) {
                dies = 29;
            }
            else {
                dies = 28;
            }
        }
        return dies;
    }

public:

    //Constructor per defecte amb la data actual, que dóna el sistema, llibreria time.h
    Data(){
        time_t t; //time_t és una tupla de temps (dia, mes any, hora, mins, segs) definit en time.h
        time( &t );
        struct tm* info = localtime( &t );
        dia = info -> tm_mday;
        mes = info -> tm_mon + 1;
        any = 1900+ info -> tm_year; // l'any es comença a comptar a partir del 1900
    }

    //Constructor amb tres paràmetres enters
    Data(int d, int m, int a){
        dia=d;
        mes=m;
        any=a;
    }

    //Constructor amb un paràmetre enter ddmmaaaa
    Data(int ddmmaaaa){
        dia=ddmmaaaa/1000000;
        mes=(ddmmaaaa/10000)%100;
        any=ddmmaaaa%10000;
    }

    //Constructor amb un paràmetre string en format dd:mm:aaaa o dd-mm-aaaa
    //stoi és una funció per converir un string (p.ex "12") en un enter (p.ex. 12)
    Data(string sd){
        string c1 = sd.substr (0,2);//el string dels caràcters dd
        dia=stoi(c1);
        string c2 = sd.substr (3,2);//el string dels caràcters mm
        mes=stoi(c2);
        string c3 = sd.substr (6); //el substring de la 6à posició fins al final
        any=stoi(c3);
    }

    //Métodes consultors
    int getDia() const
    {
        return dia;
    }
    int getMes() const
    {
        return mes;
    }
    int getAny() const
    {
        return any;
    }

    //Comprovar si la data que s'està construint es d'un any de traspàs
    bool de_traspas() const
    {
        return ((any % 4 == 0 && any % 100 != 0) or any%400 == 0);
    }

    //Métodes modificadors. Se suposa que d, m i a són vàlids
    void setDia (int d){
        dia=d;
    }
    void setMes (int m){
        mes=m;
    }
    void setAny (int a){
        any=a;
    }

    //Nombre de dies d'un any
    int diesAny(int any) const
    {
        int dies = 365;
        if (de_traspas(any))
        {
            dies = 366;
        }
        return dies;
    }

    //Nombre de dies entre la data que s'està construint i una data donada D. Suposem que la data que s'està construint és menor o igual que la data D
    int diesFinsLaData(const Data& D) const
    {
        // Nombre total de dies fins la data que s'està construint
        int dies1 = any * 365 + dia;

        // Afegim els dies corresponents als mesos de la data que s'està construint
        for (int m =0;  m < mes-1; m++)
        {
           dies1 += dias_mes(mes, any);
        }

     // Fem el mateix càlcul per la data donada D

        // Nombre total de dies fins la data D
        int dies2 = D.any * 365 + D.dia;

        // Afegim els dies corresponents als mesos de la data D
        for (int m =0;  m < D.mes-1; m++)
        {
           dies2 += dias_mes(D.mes, D.any);
        }

        // el nombre de dies entre les dues dates és la diferència
        return (dies2 - dies1);
    }

    //Incrementar la data amb una quantitat de dies
    void incrementaData (int dd){
        dia=dia+dd;
        if (dia > dias_mes(mes, any)) {
            dia = dia-dias_mes(mes,any);
            mes++;
            if (mes > 12) {
                mes = 1;
                any++;
            }
        }
    }

    //Comptem els anys de traspàs fins una data
    int anysDeTraspas(const Data& D) const
    {
        int anys = D.any;

        //Comprovem si l'any actual s'ha de comprovar igualment
        if (D.mes <= 2)
            anys--;

        return D.any / 4
               - D.any / 100
               + D.any / 400;
    }
    //Resta dues dates
    int operator - (const Data& D)
    {
        const int diesMes[12]
            = { 31, 28, 31, 30, 31, 30,
               31, 31, 30, 31, 30, 31 };

        //Comptem el total de dies fins data que s'est� construint
        int dies1 = any * 365 + dia;

        //Afegim els dies dels mesos
        for (int m = 0; m < mes - 1; m++)
            dies1 += diesMes[m];

        //Tenint en compte els anys de traspas...afegim un dia per cada any
        Data DD(dia,mes,any);
        dies1 += anysDeTraspas(DD);

        //Fem el mateix amb D

        int dies2 = D.any * 365 + D.dia;
        for (int m = 0; m < D.mes - 1; m++)
            dies2 += diesMes[m];
        dies2 += anysDeTraspas(D);

        //retornen la diferència de dies dels dos anys
        return abs(dies2 - dies1);
    }

    //Comparar dues dates <
    friend bool operator < (const Data& d1, const Data& d2)
    {
        return (d1.any*10000+d1.mes*100+d1.dia < d2.any*10000+d2.mes*100+d2.dia);
    }

    //Comparar dues dates <=
    friend bool operator <= (const Data& d1, const Data& d2)
    {
        return (d1.any*10000+d1.mes*100+d1.dia <= d2.any*10000+d2.mes*100+d2.dia);
    }

    //Comparar dues dates ==
    friend bool operator == (const Data& d1, const Data& d2)
    {
        return (d1.any*10000+d1.mes*100+d1.dia == d2.any*10000+d2.mes*100+d2.dia);
    }
    //Escriure una data per canal de sortida dd/mm/aaaa
   friend ostream& operator << (ostream& os, const Data d)
    {
        os << "Data: ";
        if (d.dia < 10){
            os << "0";
        }
        os << d.dia <<"/";

        if (d.mes < 10){
            os << "0";
        }
        os<< d.mes << "/" << d.any<<endl;

        return os;
    }
    //Llegir una data per canal d'entrada dd mm aaaa
   friend istream& operator >> (istream& is, Data& d)
    {
        is >> d.dia >> d.mes >> d.any;

        return is;
    }

};

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
    os<<" -------------------------------"<<endl;
    os<<" Area de Jocs ID: "<< Obj.AJ_Id<<endl;
    os<<" Area de Jocs M2: "<< Obj.AJ_M2<<endl;
    os<<" Area de Jocs Edat ID: "<< Obj.AJ_Edat_Id<<endl;
    os<<" Area de Jocs Edat: "<< Obj.AJ_Edat<<endl;
    os<<" Codi: "<< Obj.Codi<< endl;
    os<<" Tipus: "<< Obj.Tipus<< endl;

    return os;
}

                    ///OPERATOR CIN

friend istream & operator>>(istream & is, ObjetoParque & Obj)
{
    cout<<" - Area de Jocs ID: "; is>>Obj.AJ_Id;
    cout<<" - Area de Jocs M2: "; is>>Obj.AJ_M2;
    cout<<" - Area de Jocs Edat ID: "; is>>Obj.AJ_Edat_Id;
    cout<<" - Area de Jocs Edat: "; is>>Obj.AJ_Edat;
    cout<<" - Codi: "; is>>Obj.Codi;
    cout<<" - Tipus: "; is>>Obj.Tipus;

    return is;
}
    ObjetoParque & operator = (const ObjetoParque & Obj)
    {
        if(this != & Obj)
        {
            AJ_Id = Obj.AJ_Id;
            AJ_M2 = Obj.AJ_M2;
            AJ_Edat_Id = Obj.AJ_Edat_Id;
            AJ_Edat = Obj.AJ_Edat;
            Codi = Obj.Codi;
            Tipus = Obj.Tipus;
        }
        return *this;
    }

};

typedef vector<ObjetoParque> VOP;

///--------------------------------------------> CLASSE

class Lugar
{
  private:

  int  Codi_V , Codi_D , Codi_B , AJ_Id ; //Codi Via , Codi Districte , Codi Barri
  string Nom_V , Nom_D , Nom_B ; //Nom Via , Nom Districte , Nom Barri
  string Tipus_V; //Tipus Via
  int Num_P,SPVC; //Numero Postal
  string Long , Lat ,X9,Y9,SPVN; //Longitud  Latitud
  Data DAfegit,DEditat;
  Hora HAfegit,HEditat;


  public:

///------------------------------> CONSTRUCTORS

Lugar(){}

Lugar(int Codi_V, int Codi_D, int Codi_B, int Num_P, string Long, string Lat,string Nom_V, string Nom_D, string Nom_B, string Tipus_V , int AJ_Id,Data DAfegit,Data DEditat, Hora HEditat, Hora HAfegit){
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
    this -> DAfegit =DAfegit;
    this -> HAfegit = HAfegit;
    this -> DEditat = DEditat;
    this -> HEditat = HEditat;
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
    DAfegit = Loc.DAfegit;
    HAfegit = Loc.HAfegit;
    DEditat = Loc.DEditat;
    HEditat = Loc.HEditat;
}

///-----------------------------------------------> METODES

                ///METODES GET

int getAJ_Id()const {return AJ_Id;}
int getCodi_V()const {return Codi_V;}
int getCodi_D()const {return Codi_D;}
int getCodi_B()const {return Codi_B;}
int getNum_P()const {return Num_P;}
int getSPVC()const {return SPVC;}
string getNom_V()const {return Nom_V;}
string getNom_D()const {return Nom_D;}
string getNom_B()const {return Nom_B;}
string getTipus_V()const {return Tipus_V;}
string getLong()const  {return Long;}
string getLat()const  {return Lat;}
string getX9()const {return X9;}
string getY9 ()const {return Y9;}
string getSPVN () const {return SPVN;}
Data getDAdd () const {return DAfegit;}
Data getDEdit () const {return DEditat;}
Hora getHAdd () const {return HAfegit;}
Hora getHEdit () const {return HEditat;}

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
void setX9(string X9){this -> X9 = X9;}
void setY9(string Y9){this -> Y9 = Y9;}
void setSPVC(int SPVC){this -> SPVC = SPVC;}
void setSPVN(string SPVN){this -> SPVN = SPVN;}
void setDAdd (Data DAfegit){this -> DAfegit = DAfegit;}
void setDEdit (Data DEditat){this -> DEditat = DEditat;}
void setHAdd (Hora HAfegit){this -> HAfegit = HAfegit;}
void setHEdit (Hora HEditat){this -> HEditat = HEditat;}

                ///OPERADOR COUT

friend ostream & operator<<(ostream & os, const Lugar & Loc){

    os<<" -------------------------------"<<endl;
    os<<" ººººººººººººººººººººººººººººººº"<<endl;
    os<<" -------------------------------"<<endl;
    os<<" Id de l'area de joc :"<<Loc.AJ_Id<<endl;
    os<<" Codi de la via :"<<Loc.Codi_V<<endl;
    os<<" Codi del districte :"<<Loc.Codi_D<<endl;
    os<<" Codi del barri :"<<Loc.Codi_B<<endl;
    os<<" nom de la via: "<<Loc.Nom_V<<endl;
    os<<" nom del barri: "<<Loc.Nom_B<<endl;
    os<<" nom del districte: "<<Loc.Nom_D<<endl;
    os<<" tipus de via: "<<Loc.Tipus_V<<endl;
    os<<" numero postal: "<<Loc.Num_P<<endl;
    os<<" Latitud: "<<Loc.Lat<<endl;
    os<<" Longitud: "<<Loc.Long<<endl;
    os<<" Data Afegit: "<<Loc.DAfegit<<" "<<Loc.HAfegit<<endl;
    os<<" Data Editat: "<<Loc.DEditat<<" "<<Loc.HEditat<<endl;

  return os;
}

                ///OPERADOR CIN

friend istream & operator>>(istream & is, Lugar & Loc)
{

    cout<<" - Id de l'area de joc: "; is>>Loc.AJ_Id;
    cout<<" - Nom del Districte: "; is>>Loc.Nom_D;
    cout<<" - Codi del Districte: "; is>>Loc.Codi_D;
    cout<<" - Nom del Barri: "; is>>Loc.Nom_B;
    cout<<" - Codi del Barri: "; is>>Loc.Codi_B;
    cout<<" - Nom de la Via: "; is>>Loc.Nom_V;
    cout<<" - Codi de la Via: "; is>>Loc.Codi_V;
    cout<<" - Tipus de Via: "; is>>Loc.Tipus_V;
    cout<<" - Numero Postal: "; is>>Loc.Num_P;
    cout<<" - Longitud: "; is>>Loc.Long;
    cout<<" - Latitud: "; is>>Loc.Lat;

    return is;
}

Lugar & operator = (const Lugar & Lug)
    {
        if(this != & Lug)
        {
            AJ_Id = Lug.AJ_Id;
            Nom_D = Lug.Nom_D;
             Codi_D= Lug.Codi_D;
            Nom_B = Lug.Nom_B;
            Codi_B = Lug.Codi_B;
            Nom_V = Lug.Nom_V;
            Codi_V = Lug.Codi_V;
            Tipus_V = Lug.Tipus_V;
            Num_P = Lug.Num_P;
            Long = Lug.Long;
            Lat = Lug.Lat;
            DAfegit = Lug.DAfegit;
            HAfegit = Lug.HAfegit;
            DEditat = Lug.DEditat;
            HEditat = Lug.HEditat;
        }
        return *this;
    }

};

typedef vector<Lugar> VL;

///----------------------------------> CLASSE

class Parque
{
private:

    Lugar LUG;
    VOP Obj;

public:

///-----------------------------------------> CONSTRUCTORS

    Parque(){}

///----------------------------------------------------------> METODES

    void Insertar_En_Vector_Objeto(const ObjetoParque & OBJ)
    {
        Obj.push_back(OBJ);
    }

    int ObjSize()const{return Obj.size();}

    ObjetoParque getVObj(int q)const {return Obj[q];}

    void SetLUG(Lugar & LUG){this -> LUG = LUG;}

     void Clear(){Obj.clear();}

     void SetVOP(int numerin,ObjetoParque & Obj){this -> Obj[numerin] = Obj;}

     Lugar getLUG()const {return LUG;}

     VOP GetVOP()const{return Obj;}

     void ERASE( vector<ObjetoParque>::iterator & It){Obj.erase(It);}

    void pushObj(ObjetoParque & ob){Obj.push_back(ob);}

                    ///OPERADOR COUT

     friend ostream & operator<<(ostream & os, const Parque & Pp){
        os<<Pp.LUG;
        for(int x = 0; x < Pp.Obj.size(); x++)
        {
            os<<Pp.Obj[x];
        }

    return os;
    }

    friend bool operator < (const Parque & PA, const Parque & PB)
    {
        if(PA.getLUG().getAJ_Id() != PB.getLUG().getAJ_Id())
        {
            return PA.getLUG().getAJ_Id() < PB.getLUG().getAJ_Id();
        }

        if(PA.getLUG().getNom_B() != PB.getLUG().getNom_B())
        {
            return PA.getLUG().getNom_B() < PB.getLUG().getNom_B();
        }

        if(PA.getLUG().getNom_D() != PB.getLUG().getNom_D())
        {
            return PA.getLUG().getNom_D() < PB.getLUG().getNom_D();
        }

        if(PA.getLUG().getNum_P() != PB.getLUG().getNum_P())
        {
            return PA.getLUG().getNum_P() < PB.getLUG().getNum_P();
        }

        if(PA.getVObj(0).getAJ_Edat() != PB.getVObj(0).getAJ_Edat())
        {
            return PA.getVObj(0).getAJ_Edat() < PB.getVObj(0).getAJ_Edat();
        }

    }



};

///-----------------------------------------------> CLASSE GLOBAL

class Parques_Barna
{
    private:

    VOP Obj;
    VL Lug;
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
        //P.VLongLatCompletiser();
        VPS.push_back(P);
        P.Clear();
        }
    }

    public:

///-------------------------------------------> CONSTRUCTORS

    Parques_Barna(ifstream & Data)
    {

        Lugar L;
        ObjetoParque O;

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
            L.setX9(x_etrs89);
            L.setY9(y_etrs89);
            L.setSPVC(SPVC);
            L.setSPVN(SPVN);

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
        Sorting();
    }

///---------------------------------------------------------> METODES

    Parque getParque(int q)const {return VPS[q];}

    void Sorting()
    {
        sort(VPS.begin(),VPS.end());
    }

    int Comparator(int Start,int Final,int Q)
    {
        while(Start <= Final){
            int mid = (Start+Final)/2;
            if(Q > VPS[mid].getLUG().getAJ_Id())
            {
                Start = mid + 1;
            }
            else if(Q < VPS[mid].getLUG().getAJ_Id())
            {
                Final = mid -1;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }

    void Save_File()
    {
        ofstream Datout("DATA_PARQUES_BARNA_SAFE.txt");
        for(int i = 0; i < VPS.size();i++)
        {
            for(int j = 0; j < VPS[i].GetVOP().size();j++)
            {
                Datout<<" "<<VPS[i].getVObj(j).getCodi()<<" "<<VPS[i].getLUG().getAJ_Id()<<" "<<VPS[i].getVObj(j).getTipus()
                <<" "<<VPS[i].getVObj(j).getAJ_M2()<<" "<<VPS[i].getVObj(j).getAJ_Edat_Id()<<" "<<VPS[i].getVObj(j).getAJ_Edat()
                <<" "<<VPS[i].getLUG().getCodi_V()<<" "<<VPS[i].getLUG().getTipus_V()<<" "<<VPS[i].getLUG().getNom_V()
                <<" "<<VPS[i].getLUG().getNum_P()<<" "<<VPS[i].getLUG().getCodi_D()<<" "<<VPS[i].getLUG().getNom_D()
                <<" "<<VPS[i].getLUG().getCodi_B()<<" "<<VPS[i].getLUG().getNom_B()<<" "<<VPS[i].getLUG().getX9()
                <<" "<<VPS[i].getLUG().getY9()<<" "<<VPS[i].getLUG().getLong()<<" "<<VPS[i].getLUG().getLat()
                <<" "<<VPS[i].getLUG().getSPVC()<<" "<<VPS[i].getLUG().getSPVN()<<endl;
            }
        }

    }

   int Edit()
    {
        Sorting();
        bool TotCorrecte = false, adv = false;
        Lugar L;
        ObjetoParque O;
        vector<Parque>::iterator itVP = VPS.begin();

        while(TotCorrecte == false)
        {
            system("Color E9");system("cls");
            int Search,asc,numerin,Editor;
            cout<<endl<<" Inserta el ID de l'area de Joc que vols editar: ";cin>>Search; Editor = Search;
            Search = Comparator(0,VPS.size(),Search);
            if(Search != -1)
            {
                    cout<<endl<<" - Editar la localitzacio (1)"<<endl<<endl<<" - Editar els objectes (2)"<<endl<<endl<<" - Surt de l'editor (3)"<<endl<<endl<<" ---> ";cin>>asc;;

                    if(asc == 2)
                        {
                            system("cls");
                            cout<<endl<<" Pots editar "<<VPS[Search].ObjSize()<<", inserta el seguent objecte que vulguis editar, o surt de l'editor d'objectes insertan cualsevol tecla: "<<endl<<endl<<" ---> ";cin>>numerin;
                            if(numerin > VPS[Search].ObjSize() || numerin <= 0){system("Color E0");return 0;}
                            else
                            {
                                numerin--;
                                cout<<VPS[Search].getVObj(numerin)<<endl;
                                cout<<" As escollit aquest objecte. "<<endl<<endl;
                                if (adv == false){advance(itVP,Search);adv = true;}
                                cin>>O;
                                O.setAJ_Id(Editor);
                                itVP->SetVOP(numerin,O);
                                Data D;
                                Hora H;
                                VPS[Search].getLUG().setDEdit(D);
                                VPS[Search].getLUG().setHEdit(H);
                            }
                        }

                    if(asc == 1)
                    {
                        system("cls");
                        advance(itVP,Search);
                        cout<<endl;cin>>L;
                        L.setAJ_Id(Editor);
                        itVP->SetLUG(L);
                        cout<<endl<<" - Editar un altre objecte (1)"<<endl<<endl<<" - Sortir de l'editor (2)"<<endl<<endl<<" ---> "; cin>>asc;
                        if(asc == 1){Edit();}
                        else {system("Color E0");system("cls");return 0;}
                    }

                    else if(asc == 3){system("Color E0");system("cls");return 0;}

                    else {system("cls");cout<<endl<<" Inserta un valor correcte: "<<endl<<endl;}
            }
        }
    }

    void AddO(int numerin,int Editor, ObjetoParque & O,Parque & P)
    {system("cls");
        cout<<endl<<endl<<" Vols afegir un nou objecte: "<<endl<<endl<<" - Si (1)"<<endl<<endl<<" - No (2)"<<endl<<endl<<" ---> ";cin>>numerin;cout<<endl;
                if(numerin == 1)
                {
                    cin>>O;
                    O.setAJ_Id(Editor);
                    P.pushObj(O);
                    AddO(numerin,Editor,O,P);

                }
    }

    int Add()
    {
        system("color EA");system("cls");
        Lugar L;
        ObjetoParque O;
        Parque P;
        int Editor = 0,numerin = 0;
        bool correcte = true;
        vector<Parque>::iterator itVP = VPS.begin();

        cout<<endl<<" - Afegir un nou parc (1)"<<endl<<endl<<" - Afegir un nou objecte a un parc existent (2)"<<endl<<
        endl<<" - Sortir de l'editor (3)"<<endl<<endl<<" ---> ";cin>>numerin;cout<<endl;

        if(numerin == 1)
        {
            system("cls");
            cout<<endl<<" Inserta la localitzacio del parc que vols afegir: "<<endl<<endl;cin>>L;
            if(Comparator(0,VPS.size(),L.getAJ_Id()) == -1)
            {
                P.SetLUG(L);
                Editor = P.getLUG().getAJ_Id();
                AddO(numerin,Editor,O,P);
                Data D;
                Hora H;
                if(P.GetVOP().size()== 0){cout<<endl<<endl<<" !! Al no tenir cap objecte no s'ha guardat correctament !!"<<endl<<endl;}
                VPS.insert(itVP,P);
            }
            Add();
        }
        else if(numerin == 2)
        {
            system("cls");
            while(correcte == true)
            {
                cout<<endl<<" Inserta el ID de l'area de Joc que vols afegir un objecte: ";cin>>numerin;cout<<endl;Editor = numerin;
                numerin = Comparator(0,VPS.size(),numerin);
                if(numerin != -1)
                {
                    L = VPS[numerin].getLUG();
                    P = VPS[numerin];
                    AddO(numerin,Editor,O,P);
                    advance(itVP,numerin);
                    *itVP = P;
                    correcte = false;
                }
                else{system("cls");cout<<endl<<" El valor insertat no existeix, torna a insertar un valor existent: "<<endl;}
            }
            Add();
        }
        system("cls");
        system("Color E0");
        return 0;
    }

    int Delete()
    {
        Sorting();
        vector<Parque>::iterator itVP = VPS.begin();
        vector<ObjetoParque>::iterator itVOP;
        system ("cls");
        system("Color E4");
        int Search,asc;

            cout<<endl<<" Inserta el ID de l'area de Joc que vols eliminar: ";cin>>Search;
            Search = Comparator(0,VPS.size(),Search);
            if(Search != -1)
            {
                cout<<endl<<" - Eliminar el parc (1) "<<endl<<endl<<" - Eliminar un objecte (2) "<<endl<<endl<<" - Sortir de l'editor (3)"<<endl<<endl;cin>>asc;
                if(asc == 1)
                {
                    system ("cls");
                    advance(itVP,Search);
                    VPS.erase(itVP);
                    Delete();
                }
                else if(asc == 2)
                {
                    while(true)
                    {

                        system ("cls");
                        cout<<endl<<" Pots eliminar "<<VPS[Search].ObjSize()<<", inserta el seguent objecte que vulguis eliminar, o surt de l'editor d'objectes insertan cualsevol tecla: "<<endl<<endl<<" ---> ";cin>>asc;
                        if(asc > VPS[Search].ObjSize() || asc <= 0){system("cls");system("Color E0");return 0;}
                        else
                        {
                            asc--;
                            cout<<endl<<VPS[Search].getVObj(asc)<<endl;
                            cout<<endl<<" As escollit aquest objecte. "<<endl<<endl;
                            itVOP = VPS[Search].GetVOP().begin();
                            advance(itVOP,asc);
                            cout<<" ";
                            VPS[Search].ERASE(itVOP);
                            cout<<" - Eliminar un altre objecte (1)"<<endl<<endl<<" - Sortir de l'editor (2) "<<endl<<endl;cin>>asc;
                            if(asc == 2){system("cls");system("Color E0");return 0;}
                        }
                    }
                }
                else if(asc == 3){system("Color E0");system("cls");return 0;}
            }
            else
            {
                cout<<endl<<" El valor insertat no existeix, torna a insertar un valor existent: "<<endl;
            }
    }

 void buscarPorIDLugar() {


 int id,Buscador,aux;
 Sorting();
system("Color E9");system("cls");

        cout << " Introduce el ID del lugar: ";
        cin >>id;
        Buscador=Comparator(0,VPS.size(),id);


   if(Buscador != -1)
            {
                cout << " Los datos del lugar con ID " << id << " son los siguientes: " << endl;
                  cout<<VPS[Buscador]<<endl;}

            else {
        cout << " No se encontro ningun lugar con el ID especificado." << endl;
    }
}

 void BuscarPorDistrito() {
    system("Color E9");
    system("cls");
    Sorting();
    int aux=0,u=1;
    string nDistrito;
    bool encontrado=false;
    cout << " Introduce el nombre del distrito para ver los parques que hay: " << endl;
    cout << " Ejemplo: Sant_Marti" << endl;
    cin >> nDistrito;

    for (int i = 0; i < VPS.size(); i++) {

        if (nDistrito == VPS[i].getLUG().getNom_D()) {

            cout << " ID del parque num "<<u<<" en el distrito _ " << VPS[i].getLUG().getAJ_Id() << endl;
            u++;
             aux++;

        }

        }

        cout<<" hay un total de "<<aux<<" parques!!!!"<<endl;
    }


 void BuscarPorBarrio() {
    system("Color E9");
    system("cls");
    Sorting();
    int aux=0,u=1;
    string nBarrio;
    bool encontrado=false;
    cout << " Introduce el nombre del barrio para ver los parques que hay: " << endl;
    cout << " Ejemplo: la_Verneda_i_la_Pau" << endl;
    cin >> nBarrio;

    for (int i = 0; i < VPS.size(); i++) {

        if (nBarrio == VPS[i].getLUG().getNom_B()) {

            cout << " ID del parque num "<<u<<" en el barrio " << VPS[i].getLUG().getAJ_Id() << endl;
            u++;
             aux++;

        }

    }

        cout<<" hay un total de "<<aux<<" parques!!!!"<<endl;
    }

    void BuscarPorCP() {
    system("Color E9");
    system("cls");
    Sorting();
    int aux=0,u=1,CP;
    string nDistrito;
    bool encontrado=false;
    cout << " Introduce el codigo postal para ver los parques que hay: " << endl;
    cin >> CP;

    for (int i = 0; i < VPS.size(); i++) {

        if (CP == VPS[i].getLUG().getNum_P()) {

            cout << " ID del parque num "<<u<<" con codigo postal :" << VPS[i].getLUG().getAJ_Id() << endl;
            u++;
             aux++;

        }

    }
}

void BuscarPorEdad() {
    system("Color E9");
    system("cls");
    Sorting();
    int aux = 0, u = 1, opcion;
    string nDistrito;
    bool encontrado = false;
    cout << endl;
    cout << " Ver la ID de los parques que hay por franja de edad " << endl;
    cout << endl;
    cout << " (1) FINS_A_5_ANYS  " << endl;
    cout << endl;
    cout << " (2) DE_6_A_12_ANYS " << endl;
    cout << endl;
    cout << " (3) MIXTA " << endl;
    cout << endl;
    cin >> opcion;

    switch (opcion) {
        case 1: {
            string uno = " FINS_A_5_ANYS";
            for (int i = 0; i < VPS.size(); i++) {
                if (uno == VPS[i].getVObj(0).getAJ_Edat()) {
                    cout << " ID del objeto num " << u << " de franja de edad " << uno << " " << VPS[i].getLUG().getAJ_Id() << endl;
                    u++;
                    aux++;
                }
            }
            cout << " hay un total de " << aux << " objetos!!!!" << endl;
            break;
        }
        case 2: {
            string dos = " DE_6_A_12_ANYS";
            for (int i = 0; i < VPS.size(); i++) {
                if (dos == VPS[i].getVObj(0).getAJ_Edat()) {
                    cout << " ID del objeto num " << u << " de franja de edad " << dos << " " << VPS[i].getLUG().getAJ_Id() << endl;
                    u++;
                    aux++;
                }
            }
            cout << " hay un total de " << aux << " objetos!!!!" << endl;
            break;
        }
        case 3: {
            string tres = " MIXTA";
            for (int i = 0; i < VPS.size(); i++) {
                if (tres == VPS[i].getVObj(0).getAJ_Edat()) {
                    cout << " ID del objeto num " << u << " de franja de edad " << tres << " " << VPS[i].getLUG().getAJ_Id() << endl;
                    u++;
                    aux++;
                }
            }
            cout << " hay un total de " << aux << " objetos!!!!" << endl;
            break;
        }
        default:
            cout << " Opción no válida." << endl;
            break;
    }
}


                        ///OPERADOR COUT

    friend ostream & operator<<(ostream & os, const Parques_Barna & PB){
        for(int x = 0; x < PB.VPS.size(); x++)
        {
          os<<PB.VPS[x];
        }
    return os;
    }
};

///-------------------------------------------------> MAIN


int main()
{
    system("color E0");

    bool t = true, y = true;
    int x,j;

    ifstream Data("DATA.txt");
    Parques_Barna P(Data);

    while(t)
    {
        system("cls");
        y = true;
        cout<<endl;
        cout<<" |-------------------------------------------------------------------------|"<<endl;
        cout<<" Escull una opcio valida:\n" <<endl;
        cout<<" (1): Consultar informacio parc \n"<<endl;
        cout<<" (2):Modificar Informacio parc \n"<<endl;
        cout<<" (3):Eliminar Parc/Objecte \n"<<endl;
        cout<<" (4):Afegir Parc/Objecte \n"<<endl;
        cout<<" (5):Guardar \n"<<endl;
        cout<<" (6):Sortir del programa \n"<<endl;
        cout<<" |-------------------------------------------------------------------------|"<<endl<<endl;
        cout<<" ";cin>> x;

        switch (x)
        {
        case 1:
            while(y){
                    system("cls");
                int z;
                system("cls");
                cout<<endl;
                cout<<" |-------------------------------------------------------------------------|"<<endl;
                cout<<" Escull una opcio valida:\n" <<endl;
                cout<<" (1):Busqueda per ID \n"<<endl;
                cout<<" (2):Busqueda per Nom del Barri \n"<<endl;
                cout<<" (3):Busqueda per Nom del Districte \n"<<endl;
                cout<<" (4):Busqueda per Codi Postal \n"<<endl;
                cout<<" (5):Busqueda per Edat \n"<<endl;
                cout<<" (6):Tornar enrera \n"<<endl;
                cout<<" |-------------------------------------------------------------------------|"<<endl<<endl;
                cout<<" ";cin>> j;
                switch(j)
                {
                case 1:
                    P.buscarPorIDLugar();
                    cout<<" (1) Tornar a buscar: "<<endl<<endl;
                    cout<<" (2) Tornar enrera: "<<endl<<endl;
                    cin>>x;
                    switch(z)
                    {
                    case 1:
                    P.buscarPorIDLugar();
                        break;
                    case 2:
                        main();
                        break;
                    }
                    break;
                case 2:
                    P.BuscarPorBarrio();
                    cout<<" (1) Tornar a buscar: "<<endl<<endl;
                    cout<<" (2) Tornar enrera: "<<endl<<endl;
                    cin>>x;
                    switch(z)
                    {
                    case 1:
                    P.BuscarPorBarrio();
                        break;
                    case 2:
                        main();
                        break;
                    }
                    break;
                case 3:
                    P.BuscarPorDistrito();
                    cout<<" (1) Tornar a buscar: "<<endl<<endl;
                    cout<<" (2) Tornar enrera: "<<endl<<endl;
                    cin>>x;
                    switch(z)
                    {
                    case 1:
                    P.BuscarPorDistrito();
                        break;
                    case 2:
                        main();
                        break;
                    }
                    break;
                case 4:
                    P.BuscarPorCP();
                    int x;
                    cout<<" (1) Tornar a buscar: "<<endl<<endl;
                    cout<<" (2) Tornar enrera: "<<endl<<endl;
                    cin>>x;
                    switch(z)
                    {
                    case 1:
                    P.BuscarPorCP();
                        break;
                    case 2:
                        main();
                        break;
                    }
                    break;
                case 5:
                    P.BuscarPorEdad();
                    cout<<" (1) Tornar a buscar: "<<endl<<endl;
                    cout<<" (2) Tornar enrera: "<<endl<<endl;
                    cin>>x;
                    switch(z)
                    {
                    case 1:
                    P.BuscarPorEdad();
                        break;
                    case 2:
                        main();
                        break;
                    }
                    break;
                case 6:
                    system("cls");
                    main();
                default:
                    y = false;
                }
            }
            break;
        case 2:
            P.Edit();
            break;
        case 3:
            P.Delete();
            break;
        case 4:
            P.Add();
            break;
        case 5:
            P.Save_File();
            system("cls");
            break;
        case 6:
            y = false;
            t = false;
            return 0;
            break;
        default:
            main();
            break;
        }
    }
}
