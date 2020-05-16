#include <string>
#include <iostream>
#include <vector>
#include <fstream>

#ifndef FARMACIE_H
#define FARMACIE_H


class Farmacie
{
protected:
    static int Numar_Farmacii;
public:
    Farmacie();
    virtual ~Farmacie() {};
    Farmacie(const Farmacie& other);
    Farmacie& operator=(const Farmacie& other);

    static int getNrFarmacii() {return Numar_Farmacii;}

    virtual void showData() const = 0;
};

#endif // FARMACIE_H
