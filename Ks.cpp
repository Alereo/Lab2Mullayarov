#include "Ks.h"
#include <string>
using namespace std;
int Ks::id = 0;
Ks::Ks()
{
    amountWorkshops = amountWorkshopsNow = effectiveness = 0;
}
Ks::Ks(string name, int amountWorkshops, int amountWorhshopsNow) {
    Ks::name = name;
    Ks::amountWorkshops = amountWorkshops;
    Ks::amountWorkshopsNow = amountWorhshopsNow;
    id++;
    uptadeEff();
}
void Ks::uptadeEff()
{
    Ks::effectiveness = (int)(Ks::amountWorkshopsNow / (double)Ks::amountWorkshops * 100);
}
void Ks::cout() {
    std::cout << "���: " << name << endl << "���������� �����: " << amountWorkshops << endl <<
        "���������� ����� � ������: " << amountWorkshopsNow << endl << "�������������: " << effectiveness << "%" << endl;
}
void Ks::cout(ofstream& file) {
    file << "���: " << name << endl << "���������� �����: " << amountWorkshops << endl <<
        "���������� ����� � ������: " << amountWorkshopsNow << endl << "�������������: " << effectiveness << "%" << endl;
}