#include  "Header.h"

    void Services::CreateServices(string str, int value, int serv)
    {
        name = str;
        price = value;
        count = serv;
    }
    void Services::Printt()
    {
        cout << "Number of service: " << count + 1 << endl;
        cout << "Name of service: " << name << endl;
        cout << "Price of service: " << price << endl;
    }
    void Services::Refresh(int i)
    {
        count = i;
    }
    int Services::GetPrice()
    {
        return price;
    }
    string Services::Closi()
    {
        return name + "-" + to_string(price) + ";";
    }