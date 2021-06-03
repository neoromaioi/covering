#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <fstream>
#include <conio.h>


using namespace std;

    class Services
    {
        int count = 0;
        string name;
        int price = 0;
    public:
        void CreateServices(string str, int value, int serv);

        void Printt();

        void Refresh(int i);

        int GetPrice();

        string Closi();
    };