#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <string> 
using namespace std;

int main(){

    cout << "1.Calculate smth\n2.View history\n3.Exit calculator\n";
    int choice;
    double num1;
    double num2;
    char op;
    double equals;
    double pow1;
    double pow2;
    cin >> choice;


    switch(choice){
        case 1:
            cout << "\ngive me the first number: \n";
            cin >> num1;

            cout << "to the power of: \n";

            int pow1;
            cin >> pow1;

            cout << "second number: \n";
            cin >> num2;

            cout << "to the power of: \n";

            int pow2;
            cin >> pow2;

            cout << "whatchu wanna do with these numbers: \n";
            cin >> op;
            switch (op)
            {
            case '+':
                equals = pow(num1, pow1) + pow(num2, pow2);
                cout << equals << "\n";
                break;
            case '-':
                equals = pow(num1, pow1) - pow(num2, pow2);
                cout << equals << "\n";
                break;
            case '*':
                equals = pow(num1, pow1) * pow(num2, pow2);
                cout << equals << "\n";
                break;
            case '/':
                equals = pow(num1, pow1) / pow(num2, pow2);
                cout << equals << "\n";
                break;
            default:
                cout << "thats not how calculators work bruh\n";
                break;
            } 

            cout << "save to history ? y/n \n";
            char answer;
            cin >> answer;

            if (answer == 'y'){
                ofstream ofile;
                ofile.open("history.txt", ios::app);
                if (ofile.is_open()){
                    ofile << num1 << " " << op << " " << num2 << " = " << equals << endl;
                    ofile.close();
                }
            }
            break;
        case 2:
            ifstream ifile;
            ifile.open("history.txt");
            string line;

            while (getline(ifile, line)){
                cout << line << endl;
            }

            ifile.close();
        break;
    }
}
