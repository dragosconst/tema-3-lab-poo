#ifndef FARMACIE_OFFLINE_H
#define FARMACIE_OFFLINE_H

#include <Farmacie.h>
#include <Negative_Number.h>

class Farmacie_offline : public Farmacie
{
    std::string denumire;
    int nr_angajati;
    std::vector<double> profits;
public:
    Farmacie_offline();
    Farmacie_offline(std::string, int, std::vector<double>);
    ~Farmacie_offline();
    Farmacie_offline(const Farmacie_offline&);
    Farmacie_offline& operator=(const Farmacie_offline&);

    std::string getDenumire() const { return this->denumire;}
    void setDenumire(std::string s) {this->denumire = s;}
    int getNrAngajati() const { return this->nr_angajati;}
    void setNrAngajati(int nr) {this->nr_angajati = nr;}
    std::vector<double> getProfits() { return this->profits;}
    void setProfits(std::vector<double> pr) {this->profits = pr;}

    void showData() const;

    friend std::istream& operator>>(std::istream&, Farmacie_offline&);
    friend std::ostream& operator<<(std::ostream&, const Farmacie_offline&);
};

#endif // FARMACIE_OFFLINE_H
