#ifndef FARMACIE_ONLINE_H
#define FARMACIE_ONLINE_H

#include <Farmacie.h>
#include <Negative_Number.h>

class Farmacie_online : public Farmacie
{
    std::string web;
    int nr_viz;
    std::vector<double> discount;
public:
    Farmacie_online();
    Farmacie_online(std::string,int, std::vector<double>);
    virtual ~Farmacie_online();
    Farmacie_online(const Farmacie_online& other);
    Farmacie_online& operator=(const Farmacie_online& other);

    std::string getWeb() const { return this->web; }
    int getNrViz() const { return this->nr_viz; }
    std::vector<double>& getDiscount() { return this->discount; }

    void showData() const;

    friend std::istream& operator>>(std::istream&, Farmacie_online&);
    friend std::ostream& operator<<(std::ostream&, const Farmacie_online&);
};

#endif // FARMACIE_ONLINE_H
