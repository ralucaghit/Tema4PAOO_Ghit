#include <iostream>
#include <string>

class Tren {
    std::string* vagoane; // array dinamic pentru numele vagoanelor
    size_t numarVagoane;

public:
    // constructor: alocă memoria pentru vagoane
    explicit Tren(size_t numarVagoane)
        : numarVagoane(numarVagoane), vagoane(new std::string[numarVagoane]) {
        for (size_t i = 0; i < numarVagoane; i++) {
            vagoane[i] = "Vagon gol"; // inițializez vagoanele cu un nume implicit
        }
    }

    // destructor care eliberează memoria
    ~Tren() {
        delete[] vagoane;
    }

    // constructor de copiere: copiere profundă
    Tren(const Tren& other)
        : numarVagoane(other.numarVagoane), vagoane(new std::string[other.numarVagoane]) {
        for (size_t i = 0; i < other.numarVagoane; i++) {
            vagoane[i] = other.vagoane[i];
        }
    }

    // Operator de atribuire: copiere profunda
    Tren& operator=(const Tren& other) {
        if (this == &other) {
            return *this; // Evit auto-atribuirea
        }

        // Eliberam memoria existenta
        delete[] vagoane;

        // Realocam si copiem datele
        numarVagoane = other.numarVagoane;
        vagoane = new std::string[other.numarVagoane];
        for (size_t i = 0; i < other.numarVagoane; ++i) {
            vagoane[i] = other.vagoane[i];
        }
        
        return *this;
    }

    // setez numele unui vagon
    void setVagon(size_t index, const std::string& nume) {
        if (index < numarVagoane) {
            vagoane[index] = nume;
        }
    }

    // afisare
    void afiseazaVagoane() const {
        std::cout << "Tren: ";
        for (size_t i = 0; i < numarVagoane; i++) {
            std::cout << vagoane[i];
        }
        std::cout << "\n";
    }
};

int main() {
    Tren t1(3);
    t1.setVagon(0, "Vagon marfă");
    t1.setVagon(1, "Vagon pasageri");
    t1.afiseazaVagoane();  

    Tren t2 = t1;        // Constructor de copiere
    t2.setVagon(0, "Vagon special");
    t1.afiseazaVagoane();  
    t2.afiseazaVagoane();

    Tren t3(2);          
    t3 = t1;                // Operator de atribuire
    t3.afiseazaVagoane();   // Afișează: Tren: Vagon marfă, Vagon pasageri, Vagon gol


    return 0;
}
