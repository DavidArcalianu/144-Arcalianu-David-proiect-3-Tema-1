#include <iostream>
#include <unordered_map>
#include <string>

class Client
{
protected:
    std::string c_nume;
public:
    // constructori + destructor
    Client() : c_nume(""){}
    Client(std::string nume) : c_nume(nume){}
    Client(Client &client) : c_nume(client.c_nume){}
    ~Client(){}
    // getter + setter
    std::string GetClient(){return c_nume;}
    void SetClient(std::string nume){c_nume = nume;}
    // operatori
    Client operator=(Client &client)
    {
        c_nume = client.c_nume;
        return *this;
    }
    friend std::istream &operator>>(std::istream &in, Client &client)
    {
        getline(in, client.c_nume);
        return in;
    }
    friend std::ostream &operator<<(std::ostream &out, Client &client)
    {
        out << "Numele clientului: " << client.c_nume;
        return out;
    }
};

template<typename T>
class Gestiune
{
private:
    int n;
    std::unordered_map<int, T> map;
public:
    // constructori + destructor
    Gestiune() {}
    ~Gestiune() {}
    // getter + setter
    T GetMap(int i) { return map[i]; }
    void SetMap(int i, T x) { map[i] = x; }
    // operatori
    T operator=(T &gestiune)
    {
        n = gestiune.n;
        for(int i=0; i<n; i++)
            map[i] = gestiune.map[i];
    }
    friend std::istream &operator>>(std::istream &in, Gestiune<T> &gestiune)
    {
        in >> gestiune.n;
        for(int i=0; i<gestiune.n; i++)
            in >> gestiune.map[i];
        return in;
    }
    friend std::ostream &operator<<(std::ostream &out, Gestiune<T> &gestiune)
    {
        out << "Numar plati:" << gestiune.n << std::endl;
        for(int i=0; i<gestiune.n; i++)
            out << gestiune.map[i] << " ";
        return out;
    }
//    T operator+=(T &gestiune)
//    {
//        n += 1;
//        map.insert(std::make_pair(n,gestiune));
//        return gestiune;
//    }
//    void afisare()
//    {
//        std::cout << "Numar: " << n << std::endl;
//        for(int i=0; i<n; i++)
//            std::cout << map[i] << " ";
//    }
};

class Plata
{
protected:
    int c_suma;
    std::string c_data;
public:
    // constructori + destructor
    Plata(){}
    Plata(int suma) : c_suma(suma), c_data(""){}
    Plata(int suma, std::string data) : c_suma(suma), c_data(data){}
    Plata(Plata &plata) : c_suma(plata.c_suma), c_data(plata.c_data){}
    ~Plata(){}
    // setteri + getteri
    void SetSuma(int suma) {c_suma = suma;}
    void SetData(std::string data) {c_data = data;}
    int GetSuma(){return c_suma;}
    std::string GetData(){return c_data;}
    // operatori
    Plata operator=(Plata &plata)
    {
        c_suma = plata.c_suma;
        c_data = plata.c_data;
        return *this;
    }
    friend std::istream &operator>>(std::istream &in, Plata &plata)
    {
        in >> plata.c_suma;
        in >> plata.c_data;
        return in;
    }
    friend std::ostream &operator<<(std::ostream &out, Plata &plata)
    {
        out << "Suma platii: " << plata.c_suma << std::endl;
        out << "Data platii: " << plata.c_data << std::endl;
        return out;
    }
    // citire + afisare
    virtual void citire()
    {
        std::cin >> c_suma >> c_data;
    }
    virtual void afisare()
    {
        std::cout << "Suma platii: " << c_suma << std::endl;
        std::cout << "Data platii: " << c_data << std::endl;
    }
};

class Numerar : public Plata
{
public:
    // constructori + destructor
    Numerar(){}
    Numerar(int suma) : Plata(suma){}
    Numerar(int suma, std::string data) : Plata(suma, data){}
    Numerar(Numerar &numerar)
    {
        c_suma = numerar.c_suma;
        c_data = numerar.c_data;
    }
    ~Numerar(){}
    // setteri + getteri
    void SetNumerar(int suma, std::string data){c_suma = suma;}
    void SetNumerar(std::string data){c_data = data;}
    int GetNumerarSuma(){return c_suma;}
    std::string GetNumerarData(){return c_data;}
    // operatori
    Numerar operator=(Numerar &numerar)
    {
        c_suma = numerar.c_suma;
        c_data = numerar.c_data;
        return *this;
    }
    friend std::istream &operator>>(std::istream &in, Numerar &numerar)
    {
        in >> numerar.c_suma;
        in >> numerar.c_data;
        return in;
    }
    friend std::ostream &operator<<(std::ostream &out, Numerar &numerar)
    {
        out << "Suma platii: " << numerar.c_suma << std::endl;
        out << "Data platii: " << numerar.c_data << std::endl;
        return out;
    }
    // citire + afisare
    void citire()
    {
        std::cin >> c_suma >> c_data;
    }
    void afisare()
    {
        std::cout << "Suma platii: " << Plata::GetSuma() << std::endl;
        std::cout << "Data platii: " << Plata::GetData() << std::endl;
    }
};

class Cec : public Plata
{
public:
    // constructori + destructor
    Cec(){}
    Cec(int suma) : Plata(suma){}
    Cec(int suma, std::string data) : Plata(suma, data){}
    Cec(Cec &cec)
    {
        c_suma = cec.c_suma;
        c_data = cec.c_data;
    }
    ~Cec(){}
    // setteri + getteri
    void SetNumerar(int suma, std::string data){c_suma = suma;}
    void SetNumerar(std::string data){c_data = data;}
    int GetNumerarSuma(){return c_suma;}
    std::string GetNumerarData(){return c_data;}
    // operatori
    Cec operator=(Cec &cec)
    {
        c_suma = cec.c_suma;
        c_data = cec.c_data;
        return *this;
    }
    friend std::istream &operator>>(std::istream &in, Cec &cec)
    {
        in >> cec.c_suma;
        in >> cec.c_data;
        return in;
    }
    friend std::ostream &operator<<(std::ostream &out, Cec &cec)
    {
        out << "Suma platii: " << cec.c_suma << std::endl;
        out << "Data platii: " << cec.c_data << std::endl;
        return out;
    }
    // citire + afisare
    void citire()
    {
        std::cin >> c_suma >> c_data;
    }
    void afisare()
    {
        std::cout << "Suma platii: " << Plata::GetSuma() << std::endl;
        std::cout << "Data platii: " << Plata::GetData() << std::endl;
    }
};

class Card : public Plata
{
private:
    int nrCard;
public:
    // constructori + destructori
    Card() : nrCard(0){}
    Card(int nr) : nrCard(nr){}
    Card(Card &card)
    {
        nrCard = card.nrCard;
        c_suma = card.c_suma;
        c_data = card.c_data;
    }
    Card(int nr, int suma, std::string data) : Plata(suma, data), nrCard(nr){}
    ~Card(){}
    // getter + setter
    int GetNrCard() {return nrCard;}
    void SetNrCard(int numar) {nrCard = numar;}
    // operatori
    Card operator=(Card &card)
    {
        nrCard = card.nrCard;
        return *this;
    }
    friend std::istream &operator>>(std::istream &in, Card &card)
    {
        in >> card.nrCard >> card.c_suma >> card.c_data;
        return in;
    }
    friend std::ostream &operator<<(std::ostream &out, Card &card)
    {
        out << "Numarul cardului este: " << card.nrCard << std::endl;
        out << "Suma platii: " << card.c_suma << std::endl;
        out << "Data platii: " << card.c_data << std::endl;
        return out;
    }
    // citire + afisare
    void citire()
    {
        std::cin >> c_suma >> c_data >> nrCard;
    }
    void afisare()
    {
        std::cout << "Suma platii: " << Plata::GetSuma() << std::endl;
        std::cout << "Data platii: " << Plata::GetData() << std::endl;
        std::cout << "Numar card: " << nrCard << std::endl;
    }
};

void printMenuOptions()
{
    std::cout << "1: Cititi n plati si datele lor" << std::endl;
    std::cout << "2: Afisati platile" << std::endl;
    std::cout << "3: Oprire" << std::endl;
}

void Menu()
{
    std::cout << "Alegeti dintre urmatoarele optiuni: " << std::endl;
    printMenuOptions();
    int exit_option = 3;
    int option;
    int nr;

    Gestiune<Plata> G;
    std::cin>>option;

    while(option != 3)
    {
        if(option == 1)
        {
            std::cout << "Cititi numarul de plati:" << std::endl;
            std::cin >> nr;

            std::string tip;

            for(int i=0; i<nr; i++)
            {
                std::cout << "Tipul platii: " << std::endl;
                std::cin >> tip;
                if(tip == "Cec" || tip == "cec")
                {
                    Cec cec;
                    std::cout << "Suma si data platii: " << std::endl;
                    std::cin >> cec;
//                    G += cec;
                }
                else if(tip == "Numerar" || tip == "numerar" || tip == "Cash" || tip == "cash")
                {
                    Numerar numerar;
                    std::cout << "Suma si data platii: " << std::endl;
                    std::cin >> numerar;
//                    G += numerar;
                }
                else if(tip == "Card" || tip == "card")
                {
                    Card card;
                    std::cout << "Numarul cardului, suma platii si data platii: " << std::endl;
                    std::cin >> card;
//                    G += card;
                }
            }
        }
        else if(option == 2)
        {
//            G.afisare();
            return;
        }
        std::cout << std::endl;
        printMenuOptions();
        std::cin >> option;
    }
}

int main()
{
    Menu();
    return 0;
}
