#include "Farmacie_online.h"

Farmacie_online::Farmacie_online() : Farmacie()
{
    Farmacie::Numar_Farmacii++;
}


Farmacie_online::~Farmacie_online()
{}

Farmacie_online::Farmacie_online(std::string web, int nr_viz, std::vector<double> discounts)
{
    this->web = web;
    this->nr_viz = nr_viz;
    this->discount = discounts;
    Farmacie::Numar_Farmacii++;
}

Farmacie_online::Farmacie_online(const Farmacie_online& other)
{
    this->web = other.web;
    this->nr_viz = other.nr_viz;
    this->discount = other.discount;
}

Farmacie_online& Farmacie_online::operator=(const Farmacie_online& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    this->web = rhs.web;
    this->nr_viz = rhs.nr_viz;
    this->discount = rhs.discount;
    return *this;
}

void Farmacie_online::showData() const
{
    std::cout << "Farmacia aceasta este online  si contine urmatoarele date:\nAdresa web este: " << this->web << "\nNumarul de vizitatori ai paginii este: " << this->nr_viz
    << "\nDiscounturile folosite de vizitatori sunt in numar de " << this->discount.size() << " si au urmatoarele valori:";
    for(auto it: this->discount)
    {
        std::cout << " " << it;
    }
    std::cout << ".";
}

std::istream& operator>>(std::istream& in, Farmacie_online& f)
{
    in >> f.web >> f.nr_viz;
    int discs;
    in >> discs;
    if(discs < 0 || f.nr_viz < 0) throw Negative_Number();
    while(discs)
    {
        double disc;
        in >> disc;
        f.discount.push_back(disc);
        --discs;
    }
    return in;
}
std::ostream& operator<<(std::ostream& out, const Farmacie_online& f)
{
    f.showData();
    return out;
}
