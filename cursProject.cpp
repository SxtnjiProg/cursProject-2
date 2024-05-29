#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <random>
#include <ctime>

using namespace std;

class Vehicle {
public:
    string typeofVehicle,
        number;
    int year;
    double engineVolume;
    string engineNumber,
        chassisNumber,
        bodyNumber,
        color;
    bool inAccident;
    bool isInspected;

    string gettypeofVehicle() const {
        return typeofVehicle;
    }

    string getNumber() const {
        return number;
    }

    bool getInAccident() const {
        return inAccident;
    }

    void setVehicleDetails(string tTypeofVehicle, string tNumber)
    {
        typeofVehicle = tTypeofVehicle;
        number = tNumber;

    }

    friend ostream& operator<<(ostream& out, const Vehicle& obj) {
        out << obj.typeofVehicle << endl << obj.number << endl;
        return out;
    }
    friend istream& operator>>(istream& in, Vehicle& obj) {
        in >> obj.typeofVehicle >> obj.number;
        return in;
    }
};

// Наслідуваний клас PrivateOwner
class PrivateOwner : public Vehicle {
public:
    string ownerName;
    string address;
    string carBrand;

    void getPrivateOwner() const {
        cout << "------------------------" << endl;
        cout << "Type of vehicle: " << typeofVehicle << "\nCar number: " << number << "\nOwner name: " << ownerName << "\nAddress: " << address
            << "\nCar brand: " << carBrand << "\nYear of manufacture: " << year << "\nEngine volume: " << engineVolume
            << "\nEngine number: " << engineNumber << "\nChassis number: " << chassisNumber
            << "\nBody number: " << bodyNumber << "\nColor: " << color << "\nHas been in accident: " << std::boolalpha << inAccident
            << "\nHas passed inspection: " << std::boolalpha << isInspected << endl;
        cout << "------------------------" << endl;
    }

    // Конструктор за замовчуванням
    PrivateOwner() = default;

    // Конструктор для ініціалізації всіх полів
    PrivateOwner(const string& typeofVehicle, const string& number, const string& ownerName,
        const string& address, const string& carBrand, int year, double engineVolume,
        const string& engineNumber, const string& chassisNumber, const string& bodyNumber,
        const string& color, bool inAccident, bool isInspected)
        : Vehicle(), ownerName(ownerName), address(address), carBrand(carBrand) {
        this->typeofVehicle = typeofVehicle;
        this->number = number;
        this->year = year;
        this->engineVolume = engineVolume;
        this->engineNumber = engineNumber;
        this->chassisNumber = chassisNumber;
        this->bodyNumber = bodyNumber;
        this->color = color;
        this->inAccident = inAccident;
        this->isInspected = isInspected;
    }

    friend ostream& operator<<(ostream& out, const PrivateOwner& obj) {
        out << obj.typeofVehicle << " " << obj.number << " " << obj.ownerName << " " << obj.address << " " << obj.carBrand << " " << obj.year << " "
            << obj.engineVolume << " " << obj.engineNumber << " " << obj.chassisNumber << " " << obj.bodyNumber << " "
            << obj.color << " " << obj.inAccident << " " << obj.isInspected;
        return out;
    }

    friend istream& operator>>(istream& in, PrivateOwner& obj) {
        in >> obj.typeofVehicle >> obj.number >> obj.ownerName >> obj.address >> obj.carBrand >> obj.year >> obj.engineVolume
            >> obj.engineNumber >> obj.chassisNumber >> obj.bodyNumber >> obj.color >> obj.inAccident >> obj.isInspected;
        return in;
    }
};

// Фабрика для створення об'єктів PrivateOwner
class PrivateOwnerFactory {
public:
    static PrivateOwner createPrivateOwner(const string& typeofVehicle, const string& number, const string& ownerName,
        const string& address, const string& carBrand, int year, double engineVolume,
        const string& engineNumber, const string& chassisNumber, const string& bodyNumber,
        const string& color, bool inAccident, bool isInspected) {
        return PrivateOwner(typeofVehicle, number, ownerName, address, carBrand, year, engineVolume,
            engineNumber, chassisNumber, bodyNumber, color, inAccident, isInspected);
    }
};

// Клас OrganizationOwner
class OrganizationOwner : public Vehicle {
public:
    string organizationName, district, address, directorName, brand;

    // Конструктор за замовчуванням
    OrganizationOwner() = default;

    string getOrganizationName() const {
        return organizationName;
    }

    void getOrganizationOwner() const {
        cout << "------------------------" << endl;
        cout << "Type of vehicle: " << typeofVehicle << "\nCar number: " << number << "\nOrganization name: " << organizationName
            << "\nDistrict: " << district << "\nAddress: " << address << "\nDirector name: " << directorName << "\nCar brand: " << brand
            << "\nYear of manufacture: " << year << "\nEngine volume: " << engineVolume << "\nEngine number: " << engineNumber
            << "\nChassis number: " << chassisNumber << "\nBody number: " << bodyNumber << "\nColor: " << color
            << "\nHas been in accident: " << boolalpha << inAccident << "\nHas passed inspection: " << boolalpha << isInspected << endl;
        cout << "------------------------" << endl;
    }

    friend std::istream& operator>>(std::istream& in, OrganizationOwner& obj) {
        in >> obj.typeofVehicle >> obj.number >> obj.organizationName >> obj.district >> obj.address >> obj.directorName >> obj.brand >> obj.year
            >> obj.engineVolume >> obj.engineNumber >> obj.chassisNumber >> obj.bodyNumber >> obj.color >> obj.inAccident >> obj.isInspected;
        return in;
    }

    friend ostream& operator<<(ostream& out, const OrganizationOwner& obj) {
        out << obj.typeofVehicle << " " << obj.number << " " << obj.organizationName << " " << obj.district << " " << obj.address << " "
            << obj.directorName << " " << obj.brand << " " << obj.year << " " << obj.engineVolume << " " << obj.engineNumber << " "
            << obj.chassisNumber << " " << obj.bodyNumber << " " << obj.color << " " << obj.inAccident << " " << obj.isInspected;
        return out;
    }

    // Builder клас для OrganizationOwner
    class Builder {
    private:
        string typeofVehicle, number, organizationName, district, address, directorName, brand, engineNumber, chassisNumber, bodyNumber, color;
        int year;
        double engineVolume;
        bool inAccident, isInspected;

    public:
        Builder& setTypeofVehicle(const string& tTypeofVehicle) {
            typeofVehicle = tTypeofVehicle;
            return *this;
        }

        Builder& setNumber(const string& tNumber) {
            number = tNumber;
            return *this;
        }

        Builder& setOrganizationName(const string& tOrganizationName) {
            organizationName = tOrganizationName;
            return *this;
        }

        Builder& setDistrict(const string& tDistrict) {
            district = tDistrict;
            return *this;
        }

        Builder& setAddress(const string& tAddress) {
            address = tAddress;
            return *this;
        }

        Builder& setDirectorName(const string& tDirectorName) {
            directorName = tDirectorName;
            return *this;
        }

        Builder& setBrand(const string& tBrand) {
            brand = tBrand;
            return *this;
        }

        Builder& setYear(int tYear) {
            year = tYear;
            return *this;
        }

        Builder& setEngineVolume(double tEngineVolume) {
            engineVolume = tEngineVolume;
            return *this;
        }

        Builder& setEngineNumber(const string& tEngineNumber) {
            engineNumber = tEngineNumber;
            return *this;
        }

        Builder& setChassisNumber(const string& tChassisNumber) {
            chassisNumber = tChassisNumber;
            return *this;
        }

        Builder& setBodyNumber(const string& tBodyNumber) {
            bodyNumber = tBodyNumber;
            return *this;
        }

        Builder& setColor(const string& tColor) {
            color = tColor;
            return *this;
        }

        Builder& setInAccident(bool tInAccident) {
            inAccident = tInAccident;
            return *this;
        }

        Builder& setIsInspected(bool tIsInspected) {
            isInspected = tIsInspected;
            return *this;
        }

        string getTypeofVehicle() const { return typeofVehicle; }
        string getNumber() const { return number; }
        string getOrganizationName() const { return organizationName; }
        string getDistrict() const { return district; }
        string getAddress() const { return address; }
        string getDirectorName() const { return directorName; }
        string getBrand() const { return brand; }
        int getYear() const { return year; }
        double getEngineVolume() const { return engineVolume; }
        string getEngineNumber() const { return engineNumber; }
        string getChassisNumber() const { return chassisNumber; }
        string getBodyNumber() const { return bodyNumber; }
        string getColor() const { return color; }
        bool getInAccident() const { return inAccident; }
        bool getIsInspected() const { return isInspected; }

        OrganizationOwner build() {
            return OrganizationOwner(*this);
        }
    };

    OrganizationOwner(const Builder& builder) {
        typeofVehicle = builder.getTypeofVehicle();
        number = builder.getNumber();
        organizationName = builder.getOrganizationName();
        district = builder.getDistrict();
        address = builder.getAddress();
        directorName = builder.getDirectorName();
        brand = builder.getBrand();
        year = builder.getYear();
        engineVolume = builder.getEngineVolume();
        engineNumber = builder.getEngineNumber();
        chassisNumber = builder.getChassisNumber();
        bodyNumber = builder.getBodyNumber();
        color = builder.getColor();
        inAccident = builder.getInAccident();
        isInspected = builder.getIsInspected();
    }
};

class Accident : public Vehicle {
public:
    string date;
    string typeOfEvent;
    string location;
    int numberOfInjuries;
    double totalDamage;
    string causeofacc;
    vector<Vehicle> vehicles;

    void setAccidentDetails(string tDate, string tTypeOfEvent, string tLocation,
        int tNumberOfInjuries, double tTotalDamage, string tcauseofacc, const vector<Vehicle>& tVehicles) {
        date = tDate;
        typeOfEvent = tTypeOfEvent;
        location = tLocation;
        vehicles = tVehicles;
        causeofacc = tcauseofacc;
        numberOfInjuries = tNumberOfInjuries;
        totalDamage = tTotalDamage;

    }
    void getAccidentDetails() const {
        cout << "Date: " << date << endl;
        cout << "Type of event: " << typeOfEvent << endl;
        cout << "Location: " << location << endl;
        cout << "Number of injuries: " << numberOfInjuries << endl;
        cout << "Total damage: " << totalDamage << endl;
        cout << "Cause: " << causeofacc << endl;
        cout << "Vehicles involved:" << endl;

        for (const auto& v : vehicles) {
            cout << v.typeofVehicle << endl;
            cout << v.number << endl;
        }

        cout << endl;
    }
    string getCause() const {
        return causeofacc;

    }

    friend ostream& operator<<(ostream& out, const Accident& obj) {
        out << obj.date << " " << obj.typeOfEvent << " " << obj.location << " " << obj.numberOfInjuries << " " << obj.totalDamage << " " << obj.causeofacc << " " << obj.vehicles.size() << endl;
        for (const auto& vehicle : obj.vehicles) {
            out << vehicle << endl;
        }
        return out;
    }
    friend istream& operator>>(istream& in, Accident& obj) {
        size_t numVehicles;
        in >> obj.date >> obj.typeOfEvent >> obj.location >> obj.numberOfInjuries >> obj.totalDamage >> obj.causeofacc >> numVehicles;
        obj.vehicles.clear();
        for (size_t i = 0; i < numVehicles; i++) {
            Vehicle vehicle;
            in >> vehicle;
            obj.vehicles.push_back(vehicle);
        }
        return in;
    }

};

class AccidentFacade {
private:
    Accident accident;

public:
    AccidentFacade(const string& date, const string& typeOfEvent, const string& location,
        int numberOfInjuries, double totalDamage, const string& causeOfAccident,
        const vector<Vehicle>& vehicles) {
        accident.setAccidentDetails(date, typeOfEvent, location, numberOfInjuries, totalDamage, causeOfAccident, vehicles);
    }

    void displayAccidentDetails() const {
        accident.getAccidentDetails();
    }

    string getCauseOfAccident() const {
        return accident.getCause();
    }

    const Accident& getAccident() const {
        return accident;
    }

    friend ostream& operator<<(ostream& out, const AccidentFacade& obj) {
        out << obj.accident;
        return out;
    }

    friend istream& operator>>(istream& in, AccidentFacade& obj) {
        in >> obj.accident;
        return in;
    }
};

class stolencars : public Vehicle {
public:
    string date;
    string brand;
    bool isStolen;
    bool isSearchInProgress;
    bool isfound;
    bool escaped;
    string alarmType;
    string alarmBypassMethod;

    void setStolenCar(string tDate, string tbrand, string tTypeofVehicle, string tNumber, bool tIsStolen, bool tIsSearchInProgress, bool tIsFound, bool tescaped,
        string tAlarmType, string tAlarmBypassMethod) {
        date = tDate;
        brand = tbrand;
        typeofVehicle = tTypeofVehicle;
        number = tNumber;
        isStolen = tIsStolen;
        isSearchInProgress = tIsSearchInProgress;
        isfound = tIsFound;
        escaped = tescaped;
        alarmType = tAlarmType;
        alarmBypassMethod = tAlarmBypassMethod;
    }

    void displayStolenCarDetails() const {
        cout << "Date: " << date << "\nCar Brand: " << brand << "\nType of vehicle: " << typeofVehicle << "\nCar number: " << number << "\nIs stolen: " << boolalpha << isStolen
            << "\nIs search in progress: " << isSearchInProgress << "\nIs found: " << isfound << "\nFled the scene of an accident: " << escaped << "\nAlarm type: " << alarmType
            << "\nAlarm bypass method: " << alarmBypassMethod << endl;
    }

    friend ostream& operator<<(ostream& out, const stolencars& obj) {
        const Vehicle& baseObj = obj;
        out << baseObj << " " << obj.date << " " << obj.brand << ""
            << obj.isStolen << " " << obj.isSearchInProgress << " " << obj.isfound << " " << obj.escaped << " " << obj.alarmType << " " << obj.alarmBypassMethod;
        return out;
    }

    friend istream& operator>>(istream& in, stolencars& obj) {
        Vehicle& baseObj = obj;
        in >> obj.date >> obj.brand >> baseObj >> obj.isStolen >> obj.isSearchInProgress >> obj.isfound >> obj.escaped
            >> obj.alarmType >> obj.alarmBypassMethod;
        return in;
    }
};

void saveToFile(const vector<PrivateOwner>& owners, const string& filename) {
    ofstream outfile(filename);
    if (!outfile.is_open()) {
        cerr << "Failed to open file." << endl;
        return;
    }

    for (const auto& owner : owners) {
        outfile << owner << endl;
    }

    outfile.close();
}

//çáåðåæåííÿ äî ôàéëó âëàñíèê³â îðãàí³çàö³é
void saveToFileOrg(const vector<OrganizationOwner>& owners2, const string& filename) {
    std::ofstream file(filename, std::ios::out | std::ios::trunc);
    if (!file.is_open()) {
        std::cerr << "Error: could not open file " << filename << " for writing." << std::endl;
        return;
    }
    for (const auto& owner : owners2) {
        file << owner << endl;
    }
    file.close();
}
//çáåðåæåííÿ äî ôàéëó ÄÒÏ
void saveToFileAcc(const vector<Accident>& accidents, const string& filename) {
    std::ofstream file(filename, ios::out | std::ios::trunc);
    if (!file.is_open()) {
        cerr << "Error: could not open file " << filename << " for writing." << endl;
        return;
    }

    for (const auto& accident : accidents) {
        file << accident << endl;
    }

    file.close();
}
//ôóíêö³ÿ ç÷èòóâàííÿ äëÿ Ïðèâàòíèõ âëàñíèê³â
void readDataPowners(vector<PrivateOwner>& owners) {

    ifstream file("owners.txt");

    if (!file.is_open()) {
        cerr << "Failed to open file." << std::endl;
        return;
    }
    else {

        string line;
        while (getline(file, line)) {
            PrivateOwner owner;
            stringstream ss(line);
            string vehicleType, number, ownerName, address, carBrand, engineNumber, chassisNumber, bodyNumber, color;
            int year;
            double engineVolume;
            bool inAccident;
            bool isInspected;

            // read data from line
            ss >> vehicleType >> number >> ownerName >> address >> carBrand >> year >> engineVolume >> engineNumber >> chassisNumber >> bodyNumber >> color >> inAccident >> isInspected;

            // set data to owner object
            owner.typeofVehicle = vehicleType;
            owner.number = number;
            owner.ownerName = ownerName;
            owner.address = address;
            owner.carBrand = carBrand;
            owner.year = year;
            owner.engineVolume = engineVolume;
            owner.engineNumber = engineNumber;
            owner.chassisNumber = chassisNumber;
            owner.bodyNumber = bodyNumber;
            owner.color = color;
            owner.inAccident = inAccident;
            owner.isInspected = isInspected;

            owners.push_back(owner);
        }
    }
    file.close();
}
//ôóíêö³ÿ ç÷èòóâàííÿ äëÿ Ïðèâàòíèõ âëàñíèê³â
void readDataOowners(vector<OrganizationOwner>& owners2) {
    ifstream file("owners2.txt");
    if (!file.is_open()) {
        cerr << "Failed to open file." << std::endl;
        return;
    }
    else {

        string line;
        while (std::getline(file, line)) {
            OrganizationOwner owner;
            stringstream ss(line);
            string vehicleType, number, organizationName, district, address, directorName, brand;
            int year;
            double engineVolume;
            string engineNumber, chassisNumber, bodyNumber, color;
            bool inAccident;
            bool isInspected;

            // read data from\ line
            ss >> vehicleType >> number >> organizationName >> district >> address >> directorName >> brand >> year >> engineVolume >> engineNumber >> chassisNumber >> bodyNumber >> color >> inAccident >> isInspected;

            // set data to owner object
            owner.typeofVehicle = vehicleType;
            owner.number = number;
            owner.organizationName = organizationName;
            owner.district = district;
            owner.address = address;
            owner.directorName = directorName;
            owner.brand = brand;
            owner.year = year;
            owner.engineVolume = engineVolume;
            owner.engineNumber = engineNumber;
            owner.chassisNumber = chassisNumber;
            owner.bodyNumber = bodyNumber;
            owner.color = color;
            owner.inAccident = inAccident;
            owner.isInspected = isInspected;

            owners2.push_back(owner);
        }
    }
    file.close();
}

void printAccidents(const vector<Accident>& accidents) {
    for (const auto& accident : accidents) {
        cout << "Date: " << accident.date << endl;
        cout << "Type of event: " << accident.typeOfEvent << endl;
        cout << "Location: " << accident.location << endl;
        cout << "Number of injuries: " << accident.numberOfInjuries << endl;
        cout << "Total damage: " << accident.totalDamage << endl;
        cout << "Vehicles involved:" << endl;
        for (const auto& vehicle : accident.vehicles) {
            cout << vehicle.typeofVehicle << endl;
            cout << vehicle.number << endl;
            cout << endl;
        }

        cout << endl;
    }
}

bool isUniqueNumber(const string& number, const vector<OrganizationOwner>& owners) {
    for (const auto& owner : owners) {
        if (owner.getNumber() == number) {
            return false;
        }
    }
    return true;
}
//äîäàâàííÿ Ïðèâàòíîãî âëàñíèêà
void saveToFile(const vector<PrivateOwner>& owners, const string& filename);

void addOwner(vector<PrivateOwner>& owners) {
    PrivateOwner owner;
    bool isUniqueNumber = false;

    while (!isUniqueNumber) {
        cout << "Enter owner details:" << endl;
        cout << "Type of vehicle: ";
        cin >> owner.typeofVehicle;
        cout << "Number: ";
        cin >> owner.number;

        // Перевірка унікальності номера
        isUniqueNumber = true;
        for (const auto& existing_owner : owners) {
            if (existing_owner.number == owner.number) {
                cerr << "Error: This number is already registered to another owner." << endl;
                isUniqueNumber = false;
                break;
            }
        }
    }

    cout << "Owner name: ";
    cin >> owner.ownerName;
    cout << "Address: ";
    cin >> owner.address;
    cout << "Car brand: ";
    cin >> owner.carBrand;
    cout << "Year: ";
    cin >> owner.year;
    cout << "Engine volume: ";
    cin >> owner.engineVolume;
    cout << "Engine number: ";
    cin >> owner.engineNumber;
    cout << "Chassis number: ";
    cin >> owner.chassisNumber;
    cout << "Body number: ";
    cin >> owner.bodyNumber;
    cout << "Color: ";
    cin >> owner.color;
    cout << "Has been in accident? (1 or 0): ";
    cin >> owner.inAccident;
    cout << "Has passed inspection? (1 or 0): ";
    cin >> owner.isInspected;
    owners.push_back(owner);

    // Запис у файл
    ofstream file("owners.txt", ios::app);
    if (file.is_open()) {
        file << owner.typeofVehicle << " " << owner.number << " " << owner.ownerName << " " << owner.address << " " << owner.carBrand << " "
            << owner.year << " " << owner.engineVolume << " " << owner.engineNumber << " " << owner.chassisNumber << " " << owner.bodyNumber << " "
            << owner.color << " " << owner.inAccident << " " << owner.isInspected << endl;
        file.close();
    }
    else {
        cerr << "Failed to open file for writing." << endl;
    }
}



void addOrgOwner(vector<OrganizationOwner>& owners2) {
    OrganizationOwner owner;
    bool isUniqueNumber = false;

    while (!isUniqueNumber) {
        cout << "Enter owner details:" << endl;
        cout << "Type of vehicle: ";
        cin >> owner.typeofVehicle;
        cout << "Number: ";
        cin >> owner.number;

        // Перевірка унікальності номера
        isUniqueNumber = true;
        for (const auto& existing_owner : owners2) {
            if (existing_owner.number == owner.number) {
                cerr << "Error: This number is already registered to another owner." << endl;
                isUniqueNumber = false;
                break;
            }
        }
    }

    cout << "Organization name: ";
    cin >> owner.organizationName;
    cout << "District: ";
    cin >> owner.district;
    cout << "Address: ";
    cin >> owner.address;
    cout << "Director name: ";
    cin >> owner.directorName;
    cout << "Car brand: ";
    cin >> owner.brand;
    cout << "Year: ";
    cin >> owner.year;
    cout << "Engine volume: ";
    cin >> owner.engineVolume;
    cout << "Engine number: ";
    cin >> owner.engineNumber;
    cout << "Chassis number: ";
    cin >> owner.chassisNumber;
    cout << "Body number: ";
    cin >> owner.bodyNumber;
    cout << "Color: ";
    cin >> owner.color;
    cout << "Has been in accident? (1 or 0): ";
    cin >> owner.inAccident;
    cout << "Has passed inspection? (1 or 0): ";
    cin >> owner.isInspected;
    owners2.push_back(owner);

    // Запис у файл
    ofstream file("owners2.txt", ios::app);
    if (file.is_open()) {
        file << owner.typeofVehicle << " " << owner.number << " " << owner.organizationName << " " << owner.district << " " << owner.address << " " << owner.directorName << " "
            << owner.brand << " " << owner.year << " " << owner.engineVolume << " " << owner.engineNumber << " " << owner.chassisNumber << " " << owner.bodyNumber << " "
            << owner.color << " " << owner.inAccident << " " << owner.isInspected << endl;
        file.close();
    }
    else {
        cerr << "Failed to open file for writing." << endl;
    }
}



void generatePrivateOwnerFile() {
    vector<PrivateOwner> owners;

    ifstream file("owners.txt");
    if (file.good()) {
        return;
    }

    owners.push_back(PrivateOwnerFactory::createPrivateOwner("car", "AA1234BB", "Max_Parhomenko", "str._Grushevskogo_4", "Toyota", 2010, 2.5, "3217554", "1234567890", "1234567890", "Red", false, true));
    owners.push_back(PrivateOwnerFactory::createPrivateOwner("car", "AH1234BD", "Mar'yana_Boyko", "Stepana_Banderi_st._12", "Toyota", 2010, 2.5, "3213554", "1234567809", "1234569099", "Red", false, true));
    owners.push_back(PrivateOwnerFactory::createPrivateOwner("car", "BC5678DE", "Oleksandr_Kravets", "8_Bulvarno-Kudryavska_vul.", "Honda", 2015, 1.8, "1288999", "2345678912", "2345678912", "Silver", true, true));
    owners.push_back(PrivateOwnerFactory::createPrivateOwner("car", "CD9012EF", "Natalia_Shevchenko", "16_Sahaydachnogo_St.", "Mazda", 2018, 2.0, "2333788", "3456789123", "3456789123", "Black", false, false));
    owners.push_back(PrivateOwnerFactory::createPrivateOwner("car", "DE3456FG", "Oksana_Bila", "vul.Tarasivska_20", "Nissan", 2019, 2.5, "3900999", "4567891234", "4567891234", "Blue", false, false));
    owners.push_back(PrivateOwnerFactory::createPrivateOwner("car", "FG7890GH", "Evgeniya_Ivanenko", "14_Chornovola_St.", "BMW", 2017, 2.2, "4677888", "5678912345", "5678912345", "White", false, true));
    owners.push_back(PrivateOwnerFactory::createPrivateOwner("car", "GH2345IJ", "Vitaliy_Shevchenko", "Knyagini_Olga_st._2", "Audi", 2021, 2.0, "5999555", "6789123456", "6789123456", "Black", true, true));
    owners.push_back(PrivateOwnerFactory::createPrivateOwner("truck", "GH2325IJ", "Vitaliy_Shevchenko", "Knyagini_Olga_st._2", "Ford", 2015, 2.5, "5999555", "6789123456", "6789123456", "Black", true, true));

    saveToFile(owners, "owners.txt");
}

void generateOrganizationOwnerFile() {
    vector<OrganizationOwner> owners2;

    ifstream file("owners2.txt");
    if (file.good()) {
        return;
    }

    // Створення об'єктів класу OrganizationOwner за допомогою Builder
    OrganizationOwner owner1 = OrganizationOwner::Builder()
        .setTypeofVehicle("Car")
        .setNumber("AH7642AD")
        .setOrganizationName("Autocentr/Max/")
        .setDistrict("Sokylyky")
        .setAddress("Zelenskogo_21")
        .setDirectorName("Max_Parhomenko")
        .setBrand("Ford")
        .setYear(2018)
        .setEngineVolume(1.2)
        .setEngineNumber("123123433")
        .setChassisNumber("123213213")
        .setBodyNumber("34324324")
        .setColor("red")
        .setInAccident(true)
        .setIsInspected(false)
        .build();

    owners2.push_back(owner1);

    OrganizationOwner owner2 = OrganizationOwner::Builder()
        .setTypeofVehicle("Car")
        .setNumber("AA1234BB")
        .setOrganizationName("Coca-Cola.inc")
        .setDistrict("Podilskyi")
        .setAddress("Varinykiv_21")
        .setDirectorName("Bogdan_Derzkiy")
        .setBrand("Ford")
        .setYear(2012)
        .setEngineVolume(2.3)
        .setEngineNumber("32324234")
        .setChassisNumber("1233667890")
        .setBodyNumber("12334454890")
        .setColor("Coca-cola")
        .setInAccident(true)
        .setIsInspected(true)
        .build();

    owners2.push_back(owner2);

    OrganizationOwner owner3 = OrganizationOwner::Builder()
        .setTypeofVehicle("Truck")
        .setNumber("BC5678DE")
        .setOrganizationName("ABC_Company")
        .setDistrict("Shevchenkivskyi")
        .setAddress("Morskaya_12")
        .setDirectorName("John_Doe")
        .setBrand("Volvo")
        .setYear(2015)
        .setEngineVolume(3.0)
        .setEngineNumber("9876543")
        .setChassisNumber("0987654321")
        .setBodyNumber("0987654321")
        .setColor("Blue")
        .setInAccident(true)
        .setIsInspected(true)
        .build();

    owners2.push_back(owner3);

    OrganizationOwner owner4 = OrganizationOwner::Builder()
        .setTypeofVehicle("Car")
        .setNumber("AA1234AA")
        .setOrganizationName("Maxmara")
        .setDistrict("Sokylnyky")
        .setAddress("St_Olgy_21")
        .setDirectorName("Max_Kuziv")
        .setBrand("Ford")
        .setYear(2005)
        .setEngineVolume(1.2)
        .setEngineNumber("123213")
        .setChassisNumber("123123")
        .setBodyNumber("12333")
        .setColor("red")
        .setInAccident(true)
        .setIsInspected(true)
        .build();

    owners2.push_back(owner4);

    // Запис даних у файл
    saveToFileOrg(owners2, "owners2.txt");
}
void saveToFileAccidents(const vector<AccidentFacade>& accidents, const string& filename) {
    ofstream file(filename, ios::app);
    if (!file.is_open()) {
        cerr << "Failed to open file for writing." << endl;
        return;
    }

    for (const auto& accidentFacade : accidents) {
        file << accidentFacade << endl;
    }

    file.close();
}

vector<AccidentFacade> createAccidents() {
    vector<AccidentFacade> accidents;

    // Створення першої події
    vector<Vehicle> vehicles1;
    Vehicle vehicle1;
    vehicle1.setVehicleDetails("Truck", "AA9182AP");
    vehicles1.push_back(vehicle1);
    Vehicle vehicle2;
    vehicle2.setVehicleDetails("Car", "BB2345AC");
    vehicles1.push_back(vehicle2);
    AccidentFacade accidentFacade1("2023-05-13", "Collision", "S.Bandery", 2, 5000.2, "Drunken state of one of the drivers", vehicles1);
    accidents.push_back(accidentFacade1);

    // Створення другої події
    vector<Vehicle> vehicles2;
    Vehicle vehicle3;
    vehicle3.setVehicleDetails("Motorcycle", "CC3456BD");
    vehicles2.push_back(vehicle3);
    Vehicle vehicle4;
    vehicle4.setVehicleDetails("Van", "DD4567CE");
    vehicles2.push_back(vehicle4);
    AccidentFacade accidentFacade2("2023-07-29", "Rear-end_collision", "Morskaya", 1, 3000.2, "Wet road", vehicles2);
    accidents.push_back(accidentFacade2);

    // Створення третьої події
    vector<Vehicle> vehicles3;
    Vehicle vehicle5;
    vehicle5.setVehicleDetails("Bus", "AH1239BR");
    vehicles3.push_back(vehicle5);
    Vehicle vehicle6;
    vehicle6.setVehicleDetails("Car", "AP4547CE");
    vehicles3.push_back(vehicle6);
    AccidentFacade accidentFacade3("2023-05-14", "Head-on_collision", "Morskaya", 7, 54000, "Drunken state of one of the drivers", vehicles3);
    accidents.push_back(accidentFacade3);

    // Збереження подій у файлі
    saveToFileAccidents(accidents, "accidents.txt");

    return accidents;
}

class StolenCarsManager {
private:
    vector<stolencars> cars;

    // Private constructor to prevent instantiation
    StolenCarsManager() {}

public:
    // Delete copy constructor and assignment operator to prevent copying
    StolenCarsManager(const StolenCarsManager&) = delete;
    StolenCarsManager& operator=(const StolenCarsManager&) = delete;

    static StolenCarsManager& getInstance() {
        static StolenCarsManager instance;
        return instance;
    }

    void addStolenCar(const stolencars& car) {
        cars.push_back(car);
    }

    const vector<stolencars>& getStolenCars() const {
        return cars;
    }

    void generateStolenCars() {
        stolencars car1, car2, car3, car4;

        car1.setStolenCar("2023-01-22", "Ford", "car", "AA1234BB", true, false, true, false, "GPS tracking alarm", "Keyless entry hacking");
        car2.setStolenCar("2023-06-01", "Mercedes", "car", "AH1234BD", false, true, false, true, "Passive alarm", " ");
        car3.setStolenCar("2023-06-18", "Mercedes", "motocyle", "AP9568HB", false, true, true, true, "Active alarm", " ");
        car4.setStolenCar("2023-02-18", "BMW", "car", "AP9411HH", true, true, true, false, "Active alarm", "Electronic immobilizer hacking");

        cars.push_back(car1);
        cars.push_back(car2);
        cars.push_back(car3);
        cars.push_back(car4);
    }

};

void printAccidentDetails(const vector<AccidentFacade>& accidents) {
    for (const auto& accidentFacade : accidents) {
        accidentFacade.displayAccidentDetails();
    }
}
//ïîøóê ïî íîìåðó êàðòî÷êè ïðèâàòíîãî âëàñíèêà
void searchByNumber(const vector<PrivateOwner>& owners) {
    string number;
    cout << "Enter the car number to search: ";
    cin >> number;

    bool found = false;
    for (const auto& owner : owners) {
        if (owner.getNumber() == number) {
            owner.getPrivateOwner();
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "No car owner with the number " << number << " was found" << std::endl;
    }

}

void searchByNumberOrg(const vector<OrganizationOwner>& owners2) {
    string number;
    cout << "Enter the car number to search: ";
    cin >> number;

    bool found = false;
    for (const auto& owner : owners2) {
        if (owner.getNumber() == number) {
            owner.getOrganizationOwner();
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "No car owner with the number " << number << " was found" << std::endl;
    }

}
//ïîøóê çà ñåð³ºþ íîìåðà îãðàí³çàö³é
void printOrganizationsWithSeries(vector<OrganizationOwner>& owners2) {
    string series;
    cout << "Enter the series: ";
    cin >> series;

    int count = 0;
    for (auto owner : owners2) {
        if (owner.getNumber().find(series) == 0) {
            cout << owner.getOrganizationName() << endl;
            count++;
        }
    }
    cout << "Total organizations with series " << series << ": " << count << endl;
}

void deleteByNumber(vector<PrivateOwner>& owners, const string& number) {
    auto it = find_if(owners.begin(), owners.end(), [&](const PrivateOwner& owner) {
        return owner.number == number;
        });
    if (it != owners.end()) {
        owners.erase(it);
        cout << "Owner with number " << number << " has been deleted." << endl;
        saveToFile(owners, "owners.txt");
    }
    else {
        cout << "Owner with number " << number << " was not found." << endl;
    }
}

void deleteByNumberOrg(vector<OrganizationOwner>& owners2, const string& number) {
    auto it = find_if(owners2.begin(), owners2.end(), [&](const OrganizationOwner& owner2) {
        return owner2.number == number;
        });
    if (it != owners2.end()) {
        owners2.erase(it);
        cout << "Owner with number " << number << " has been deleted." << endl;
        saveToFileOrg(owners2, "owners2.txt");
    }
    else {
        cout << "Owner with number " << number << " was not found." << endl;
    }
}

string generateCarNumber(const string& series, int range) {
    static random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1000, 9999);

    int number = dis(gen) % range + 1;
    string carNumber = series + to_string(number / 1000) + to_string((number / 100) % 10)
        + to_string((number / 10) % 10) + to_string(number % 10) + (char)(dis(gen) % 26 + 'A') + (char)(dis(gen) % 26 + 'A');
    return carNumber;
}

void generateCarNumberMenu() {
    string series;
    int range;

    cout << "Enter series of car number: ";
    cin >> series;
    cout << "Enter range: ";
    cin >> range;

    // Ãåíåðàö³ÿ ï'ÿòè íîìåð³â ³ çáåðåæåííÿ ¿õ â âåêòîð³
    vector<string> carNumbers;
    for (int i = 0; i < 5; i++) {
        string carNumber = generateCarNumber(series, range);
        carNumbers.push_back(carNumber);
    }

    // Â³äêðèòòÿ ôàéëó äëÿ çàïèñó íîìåð³â
    ofstream outfile("generated_numbers.txt", ios::trunc);
    if (!outfile) {
        cerr << "Error: Failed to create file!" << endl;
        return;
    }

    // Çàïèñ ñåð³¿ àâòîìîá³ë³â ó ôàéë
    outfile << series << ":" << endl;

    // Âèâåäåííÿ ñåð³¿ àâòîìîá³ë³â òà íîìåð³â â êîíñîëü ³ çàïèñ ¿õ ó ôàéë
    for (int i = 0; i < carNumbers.size(); i++) {
        cout << series << " " << carNumbers[i] << endl;
        outfile << series << " " << carNumbers[i] << endl;
    }

    // Çàêðèòòÿ ôàéëó
    outfile.close();

}

void printGeneratedCarNumbers() {
    ifstream infile("generated_numbers.txt");
    if (!infile) {
        cerr << "Error: Failed to open file!" << endl;
        return;
    }

    string carNumber;
    cout << "Generated car numbers:" << endl;
    while (getline(infile, carNumber)) {
        cout << carNumber << endl;
    }

    infile.close();
}

void searchPrvtInf(const vector<PrivateOwner>& owners) {
    string number;
    cout << "Enter the car number to search: ";
    cin >> number;

    bool found = false;
    for (const auto& owner : owners) {
        if (owner.getNumber() == number) {
            cout << "------------------------" << endl;
            cout << "Owner name: " << owner.ownerName << endl;
            cout << "Address: " << owner.address << endl;
            cout << "------------------------" << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "No car owner with the number " << number << " was found" << std::endl;
    }
}

void searchOwners12(bool isInspected, const std::vector<PrivateOwner>& owners1, const vector<OrganizationOwner>& owners2) {
    bool found = false;
    for (const auto& owner : owners1) {
        if (owner.isInspected == isInspected) {
            std::cout << "Private owner found:\n";
            std::cout << "Number: " << owner.number << "\n";
            std::cout << "Owner name: " << owner.ownerName << "\n";
            std::cout << "Address: " << owner.address << "\n\n";
            found = true;
        }
    }
    for (const auto& owner : owners2) {
        if (owner.isInspected == isInspected) {
            std::cout << "Organization owner found:\n";
            std::cout << "Number: " << owner.number << "\n";
            std::cout << "Organization name: " << owner.organizationName << "\n";
            std::cout << "District: " << owner.district << "\n";
            std::cout << "Address: " << owner.address << "\n";
            std::cout << "Director name: " << owner.directorName << "\n\n";
            found = true;
        }
    }
    if (!found) {
        std::cout << "No owner found with the given isInspected value.\n";
    }
}

void getAccidentsStatisticsByPeriod(const vector<AccidentFacade>& accidents) {
    string startDate, endDate;
    cout << "Enter the start date (YYYY-MM-DD): ";
    cin >> startDate;
    cout << "Enter the end date (YYYY-MM-DD): ";
    cin >> endDate;

    int totalAccidents = 0;
    int totalInjuries = 0;
    double totalDamage = 0.0;

    for (const auto& accidentFacade : accidents) {
        const Accident& accident = accidentFacade.getAccident();
        if (accident.date >= startDate && accident.date <= endDate) {
            totalAccidents++;
            totalInjuries += accident.numberOfInjuries;
            totalDamage += accident.totalDamage;
        }
    }

    cout << "Accident statistics for the period " << startDate << " to " << endDate << ":" << endl;
    cout << "Total accidents: " << totalAccidents << endl;
    cout << "Total injuries: " << totalInjuries << endl;
    cout << "Total damage: " << totalDamage << endl;
}

void getMostDangerousLocation(const vector<AccidentFacade>& accidents) {
    int maxCount = 0;
    string mostDangerousLocation;

    for (const auto& accidentFacade : accidents) {
        string currentLocation = accidentFacade.getAccident().location;
        int currentCount = 0;

        for (const auto& otherAccidentFacade : accidents) {
            if (otherAccidentFacade.getAccident().location == currentLocation) {
                currentCount++;
            }
        }

        if (currentCount > maxCount) {
            maxCount = currentCount;
            mostDangerousLocation = currentLocation;
        }
    }

    cout << "The most dangerous location: " << mostDangerousLocation << endl;
    cout << "Number of accidents at the most dangerous location: " << maxCount << endl;
}

void getMostFrequentCause(const vector<AccidentFacade>& accidents) {
    int maxCount = 0;
    string mostFrequentCause;

    for (const auto& accidentFacade : accidents) {
        string currentCause = accidentFacade.getCauseOfAccident();
        int currentCount = 0;

        for (const auto& otherAccidentFacade : accidents) {
            if (otherAccidentFacade.getCauseOfAccident() == currentCause) {
                currentCount++;
            }
        }

        if (currentCount > maxCount) {
            maxCount = currentCount;
            mostFrequentCause = currentCause;
        }
    }

    cout << "The most frequent cause of accidents: " << mostFrequentCause << endl;
}

void getDrunkDrivingStats(const vector<AccidentFacade>& accidents) {
    int totalAccidents = accidents.size();
    int drunkDrivingAccidents = 0;

    for (const auto& accidentFacade : accidents) {
        if (accidentFacade.getCauseOfAccident() == "Drunken state of one of the drivers") {
            drunkDrivingAccidents++;
        }
    }

    double drunkDrivingPercentage = (drunkDrivingAccidents * 100.0) / totalAccidents;

    cout << "Number of accidents caused by drunk drivers: " << drunkDrivingAccidents << endl;
    cout << "Percentage of accidents caused by drunk drivers: " << drunkDrivingPercentage << "%" << endl;
}
void printStolenCars() {
    const vector<stolencars>& cars = StolenCarsManager::getInstance().getStolenCars();
    cout << "The list of wanted cars with drivers who disappeared from the scene of the accident or the cars were stolen:" << endl;
    for (const auto& car : cars) {
        if (car.isSearchInProgress || car.isStolen) {
            car.displayStolenCarDetails(); // Оновлений виклик методу
            cout << endl;
        }
    }
}

void calculateSearchEfficiency(const vector<stolencars>& cars) {
    int totalCars = cars.size();
    int foundCars = 0;

    for (const auto& car : cars) {
        if (car.isfound) {
            foundCars++;
        }
    }

    double efficiency = (foundCars * 100.0) / totalCars;

    cout << "Search efficiency: " << efficiency << "% (" << foundCars << " out of " << totalCars << " cars found)" << endl;
}
void getStolenCarsStatisticsByPeriod(const vector<stolencars>& cars) {
    string startDate, endDate;
    cout << "Enter the start date (YYYY-MM-DD): ";
    cin >> startDate;
    cout << "Enter the end date (YYYY-MM-DD): ";
    cin >> endDate;

    int totalStolenCars = 0;

    for (const auto& car : cars) {
        if (car.date >= startDate && car.date <= endDate) {
            totalStolenCars++;
            car.displayStolenCarDetails();
            cout << endl;
        }
    }

    cout << "Stolen cars statistics for the period " << startDate << " to " << endDate << ":" << endl;
    cout << "Total stolen cars: " << totalStolenCars << endl;
}

void getStolenCarsStatistics(const vector<stolencars>& cars) {
    string mostFrequentBrand;
    int maxBrandFrequency = 0;

    string mostReliableAlarmType;
    int maxAlarmTypeFrequency = 0;

    
    for (const auto& car : cars) {
        
        int brandFrequency = 0;
        for (const auto& otherCar : cars) {
            if (car.brand == otherCar.brand) {
                brandFrequency++;
            }
        }
        if (brandFrequency > maxBrandFrequency) {
            maxBrandFrequency = brandFrequency;
            mostFrequentBrand = car.brand;
        }

        
        int alarmTypeFrequency = 0;
        for (const auto& otherCar : cars) {
            if (car.alarmType == otherCar.alarmType) {
                alarmTypeFrequency++;
            }
        }
        if (alarmTypeFrequency > maxAlarmTypeFrequency) {
            maxAlarmTypeFrequency = alarmTypeFrequency;
            mostReliableAlarmType = car.alarmType;
        }
    }

    
    cout << "Most frequently stolen car brand: " << mostFrequentBrand << " (" << maxBrandFrequency << " times)" << endl;

    
    cout << "Most reliable alarm type: " << mostReliableAlarmType << " (" << maxAlarmTypeFrequency << " times)" << endl;
}



void privateOwnerMenu() {
    vector<PrivateOwner> owners;
    readDataPowners(owners);
    int choice = -1;
    string number;
    while (choice != 0) {
        cout << "Private Owner Menu" << endl;
        cout << "1 - Display all Private owners" << endl;
        cout << "2 - Search for an owner by car number" << endl;
        cout << "3 - Add a new owner" << endl;
        cout << "4 - Get full specification for car by number " << endl;
        cout << "5 - Remove an owner by number of car" << endl;
        cout << "0 - Back to main menu" << endl;
        cout << "Your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
        case 0:
            system("cls");
            cout << "Returning to main menu..." << endl;
            break;
        case 1:
            system("cls");
            
            for (const auto& owner : owners) {
                owner.getPrivateOwner();
                cout << endl;
            }
            break;
        case 2:
            system("cls");
            
            searchPrvtInf(owners);
            break;
        case 3:
            system("cls");
            
            addOwner(owners);
            break;
        case 4:
            system("cls");
            searchByNumber(owners);
            break;
        case 5:
            system("cls");
            
            cout << "Enter number: ";
            cin >> number;
            deleteByNumber(owners, number);
            break;
        default:
            cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
    }
}

void organizOwnerMenu() {
    vector<OrganizationOwner> owners2;

    readDataOowners(owners2);
    int choice = -1;
    string number;
    while (choice != 0) {
        cout << "Organization Owner Menu" << endl;
        cout << "1 - Display all Organization owners" << endl;
        cout << "2 - Search for an owner by car number" << endl;
        cout << "3 - Add a new owner" << endl;
        cout << "4 - Get full specification for car by number " << endl;
        cout << "5 - Remove an owner by number of car" << endl;
        cout << "0 - Back to main menu" << endl;
        cout << "Your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
        case 0:
            system("cls");
            cout << "Returning to main menu..." << endl;
            break;
        case 1:
            system("cls");
            
            for (const auto& owner : owners2) {
                owner.getOrganizationOwner();
                cout << endl;
            }
            break;
        case 2:
            system("cls");
            
            printOrganizationsWithSeries(owners2);
            break;
        case 3:
            system("cls");
            
            addOrgOwner(owners2);
            break;
        case 4:
            searchByNumberOrg(owners2);
            break;
        case 5:
            system("cls");
            
            cout << "Enter number: ";
            cin >> number;
            deleteByNumberOrg(owners2, number);

            break;
        default:
            cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
    }
}

int main() {
    
    vector<PrivateOwner> owners;
    
    vector<OrganizationOwner> owners2;
 
    generatePrivateOwnerFile();
    
    generateOrganizationOwnerFile();
    
    vector<AccidentFacade> accidents = createAccidents();
    
    StolenCarsManager& manager = StolenCarsManager::getInstance();
    
    const vector<stolencars>& cars = manager.getStolenCars();
   
    manager.generateStolenCars();
    
    readDataPowners(owners);
    readDataOowners(owners2);


    string number;
    int choice = -1;

    while (choice != 0) {

        cout << "Choose an action:" << endl;
        cout << "1 - Private Owner Menu" << endl;
        cout << "2 - Organization Owner Menu" << endl;
        cout << "3 - Generate Free Car Numbers" << endl;
        cout << "4 - Print Free Car Numbers" << endl;
        cout << "5 - find owners who did not pass technical inspection on time" << endl;
        cout << "6 - Print all accidents" << endl;
        cout << "7 - Get accidents statistics by period" << endl;
        cout << "8 - Get most dangerous location" << endl;
        cout << "9 - Get drunk driving Stats" << endl;
        cout << "10 - Get a list of wanted cars:" << endl;
        cout << "11 - Get data on the effectiveness of investigative work:" << endl;
        cout << "12 - Get a list and the total number of thefts for the specified period:" << endl;
        cout << "13 - Get car theft statistics:" << endl;
        cout << "0 - Exit" << endl;
        cout << "Your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
        case 0:
            system("cls");
            cout << "Exiting program..." << endl;
            break;
        case 1:
            system("cls");
            privateOwnerMenu();
            
            break;
        case 2:
            system("cls");
            organizOwnerMenu();
            
            break;
        case 3:
            system("cls");
            
            generateCarNumberMenu();
            break;
        case 4:
            system("cls");
            
            printGeneratedCarNumbers();
            break;
        case 5:
            system("cls");
            searchOwners12(false, owners, owners2);
            break;
        case 6:
            system("cls");
            printAccidentDetails(accidents);
            break;
        case 7:
            system("cls");
            getAccidentsStatisticsByPeriod(accidents);

            break;
        case 8:
            system("cls");
            cout << "------------------------" << endl;
            getMostDangerousLocation(accidents);
            getMostFrequentCause(accidents);
            cout << "------------------------" << endl;

            break;
        case 9:
            system("cls");
            cout << "------------------------" << endl;
            getDrunkDrivingStats(accidents);
            cout << "------------------------" << endl;
            break;
        case 10:
            system("cls");
            printStolenCars();
            break;
        case 11:
            system("cls");
            cout << "------------------------" << endl;
            calculateSearchEfficiency(cars);
            cout << "------------------------" << endl;
            break;
        case 12:
            system("cls");
            cout << "------------------------" << endl;
            getStolenCarsStatisticsByPeriod(cars);
            cout << "------------------------" << endl;
            break;
        case 13:
            system("cls");
            cout << "------------------------" << endl;
            getStolenCarsStatistics(cars);
            cout << "------------------------" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
    }
    return 0;
}