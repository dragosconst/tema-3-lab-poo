#include "Farmacie_offline.h"

Farmacie_offline::Farmacie_offline() : Farmacie()
{
    Farmacie::Numar_Farmacii++;
}

Farmacie_offline::Farmacie_offline(std::string name, int ang, std::vector<double> pr)
{
    this->denumire = denumire;
    this->nr_angajati = nr_angajati;
    this->profits = profits;
    Farmacie::Numar_Farmacii++;
}

Farmacie_offline::Farmacie_offline(const Farmacie_offline& other)
{
    this->denumire = other.denumire;
    this->nr_angajati = other.nr_angajati;
    this->profits = other.profits;
}

Farmacie_offline& Farmacie_offline::operator=(const Farmacie_offline& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    this->denumire = rhs.denumire;
    this->nr_angajati = rhs.nr_angajati;
    this->profits = rhs.profits;
    return *this;
}

Farmacie_offline::~Farmacie_offline()
{
}

void Farmacie_offline::showData() const
{
    std::cout << "Farmacia aceasta este offline si contine urmatoarele date:\nDenumirea farmaciei este: " << this->denumire << "\nNumarul de angajati este: " << this->nr_angajati
    << "\nProfiturile pe primele " << this->profits.size() << " luni sunt urmatoarele:";
    for(auto it: this->profits)
    {
        std::cout << " " << it;
    }
    std::cout << ".";
}

std::istream& operator>>(std::istream& in, Farmacie_offline& f)
{
    in >> f.denumire >> f.nr_angajati;
    int months;
    in >> months;
    if(months < 0 || f.nr_angajati < 0) throw Negative_Number();
    while(months)
    {
        double pr;
        in >> pr;
        f.profits.push_back(pr);
        --months;
    }

    return in;
}

std::ostream& operator<<(std::ostream& out, const Farmacie_offline& f)
{
    f.showData();
    return out;
}
