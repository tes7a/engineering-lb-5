#include <Windows.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

class Calculator {
public: int calculateY(int a, int b, int h, int n, bool fstream) {
    ofstream fout("results.txt");

    if (n < 1)
    {
        cout << "Wrong Data" << endl;
        return 0;
    }
    int x;

    for (x = a; x <= b; x += h)
    {
        if (x < 0)
        {
            double y = 0;

            for (int i = 1; i <= (n - 1); i++)
            {
                double s = 0;

                for (int j = 0; j < n; j++)
                    s += (x - i * i + j);

                y += s;
            }

            cout << "X: " << x << ";  Y: " << y << endl;

            if (fstream)
            {
                fout << "X: " << x << ";  Y: " << y << endl;
            }
        }
        else
        {
            double y = 0;

            for (int i = 0; i <= (n - 1); i++)
            {
                y += ((x - 1) / (i + 1));
            }

            y = x - y;

            cout << "X: " << x << ";  Y: " << y << endl;

            if (fstream)
            {
                fout << "X: " << x << ";  Y: " << y << endl;
            }
        }
    }
    return 1;
}

};

class AdvancedCalculator : public Calculator {
public: string writeResults(int a, int b, int h, int n) { 
    string results = "";

    if (n < 1)
    {
        cout << "Wrong Data" << endl;
        return 0;
    }
    int x;

    for (x = a; x <= b; x += h)
    {
        if (x < 0)
        {
            double y = 0;

            for (int i = 1; i <= (n - 1); i++)
            {
                double s = 0;

                for (int j = 0; j < n; j++)
                    s += (x - i * i + j);

                y += s;
            }

            results += to_string(x) + " " + to_string(y) + ". ";
        }
        else
        {
            double y = 0;

            for (int i = 0; i <= (n - 1); i++)
            {
                y += ((x - 1) / (i + 1));
            }

            y = x - y;

            results += to_string(x) + " " + to_string(y) + ". ";
        }
    }
    return results;
}

void displayFromFiles(bool isRead) {
    string data;
    string filename;
    cout << "Input filename" << endl;
    cin >> filename;
    if (isRead) {
        ifstream file(filename.c_str());
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                cout << line << endl;
            }
            file.close();
        }
        else {
            cout << "Incorrect filename" << endl;
        }
    }
}
};

int main() {
    int a, b, h, n = 0;
    cout << "Input a, b, h, n" << endl;

    cin >> a >> b >> h >> n;

    bool fstream;
    cout << "Do you want to save the results to a file? \nEnter 1 if yes, \nEnter 0 if no" << endl;
    cin >> fstream;

    AdvancedCalculator ac;

    ac.calculateY(a, b, h, n, fstream);

    string results = ac.writeResults(a, b, h, n);
    cout << "Results in string: " << endl;
    cout << results << endl;

    bool isRead;
    cout << "Do you want to read data from file? \nEnter 1 if yes, \nEnter 0 if no" << endl;
    cin >> isRead;

    ac.displayFromFiles(isRead);

    return 0;

}