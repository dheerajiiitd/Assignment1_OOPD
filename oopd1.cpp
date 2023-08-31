#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <tuple>
using namespace std;

int main() {
    ifstream file("spain_data.csv");
    int year = 1;
    int rateInterest = 2;
    int rateInflation = 3;

    if (!file.is_open()) {
        cerr << "unable to open the file" << endl;
        return 1;
    }

    double investment_money;
    int investment_year;
    double dictEra=0;
    double repcEra=0;
    bool monarchPeriod=true;
    bool republicPeriod=true;

    cout << "How much money you have invested? : ";
    cin >> investment_money;

    cout << "Put the year in which you have invested the money: ";
    cin >> investment_year; 

    string line;
    bool isHeader = true; 

    double received_Money = investment_money;
    double value_of_investment = investment_money;
    bool checkCondition=true;

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
            if(investment_year<=2002){
                if (year >= investment_year && year <2002) {
                    received_Money = (received_Money) * (1 + (r_O_Interest / 100));
                    value_of_investment = (value_of_investment) * (1 + (r_O_Interest / 100)) * (1 - (r_O_Inflation / 100));
                }
                while(checkCondition)
                {
                    received_Money=received_Money/166;
                    value_of_investment=value_of_investment/166;
                    checkCondition=false;
                }
                if (year >= 2002 && year <= 2022) {
                    received_Money = received_Money * (1 + (r_O_Interest / 100));
                    value_of_investment = value_of_investment * (1 + (r_O_Interest / 100)) * (1 - (r_O_Inflation / 100));
                }
            }
            if(investment_year>2000){
                if (year >= investment_year && year <= 2022) {
                received_Money = received_Money * (1 + (r_O_Interest / 100));
                value_of_investment = value_of_investment * (1 + (r_O_Interest / 100)) * (1 - (r_O_Inflation / 100));
                }
            }
            if(investment_year>=1960 && investment_year<=1977)
            {
                while(monarchPeriod)
                {
                    dictEra=1;
                    monarchPeriod=false;
                }
                dictEra=dictEra*(1+((r_O_Interest-r_O_Inflation)/100));
            }
            if(investment_year>=1978 && investment_year<=2022)
            {
                while(republicPeriod)
                {
                    repcEra=1;
                    republicPeriod=false;
                }
                repcEra=repcEra*(1+((r_O_Interest-r_O_Inflation)/100));
            }
            
        } catch (const std::invalid_argument& e) {
            if (rowData[0] != "year" && rowData[1] != "interest-rate" && rowData[2] != "inflation") {
                cout << "Invalid data in the row: " << rowData[0] << ", " << rowData[1] << ", " << rowData[2] << endl;
            }
        }
    }
    cout << "Final money received: " << received_Money << endl;
    cout << "Final value of investment: " << value_of_investment<<endl;
    cout<<"Monarchy Era's growth :"<<dictEra<< endl;
    cout<<"Republic Era's growth :"<<repcEra;
    

    file.close();

    return 0;
}
