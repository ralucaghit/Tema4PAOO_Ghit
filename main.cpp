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
    Tren tren1(3);
    tren1.setVagon(0, "Vagon marfă");
    tren1.setVagon(1, "Vagon pasageri");
    tren1.afiseazaVagoane();  

    return 0;
}
