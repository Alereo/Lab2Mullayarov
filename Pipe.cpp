#include "Pipe.h"
#include <string>
using namespace std;
int Pipe::id = 0;
Pipe::Pipe()
{
	len = diam = isWorking = 0;
	kmMark = " ";
}
Pipe::Pipe(string name, double len, int diam , bool isWorking) {
	Pipe::kmMark = name;
	Pipe::len = len;
	Pipe::diam = diam;
	Pipe::isWorking = isWorking;
	id++;
}
void Pipe::cout() {
    std::cout << "Километровая отметка: " << this->kmMark << endl << "Длина трубы: " << len << endl << "Диаметр: " << this->diam << endl
        << "Состояние работы трубы: " << isWorking << endl;
}
void Pipe::cout(ofstream& file) {
    file << "Километровая отметка: " << this->kmMark << endl << "Длина трубы: " << len << endl
        << "Диаметр: " << this->diam << endl << "Состояние работы трубы: " << isWorking << endl;
}
