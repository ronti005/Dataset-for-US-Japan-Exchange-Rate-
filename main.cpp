#include <iostream>
#include <vector>

using namespace std;

struct Data {
    int year;
    double nominalExchangeRate;
    double cpiUS;
    double cpiJapan;
    double realExchangeRate;
};

// Function to calculate Real Exchange Rate
double calculateRealExchangeRate(double nominalExchangeRate, double cpiUS, double cpiJapan) {
    return (nominalExchangeRate * cpiJapan) / cpiUS;
}

int main() {
    // Example dataset (Year, Nominal Exchange Rate, CPI (US), CPI (Japan))
    vector<Data> dataset = {
        {1995, 96.0, 160.0, 101.0, 0},
        {1996, 98.0, 162.0, 102.0, 0},
        {1997, 100.5, 164.0, 103.0, 0},
        {1998, 105.0, 168.0, 104.0, 0},
        {1999, 108.0, 172.0, 105.0, 0},
        // Add more years if needed
    };

    // Calculating Real Exchange Rate for each year
    for (auto& data : dataset) {
        data.realExchangeRate = calculateRealExchangeRate(data.nominalExchangeRate, data.cpiUS, data.cpiJapan);
    }

    // Output the results
    cout << "Year | Nominal Exchange Rate | CPI (US) | CPI (Japan) | Real Exchange Rate" << endl;
    cout << "---------------------------------------------------------" << endl;
    for (const auto& data : dataset) {
        cout << data.year << " | " 
             << data.nominalExchangeRate << " | " 
             << data.cpiUS << " | " 
             << data.cpiJapan << " | " 
             << data.realExchangeRate << endl;
    }

    return 0;
}
