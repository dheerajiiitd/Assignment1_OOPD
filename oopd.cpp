#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <tuple>
using namespace std;

int main() {
    ifstream file("india_data.csv");
    int year = 1;
    int rateInterest = 2;
    int rateInflation = 3;

    if (!file.is_open()) {
        cerr << "unable to open the file" << endl;
        return 1;
    }

    double investment_money;
    int investment_year;

    cout << "How much money you have invested? : ";
    cin >> investment_money;

    cout << "Put the year in which you have invested the money: ";
    cin >> investment_year;

    string line;
    bool isHeader = true; 

    double received_Money = investment_money;
    double value_of_investment = investment_money;

    while (getline(file, line)) {
        if (isHeader) {
            isHeader = false; 
            continue; 
        }

        stringstream lineStream(line);
        string cell;

        int currIndex = 0;
        string rowData[3]; 

        while (getline(lineStream, cell, ',')) {
            if (currIndex == year || currIndex == rateInterest || currIndex == rateInflation) {
                rowData[currIndex - 1] = cell; 
            }
            currIndex++;
        }

        try {
            double year = std::stod(rowData[0]);
            double r_O_Interest = std::stod(rowData[1]);
            double r_O_Inflation = std::stod(rowData[2]);

            if (year >= investment_year && year <= 2022) {
                received_Money = received_Money * (1 + (r_O_Interest / 100));
                value_of_investment = value_of_investment * (1 + (r_O_Interest / 100)) * (1 - (r_O_Inflation / 100));
            }
        } catch (const std::invalid_argument& e) {
            if (rowData[0] != "year" && rowData[1] != "interest-rate" && rowData[2] != "inflation") {
                cout << "Invalid data in the row: " << rowData[0] << ", " << rowData[1] << ", " << rowData[2] << endl;
            }
        }
    }
    cout << "Final money received: " << received_Money << endl;
    cout << "Final value of investment: " << value_of_investment;

    file.close();

    return 0;
}
