#include<iostream>
#include<fstream>
#include <cstring> 
#include <string>
using namespace std;
class Name
{
private:
    char* fName;
    char* lName;
public:
    Name(char*, char*);
    Name();
    void SetName();
    void getName(char*&, char*&);
    void setName(char*, char*);
    Name(const Name&);
    friend ostream& operator<<(ostream&, const Name&);
    ~Name()
    {
        delete[]fName;
        delete[]lName;
    }
};
Name::Name()
{
    fName = new char[25];
    lName = new char[25];
}
Name::Name(char* fN, char* lN)
{
    fName = new char[25];
    lName = new char[25];
    for (int i = 0; i < 25; i++)
    {
        fName[i] = fN[i];
        lName[i] = lN[i];
    }
}
Name::Name(const Name& n)
{
    fName = n.fName;
    lName = n.lName;
}
void Name::SetName()
{
    cout << "Enter first Name(char[]): ";
    cin.getline(fName, 25);
    cout << "Enter last name(char[]): ";
    cin.getline(lName, 25);
}
ostream& operator<<(ostream& COUT, const Name& name)
{
    COUT << "Name: ";
    COUT << name.fName << " " << name.lName << endl;
    return COUT;
}
void Name::getName(char*&First, char*&Last)
{
    First = new char[25];
    Last = new char[25];
    for (int i = 0; i < 25; i++)
    {
        First[i] = fName[i];
        Last[i] = lName[i];
    }
}
void Name::setName(char* First, char* Last)
{
    for (int i = 0; i < 25; i++)
    {
        fName[i] = First[i];
        lName[i] = Last[i];
    }
}
class Date
{
private:
    int day;
    int month;
    int year;
public:
    Date();
    Date(int, int, int);
    void setDate();
    void SetDate(int, int, int);
    void getDate(int&, int&, int&);
    friend ostream& operator<<(ostream&, const Date&);
};
Date::Date()
{
    day = 0;
    month = 0;
    year = 0;
}
Date::Date(int d, int m, int y)
{
    day = d;
    month = m;
    year = y;
}
void Date::setDate()
{
    cout << "Enter day: ";
    cin >> day;
    cout << "Enter month: ";
    cin >> month;
    cout << "Enter year: ";
    cin >> year;
}
void Date::getDate(int&Day, int&Month, int&Year)
{
    Day = day;
    Month = month;
    Year = year;
}
void Date::SetDate(int Day, int Month, int Year)
{
    day = Day;
    month = Month;
    year = Year;
}
ostream& operator<<(ostream& COUT, const Date& date)
{
    //day / mon / year
    COUT << date.day << " / " << date.month << " / " << date.year << endl;
    return COUT;
}
class mTime
{
private:
    int hour;
    int min;
    int sec;
public:
    mTime();
    mTime(int, int, int);
    void setmTime();
    void getmTime(int&, int&, int&);
    void SetmTime(int, int, int);
    friend ostream& operator<<(ostream&, const mTime&);
};
mTime::mTime()
{
    hour = 0;
    min = 0;
    sec = 0;
}
mTime::mTime(int h, int m, int s)
{
    hour = h;
    min = m;
    sec = s;
}
void mTime::setmTime()
{
    cout << "Enter Hours: ";
    cin >> hour;
    cout << "Enter minutes: ";
    cin >> min;
    cout << "Enter seconds: ";
    cin >> sec;
}
void mTime::getmTime(int& h, int& m, int& s)
{
    h = hour;
    m = min;
    s = sec;
}
void mTime::SetmTime(int h, int m, int s) 
{
    hour = h;
    min = m;
    sec = s;
}
ostream& operator<<(ostream& COUT, const mTime& time)
{
    //hr : min : sec
    COUT << time.hour << " : " << time.min << " : " << time.sec << endl;
    return COUT;
}
class Service
{
private:
    char* source;
    char* destination;
    float distance; 
    Date bookingDate;
    mTime bookingTime;
    bool status;
    float fuelrate;
    int cId;
    int dId;  
    int vId;  
public:
    Service();
    int getvid()
    {
        return vId;
    }
    int getcid()
    {
        return cId;
    }
    int getdid()
    {
        return dId;
    }
    void setService();
    void GetData(char*&, char*&, float&, int&, int&, int&, int&, int&, int&, int&, float&, int&, int&, int&);
    void SetData(char*, char*, float, int, int, int, int, int, int, int, float, int, int, int);
};
Service::Service()
{
    source = new char[25];
    destination = new char[25];
    distance = 0.0;
    status = false;
    fuelrate = 0.0;
    cId = 0;
    dId = 0;
    vId = 0;
}
void Service::setService()
{
    cin.ignore();
    cout << "Enter Source(char[]): ";
    cin.getline(source, 25);
    cout << "Enter Destinations(char[]): ";
    cin.getline(destination, 25);
    cout << "Enter Distance: ";
    cin >> distance;
    bookingDate.setDate();
    bookingTime.setmTime();
    cout << "Enter status(1 for true, 0 for false): ";
    int stat;
    cin >> stat;
    if (stat == 1)
    {
        status = true;
    }
    else
    {
        status = false;
    }
    cout << "Enter fuel rate: ";
    cin >> fuelrate;
    cout << "Enter cId: ";
    cin >> cId;
    cout << "Enter dId: ";
    cin >> dId;
    cout << "Enter vId: ";
    cin >> vId;
}
void Service::GetData(char*& Source, char*& Destination, float& Distance, int& Day, int& Month, int& Year, int& Hour, int& Min, int& Sec, int& Status, float& FuelRate, int& CId, int& DId, int& VId)
{
    Source = new char[25];
    for (int i = 0; i < 25; i++)
    {
        Source[i] = source[i];
    }
    Destination = new char[25];
    for (int i = 0; i < 25; i++)
    {
        Destination[i] = destination[i];
    }
    Distance = distance;
    bookingDate.getDate(Day, Month, Year);
    bookingTime.getmTime(Hour,Min,Sec);
    if (status)
    {
        Status = 1;
    }
    else
    {
        Status = 0;
    }
    FuelRate = fuelrate;
    CId = cId;
    DId = dId;
    VId = vId;
}
void Service::SetData(char* Source, char* Destination, float Distance, int Day, int Month, int Year, int Hour, int Min, int Sec, int Status, float FuelRate, int CId, int DId, int VId)
{
    for (int i = 0; i < 25; i++)
    {
        source[i] = Source[i];
    }
    for (int i = 0; i < 25; i++)
    {
        destination[i] = Destination[i];
    }
    distance = Distance;
    bookingDate.SetDate(Day, Month, Year);
    bookingTime.SetmTime(Hour, Min, Sec);
    if (Status==1)
    {
        status = true;
    }
    else
    {
        status = false;
    }
    fuelrate = FuelRate;
    cId = CId;
    dId = DId;
    vId = VId;
}
class Ride : public Service
{
private:
    int noofPassengers;
    char* rideType;
    float DriverRanking;
    float VehicleRanking;
public:
    Ride();
    int getVID()
    {
        return (getvid());
    }
    void setRide();
    void getAllData(int&, char*&, float&, float&, char*&, char*&, float&, int&, int&, int&, int&, int&, int&, int&, float&, int&, int&, int&);
    void setAllData(int, char*, float, float, char*, char*, float, int, int, int, int, int, int, int, float, int, int, int);
};
Ride::Ride()
{
    noofPassengers = 0;
    rideType = new char[25];
    DriverRanking = 0.0;
    VehicleRanking = 0.0;
}
void Ride::setRide()
{
    setService();
    cout << "Enter NO of Passenger: ";
    cin >> noofPassengers;
    cin.ignore();
    cout << "Enter ride type(char[]): ";
    cin.getline(rideType, 25);
    cout << "Enter Driver Ranking: ";
    cin >> DriverRanking;
    cout << "Enter Vehicle Ranking: ";
    cin >> VehicleRanking;
}
void Ride::getAllData(int& NoPassenegers, char*& RideType, float& DriverRank, float& VehicleRank, char*& Source, char*& Destination, float& Distance, int& Day, int& Month, int& Year, int& Hour, int& Min, int& Sec, int& Status, float& FuelRate, int& CId, int& DId, int& VId)
{
    NoPassenegers = noofPassengers;
    RideType = new char[25];
    for (int i = 0; i < 25; i++)
    {
        RideType[i] = rideType[i];
    }
    DriverRank = DriverRanking;
    VehicleRank = VehicleRanking;
    GetData(Source, Destination, Distance, Day, Month, Year, Hour, Min, Sec, Status, FuelRate, CId, DId, VId);
}
void Ride::setAllData(int NoPassenegers, char* RideType, float DriverRank, float VehicleRank, char* Source, char* Destination, float Distance, int Day, int Month, int Year, int Hour, int Min, int Sec, int Status, float FuelRate, int CId, int DId, int VId)
{
    noofPassengers = NoPassenegers;
    for (int i = 0; i < 25; i++)
    {
        rideType[i] = RideType[i];
    }
    DriverRanking = DriverRank;
    VehicleRanking = VehicleRank;
    SetData(Source, Destination, Distance, Day, Month, Year, Hour, Min, Sec, Status, FuelRate, CId, DId, VId);
}
class Delivery :public Service
{
private:
    float goodsWeight;
    char* goodsType;
public:
    Delivery()
    {
        goodsWeight = 0.0;
        goodsType = new char[25];
    }
    ~Delivery()
    {
        delete[]goodsType;
    }
    void setDelivery();
    void GetAlldata(float&, char*&, char*&, char*&, float&, int&, int&, int&, int&, int&, int&, int&, float&, int&, int&, int&);
    void SetAlldata(float, char*, char*, char*, float, int, int, int, int, int, int, int, float, int, int, int);
};
void Delivery::setDelivery()
{
    cin.ignore();
    cout << "Enter Goods Type(char[]): ";
    cin.getline(goodsType, 25);
    cout << "Enter Goods Weight: ";
    cin >> goodsWeight;
    setService();
}
void Delivery::GetAlldata(float& Weight, char*& Type, char*& Source, char*& Destination, float& Distance, int& Day, int& Month, int& Year, int& Hour, int& Min, int& Sec, int& Status, float& FuelRate, int& CId, int& DId, int& VId)
{
    Weight = goodsWeight;
    Type = new char[25];
    for (int i = 0; i < 25; i++)
    {
        Type[i] = goodsType[i];
    }
    GetData(Source, Destination, Distance, Day, Month, Year, Hour, Min, Sec, Status, FuelRate, CId, DId, VId);
}
void Delivery::SetAlldata(float Weight, char* Type, char* Source, char* Destination, float Distance, int Day, int Month, int Year, int Hour, int Min, int Sec, int Status, float FuelRate, int CId, int DId, int VId)
{
    goodsWeight = goodsWeight;
    for (int i = 0; i < 25; i++)
    {
        goodsType[i] = Type[i];
    }
    SetData(Source, Destination, Distance, Day, Month, Year, Hour, Min, Sec, Status, FuelRate, CId, DId, VId);
}
class Person
{
    Name pName;
    Date DOB;
    int Age;
    int Nid;
public:
    Person();
    Person(Name,Date,int,int);
    Person(const Person&);
    void setPerson();
    void getPersonName(char*& , char*& ,int&,int&);
    void setPersonName(char*, char*, int, int);
    void getPersonDate(int&, int&, int&);
    void setPersonDate(int, int, int);
    friend ostream& operator<<(ostream&, const Person&);
};
Person::Person()
{
    Nid = 0;
    Age = 0;
}
void Person::setPerson()
{
    pName.SetName();
    DOB.setDate();
    cout << "Enter age: ";
    cin >> Age;
    cout << "Enter Nid: ";
    cin >> Nid;
}
Person::Person(Name n, Date d, int a, int b)
{
    pName = n;
    DOB = d;
    Age = a;
    Nid = b;
}
Person::Person(const Person&p)
{
    pName = p.pName;
    DOB = p.DOB;
    Age = p.Age;
    Nid = p.Nid;
}
void Person::getPersonName(char*& First, char*& Last,int&AGE,int&NID)
{
    AGE = Age;
    NID = Nid;
    pName.getName(First, Last);
}
void Person::setPersonName(char* First, char* Last, int AGE, int NID)
{
    Age = AGE;
    Nid = NID;
    pName.setName(First, Last);
}
void Person::getPersonDate(int& Day, int& Month, int& Year)
{
    DOB.getDate(Day, Month, Year);
}
void Person::setPersonDate(int Day, int Month, int Year)
{
    DOB.SetDate(Day, Month, Year);
}
ostream& operator<<(ostream& COUT, const Person& P)
{
    COUT << P.pName;
    COUT << P.DOB;
    COUT << "Age: "<<P.Age<<endl<<"Nid: "<<P.Nid;
    return COUT;
}
class Customer :public Person
{
private:
    int cId;
    Service** bookingHistory;
    //members if needed
public:
    Customer();
    ~Customer()
    {
        delete[]bookingHistory;
    }
    void setCustomer();
    void getAllData(int&, char*&, char*&, int&, int&, int&,int&,int&);
    void setAllData(int, char*, char*, int, int, int, int, int);
    int getId()
    {
        return cId;
    }
};
Customer::Customer()
{
    cId = 0;
    bookingHistory = new Service * [20];
}
void Customer::setCustomer()
{
    cout << "Enter cId: ";
    cin >> cId;
    cin.ignore();
    setPerson();
}
void Customer::getAllData(int&cID, char*&firstN, char*&lastN, int&Day, int&Month, int&Year,int&AGE,int&NID)
{
    cID = cId;
    getPersonName(firstN, lastN,AGE,NID);
    getPersonDate(Day, Month, Year);
}
void Customer::setAllData(int cID, char* firstN, char* lastN, int Day, int Month, int Year, int AGE, int NID)
{
    cId = cID;
    setPersonName(firstN, lastN, AGE, NID);
    setPersonDate(Day, Month, Year);
}
class Driver :public Person
{
private:
    int dId;
    char* LicencesList;
    int noofLicences;
    float overallRanking;
    float salary;
    int experience;
    int status;
    Service** serviceHistory;
public:
    Driver();
    void setDriver();
    int getID()
    {
        return dId;
    }
    void getallData(int&, char*&, char*&, int&, int&, int&, int&, int&, char*&,int&, float&, float&, int&, int &);
    void setallData(int, char*, char*, int, int, int, int, int, char*, int, float, float, int, int);
    float getRanking()
    {
        return overallRanking;
    }
    int getNoOfLic()
    {
        return noofLicences;
    }
};
Driver::Driver()
{
    dId = 0;
    LicencesList = new char [25];
    noofLicences = 0;
    overallRanking = 0.0;
    salary = 0.0;
    experience = 0;
    status = 0;
    serviceHistory = new Service * [25];
}
void Driver::setDriver()
{
    setPerson();
    cout << "Enter dId: ";
    cin >> dId;
    cout << "Licenses Types: \n";
    cout << "1. Motorcar/jeep." << endl;
    cout << "2. Motorbike/rickshaw." << endl;
    cout << "3. LTV." << endl;
    cout << "4. HTV." << endl;
    cout << "5. Tractor." << endl;
    cout << "6. PSV." << endl;
    cout << "7. International driver's permit." << endl;
    cout << "Enter No of Licenses: ";
    cin >> noofLicences;
    delete[]LicencesList;
    LicencesList = new char[noofLicences];
    int Lcount = 1;
    for (int i = 0; i < noofLicences; i++)
    {
        cout << "Enter Licencse " << Lcount << " type from above 7: ";
        cin >> LicencesList[i];
        Lcount++;
    }
    cout<< "Enter overall Ranking: ";
    cin >> overallRanking;
    cout << "Enter salary: ";
    cin >> salary;
    cout << "Enter experience: ";
    cin >> experience;
    cout << "Enter Status: ";
    cin >> status;
}
void Driver::getallData(int& DID, char*& firstN, char*& lastN, int& Day, int& Month, int& Year, int& AGE,int& NID, char*& licenses,int& Lcount, float& OverallRanking, float& Salary, int& Experience, int& Status)
{
    DID = dId;
    getPersonName(firstN, lastN,AGE, NID);
    getPersonDate(Day, Month, Year);
    Lcount = noofLicences;
    licenses = new char[noofLicences];
    for (int i = 0; i < noofLicences; i++)
    {
        licenses[i] = LicencesList[i];
    }
    OverallRanking = overallRanking;
    Salary = salary;
    Experience = experience;
    Status = status;
}
void Driver::setallData(int DID, char* firstN, char* lastN, int Day, int Month, int Year, int AGE, int NID, char* licenses, int Lcount, float OverallRanking, float Salary, int Experience, int Status)
{
    dId = DID;
    setPersonName(firstN, lastN, AGE, NID);
    setPersonDate(Day, Month, Year);
    noofLicences = Lcount;
    for (int i = 0; i < noofLicences; i++)
    {
        LicencesList[i] = licenses[i];
    }
    overallRanking = OverallRanking;
    salary = Salary;
    experience = Experience;
    status = Status;
}
class Feature
{
private:
    int fId;
    char* description;
    float cost;
public:
    Feature()
    {
        fId = 0;
        description = new char[25];
        cost = 0.0;
    }
};
class Vehicle
{
private:
    int vId;
    int registrationNo;
    float avgMileage;
    char* LicenceType;
    bool status;
    char* fuelType;
    float overallRanking;
    Date manufacturingDate;
    Feature* list;
    Service* serviceHistory;
    
public:
    Vehicle();
    void setVehicle();
    int getID()
    {
        return vId;
    }
    ~Vehicle()
    {
        delete[]LicenceType;
        delete[]fuelType;
        delete[]list;
    }
    void getallData(int&, int&, float&, char*&, int&, char*&, float&, int&, int&, int&);
    void setallData(int, int, float, char*, int, char*, float, int, int, int);
};
Vehicle::Vehicle()
{
    vId = 0;
    registrationNo = 0;
    avgMileage = 0;
    LicenceType = new char[25];
    status = false;
    fuelType = new char[25];
    overallRanking = 0;
    list = new Feature[25];
    serviceHistory = new Service[25];
}
void Vehicle::setVehicle()
{
    manufacturingDate.setDate();
    cout << "Enter vId: ";
    cin >> vId;
    cout << "Enter registration No: ";
    cin >> registrationNo;
    cout << "Enter average Mileage: ";
    cin >> avgMileage;
    cout << "Enter Licence Type(char[]): ";
    cin.ignore();
    cin.getline(LicenceType,25);
    cout << "Enter status(1 for true, 0 for false): ";
    int stat;
    cin >> stat;
    if (stat==1)
    {
        status = true;
    }
    else
    {
        status = false;
    }
    cout << "Enter fuel type(char[]): ";
    cin.ignore();
    cin.getline(fuelType, 25);
    cout << "Enter overall ranking ";
    cin >> overallRanking;
}
void Vehicle::getallData(int& VID, int& regNo, float& AvgMileage, char*& Licence, int& stat, char*& FuelType, float& overallRank, int& DAY, int& MONTH, int& YEAR)
{
    manufacturingDate.getDate(DAY, MONTH, YEAR);
    VID = vId;
    regNo = registrationNo;
    AvgMileage = avgMileage;
    Licence = new char[25];
    for (int i = 0; i < 25; i++)
    {
        Licence[i] = LicenceType[i];
    }
    if (status)
    {
        stat = 1;
    }
    else
    {
        stat = 0;
    }
    FuelType = new char[25];
    for (int i = 0; i < 25; i++)
    {
        FuelType[i] = fuelType[i];
    }
    overallRank = overallRanking;
}
void Vehicle::setallData(int VID, int regNo, float AvgMileage, char* Licence, int stat, char* FuelType, float overallRank, int DAY, int MONTH, int YEAR)
{
    manufacturingDate.SetDate(DAY, MONTH, YEAR);
    vId = VID;
    registrationNo = regNo;
    avgMileage = AvgMileage;
    for (int i = 0; i < 25; i++)
    {
        LicenceType[i] = Licence[i];
        fuelType[i] = FuelType[i];
    }
    if (stat==1)
    {
        status = true;
    }
    else
    {
        status = false;
    }
    overallRanking = overallRank;
}
class TMS
{
public:
    TMS();
    ~TMS();
    void getCounts(int&, int&, int&, int&, int&);
    void Task1_addCustomer(int);
    void Task2_addDriver(int);
    void Task2_deleteDriver(int &,int);
    void Task3_addVehicle(int);
    void Task3_deleteVehicle(int&, int);
    void Task4_PrintCustomers(int);
    void Task5_PrintDrivers(int);
    void Task6_PrintVehicles(int);
    void Task7_PrintParticularVehicle(int, int, int, int);
    void Task8_PrintParticularCustomer(int, int, int, int);
    void Task9_PrintParticularDriver(int, int, int, int);
    void Task10_Rank(int);
    void Task11_MultipleLicenses(int);
    void Task12_PrintSalary(int);
    void Task13_BookRide(int);
    void Task13_BookDelivery(int);
private:
    Driver* d;
    Customer* c;
    Vehicle* v;
    Ride* r;
    Delivery* Del;
    int CustCount;
    int DriverCount;
    int VehicleCount;
    int RideCount;
    int DeliveryCount;
};
void TMS::getCounts(int& a, int& b, int& c, int& d,int &e)
{
    a = CustCount;
    b = DriverCount;
    c = VehicleCount;
    d = RideCount;
    e = DeliveryCount;
}
void delete_line(const char* FILES, int lineNO)
{
    ifstream is(FILES);
    ofstream ofs;
    ofs.open("temp.txt", ofstream::out);
    char c;
    int line_no = 0;
    while (is.get(c))
    {
        if (c == '\n')
            line_no++;
        if (line_no != lineNO)
            ofs << c;
    }
    ofs.close();
    is.close();
    remove(FILES);
    rename("temp.txt", FILES);
}
TMS::TMS()
{
    d = new Driver[10];
    c = new Customer[15];
    v = new Vehicle[20];
    r = new Ride[50];
    Del = new Delivery[50];
    CustCount = 0;
    DriverCount = 0;
    VehicleCount = 0;
    RideCount = 0;
    DeliveryCount = 0;
    ifstream Customers("Customers.txt");
    if (Customers.is_open())
    {
        while (true)
        {
            char ignore;
            int cID;
            char* firstN;
            firstN = new char[25];
            char* lastN;
            lastN = new char[25];
            int Day;
            int Month;
            int Year;
            int AGE;
            int NID;
            Customers >> cID;
            if (Customers.eof())
            {
                break;
            }
            else
            {
                Customers >> ignore;
                Customers.getline(firstN,25,',');
                Customers.getline(lastN,25,',');
                Customers >> Day;
                Customers >> ignore;
                Customers >> Month;
                Customers >> ignore;
                Customers >> Year;
                Customers >> ignore;
                Customers >> AGE;
                Customers >> ignore;
                Customers >> NID;
                c[CustCount].setAllData(cID, firstN, lastN, Day, Month, Year, AGE, NID);
                CustCount++;
            }
        }
    }
    ifstream Drivers("Drivers.txt");
    if (Drivers.is_open())
    {
        while (true)
        {
            char ignore;
            int DID;
            char* firstN;
            firstN = new char[25];
            char* lastN;
            lastN = new char[25];
            int Day;
            int Month;
            int Year;
            int AGE;
            int NID;
            char* licenses;
            licenses = new char[7];
            float overallRanking;
            float salary;
            int experience;
            int status;
            int Lcount;
            Drivers >> DID;
            if (Drivers.eof())
            {
                break;
            }
            else
            {
                Drivers >> ignore;
                Drivers.getline(firstN, 25, ',');
                Drivers.getline(lastN, 25, ',');
                Drivers >> Day;
                Drivers >> ignore;
                Drivers >> Month;
                Drivers >> ignore;
                Drivers >> Year;
                Drivers >> ignore;
                Drivers >> AGE;
                Drivers >> ignore;
                Drivers >> NID;
                Drivers >> ignore;
                Drivers >> Lcount;
                Drivers >> ignore;
                for (int i = 0; i < Lcount; i++)
                {
                    Drivers >> ignore;
                    licenses[i] = ignore;
                    Drivers >> ignore;
                }
                Drivers >> overallRanking;
                Drivers >> ignore;
                Drivers >> salary;
                Drivers >> ignore;
                Drivers >> experience;
                Drivers >> ignore;
                Drivers >> status;
                d[DriverCount].setallData(DID, firstN, lastN, Day, Month, Year, AGE, NID, licenses, Lcount, overallRanking, salary, experience, status);
                DriverCount++;
            }
        }
    }
    ifstream Vehicles("Vehicles.txt");
    if (Vehicles.is_open())
    {
        while (true)
        {
            char ignore;
            int VID;
            int registrationNo;
            float avgMileage;
            char* LicenceType;
            LicenceType = new char[25];
            int status;
            char* fuelType;
            fuelType = new char[25];
            float overallRanking;
            int Day;
            int Month;
            int Year;
            Vehicles >> VID;
            if (Vehicles.eof())
            {
                break;
            }
            else
            {
                Vehicles >> ignore;
                Vehicles >> registrationNo;
                Vehicles >> ignore;
                Vehicles >> avgMileage;
                Vehicles >> ignore;
                Vehicles.getline(LicenceType, 25, ',');
                Vehicles >> status;
                Vehicles >> ignore;
                Vehicles.getline(fuelType, 25, ',');
                Vehicles >> overallRanking;
                Vehicles >> ignore;
                Vehicles >> Day;
                Vehicles >> ignore;
                Vehicles >> Month;
                Vehicles >> ignore;
                Vehicles >> Year;
                v[VehicleCount].setallData(VID, registrationNo, avgMileage, LicenceType, status, fuelType, overallRanking, Day, Month, Year);
                VehicleCount++;
            }
        }
    }
    ifstream Rides("Ride.txt");
    if (Rides.is_open())
    {
        while (true)
        {
            char ignore;
            int cId;
            int dId;
            int vId;
            int noofPassengers;
            char* rideType;
            rideType = new char[25];
            float DriverRanking;
            float VehicleRanking;
            char* source;
            source = new char[25];
            char* destination;
            destination = new char[25];
            float distance;
            int day;
            int month;
            int year;
            int hour;
            int min;
            int sec;
            int status;
            float fuelrate;
            Rides >> cId;
            if (Rides.eof())
            {
                break;
            }
            else
            {
                Rides >> ignore;
                Rides >> dId;
                Rides >> ignore;
                Rides >> vId;
                Rides >> ignore;
                Rides >> noofPassengers;
                Rides >> ignore;
                Rides.getline(rideType,25,',');
                Rides >> DriverRanking;
                Rides >> ignore;
                Rides >> VehicleRanking;
                Rides >> ignore;
                Rides.getline(source,25,',');
                Rides.getline(destination, 25, ',');
                Rides >> distance;
                Rides >> ignore;
                Rides >> day;
                Rides >> ignore;
                Rides >> month;
                Rides >> ignore;
                Rides >> year;
                Rides >> ignore;
                Rides >> hour;
                Rides >> ignore;
                Rides >> min;
                Rides >> ignore;
                Rides >> sec;
                Rides >> ignore;
                Rides >> status;
                Rides >> ignore;
                Rides >> fuelrate;
                r[RideCount].setAllData(noofPassengers, rideType, DriverRanking, VehicleRanking, source, destination, distance, day, month, year, hour, min, sec, status, fuelrate, cId, dId, vId);
                RideCount++;
            }
        }
    }
    ifstream Deliverys("Delivery.txt");
    if (Deliverys.is_open())
    {
        while (true)
        {
            char ignore;
            float goodsWeight;
            char* goodsType;
            goodsType = new char[25];
            char* source;
            source = new char[25];
            char* destination;
            destination = new char[25];
            float distance;
            int day;
            int month;
            int year;
            int hour;
            int min;
            int sec;
            int status;
            float fuelrate;
            int cId;
            int dId;
            int vId;
            Deliverys >> cId;
            if (Deliverys.eof())
            {
                break;
            }
            else
            {
                Deliverys >> ignore;
                Deliverys >> dId;
                Deliverys >> ignore;
                Deliverys >> vId;
                Deliverys >> ignore;
                Deliverys >> goodsWeight;
                Deliverys >> ignore;
                Deliverys.getline(goodsType, 25, ',');
                Deliverys.getline(source, 25, ',');
                Deliverys.getline(destination, 25, ',');
                Deliverys >> distance;
                Deliverys >> ignore;
                Deliverys >> day;
                Deliverys >> ignore;
                Deliverys >> month;
                Deliverys >> ignore;
                Deliverys >> year;
                Deliverys >> ignore;
                Deliverys >> hour;
                Deliverys >> ignore;
                Deliverys >> min;
                Deliverys >> ignore;
                Deliverys >> sec;
                Deliverys >> ignore;
                Deliverys >> status;
                Deliverys >> ignore;
                Deliverys >> fuelrate;
                Del[DeliveryCount].SetAlldata(goodsWeight, goodsType, source, destination, distance, day, month, year, hour, min, sec, status, fuelrate, cId, dId, vId);
                DeliveryCount++;
            }   
        }
    }
}
TMS::~TMS()
{
    delete[]d;
    delete[]c;
    delete[]v;
    delete[]r;
    delete[]Del;
}
void TMS::Task1_addCustomer(int count)
{
    c[count].setCustomer();
    ofstream Customers("Customers.txt",ios::app);
    if (Customers.is_open())
    {
        int cID;
        char* firstN;
        char* lastN;
        int Day;
        int Month;
        int Year;
        int AGE;
        int NID;
        c[count].getAllData(cID, firstN, lastN, Day, Month, Year, AGE, NID);
        Customers << cID;
        Customers << ',';
        Customers << firstN;
        Customers << ',';
        Customers << lastN;
        Customers << ',';
        Customers << Day;
        Customers << ',';
        Customers << Month;
        Customers << ',';
        Customers << Year;
        Customers << ',';
        Customers << AGE;
        Customers << ',';
        Customers << NID;
        Customers << '\n';
        Customers.close();
        cout << endl << "Customer Saved In File"<<endl;
    }
    else
    {
        cout << endl << "Customer Could Not Be Saved In File." << endl;
    }
}
void TMS::Task2_addDriver(int count)
{
    d[count].setDriver();
    ofstream Drivers("Drivers.txt", ios::app);
    if (Drivers.is_open())
    {
        int DID;
        char* firstN;
        char* lastN;
        int Day;
        int Month;
        int Year;
        int AGE;
        int NID;
        char* licenses;
        float overallRanking;
        float salary;
        int experience;
        int status;
        int Lcount;
        d[count].getallData(DID, firstN,  lastN,  Day,  Month,  Year,  AGE,  NID,  licenses,Lcount,  overallRanking,  salary,  experience,  status);
        Drivers << DID;
        Drivers << ',';
        Drivers << firstN;
        Drivers << ',';
        Drivers << lastN;
        Drivers << ',';
        Drivers << Day;
        Drivers << ',';
        Drivers << Month;
        Drivers << ',';
        Drivers << Year;
        Drivers << ',';
        Drivers << AGE;
        Drivers << ',';
        Drivers << NID;
        Drivers << ',';
        Drivers << Lcount;
        Drivers << ',';
        for (int i = 0; i <Lcount ; i++)
        {
            Drivers << licenses[i];
            Drivers << ',';
        }
        Drivers << overallRanking;
        Drivers << ',';
        Drivers << salary;
        Drivers << ',';
        Drivers << experience;
        Drivers << ',';
        Drivers << status;
        Drivers << '\n';
        Drivers.close();
        cout << endl << "Driver Saved In File." << endl;
    }
    else
    {
        cout << endl << "Driver Could Not Be Saved In File." << endl;
    }
}
void TMS::Task2_deleteDriver(int&count, int DID)
{
    int countcheck;
    bool check = false;
    for (int i = 0; i < count; i++)
    {
        if (d[i].getID()==DID)
        {
            check = true;
            countcheck = i;
            break;
        }
    }
    if (check)
    {
        delete_line("Drivers.txt", countcheck);
        cout << endl << "Driver deleted from file." << endl;
        count--;
    }
    else
    {
        cout << "Driver not found."<<endl;
    }
}
void TMS::Task3_addVehicle(int count)
{
    v[count].setVehicle();
    ofstream Vehicles("Vehicles.txt", ios::app);
    if (Vehicles.is_open())
    {
        int VID;
        int registrationNo;
        float avgMileage;
        char* LicenceType;
        int status;
        char* fuelType;
        float overallRanking;
        int Day;
        int Month;
        int Year;
        v[count].getallData(VID,registrationNo,avgMileage,LicenceType,status,fuelType,overallRanking,Day,Month,Year);
        Vehicles << VID;
        Vehicles << ',';
        Vehicles << registrationNo;
        Vehicles << ',';
        Vehicles << avgMileage;
        Vehicles << ',';
        Vehicles << LicenceType;
        Vehicles << ',';
        Vehicles << status;
        Vehicles << ',';
        Vehicles << fuelType;
        Vehicles << ',';
        Vehicles << overallRanking;
        Vehicles << ',';
        Vehicles << Day;
        Vehicles << ',';
        Vehicles << Month;
        Vehicles << ',';
        Vehicles << Year;
        Vehicles << '\n';
        Vehicles.close();
        cout << endl << "Vehicle Saved In File." << endl;
    }
    else
    {
        cout << endl << "Vehicle Could Not Be Saved In File." << endl;
    }
}
void TMS::Task3_deleteVehicle(int& count, int VID)
{
    int countcheck;
    bool check = false;
    for (int i = 0; i < count; i++)
    {
        if (v[i].getID() == VID)
        {
            check = true;
            countcheck = i;
            break;
        }
    }
    if (check)
    {
        delete_line("Vehicles.txt", countcheck);
        cout << endl << "Vehicle deleted from file." << endl;
        count--;
    }
    else
    {
        cout << "Driver not found." << endl;
    }
}
void TMS::Task4_PrintCustomers(int count)
{
    for (int i = 0; i < count; i++)
    {
        int cID;
        char* firstN;
        char* lastN;
        int Day;
        int Month;
        int Year;
        int AGE;
        int NID;
        c[i].getAllData(cID, firstN, lastN, Day, Month, Year, AGE, NID);
        cout << "Customer Id: " << cID << endl;
        cout << "First Name: " << firstN << endl << "Last Name: " << lastN << endl;
        cout << "Day: " << Day << endl << "Month: " << Month << endl << "Year: " << Year << endl;
        cout << "Age: " << AGE << endl << "NID: " << NID << endl << endl << endl;
    }
}
void TMS::Task5_PrintDrivers(int count)
{
    for (int i = 0; i < count; i++)
    {
        int DID;
        char* firstN;
        char* lastN;
        int Day;
        int Month;
        int Year;
        int AGE;
        int NID;
        char* licenses;
        float overallRanking;
        float salary;
        int experience;
        int status;
        int Lcount;
        d[i].getallData(DID, firstN, lastN, Day, Month, Year, AGE, NID, licenses, Lcount, overallRanking, salary, experience, status);
        cout << "Driver Id: " << DID << endl;
        cout << "First Name: " << firstN << endl << "Last Name: " << lastN << endl;
        cout << "Day: " << Day << endl << "Month: " << Month << endl << "Year: " << Year << endl;
        cout << "Age: " << AGE << endl << "NID: " << NID << endl;
        cout << "Licenses: " << endl;
        for (int i = 0; i < Lcount; i++)
        {
            if (licenses[i] == '1')
            {
                cout << "Motorcar/jeep" << endl;
            }
            else if (licenses[i] == '2')
            {
                cout << "Motorbike/rickshaw" << endl;
            }
            else if (licenses[i] == '3')
            {
                cout << "LTV" << endl;
            }
            else if (licenses[i] == '4')
            {
                cout << "HTV" << endl;
            }
            else if (licenses[i] == '5')
            {
                cout << "Tractor" << endl;
            }
            else if (licenses[i] == '6')
            {
                cout << "PSV" << endl;
            }
            else if (licenses[i] == '7')
            {
                cout << "International driver's permit" << endl;
            }
        }
        cout << "Overall Ranking: " << overallRanking << endl;
        cout << "Salary: " << salary << endl << "Experience: " << experience << endl;
        cout << "Status: " << status << endl << endl << endl;
    }
}
void TMS::Task6_PrintVehicles(int count)
{
    for (int i = 0; i < count; i++)
    {
        int VID;
        int registrationNo;
        float avgMileage;
        char* LicenceType;
        int status;
        char* fuelType;
        float overallRanking;
        int Day;
        int Month;
        int Year;
        v[i].getallData(VID, registrationNo, avgMileage, LicenceType, status, fuelType, overallRanking, Day, Month, Year);
        cout << "Vehicle ID: " << VID << endl << "Registration Number: " << registrationNo << endl;
        cout << "Average Mileage: " << avgMileage << endl;
        cout << "Licence Type: " << LicenceType << endl << "Status: " << status << endl;
        cout << "Fuel Type: " << fuelType << endl;
        cout << "Overall Ranking: " << overallRanking << endl;
        cout << "Day: " << Day << endl << "Month: " << Month << endl << "Year: " << Year << endl << endl << endl;
    }
}
void TMS::Task7_PrintParticularVehicle(int count, int VID, int R_count, int D_count)
{
    bool check = false;
    bool check2 = false;
    bool check3 = false;
    for (int i = 0; i < count; i++)
    {
        if (v[i].getID()==VID)
        {
            int VID;
            int registrationNo;
            float avgMileage;
            char* LicenceType;
            int status;
            char* fuelType;
            float overallRanking;
            int Day;
            int Month;
            int Year;
            v[i].getallData(VID, registrationNo, avgMileage, LicenceType, status, fuelType, overallRanking, Day, Month, Year);
            cout << "Vehicle ID: " << VID << endl << "Registration Number: " << registrationNo << endl;
            cout << "Average Mileage: " << avgMileage << endl;
            cout << "Licence Type: " << LicenceType << endl << "Status: " << status << endl;
            cout << "Fuel Type: " << fuelType << endl;
            cout << "Overall Ranking: " << overallRanking << endl;
            cout << "Day: " << Day << endl << "Month: " << Month << endl << "Year: " << Year << endl << endl << endl;
            check = true;
        }
    }
    if (check)
    {
        for (int i = 0; i < R_count; i++)
        {
            if (r[i].getvid() == VID)
            {
                cout << "Ride Service: " << endl;
                int noofPassengers;
                char* rideType;
                float DriverRanking;
                float VehicleRanking;
                char* source;
                char* destination;
                float distance;
                int day;
                int month;
                int year;
                int hour;
                int min;
                int sec;
                int status;
                float fuelrate;
                int cId;
                int dId;
                int vId;
                r[i].getAllData(noofPassengers, rideType, DriverRanking, VehicleRanking, source, destination, distance, day, month, year, hour, min, sec, status, fuelrate, cId, dId, vId);
                cout << "Vehicle Id: " << vId << endl << "Driver Id: " << dId << endl;
                cout << "Customer Id: " << cId << endl << "Fuel Rate: " << fuelrate << endl;
                cout << "Day: " << day << endl << "Month: " << month << endl << "Year: " << year << endl;
                cout << "Hour: " << hour << endl << "Minute: " << min << endl << "Second: " << sec << endl;
                cout << "Distance: " << distance << endl << "Source: " << source << endl << "Destination: " << destination << endl;
                cout << "Driver Ranking: " << DriverRanking << endl << "Vehicle Ranking: " << VehicleRanking << endl;
                cout << "No of Passenegers: " << noofPassengers << endl;
                cout << "Ride type: " << rideType << endl << endl << endl;
                check2 = true;
            }
        }
        if (!check2)
        {
            cout << "No ride Service for this Id." << endl;
        }
        for (int i = 0; i < D_count; i++)
        {
            if (Del[i].getvid() == VID)
            {
                cout << "Delivery Service: " << endl;
                float goodsWeight;
                char* goodsType;
                char* source;
                char* destination;
                float distance;
                int day;
                int month;
                int year;
                int hour;
                int min;
                int sec;
                int status;
                float fuelrate;
                int cId;
                int dId;
                int vId;
                Del[i].GetAlldata(goodsWeight, goodsType, source, destination, distance, day, month, year, hour, min, sec, status, fuelrate, cId, dId, vId);
                cout << "Vehicle Id: " << vId << endl << "Driver Id: " << dId << endl;
                cout << "Customer Id: " << cId << endl << "Fuel Rate: " << fuelrate << endl;
                cout << "Day: " << day << endl << "Month: " << month << endl << "Year: " << year << endl;
                cout << "Hour: " << hour << endl << "Minute: " << min << endl << "Second: " << sec << endl;
                cout << "Distance: " << distance << endl << "Source: " << source << endl << "Destination: " << destination << endl;
                cout << "Goods Weight: " << goodsWeight << endl << "Goods Type: " << goodsType << endl << endl << endl;
                check3 = true;
            }
        }
        if (!check3)
        {
            cout << "No Delivery Service for this Id." << endl;
        }
    }
    else
    {
        cout << "Vehicle not found." << endl;
    }
}
void TMS::Task8_PrintParticularCustomer(int count, int CID, int R_count, int D_count)
{
    bool check = false;
    bool check2 = false;
    bool check3 = false;
    for (int i = 0; i < count; i++)
    {
        if (c[i].getId()==CID)
        {
            int cID;
            char* firstN;
            char* lastN;
            int Day;
            int Month;
            int Year;
            int AGE;
            int NID;
            c[i].getAllData(cID, firstN, lastN, Day, Month, Year, AGE, NID);
            cout << "Customer Id: " << cID << endl;
            cout << "First Name: " << firstN << endl << "Last Name: " << lastN << endl;
            cout << "Day: " << Day << endl << "Month: " << Month << endl << "Year: " << Year << endl;
            cout << "Age: " << AGE << endl << "NID: " << NID << endl << endl << endl;
            check = true;
        }
    }
    if (check)
    {
        for (int i = 0; i < R_count; i++)
        {
            if (r[i].getcid() == CID)
            {
                cout << "Ride Service: " << endl;
                int noofPassengers;
                char* rideType;
                float DriverRanking;
                float VehicleRanking;
                char* source;
                char* destination;
                float distance;
                int day;
                int month;
                int year;
                int hour;
                int min;
                int sec;
                int status;
                float fuelrate;
                int cId;
                int dId;
                int vId;
                r[i].getAllData(noofPassengers, rideType, DriverRanking, VehicleRanking, source, destination, distance, day, month, year, hour, min, sec, status, fuelrate, cId, dId, vId);
                cout << "Vehicle Id: " << vId << endl << "Driver Id: " << dId << endl;
                cout << "Customer Id: " << cId << endl << "Fuel Rate: " << fuelrate << endl;
                cout << "Day: " << day << endl << "Month: " << month << endl << "Year: " << year << endl;
                cout << "Hour: " << hour << endl << "Minute: " << min << endl << "Second: " << sec << endl;
                cout << "Distance: " << distance << endl << "Source: " << source << endl << "Destination: " << destination << endl;
                cout << "Driver Ranking: " << DriverRanking << endl << "Vehicle Ranking: " << VehicleRanking << endl;
                cout << "No of Passenegers: " << noofPassengers << endl;
                cout << "Ride type: " << rideType << endl << endl << endl;
                check2 = true;
            }
        }
        if (!check2)
        {
            cout << "No ride Service for this Id." << endl;
        }
        for (int i = 0; i < D_count; i++)
        {
            if (Del[i].getcid() == CID)
            {
                cout << "Delivery Service: " << endl;
                float goodsWeight;
                char* goodsType;
                char* source;
                char* destination;
                float distance;
                int day;
                int month;
                int year;
                int hour;
                int min;
                int sec;
                int status;
                float fuelrate;
                int cId;
                int dId;
                int vId;
                Del[i].GetAlldata(goodsWeight, goodsType, source, destination, distance, day, month, year, hour, min, sec, status, fuelrate, cId, dId, vId);
                cout << "Vehicle Id: " << vId << endl << "Driver Id: " << dId << endl;
                cout << "Customer Id: " << cId << endl << "Fuel Rate: " << fuelrate << endl;
                cout << "Day: " << day << endl << "Month: " << month << endl << "Year: " << year << endl;
                cout << "Hour: " << hour << endl << "Minute: " << min << endl << "Second: " << sec << endl;
                cout << "Distance: " << distance << endl << "Source: " << source << endl << "Destination: " << destination << endl;
                cout << "Goods Weight: " << goodsWeight << endl << "Goods Type: " << goodsType << endl << endl << endl;
                check3 = true;
            }
        }
        if (!check3)
        {
            cout << "No Delivery Service for this Id." << endl;
        }
    }
    else
    {
        cout << "Customer not found." << endl;
    }
}
void TMS::Task9_PrintParticularDriver(int count, int DID, int R_count, int D_count)
{
    bool check = false;
    bool check2 = false;
    bool check3 = false;
    for (int i = 0; i < count; i++)
    {
        if (d[i].getID()==DID)
        {
            int DID;
            char* firstN;
            char* lastN;
            int Day;
            int Month;
            int Year;
            int AGE;
            int NID;
            char* licenses;
            float overallRanking;
            float salary;
            int experience;
            int status;
            int Lcount;
            d[i].getallData(DID, firstN, lastN, Day, Month, Year, AGE, NID, licenses, Lcount, overallRanking, salary, experience, status);
            cout << "Driver Id: " << DID << endl;
            cout << "First Name: " << firstN << endl << "Last Name: " << lastN << endl;
            cout << "Day: " << Day << endl << "Month: " << Month << endl << "Year: " << Year << endl;
            cout << "Age: " << AGE << endl << "NID: " << NID << endl;
            cout << "Licenses: " << endl;
            for (int i = 0; i < Lcount; i++)
            {
                if (licenses[i] == '1')
                {
                    cout << "Motorcar/jeep" << endl;
                }
                else if (licenses[i] == '2')
                {
                    cout << "Motorbike/rickshaw" << endl;
                }
                else if (licenses[i] == '3')
                {
                    cout << "LTV" << endl;
                }
                else if (licenses[i] == '4')
                {
                    cout << "HTV" << endl;
                }
                else if (licenses[i] == '5')
                {
                    cout << "Tractor" << endl;
                }
                else if (licenses[i] == '6')
                {
                    cout << "PSV" << endl;
                }
                else if (licenses[i] == '7')
                {
                    cout << "International driver's permit" << endl;
                }
            }
            cout << "Overall Ranking: " << overallRanking << endl;
            cout << "Salary: " << salary << endl << "Experience: " << experience << endl;
            cout << "Status: " << status << endl << endl << endl;
            check = true;
        }
    }
    if (check)
    {
        for (int i = 0; i < R_count; i++)
        {
            if (r[i].getdid() == DID)
            {
                cout << "Ride Service: " << endl;
                int noofPassengers;
                char* rideType;
                float DriverRanking;
                float VehicleRanking;
                char* source;
                char* destination;
                float distance;
                int day;
                int month;
                int year;
                int hour;
                int min;
                int sec;
                int status;
                float fuelrate;
                int cId;
                int dId;
                int vId;
                r[i].getAllData(noofPassengers, rideType, DriverRanking, VehicleRanking, source, destination, distance, day, month, year, hour, min, sec, status, fuelrate, cId, dId, vId);
                cout << "Vehicle Id: " << vId << endl << "Driver Id: " << dId << endl;
                cout << "Customer Id: " << cId << endl << "Fuel Rate: " << fuelrate << endl;
                cout << "Day: " << day << endl << "Month: " << month << endl << "Year: " << year << endl;
                cout << "Hour: " << hour << endl << "Minute: " << min << endl << "Second: " << sec << endl;
                cout << "Distance: " << distance << endl << "Source: " << source << endl << "Destination: " << destination << endl;
                cout << "Driver Ranking: " << DriverRanking << endl << "Vehicle Ranking: " << VehicleRanking << endl;
                cout << "No of Passenegers: " << noofPassengers << endl;
                cout << "Ride type: " << rideType << endl << endl << endl;
                check2 = true;
            }
        }
        if (!check2)
        {
            cout << "No ride Service for this Id." << endl;
        }
        for (int i = 0; i < D_count; i++)
        {
            if (Del[i].getdid() == DID)
            {
                cout << "Delivery Service: " << endl;
                float goodsWeight;
                char* goodsType;
                char* source;
                char* destination;
                float distance;
                int day;
                int month;
                int year;
                int hour;
                int min;
                int sec;
                int status;
                float fuelrate;
                int cId;
                int dId;
                int vId;
                Del[i].GetAlldata(goodsWeight, goodsType, source, destination, distance, day, month, year, hour, min, sec, status, fuelrate, cId, dId, vId);
                cout << "Vehicle Id: " << vId << endl << "Driver Id: " << dId << endl;
                cout << "Customer Id: " << cId << endl << "Fuel Rate: " << fuelrate << endl;
                cout << "Day: " << day << endl << "Month: " << month << endl << "Year: " << year << endl;
                cout << "Hour: " << hour << endl << "Minute: " << min << endl << "Second: " << sec << endl;
                cout << "Distance: " << distance << endl << "Source: " << source << endl << "Destination: " << destination << endl;
                cout << "Goods Weight: " << goodsWeight << endl << "Goods Type: " << goodsType << endl << endl << endl;
                check3 = true;
            }
        }
        if (!check3)
        {
            cout << "No Delivery Service for this Id." << endl;
        }
    }
    else
    {
        cout << "Driver not found." << endl;
    }
}
void TMS::Task10_Rank(int count)
{
    for (int i = 0; i < count; i++)
    {
        if (d[i].getRanking()>4.5)
        {
            int DID;
            char* firstN;
            char* lastN;
            int Day;
            int Month;
            int Year;
            int AGE;
            int NID;
            char* licenses;
            float overallRanking;
            float salary;
            int experience;
            int status;
            int Lcount;
            d[i].getallData(DID, firstN, lastN, Day, Month, Year, AGE, NID, licenses, Lcount, overallRanking, salary, experience, status);
            cout << "Driver Id: " << DID << endl;
            cout << "First Name: " << firstN << endl << "Last Name: " << lastN << endl;
            cout << "Day: " << Day << endl << "Month: " << Month << endl << "Year: " << Year << endl;
            cout << "Age: " << AGE << endl << "NID: " << NID << endl;
            cout << "Licenses: " << endl;
            for (int i = 0; i < Lcount; i++)
            {
                if (licenses[i] == '1')
                {
                    cout << "Motorcar/jeep" << endl;
                }
                else if (licenses[i] == '2')
                {
                    cout << "Motorbike/rickshaw" << endl;
                }
                else if (licenses[i] == '3')
                {
                    cout << "LTV" << endl;
                }
                else if (licenses[i] == '4')
                {
                    cout << "HTV" << endl;
                }
                else if (licenses[i] == '5')
                {
                    cout << "Tractor" << endl;
                }
                else if (licenses[i] == '6')
                {
                    cout << "PSV" << endl;
                }
                else if (licenses[i] == '7')
                {
                    cout << "International driver's permit" << endl;
                }
            }
            cout << "Overall Ranking: " << overallRanking << endl;
            cout << "Salary: " << salary << endl << "Experience: " << experience << endl;
            cout << "Status: " << status << endl << endl << endl;
        }
    }
}
void TMS::Task11_MultipleLicenses(int count)
{
    for (int i = 0; i < count; i++)
    {
        if (d[i].getNoOfLic()>1)
        {
            int DID;
            char* firstN;
            char* lastN;
            int Day;
            int Month;
            int Year;
            int AGE;
            int NID;
            char* licenses;
            float overallRanking;
            float salary;
            int experience;
            int status;
            int Lcount;
            d[i].getallData(DID, firstN, lastN, Day, Month, Year, AGE, NID, licenses, Lcount, overallRanking, salary, experience, status);
            cout << "Driver Id: " << DID << endl;
            cout << "First Name: " << firstN << endl << "Last Name: " << lastN << endl;
            cout << "Day: " << Day << endl << "Month: " << Month << endl << "Year: " << Year << endl;
            cout << "Age: " << AGE << endl << "NID: " << NID << endl;
            cout << "Licenses: " << endl;
            for (int i = 0; i < Lcount; i++)
            {
                if (licenses[i] == '1')
                {
                    cout << "Motorcar/jeep" << endl;
                }
                else if (licenses[i] == '2')
                {
                    cout << "Motorbike/rickshaw" << endl;
                }
                else if (licenses[i] == '3')
                {
                    cout << "LTV" << endl;
                }
                else if (licenses[i] == '4')
                {
                    cout << "HTV" << endl;
                }
                else if (licenses[i] == '5')
                {
                    cout << "Tractor" << endl;
                }
                else if (licenses[i] == '6')
                {
                    cout << "PSV" << endl;
                }
                else if (licenses[i] == '7')
                {
                    cout << "International driver's permit" << endl;
                }
            }
            cout << "Overall Ranking: " << overallRanking << endl;
            cout << "Salary: " << salary << endl << "Experience: " << experience << endl;
            cout << "Status: " << status << endl << endl << endl;
        }
    }
}
void TMS::Task12_PrintSalary(int count)
{
    for (int i = 0; i < count; i++)
    {
        int DID;
        char* firstN;
        char* lastN;
        int Day;
        int Month;
        int Year;
        int AGE;
        int NID;
        char* licenses;
        float overallRanking;
        float salary;
        int experience;
        int status;
        int Lcount;
        d[i].getallData(DID, firstN, lastN, Day, Month, Year, AGE, NID, licenses, Lcount, overallRanking, salary, experience, status);
        cout << "Driver Id: " << DID << endl;
        cout << "First Name: " << firstN << endl << "Last Name: " << lastN << endl;
        cout << "Overall Ranking: " << overallRanking << endl;
        cout << "Salary: " << salary << endl << endl << endl;
    }
}
void TMS::Task13_BookRide(int count)
{
    r[count].setRide();
    ofstream Rides("Ride.txt", ios::app);
    if (Rides.is_open())
    {
        int noofPassengers;
        char* rideType;
        float DriverRanking;
        float VehicleRanking;
        char* source;
        char* destination;
        float distance;
        int day;
        int month;
        int year;
        int hour;
        int min;
        int sec;
        int status;
        float fuelrate;
        int cId;
        int dId;
        int vId;
        r[count].getAllData(noofPassengers, rideType, DriverRanking, VehicleRanking, source, destination, distance, day, month, year, hour, min, sec, status, fuelrate, cId, dId, vId);
        Rides << cId;
        Rides << ',';
        Rides << dId;
        Rides << ',';
        Rides << vId;
        Rides << ',';
        Rides << noofPassengers;
        Rides << ',';
        Rides << rideType;
        Rides << ',';
        Rides << DriverRanking;
        Rides << ',';
        Rides << VehicleRanking;
        Rides << ',';
        Rides << source;
        Rides << ',';
        Rides << destination;
        Rides << ',';
        Rides << distance;
        Rides << ',';
        Rides << day;
        Rides << ',';
        Rides << month;
        Rides << ',';
        Rides << year;
        Rides << ',';
        Rides << hour;
        Rides << ',';
        Rides << min;
        Rides << ',';
        Rides << sec;
        Rides << ',';
        Rides << status;
        Rides << ',';
        Rides << fuelrate;
        Rides << '\n';
        Rides.close();
        cout << "Service of Ride saved in File." << endl;
    }
    else
    {
        cout << "Service of Ride Could Not Be saved in File." << endl;
    }
}
void TMS::Task13_BookDelivery(int count)
{
    Del[count].setDelivery();
    ofstream Deliverys("Delivery.txt", ios::app);
    if (Deliverys.is_open())
    {
        float goodsWeight;
        char* goodsType;
        char* source;
        char* destination;
        float distance;
        int day;
        int month;
        int year;
        int hour;
        int min;
        int sec;
        int status;
        float fuelrate;
        int cId;
        int dId;
        int vId;
        Del[count].GetAlldata(goodsWeight, goodsType, source, destination, distance, day, month, year, hour, min, sec, status, fuelrate, cId, dId, vId);
        Deliverys << cId;
        Deliverys << ',';
        Deliverys << dId;
        Deliverys << ',';
        Deliverys << vId;
        Deliverys << ',';
        Deliverys << goodsWeight;
        Deliverys << ',';
        Deliverys << goodsType;
        Deliverys << ',';
        Deliverys << source;
        Deliverys << ',';
        Deliverys << destination;
        Deliverys << ',';
        Deliverys << distance;
        Deliverys << ',';
        Deliverys << day;
        Deliverys << ',';
        Deliverys << month;
        Deliverys << ',';
        Deliverys << year;
        Deliverys << ',';
        Deliverys << hour;
        Deliverys << ',';
        Deliverys << min;
        Deliverys << ',';
        Deliverys << sec;
        Deliverys << ',';
        Deliverys << status;
        Deliverys << ',';
        Deliverys << fuelrate;
        Deliverys << '\n';
        Deliverys.close();
        cout << "Service of Delivery saved in File." << endl;
    }
    else
    {
        cout << "Service of Delivery Could Not Be saved in File." << endl;
    }
}
int main()
{
    int CustCount=0;
    int DriverCount=0;
    int VehicleCount = 0;
    int RideCount = 0;
    int DeliveryCount = 0;
    TMS tms;
    tms.getCounts(CustCount, DriverCount, VehicleCount, RideCount, DeliveryCount);
    cout << "Choose Option.(-1 to exit)"<<endl;
    int in=0;
    while (in!=-1)
    {
        cout << "1. Add a new Customer" << endl;
        cout << "2. Add or remove a Driver" << endl;
        cout << "3. Add or remove a Vehicle" << endl;
        cout << "4. Print List of All Customers" << endl;
        cout << "5. Print List of All drivers" << endl;
        cout << "6. Print complete list of vehicles with details by their category." << endl;
        cout << "7. Print complete details and service history of a particular vehicle, (Provide vehicle ID)" << endl;
        cout << "8. Print complete history of a particular customer. (Provide customer ID)" << endl;
        cout << "9. Print complete history of a driver including services. (Provide driver ID)" << endl;
        cout << "10. Print list of all drivers who have ranking above 4.5." << endl;
        cout << "11. Print list of all drivers who have multiple licenses and their license information." << endl;
        cout << "12. Print updated salary of all drivers based on their updated ranking" << endl;
        cout << "13. Add a Service request (ride or delivery) for a customer." << endl;
        cout << "Input: ";
        cin >> in;
        if (in == 1)
        {
            tms.Task1_addCustomer(CustCount);
            CustCount++;
        }
        else if (in == 2)
        {
            cout << "Do you want to add or remove.(1 to add,2 to remove): ";
            int d;
            cin >> d;
            if (d==1)
            {
                cin.ignore();
                tms.Task2_addDriver(DriverCount);
                DriverCount++;
            }
            else if(d==2)
            {
                cout << "Enter dId: ";
                int dID;
                cin >> dID;
                tms.Task2_deleteDriver(DriverCount, dID);
            }
            else
            {
                cout << "Wrong Input.\n";
            }
        }
        else if (in == 3)
        {
            cout << "Do you want to add or remove.(1 to add,2 to remove): ";
            int v;
            cin >> v;
            if (v == 1)
            {
                cin.ignore();
                tms.Task3_addVehicle(VehicleCount);
                VehicleCount++;
            }
            else if (v == 2)
            {
                cout << "Enter vId: ";
                int vID;
                cin >> vID;
                tms.Task3_deleteVehicle(VehicleCount, vID);
            }
            else
            {
                cout << "Wrong Input.\n";
            }
        }
        else if (in == 4)
        {
            tms.Task4_PrintCustomers(CustCount);
        }
        else if (in == 5)
        {
            tms.Task5_PrintDrivers(DriverCount);
        }
        else if (in == 6)
        {
            tms.Task6_PrintVehicles(VehicleCount);
        }
        else if (in == 7)
        {
            int VID;
            cout << "Enter Vehicle Id: ";
            cin >> VID;
            tms.Task7_PrintParticularVehicle(VehicleCount, VID, RideCount, DeliveryCount);
        }
        else if (in == 8)
        {
            int CID;
            cout << "Enter Customer Id: ";
            cin >> CID;
            tms.Task8_PrintParticularCustomer(CustCount, CID, RideCount, DeliveryCount);
        }
        else if (in == 9)
        {
            int DID;
            cout << "Enter Driver Id: ";
            cin >> DID;
            tms.Task9_PrintParticularDriver(DriverCount, DID, RideCount, DeliveryCount);
        }
        else if (in == 10)
        {
            tms.Task10_Rank(DriverCount);
        }
        else if (in == 11)
        {
            tms.Task11_MultipleLicenses(DriverCount);
        }
        else if (in == 12)
        {
            tms.Task12_PrintSalary(DriverCount);
        }
        else if (in == 13)
        {
            cout << "Do you want to book Ride or Delivery Service.(1 for Ride,2 for Delivery): ";
            int v;
            cin >> v;
            if (v == 1)
            {
                tms.Task13_BookRide(RideCount);
                RideCount++;
            }
            else if (v == 2)
            {
                tms.Task13_BookDelivery(DeliveryCount);
                DeliveryCount++;
            }
            else
            {
                cout << "Wrong Input.\n";
            }
        }
        else if (in == -1)
        {
            
        }
        else
        {
            cout << "Wrong Input." << endl;
        }
    }
    cout << endl;
    system("pause");
}