#include <iostream>
#include <Farmacie_offline.h>
#include <Farmacie_online.h>
#include <No_Assignment_Possible.h>
#include <Out_Of_Bounds.h>
#include <typeinfo>
using namespace std;

template<class T>
struct node
{
    T info;
    node* next;
};
template<class T>
class GestionareFarmacii
{
    node<T>* FarmaList_first;
    const int lant;
    int len; // adica indexul farmaciei?? cred??
public:
    GestionareFarmacii(int lant) : lant(lant)
    {
        this->FarmaList_first = nullptr;
        this->len = 0;
    }
    GestionareFarmacii(const GestionareFarmacii&);
    GestionareFarmacii& operator=(const GestionareFarmacii&);
    ~GestionareFarmacii();

    int getLength() const { return this->len; }
    int getLant() const { return this->lant; }
    int allAngajati();
    double totalProfit() const;
    int allViews() const;
    double totalDiscounts() const;

    void push(T);
    GestionareFarmacii& operator+=(T);
    T operator[](int);
};

template<>
class GestionareFarmacii<Farmacie_online> // clasa specializata pentru farmacii online
{
    const int lant;
    int numar_total;
public:
    GestionareFarmacii(int lant) : lant(lant)
    {
        this->numar_total = 0;
    }
    GestionareFarmacii(const GestionareFarmacii&);
    GestionareFarmacii& operator=(const GestionareFarmacii&);
    ~GestionareFarmacii();

    int getNumarTotal() const { return this->numar_total; }
    int getLant() const { return this->lant; }

    void push(Farmacie_online);
    GestionareFarmacii& operator+=(Farmacie_online);
};
int main()
{
    vector<Farmacie_online> onlines;
    vector<Farmacie_offline> offlines;
    GestionareFarmacii<Farmacie*> farm_infos(11);
    try{
        cout << "Cate farmacii online exista? ";
        int nr_firm;
        cin >> nr_firm;
        if(nr_firm > 0)
            cout << "Scrie, pe rand, datele pentru fiecare farmacie online.\n";
        while(nr_firm)
        {
            Farmacie_online temp;
            cin >> temp;
            onlines.push_back(temp);
            --nr_firm;
        }

        cout << "Cate farmacii offline exista? ";
        cin >> nr_firm;
        if(nr_firm > 0)
            cout << "Scrie, pe rand, datele pentru fiecare farmacie offline.\n";
        while(nr_firm)
        {
            Farmacie_offline temp;
            cin >> temp;
            offlines.push_back(temp);
            --nr_firm;
        }

        for(int i = 0; i < onlines.size(); ++i)
            farm_infos.push(&onlines[i]);
        for(int i = 0; i < offlines.size(); ++i)
            farm_infos.push(&offlines[i]);
        farm_infos[-1]->showData();
        cout << "\n\nToate farmaciile au un numar de " << farm_infos.allAngajati() << " angajati, profituri totale de " << farm_infos.totalProfit() << "; farmaciile online au fost accesate de "
        << farm_infos.allViews() << " ori si au fost folosite discounturi in valoare totala de " << farm_infos.totalDiscounts() <<"\n";
    }
    catch(exception& e)
    {
        cout << e.what();
    }
    return 0;
}

/// AICI INCEP METODELE PENTRU CLASA TEMPLATE GENERALA

template<class T>
GestionareFarmacii<T>::GestionareFarmacii(const GestionareFarmacii<T>& other) : lant(other.lant)
{
    this->len = other.len;
    node<T>* iter = new node<T>;
    iter->next = nullptr;
    if(other.FarmaList_first != nullptr)
        iter->info = other.FarmaList_first->info;
    else
        iter = nullptr;
    this->FarmaList_first = iter;

    if(iter != nullptr) // adica daca in other exista o lista
    {
        node<T>* iter_other = other.FarmaList_first->next;
        node<T>* old_it = iter; // ca sa copiez o lista inlantuita cu deep copy, e nevoie sa memorez si valoarea precedenta din lista noua
        while(iter_other != nullptr)
        {
            node<T>* temp = new node<T>;
            temp->info = iter_other->info;
            temp->next = nullptr;
            old_it->next = temp;

            iter_other = iter_other->next;
        }
    }
}

template<class T>
GestionareFarmacii<T>& GestionareFarmacii<T>::operator=(const GestionareFarmacii<T>& rhs)
{
    throw No_Assignment_Possible(); // deoarece clasa template are un membru constant, nu are sens sa existe un operator de assignment
}

template<class T>
GestionareFarmacii<T>::~GestionareFarmacii()
{
    this->len = 0;
    node<T>* to_del;
    while(this->FarmaList_first != nullptr)
    {
        to_del = this->FarmaList_first;
        this->FarmaList_first = this->FarmaList_first->next;
        delete to_del;
    }
}

template<class T>
void GestionareFarmacii<T>::push(T farm)
{
    node<T>* iter;
    if(this->FarmaList_first != nullptr)
        iter = this->FarmaList_first;
    else
    {
        iter = new node<T>;
        iter->info = farm;
        iter->next = nullptr;
    }
    while(iter->next != nullptr) // caut ultimul element din lista
    {
        iter = iter->next;
    }

    if(this->FarmaList_first != nullptr)
    {
        node<T>* new_el = new node<T>; // creez un nod pentru farm
        new_el->info = farm;
        new_el->next = nullptr;

        iter->next = new_el; // in final, il leg la lista
    }
    else
    {
        this->FarmaList_first = iter;
    }

    this->len++;
}

template<class T>
GestionareFarmacii<T>& GestionareFarmacii<T>::operator+=(T farm)
{
    this->push(farm);
    return *this;
}

template<class T>
T GestionareFarmacii<T>::operator[](int ind)
{
    if(ind < 0) // pt indecsi negativi, fac ca in python, adica numar din coada
    {
        ind = this->len + ind;
        cout << ind << ' ' << this->len << endl;
    }
    if(ind < 0 || ind > len) throw Out_Of_Bounds();
    node<T>* iter = this->FarmaList_first;
    while(--ind > 0)
    {
        iter = iter->next;
    }
    return iter->info;

}

template<class T>
int GestionareFarmacii<T>::allAngajati()
{
    if(this->FarmaList_first == nullptr) return 0;
    node<T>* iter = this->FarmaList_first;
    int totes = 0;
    while(iter != nullptr)
    {
        if(typeid(*(iter->info)) == typeid(Farmacie_offline))
        {
            totes += (dynamic_cast<Farmacie_offline*>(iter->info))->getNrAngajati();
        }
        iter = iter->next;
    }

    return totes;
}
template<class T>
double GestionareFarmacii<T>::totalProfit() const
{
    if(this->FarmaList_first == nullptr) return 0;
    double totes = 0;
    node<T>* iter = this->FarmaList_first;
    while(iter != nullptr)
    {
        if(typeid(*(iter->info)) == typeid(Farmacie_offline))
        {
            for(auto it : (dynamic_cast<Farmacie_offline*>(iter->info))->getProfits())
            {
                totes += it;
            }
        }
        iter = iter->next;
    }
    return totes;
}
template<class T>
int GestionareFarmacii<T>::allViews() const
{
    if(this->FarmaList_first == nullptr) return 0;
    int totes = 0;
    node<T>* iter = this->FarmaList_first;
    while(iter != nullptr)
    {
        if(typeid(*(iter->info)) == typeid(Farmacie_online))
        {
            totes += (dynamic_cast<Farmacie_online*>(iter->info))->getNrViz();
        }
        iter = iter->next;
    }

    return totes;
}
template<class T>
double GestionareFarmacii<T>::totalDiscounts() const
{
    if(this->FarmaList_first == nullptr) return 0;
    double totes = 0;
    node<T>* iter = this->FarmaList_first;
    while(iter != nullptr)
    {
        if(typeid(*(iter->info)) == typeid(Farmacie_online))
        {
            for(auto it : (dynamic_cast<Farmacie_online*>(iter->info))->getDiscount())
            {
                totes += it;
            }
        }
        iter = iter->next;
    }
    return totes;
}


/// AICI INCEP METODELE PENTRU SPECIALIZARE

GestionareFarmacii<Farmacie_online>::GestionareFarmacii(const GestionareFarmacii<Farmacie_online>& other) : lant(other.lant)
{
    this->numar_total = other.numar_total;
}

GestionareFarmacii<Farmacie_online>& GestionareFarmacii<Farmacie_online>::operator=(const GestionareFarmacii<Farmacie_online>& rhs)
{
    throw No_Assignment_Possible(); // deoarece clasa template are un membru constant, nu are sens sa existe un operator de assignment
}

GestionareFarmacii<Farmacie_online>::~GestionareFarmacii()
{
}

void GestionareFarmacii<Farmacie_online>::push(Farmacie_online farm)
{
    this->numar_total += farm.getNrViz();
}

GestionareFarmacii<Farmacie_online>& GestionareFarmacii<Farmacie_online>::operator+=(Farmacie_online farm)
{
    this->push(farm);
    return *this;
}
