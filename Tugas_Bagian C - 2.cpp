#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

struct Pasien {
    string nama;
    int prioritas;
    int datang;
};

struct BandingPasien {
    bool operator()(const Pasien& a,
                    const Pasien& b) const {
        if (a.prioritas == b.prioritas) {
            return a.datang > b.datang;
        }

        return a.prioritas > b.prioritas;
    }
};

int main() {
    priority_queue<Pasien, vector<Pasien>,
                   BandingPasien> igd;

    igd.push({"Galeh", 3, 1});
    igd.push({"Khabib", 1, 2});
    igd.push({"Pramana", 2, 3});
    igd.push({"Bunga", 1, 4});

    cout << "Urutan pelayanan pasien IGD:\n";

    while (!igd.empty()) {
        Pasien p = igd.top();

        cout << p.nama
             << " (prioritas  " << p.prioritas
             << ")\n";

        igd.pop();
    }

    return 0;
}