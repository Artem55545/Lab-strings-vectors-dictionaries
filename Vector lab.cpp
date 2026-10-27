/************************
* Имя:     Мусаев Артём *
* Задание: 1            *
* Вариант: 3            *
************************/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <limits>

using namespace std;

int main() {
    char selectedPart;
    if (!(cin >> selectedPart)) {
        cout << "INVALID\n";
        return 1;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (selectedPart == 'A') {
        string inputText;
        if (!getline(cin, inputText) || inputText.size() > 200) {
            cout << "INVALID\n";
            return 1;
        }

        int vowelCount = 0;
        for (char currentChar : inputText) {
            if (currentChar == 'a' || currentChar == 'A' ||
                currentChar == 'e' || currentChar == 'E' ||
                currentChar == 'i' || currentChar == 'I' ||
                currentChar == 'o' || currentChar == 'O' ||
                currentChar == 'u' || currentChar == 'U') {
                vowelCount++;
            }
        }

        cout << vowelCount << "\n";
    }
    else if (selectedPart == 'B') {
        int countElements;
        if (!(cin >> countElements) || countElements < 0 || countElements > 100) {
            cout << "INVALID\n";
            return 1;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<int> inputValues;
        inputValues.reserve(countElements);
        int currentValue;
        bool inputValid = true;
        for (int index = 0; index < countElements; ++index) {
            if (!(cin >> currentValue) || currentValue < -1000 || currentValue > 1000) {
                inputValid = false;
                break;
            }
            inputValues.push_back(currentValue);
        }
        if (!inputValid) {
            cout << "INVALID\n";
            return 1;
        }

        vector<int> evenValues;
        for (int index = 0; index < static_cast<int>(inputValues.size()); ++index) {
            int value = inputValues[index];
            if (value % 2 == 0) {
                evenValues.push_back(value);
            }
        }

        if (evenValues.empty()) {
            cout << "EMPTY\n";
        }
        else {
            for (size_t index = 0; index < evenValues.size(); ++index) {
                if (index > 0) {
                    cout << " ";
                }
                cout << evenValues[index];
            }
            cout << "\n";
        }
    }
    else if (selectedPart == 'C') {
        int pairsCount;
        if (!(cin >> pairsCount) || pairsCount < 0 || pairsCount > 100) {
            cout << "INVALID\n";
            return 1;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        map<string, int> dataMap;
        string currentKey;
        int currentValueInt;
        bool pairsValid = true;
        for (int index = 0; index < pairsCount; ++index) {
            if (!(cin >> currentKey >> currentValueInt) ||
                currentKey.size() > 40 ||
                currentValueInt < -1000 || currentValueInt > 1000) {
                pairsValid = false;
                break;
            }
            dataMap[currentKey] = currentValueInt;
        }
        if (!pairsValid) {
            cout << "INVALID\n";
            return 1;
        }

        string keyToDelete;
        if (!(cin >> keyToDelete)) {
            cout << "INVALID\n";
            return 1;
        }
        if (dataMap.count(keyToDelete)) {
            dataMap.erase(keyToDelete);
        }

        if (dataMap.empty()) {
            cout << "EMPTY\n";
        }
        else {
            for (const auto& entry : dataMap) {
                cout << entry.first << " " << entry.second << "\n";
            }
        }
    }
    else if (selectedPart == 'D') {
        int recordsCount;
        if (!(cin >> recordsCount) || recordsCount < 0 || recordsCount > 100) {
            cout << "INVALID\n";
            return 1;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        auto isFieldValid = [](const string& field) -> bool {
            if (field.empty() || field.size() > 200) {
                return false;
            }
            if (field.front() == ' ' || field.back() == ' ') {
                return false;
            }
            for (unsigned char ch : field) {
                if (ch > 127) {
                    return false;
                }
            }
            return true;
            };

        vector<map<string, string>> allRecords;
        allRecords.reserve(recordsCount);
        string tempName;
        string tempPhone;
        bool recordsValid = true;
        for (int index = 0; index < recordsCount; ++index) {
            if (!getline(cin, tempName) || !getline(cin, tempPhone)) {
                recordsValid = false;
                break;
            }
            if (!isFieldValid(tempName) || !isFieldValid(tempPhone)) {
                recordsValid = false;
                break;
            }
            allRecords.push_back({ { "name", tempName },{ "phone", tempPhone } });
        }
        if (!recordsValid) {
            cout << "INVALID\n";
            return 1;
        }

        vector<string> filteredResult;
        map<string, bool> seenPhones;
        for (size_t index = 0; index < allRecords.size(); ++index) {
            const string& phone = allRecords[index].at("phone");
            const string& name = allRecords[index].at("name");
            if (!seenPhones[phone]) {
                seenPhones[phone] = true;
                filteredResult.push_back(name + " " + phone);
            }
        }

        if (filteredResult.empty()) {
            cout << "EMPTY\n";
        }
        else {
            for (size_t index = 0; index < filteredResult.size(); ++index) {
                cout << filteredResult[index] << "\n";
            }
        }
    }
    else {
        cout << "INVALID\n";
        return 1;
    }

    return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
