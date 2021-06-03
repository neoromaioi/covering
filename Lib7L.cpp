// Lib7L.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Header.h"
class TouristProg
{
    string route;
    string date;
    int places = 1;
    int cost = 0;
    int numser = 0;
    Services* services = NULL;
public:
    TouristProg* next = NULL;
    TouristProg* prev = NULL;
    int numb;

    void NewTouristProg(string str, string datee, int placess, int costt)
    {
        route = str;
        date = datee;
        places = placess;
        cost = costt;
    }
    void AddServices(string str, int value)
    {
        if (services == NULL)
        {
            services = new Services[1];
            services[numser].CreateServices(str, value, numser);
            cost += value;
            numser++;
        }
        else
        {
            Services* serv = new Services[numser + 1];
            for (int i = 0; i < numser; i++)
            {
                serv[i] = services[i];
            }
            delete[] services;
            services = serv;
            services[numser].CreateServices(str, value, numser);
            cost += value;
            numser++;
        }
    }
    void RemoveServices(int count)
    {//
        if (services == NULL)
        {
            return;
        }
        else
        {
            numser--;
            cost -= services[count].GetPrice();
            int i = 0;
            Services* serv = new Services[numser];
            for (i; i < count; i++)
            {
                serv[i] = services[i];
            }
            for (int j = count + 1; j <= numser; i++, j++)
            {
                serv[i] = services[j];
            }
            delete[] services;
            services = serv;
            for (i = 0; i < numser; i++)
            {
                services[i].Refresh(i);
            }
        }
    }

    int GetNumser()
    {
        return numser;
    }

    void ChooseFromStand(TouristProg* tur)
    {
        string str1 = "Skiing, climbing, running";
        int a = 200;
        string str2 = "Swimming, skydiving, kayaking";
        int b = 400;
        string str3 = "Drinking, sleeping";
        int c = 50;
        cout << "Please, choose what do you want.\n1.Skiing, climbing, running.\n2.Swimming, skydiving, kayaking.\n3.Drinking and sleeping.\n0.Nothing from this." << endl;
        int d;
        cin >> d;
        if (d == 0)
            return;
        while (d < 0 || d > 3)
        {
            cout << "Please, enter correct data." << endl;
            cin >> d;
        }
        switch (d)
        {
        case 1:
        {
            cout << "It will cost: " << a << endl;
            tur->AddServices(str1, a);
        }
        break;
        case 2:
        {
            cout << "It will cost: " << b << endl;
            tur->AddServices(str2, b);
        }
        break;
        case 3:
        {
            cout << "It will cost: " << c << endl;
            tur->AddServices(str3, c);
        }
        break;
        }
    }

    string Closin()
    {
        string str;
        str = route + ";" + date + ";" + to_string(places) + ";" + to_string(cost) + "|";
        for (int i = 0; i < numser; i++)
        {
            str += services[i].Closi();
        }
        int l = str.length();
        str[l - 1] = '.';
        return str;
    }

    void Print()
    {
        cout << "Your route: " << route << endl;
        cout << "Date: " << date << endl;
        cout << "Number of places: " << places << endl;
        cout << "Cost: " << cost << endl;
        for (int i = 0; i < numser; i++)
        {
            services[i].Printt();
        }
    }

    void SetNumb(int i)
    {
        numb = i;
        if (next != NULL)
            next->SetNumb(i + 1);
    }

    int GetNumb()
    {
        return numb;
    }

    int GetCost()
    {
        return cost;
    }

    int GetPlaces()
    {
        return places;
    }

    void FixPlaces()
    {
        places--;
    }

    void EditProgram()
    {
        while (true)
        {
            cout << "Please, choose what do you want.\n1.Edit program info.\n2.Edit program services.\n0.Nothing from this." << endl;
            int m;
            cin >> m;
            if (m == 0)
            {
                return;
            }
            else
            {
                while (m < 0 || m > 2)
                {
                    cout << "Please, enter correct data." << endl;
                    cin >> m;
                }
            }
            if (m == 1)
            {
                cout << "1.Your route: " << route << endl;
                cout << "2.Date: " << date << endl;
                cout << "3.Number of places: " << places << endl;
                cout << "0.Back." << endl;
                cout << "What info do you want to edit?" << endl;
                int z;
                cin >> z;
                while (z < 0 || z > 3)
                {
                    cout << "Please, enter correct data." << endl;
                    cin >> z;
                }
                if (z == 0)
                {

                }
                switch (z)
                {
                case 1:
                {
                    cout << "Your route will from: ";
                    string rout1;
                    cin.ignore(32767, '\n');
                    getline(cin, rout1);
                    cout << "to: ";
                    string rout2;
                    getline(cin, rout2);
                    rout1 = rout1 + " - " + rout2;
                    route = rout1;
                }
                break;
                case 2:
                {
                    cout << "Date of travel:\nYear: ";
                    int y;
                    cin >> y;
                    while (y < 2021 || y > 2025)
                    {
                        cout << "Please, enter correct data." << endl;
                        cin >> y;
                    }
                    int m;
                    cout << "Month" << endl;
                    cin >> m;
                    while (m < 1 || m > 12)
                    {
                        cout << "Please, enter correct data." << endl;
                        cin >> m;
                    }
                    int d;
                    cout << "Day" << endl;
                    cin >> d;
                    while (d < 1 || d > 31)
                    {
                        cout << "Please, enter correct data." << endl;
                        cin >> d;
                    }
                    string rout2 = to_string(d) + ":" + to_string(m) + ":" + to_string(y);
                    date = rout2;
                }
                break;
                case 3:
                {
                    cout << "Number of places: ";
                    int p;
                    cin >> p;
                    while (p < 1 || p > 1000)
                    {
                        cout << "Please, enter correct data." << endl;
                        cin >> p;
                    }
                    places = p;
                }
                }
            }
            if (m == 2)
            {
                cout << "Your Services: " << endl;
                for (int i = 0; i < numser; i++)
                {
                    services[i].Printt();
                }
                cout << "What charachteristic do you want to delete?\n0 - back " << endl;
                int z;
                cin >> z;
                if (z == 0)
                {

                }
                while (z < 0 || z > GetNumser())
                {
                    cout << "Please, enter correct data." << endl;
                    cin >> z;
                }
                if (z > 0)
                    RemoveServices(z - 1);
            }
        }
    }
};

TouristProg* init(string str, string datee, int placess, int costt)  // а- значение первого узла
{
    TouristProg* lst = new TouristProg;
    // выделение памяти под корень списка
    lst->NewTouristProg(str, datee, placess, costt);
    lst->next = NULL; // указатель на следующий узел
    lst->prev = NULL; // указатель на предыдущий узел
    return(lst);
}
TouristProg* addelem(TouristProg* lst, string str, string datee, int placess, int costt)
{
    TouristProg* temp, * p = NULL;
    temp = new TouristProg;
    if (lst->next != NULL)
        p = lst->next; // сохранение указателя на следующий узел
    lst->next = temp; // предыдущий узел указывает на создаваемый
    temp->NewTouristProg(str, datee, placess, costt);
    if (p != NULL)
        temp->next = p; // созданный узел указывает на следующий узел
    temp->prev = lst; // созданный узел указывает на предыдущий узел
    if (p != NULL)
    {
        p->prev = temp;
    }
    return temp;
}
void deletelem(TouristProg* lst)
{
    TouristProg* pre = NULL, * nex = NULL;
    if (lst->prev != NULL)
        pre = lst->prev; // узел, предшествующий lst
    if (lst->next != NULL)
        nex = lst->next; // узел, следующий за lst
    if (pre != NULL)
    {
        pre->next = lst->next; // переставляем указатель
    }
    if (nex != NULL)
    {
        nex->prev = lst->prev; // переставляем указатель
    }
    if (lst->next != NULL)
        lst->next->SetNumb(lst->numb);
    delete lst; // освобождаем память удаляемого элемента
}
TouristProg* deletehead(TouristProg* root)
{
    TouristProg* temp = NULL;
    if (root->next != NULL)
    {
        temp = root->next;
        temp->prev = NULL;
        root->next->SetNumb(root->numb);
    }
    delete root;   // освобождение памяти текущего корня
    return temp; // новый корень списка
}
TouristProg* Opening(TouristProg* lst, string line, int numer)
{
    int i = 0;
    string str1;
    while (line[i] != ';')
    {
        str1 += line[i];
        i++;
    }
    string str2;
    for (i = i + 1; line[i] != ';'; i++)
    {
        str2 += line[i];
    }
    string str3;
    for (i = i + 1; line[i] != ';'; i++)
    {
        str3 += line[i];
    }
    int placess = atoi(str3.c_str());
    string str4;
    for (i = i + 1; line[i] != '|'; i++)
    {
        str4 += line[i];
    }
    int costt = atoi(str4.c_str());
    if (numer == 0)
    {
        lst = init(str1, str2, placess, costt);
    }
    else
    {
        lst = addelem(lst, str1, str2, placess, costt);
    }
    i++;
    int pricee;
    string str5, str6;
    while (line[i])
    {
        if (line[i] == '-')
        {
            str6 = str5;
            str5 = "";
        }
        else if (line[i] == ';')
        {
            pricee = atoi(str5.c_str());
            lst->AddServices(str6, pricee);
            str5 = "";
        }
        else if (line[i] == '.')
        {
            pricee = atoi(str5.c_str());
            lst->AddServices(str6, pricee);
            break;
        }
        else
        {
            str5 += line[i];
        }
        i++;
    }
    return lst;
}

int countIncomes(string line)
{
    int i = 0;
    string str1;
    while (line[i] != ':')
    {
        i++;
    }
    for (i = i + 2; line[i] != '.'; i++)
    {
        str1 += line[i];
    }
    cout << endl<< "INCOMES: " << str1 << endl;
    return atoi(str1.c_str());
}

void info()
{
    cout << "Tourist management software moduleprograms.\nEach program includes the followinginformation:\nroute, date, number of seats, total cost tour.\nThe program consists of a set of mandatoryand optional tourist services.\nYou can yourself form your own program or choose a complete program.\nIt is possible to create new tourist programs and add services into existing ones.\n" << endl;
}


int main()
{
    int companyIncomes;
    TouristProg* head, * tur;
    int numer = 0;
    int change = 0;
    tur = new TouristProg;
    head = new TouristProg;
    while (true)
    {
        cout << "\nWelcome to the travel agency." << endl;
        cout << "Please, choose what do you want.\n1.Load existing tourist programs.\n2.Create your own tourist program.\n3.Delete or edit one of the existing tourist programs or services.\n4.View list of programs.\n5.Confirm your choice.\n6.Info\n0.End program." << endl;
        int n;
        char ni = _getch();
        if (ni == 27)
            n = 0;
        else n = ni - '0';
        while (n < 0 || n > 6)
        {
            cout << "Please, enter correct data." << endl;
            cin >> n;
        }
        if (n == 0)
        {
            break;
        }
        switch (n)
        {
        case 1:
        {
            string line;
            ifstream in("C:\\Users\\neoromaioi\\LR7.txt"); // окрываем файл для чтения
            if (in.is_open())
            {
                while (getline(in, line))
                {
                    if (line == "----------")
                    {
                        if (getline(in, line))
                        {
                            companyIncomes = countIncomes(line);
                            cout << endl << "INCOMES: " << companyIncomes << endl;
                            break;
                        }
                    }
                    if (numer == 0)
                    {
                        delete head;
                        delete tur;
                        head = Opening(head, line, numer);
                        tur = head;
                        numer++;
                    }
                    else
                    {
                        tur = head;
                        while (tur->next != NULL)
                        {
                            tur = tur->next;
                        }
                        tur = Opening(tur, line, numer);
                        tur->SetNumb(numer);
                        numer++;
                    }
                }
            }
            in.close();
        }
        break;
        case 2:
        {
            cout << "Your route will from: ";
            string rout1;
            /*if (_kbhit() && _getch() == 27)
                break;*/
                //cin.ignore(32767, '\n');
                //getline(cin, rout1);
            cin >> rout1;
            cout << "to: ";
            string rout2;
            cin >> rout2;
            //getline(cin, rout2);
            rout1 = rout1 + " - " + rout2;
            cout << "Date of travel:\nYear: ";
            int y;
            cin >> y;
            while (y < 2021 || y > 2025)
            {
                cout << "Please, enter correct data." << endl;
                cin >> y;
            }
            int m;
            cout << "Month" << endl;
            cin >> m;
            while (m < 1 || m > 12)
            {
                cout << "Please, enter correct data." << endl;
                cin >> m;
            }
            int d;
            cout << "Day" << endl;
            cin >> d;
            while (d < 1 || d > 31)
            {
                cout << "Please, enter correct data." << endl;
                cin >> d;
            }
            cout << "Number of places: ";
            int p;
            cin >> p;
            while (p < 1 || p > 1000)
            {
                cout << "Please, enter correct data." << endl;
                cin >> p;
            }
            rout2 = "";
            rout2 = to_string(d) + ":" + to_string(m) + ":" + to_string(y);
            srand(4);
            y = rand() % 2001;
            cout << "It will cost " << y << "$" << endl;
            if (numer == 0)
            {
                delete head;
                delete tur;
                head = init(rout1, rout2, p, y);
                tur = head;
                numer++;
            }
            else
            {
                tur = head;
                while (tur->next != NULL)
                {
                    tur = tur->next;
                }
                tur = addelem(tur, rout1, rout2, p, y);
                tur->SetNumb(numer);
                numer++;
            }
            //
            //
            //
            while (true)
            {
                cout << "Do you want to add services?\n1.Yes\n2.No" << endl;
                //cin >> y;
                char dy = _getch();
                if (dy == 27)
                    y = 2;
                else if (dy == 13)
                    y = 1;
                else y = dy - '0';
                while (y < 1 || y > 2)
                {
                    cout << "Please, enter correct data." << endl;
                    cin >> y;
                }
                if (y == 1)
                {
                    cout << "Do you want to choose service from standard(1) or create your own(2)?" << endl;
                    //cin >> d;
                    char di = _getch();
                    if (di == 27)
                        d = 0;
                    else d = di - '0';
                    while (d < 0 || d > 2)
                    {
                        cout << "Please, enter correct data." << endl;
                        cin >> d;
                    }
                    if (d == 0)
                    {

                    }
                    if (d == 1)
                    {
                        tur->ChooseFromStand(tur);
                    }
                    if (d == 2)
                    {
                        cout << "Enter your service." << endl;
                        cin.ignore(32767, '\n');
                        getline(cin, rout2);
                        y = rand() % 501;
                        cout << "It will cost " << y << "$" << endl;
                        tur->AddServices(rout2, y);
                    }
                }
                else
                    break;
            }
            cout << "Your charachteristics: " << endl;
            tur->Print();
        }
        break;
        case 3:
        {
            if (numer == 0)
            {

            }
            else
            {
                tur = head;
                while (tur != NULL)
                {
                    cout << "Your charachteristics of " << tur->GetNumb() + 1 << " program: " << endl;
                    tur->Print();
                    tur = tur->next;
                }
            }
            cout << "Please, choose what do you want.\n1.Delete one of the existing tourist programs.\n2.Edit one of the existing tourist programs." << endl;
            int m;
            char mi = _getch();
            if (mi == 27)
                m = 0;
            else m = mi - '0';
            while (m < 0 || m > 2)
            {
                cout << "Please, enter correct data." << endl;
                cin >> m;
            }
            if (m == 0)
            {

            }
            if (m == 1)
            {
                cout << "What program do you want to delete? " << endl;
                int z;
                char mz = _getch();
                if (mz == 27)
                    break;
                else z = mz - '0';
                while (z < 1 || z > numer)
                {
                    cout << "Please, enter correct data." << endl;
                    cin >> z;
                }
                if (z == 1)
                {
                    head = deletehead(head);
                }
                else
                {
                    tur = head;
                    while (tur != NULL && tur->GetNumb() < z - 1)
                    {
                        tur = tur->next;
                    }
                    deletelem(tur);
                }
                numer--;
            }
            if (m == 2)
            {
                cout << "What program do you want to edit? " << endl;
                int z;
                char mz = _getch();
                if (mz == 27)
                    break;
                else z = mz - '0';
                while (z < 1 || z > numer)
                {
                    cout << "Please, enter correct data." << endl;
                    cin >> z;
                }
                tur = head;
                while (tur != NULL && tur->GetNumb() < z - 1)
                {
                    tur = tur->next;
                }
                tur->EditProgram();
            }
        }
        break;
        case 4:
        {
            if (numer == 0)
            {

            }
            else
            {
                tur = head;
                while (tur != NULL)
                {
                    cout << "Your charachteristics of " << tur->GetNumb() + 1 << " program: \n" << endl;
                    tur->Print();
                    tur = tur->next;
                }
            }
        }
        break;
        case 5:
        {
            if (numer == 0)
            {

            }
            else
            {
                tur = head;
                ofstream out;          // поток для записи
                while (tur != NULL)
                {
                    cout << "\nYour charachteristics of " << tur->GetNumb() + 1 << " program: \n" << endl;
                    tur->Print();
                    tur = tur->next;
                }
                cout << "\nWhich program would you like to subscribe to?" << endl;
                int z;
                char mz = _getch();
                if (mz == 27)
                    break;
                else z = mz - '0';
                while (z < 1 || z > numer)
                {
                    cout << "Please, enter correct data." << endl;
                    cin >> z;
                }
                if (z == 1)
                {
                    cout << "Do you actually want to subscribe to this program:" << endl;
                    head->Print();
                    cout << "?" << endl;
                    char mc = _getch();
                    if (mc == 27)
                        break;
                    else {}
                    if (head->GetPlaces() == 1)
                    {
                        companyIncomes += head->GetCost();
                        head = deletehead(head);
                    }
                    else
                    {
                        head->FixPlaces();
                    }
                }
                else
                {
                    tur = head;
                    while (tur != NULL && tur->GetNumb() < z - 1)
                    {
                        tur = tur->next;
                    }
                    cout << "Do you actually want to subscribe to this program:" << endl;
                    tur->Print();
                    cout << "?" << endl;
                    char mc = _getch();
                    if (mc == 27)
                        break;
                    else {}
                    if (tur->GetPlaces() == 1)
                    {
                        companyIncomes += tur->GetCost();
                        deletelem(tur);
                    }
                    else
                    {
                        tur->FixPlaces();
                    }
                }
                tur = head;
                out.open("C:\\Users\\neoromaioi\\LR7.txt");//, ios::app); // окрываем файл для записи
                if (out.is_open())
                {
                    while (tur != NULL)
                    {
                        if (tur->next == NULL)
                        {
                            out << tur->Closin();
                        }
                        else
                        {
                            out << tur->Closin() << endl;

                        }
                        tur = tur->next;
                    }
                    out << endl << "----------" << endl << "Company incomes: " + to_string(companyIncomes) + ".";
                }
                out.close();
            }
        }
        break;
        case 6:
            info();
        break;
        }
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
