#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

struct Station {
    string line;
    string name;
};

vector<Station> readStationsFromFile(const string& filename) {
    vector<Station> stations;
    ifstream inputFile(filename);

    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            size_t commaPos = line.find(',');
            if (commaPos != string::npos) {
                Station station;
                station.line = line.substr(0, commaPos);
                station.name = line.substr(commaPos + 1);
                stations.push_back(station);
            }
        }
        inputFile.close();
    } else {
        cerr << "Error: Unable to open file " << filename << endl;
    }

    return stations;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    cout << "Welcome to the MTR Station Slot Machine!" << endl;
    cout << "---------------------------------------" << endl;

    vector<Station> stations = readStationsFromFile("mtr.txt");

    if (stations.empty()) {
        return 1;
    }

    // Simulating the slot machine effect
    for (int i = 0; i < 3; ++i) {
        int randomIndex = rand() % stations.size();

        cout << "Random Number: " << randomIndex + 1 << endl;
        cout << "Line: " << stations[randomIndex].line << endl;
        cout << "Station: " << stations[randomIndex].name << endl;

        cout << "-----------------------" << endl;

        // Delay for the slot machine effect
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    return 0;
}
