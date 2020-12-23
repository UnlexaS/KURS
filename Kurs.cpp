// Kurs.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#pragma once
#include <string.h>
#include <string>
#include <vector>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <cstdio>

using namespace std;

int getValue_int()
{
    while (true)
    {
        int a;
        std::cin >> a;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "ERROR! INT!\n";
        }
        else
        {
            std::cin.ignore(32767, '\n');
            return a;
        }
    }
}

class transport_type {
protected:
    
    string VIN;
    string transport_number;
    int price;

public:
    transport_type() {
        this->transport_number = ' ';
        this->price = 0;
    }

    transport_type(string transport_number1, int price1, string VIN1) {
        this->transport_number = transport_number1;
        this->price = price1;
        this->VIN = VIN1;
    }

    void set_VIN(string VIN1) {
        this->VIN = VIN1;
    }

    void set_transport_number(string transport_number1) {
        this->transport_number = transport_number1;
    }

    void set_price(int price1) {
        this->price = price1;
    }

    ~transport_type() {}
};



class stations {
protected:
    string first_station;
    string last_station;
public:
    stations() {
        string first_station = " ";
        string last_station = " ";
    }

    stations(string first_station1, string last_station1) {
        this->first_station = first_station1;
        this->last_station = last_station1;
    }

    void set_stations(string first_station1, string last_station1) {
        this->first_station = first_station1;
        this->last_station = last_station1;
    }

    void print_stations() {
        cout << "Первая остановка: " << first_station << endl;
        cout << "Конечная остановка: " << last_station << endl;
    }

    ~stations() {}
};

class Bus : public transport_type, public stations {
protected:

public:
    Bus() {
        
    }
     
    Bus(string transport_number1, string first_station1, string last_station1, int price1, string VIN1) {
        this->VIN = VIN1;
        this->transport_number = transport_number1;
        this->first_station = first_station1;
        this->last_station = last_station1;
        this->price = price1;
    }

    ~Bus() {}

    void set_VIN(string VIN1) {
        this->VIN = VIN1;
    }

    void set_first_station(string first_station1) {
        this->first_station = first_station1;
    }

    void set_last_station(string last_station1) {
        this->last_station = last_station1;
    }

    void set_transport_number(string transport_number1) {
        this->transport_number = transport_number1;
    }

    void set_price(int price1) {
        this->price = price1;
    }

    string get_VIN() {
        return VIN;
    }

    string get_transport_number() {
        return transport_number;
    }

    string get_first_station() {
        return first_station;
    }
    
    string get_last_station() {
        return last_station;
    }

    int get_price() {
        return price;
    }

    friend ostream& operator<<(ostream& out, Bus& buss);

};

ostream& operator<<(ostream& out, Bus& bus)
{
    out << endl;
    out << "VIN-номер: " << bus.get_VIN() << endl;
    out << "Автобус: " << bus.get_transport_number() << " (номер)" << endl;
    out << "Маршрут: " << bus.get_first_station() << "..." << bus.get_last_station() << endl;
    out << "Цена: " << bus.get_price() << endl;
    return out;
}

class Bus_work : public Bus {
protected:
    
    vector <Bus> vector_bus;

public:

    void add_bus() {

        string VIN1;
        Bus bus;
        string first_station1;
        string last_station1;
        string transport_number1;
        int price1;

        cout << endl << "VIN-номер: ";
        cin >> VIN1;
        cout << endl << "Номер автобуса:";
        cin >> transport_number1;
        cout << endl << "Первая остановка:";
        cin >> first_station1;
        cout << endl << "Конечная остановка:";
        cin >> last_station1;
        cout << endl << "Цена:" << endl;
        price1 = getValue_int();

        bus.set_VIN(VIN1);
        bus.set_first_station(first_station1);
        bus.set_last_station(last_station1);
        bus.set_transport_number(transport_number1);
        bus.set_price(price1);

        vector_bus.push_back(bus);

    }

    void show_all_bus() {
        for (int i = 0; i < vector_bus.size(); i++) {
            cout << endl << "-------------" << i << "-------------" << endl;
            cout << vector_bus[i];
            cout  << "___________________________" << endl;
        }
    }

    void delete_bus() {
        show_all_bus();
            cout << "---------------------------";
            string transport_number;
            cout << endl << "Введите номер транспорта который хотите удалить: " << endl;
            cin >> transport_number;
            for (int i = 0; i < vector_bus.size(); i++)
            {
                if (transport_number == vector_bus[i].get_transport_number())
                {
                    vector_bus.erase(vector_bus.begin() + i);
                }
            }
            system("cls");
            show_all_bus();
    }

    void change_first_station_bus() {
        show_all_bus();
        cout << "---------------------------";
        int temp;
        cout << endl << "Введите порядковый номер автобуса, первую остановку которого хотите изменить: " << endl;
        cin >> temp;
        string temp1;
        for (int i = 0; i < vector_bus.size(); i++)
        {
            if (i == temp)
            {
                system("cls");
                cout << "Изменение первой остановки: ";
                cout << endl << "-------------" << i << "-------------";
                cout << vector_bus[i];
                cout << "---------------------------" << endl;
                cout << "Введите новое значение: ";
                cin >> temp1;
                vector_bus[i].set_first_station(temp1);
                cout << vector_bus[i] << endl;
                system("pause");
            }
        }
        system("cls");
    }

    void change_last_station_bus() {
        show_all_bus();
        cout << "---------------------------";
        int temp;
        cout << endl << "Введите порядковый номер автобуса, конечную остановку которого хотите изменить: " << endl;
        cin >> temp;
        string temp1;
        for (int i = 0; i < vector_bus.size(); i++)
        {
            if (i == temp)
            {
                system("cls");
                cout << "Изменение конечной остановки: ";
                cout << endl << "-------------" << i << "-------------" << endl;
                cout << vector_bus[i] << endl;
                cout << "---------------------------" << endl;
                cout << "Введите новое значение: ";
                cin >> temp1;
                vector_bus[i].set_last_station(temp1);
                cout << vector_bus[i] << endl;
                system("pause");
            }
        }
        system("cls");
    }

    void change_transport_number() {
        show_all_bus();
        cout << "---------------------------";
        int temp;
        cout << endl << "Введите порядковый номер автобуса, номер которого хотите изменить: " << endl;
        cin >> temp;
        string temp1;
        for (int i = 0; i < vector_bus.size(); i++)
        {
            if (i == temp)
            {
                system("cls");
                cout << "Изменение номера: ";
                cout << endl << "-------------" << i << "-------------" << endl;
                cout << vector_bus[i] << endl;
                cout << "---------------------------" << endl;
                cout << "Введите новое значение: ";
                cin >> temp1;
                vector_bus[i].set_transport_number(temp1);
                cout << vector_bus[i] << endl;
                system("pause");
            }
        }
        system("cls");
    }

    void change_price_bus() {
        show_all_bus();
        cout << "---------------------------";
        int temp;
        cout << endl << "Введите порядковый номер автобуса, цену которого хотите изменить: " << endl;
        cin >> temp;
        int temp1;
        for (int i = 0; i < vector_bus.size(); i++)
        {
            if (i == temp)
            {
                system("cls");
                cout << "Изменение цены:";
                cout << endl << "-------------" << i << "-------------" << endl;
                cout << vector_bus[i] << endl;
                cout << "---------------------------" << endl;
                cout << "Введите новое значение: ";
                temp1 = getValue_int();
                vector_bus[i].set_price(temp1);
                cout << vector_bus[i] << endl;
                system("pause");
            }
        }
        system("cls");
    }

    void infile() {
        ofstream fout("database_bus.txt");
        for (int i = 0; i < vector_bus.size(); i++) {
            fout << this->vector_bus[i].get_VIN() << "/"
                << this->vector_bus[i].get_first_station() << "/"
                << this->vector_bus[i].get_last_station() << "/"
                << this->vector_bus[i].get_transport_number() << "/";
            if(i == (vector_bus.size()-1)) fout << this->vector_bus[i].get_price() << "/.";
                else fout << this->vector_bus[i].get_price() << "/";
        }
        fout.close();
    }

    bool is_emptyFile(std::ifstream& pFile)
    {
        return pFile.peek() == std::ifstream::traits_type::eof();
    }

    void outfile() {

            vector_bus.clear();

            ifstream ins("database_bus.txt");
            Bus_work bus;
            char q;
            string s;
            string VIN1;
            string first_station1;
            string last_station1;
            string transport_number1;
            string price12;
            int price1 = 0;
            int i = 0;
            int n = 0;
            int j = -1;
            while (1) {

                ins.get(q);
                if (ins.eof()) { cout << "Данные отсутствуют!" << endl; break; }
                else
                    ins.seekg(j, ins.cur);

                ins.get(q);
                if (q == '.')  break; 
                else
                    ins.seekg(j, ins.cur);

                getline(ins, VIN1, '/');
                bus.set_VIN(VIN1);

                getline(ins, first_station1, '/');
                bus.set_first_station(first_station1);

                getline(ins, last_station1, '/');
                bus.set_last_station(last_station1);

                getline(ins, transport_number1, '/');
                bus.set_transport_number(transport_number1);

                getline(ins, price12, '/');
                price1 = stoi(price12);
                bus.set_price(price1);

                vector_bus.push_back(bus);

            }
            ins.close();
    }

    ~Bus_work() {}

};



class Trolleybus : public transport_type, public stations {
protected:

public:
    Trolleybus() {
    
    }

    Trolleybus(string transport_number1, int price1, string first_station1, string last_station1, string VIN1) {
        this->VIN = VIN1;
        this->first_station = first_station1;
        this->last_station = last_station1;
        this->transport_number = transport_number1;
        this->price = price1;
    }

    ~Trolleybus() {}

    void set_VIN(string VIN1) {
        this->VIN = VIN1;
    }

    void set_first_station(string first_station1) {
        this->first_station = first_station1;
    }

    void set_last_station(string last_station1) {
        this->last_station = last_station1;
    }

    void set_transport_number(string transport_number1) {
        this->transport_number = transport_number1;
    }

    void set_price(int price1) {
        this->price = price1;
    }

    string get_VIN() {
        return VIN;
    }

    string get_transport_number() {
        return transport_number;
    }

    string get_first_station() {
        return first_station;
    }

    string get_last_station() {
        return last_station;
    }

    int get_price() {
        return price;
    }

    friend ostream& operator<<(ostream& out, Trolleybus& troll);

};

ostream& operator<<(ostream& out, Trolleybus& troll)
{
    out << "VIN-номер: " << troll.get_VIN() << endl;
    out << "Троллейбус: " << troll.get_transport_number() << "(номер)" << endl;
    out << "Маршрут: " << troll.get_first_station() << "..." << troll.get_last_station() << endl;
    out << "Цена: " << troll.get_price() << endl;
    return out;
}

class Trolleybus_work : public Trolleybus {
protected:

    vector <Trolleybus> vector_trolleybus;

public:

    void add_trolleybus() {
        Trolleybus troll;
        string VIN1;
        string first_station1;
        string last_station1;
        string transport_number1;
        int price1;

        cout << endl << "VIN-номер";
        cin >> VIN1;
        cout << endl << "Номер Троллейбуса:";
        cin >> transport_number1;
        cout << endl << "Первая остановка:";
        cin >> first_station1;
        cout << endl << "Конечная остановка:";
        cin >> last_station1;
        cout << endl << "Цена:" << endl;
        price1 = getValue_int();

        troll.set_VIN(VIN1);
        troll.set_first_station(first_station1);
        troll.set_last_station(last_station1);
        troll.set_transport_number(transport_number1);
        troll.set_price(price1);

        vector_trolleybus.push_back(troll);

    }

    void show_all_trolleybus() {
        for (int i = 0; i < vector_trolleybus.size(); i++) {
            cout << endl << "-------------" << i << "-------------" << endl;
            cout << vector_trolleybus[i];
            cout << "___________________________" << endl;
        }
    }

    void delete_bus() {
        show_all_trolleybus();
        cout << "---------------------------";
        string transport_number;
        cout << endl << "Введите номер транспорта который хотите удалить: " << endl;
        cin >> transport_number;
        for (int i = 0; i < vector_trolleybus.size(); i++)
        {
            if (transport_number == vector_trolleybus[i].get_transport_number())
            {
                vector_trolleybus.erase(vector_trolleybus.begin() + i);
            }
        }
        system("cls");
        show_all_trolleybus();
    }

    void change_first_station_trolleybus() {
        show_all_trolleybus();
        cout << "---------------------------";
        int temp;
        cout << endl << "Введите порядковый номер троллейбуса, первую остановку которого хотите изменить: " << endl;
        cin >> temp;
        string temp1;
        for (int i = 0; i < vector_trolleybus.size(); i++)
        {
            if (i == temp)
            {
                system("cls");
                cout << "Изменение первой остановки: ";
                cout << endl << "-------------" << i << "-------------" << endl;
                cout << vector_trolleybus[i] << endl;
                cout << "---------------------------" << endl;
                cout << "Введите новое значение: ";
                cin >> temp1;
                vector_trolleybus[i].set_first_station(temp1);
                cout << vector_trolleybus[i] << endl;
                system("pause");
            }
        }
        system("cls");
    }

    void change_last_station_trolleybus() {
        show_all_trolleybus();
        cout << "---------------------------";
        int temp;
        cout << endl << "Введите порядковый номер троллейбуса, конечную остановку которого хотите изменить: " << endl;
        cin >> temp;
        string temp1;
        for (int i = 0; i < vector_trolleybus.size(); i++)
        {
            if (i == temp)
            {
                system("cls");
                cout << "Изменение конечной остановки: ";
                cout << endl << "-------------" << i << "-------------" << endl;
                cout << vector_trolleybus[i] << endl;
                cout << "---------------------------" << endl;
                cout << "Введите новое значение: ";
                cin >> temp1;
                vector_trolleybus[i].set_last_station(temp1);
                cout << vector_trolleybus[i] << endl;
                system("pause");
            }
        }
        system("cls");
    }

    void change_transport_number() {
        show_all_trolleybus();
        cout << "---------------------------";
        int temp;
        cout << endl << "Введите порядковый номер троллейбуса, номер которого хотите изменить: " << endl;
        cin >> temp;
        string temp1;
        for (int i = 0; i < vector_trolleybus.size(); i++)
        {
            if (i == temp)
            {
                system("cls");
                cout << "Изменение номера: ";
                cout << endl << "-------------" << i << "-------------" << endl;
                cout << vector_trolleybus[i] << endl;
                cout << "---------------------------" << endl;
                cout << "Введите новое значение: ";
                cin >> temp1;
                vector_trolleybus[i].set_transport_number(temp1);
                cout << vector_trolleybus[i] << endl;
                system("pause");
            }
        }
        system("cls");
    }

    void change_price_trolleybus() {
        show_all_trolleybus();
        cout << "---------------------------";
        int temp;
        cout << endl << "Введите порядковый номертроллейбуса, цену которого хотите изменить: " << endl;
        cin >> temp;
        int temp1;
        for (int i = 0; i < vector_trolleybus.size(); i++)
        {
            if (i == temp)
            {
                system("cls");
                cout << "Изменение цены:";
                cout << endl << "-------------" << i << "-------------" << endl;
                cout << vector_trolleybus[i] << endl;
                cout << "---------------------------" << endl;
                cout << "Введите новое значение: ";
                temp1 = getValue_int();
                vector_trolleybus[i].set_price(temp1);
                cout << vector_trolleybus[i] << endl;
                system("pause");
            }
        }
        system("cls");
    }

    void infile() {
        ofstream fout("database_trolleybus.txt");
        for (int i = 0; i < vector_trolleybus.size(); i++) {
            fout << this->vector_trolleybus[i].get_VIN() << "/"
                << this->vector_trolleybus[i].get_first_station() << "/"
                << this->vector_trolleybus[i].get_last_station() << "/"
                << this->vector_trolleybus[i].get_transport_number() << "/";
            if (i == (vector_trolleybus.size()-1)) fout << this->vector_trolleybus[i].get_price() << "/.";
            else fout << this->vector_trolleybus[i].get_price() << "/";
        }
        fout.close();
    }

        void outfile() {

            vector_trolleybus.clear();

            ifstream ins("database_trolleybus.txt");
            Trolleybus_work troll;
            char q;
            string s;
            string VIN1;
            string first_station1;
            string last_station1;
            string transport_number1;
            string price12;
            int price1=0;
            int i = 0;
            int n = 0;
            int j = -1;
            while (1) {

                ins.get(q);
                if (ins.eof()) { cout << "Данные отсутствуют!" << endl; break; }
                else
                    ins.seekg(j, ins.cur);

                ins.get(q);
                if (q == '.' || ins.eof()) break; 
                else
                    ins.seekg(j, ins.cur);

                getline(ins, VIN1, '/');
                troll.set_VIN(VIN1);

                getline(ins, first_station1, '/');
                troll.set_first_station(first_station1);

                getline(ins, last_station1, '/');
                troll.set_last_station(last_station1);

                getline(ins, transport_number1, '/');
                troll.set_transport_number(transport_number1);

                getline(ins, price12, '/');
                price1 = stoi(price12);
                troll.set_price(price1);

                vector_trolleybus.push_back(troll);

            }
            ins.close();

        }
    
        ~Trolleybus_work() {}

};



class Tram : public transport_type, public stations {
protected:

    vector <Tram> tram_vector;

public:
    Tram() {
    
    }

    Tram(string transport_number1, int price1, string first_station1, string last_station1, string VIN1) {
        this->VIN = VIN1;
        this->first_station = first_station1;
        this->last_station = last_station1;
        this->transport_number = transport_number1;
        this->price = price1;
    }

    ~Tram() {}

    void set_VIN(string VIN1) {
        this->VIN = VIN1;
    }

    void set_first_station(string first_station1) {
        this->first_station = first_station1;
    }

    void set_last_station(string last_station1) {
        this->last_station = last_station1;
    }

    void set_transport_number(string transport_number1) {
        this->transport_number = transport_number1;
    }

    void set_price(int price1) {
        this->price = price1;
    }

    string get_VIN() {
        return VIN;
    }

    string get_transport_number() {
        return transport_number;
    }

    string get_first_station() {
        return first_station;
    }

    string get_last_station() {
        return last_station;
    }

    int get_price() {
        return price;
    }

    friend ostream& operator<<(ostream& out, Tram& tram);

};

ostream& operator<<(ostream& out, Tram& tram)
{
    out << "VIN-номер: " << tram.get_VIN() << endl;
    out << "Троллейбус: " << tram.get_transport_number() << "(номер)" << endl;
    out << "Маршрут: " << tram.get_first_station() << "..." << tram.get_last_station() << endl;
    out << "Цена: " << tram.get_price() << endl;
    return out;
}

class Tram_work : public Tram {
protected:

    vector <Tram> vector_tram;

public:

    void add_tram() {
        Tram tram;
        string VIN1;
        string first_station1;
        string last_station1;
        string transport_number1;
        int price1;

        cout << endl << "VIN-номер: ";
        cin >> VIN1;
        cout << endl << "Номер Трамвая:";
        cin >> transport_number1;
        cout << endl << "Первая остановка:";
        cin >> first_station1;
        cout << endl << "Конечная остановка:";
        cin >> last_station1;
        cout << endl << "Цена:" << endl;
        price1 = getValue_int();

        tram.set_VIN(VIN1);
        tram.set_first_station(first_station1);
        tram.set_last_station(last_station1);
        tram.set_transport_number(transport_number1);
        tram.set_price(price1);

        vector_tram.push_back(tram);

    }

    void show_all_tram() {
        for (int i = 0; i < vector_tram.size(); i++) {
            cout << endl << "-------------" << i << "-------------" << endl;
            cout << vector_tram[i];
            cout << "___________________________" << endl;
        }
    }

    void delete_tram() {
        show_all_tram();
        cout << "---------------------------";
        string transport_number;
        cout << endl << "Введите номер транспорта который хотите удалить: " << endl;
        cin >> transport_number;
        for (int i = 0; i < vector_tram.size(); i++)
        {
            if (transport_number == vector_tram[i].get_transport_number())
            {
                vector_tram.erase(vector_tram.begin() + i);
            }
        }
        system("cls");
        show_all_tram();
    }

    void change_first_station_tram() {
        show_all_tram();
        cout << "---------------------------";
        int temp;
        cout << endl << "Введите порядковый номер трамвая, первую остановку которого хотите изменить: " << endl;
        cin >> temp;
        string temp1;
        for (int i = 0; i < vector_tram.size(); i++)
        {
            if (i == temp)
            {
                system("cls");
                cout << "Изменение первой остановки: ";
                cout << endl << "-------------" << i << "-------------" << endl;
                cout << vector_tram[i] << endl;
                cout << "---------------------------" << endl;
                cout << "Введите новое значение: ";
                cin >> temp1;
                vector_tram[i].set_first_station(temp1);
                cout << vector_tram[i] << endl;
                system("pause");
            }
        }
        system("cls");
    }

    void change_last_station_tram() {
        show_all_tram();
        cout << "---------------------------";
        int temp;
        cout << endl << "Введите порядковый номер трамвая, конечную остановку которого хотите изменить: " << endl;
        cin >> temp;
        string temp1;
        for (int i = 0; i < vector_tram.size(); i++)
        {
            if (i == temp)
            {
                system("cls");
                cout << "Изменение конечной остановки: ";
                cout << endl << "-------------" << i << "-------------" << endl;
                cout << vector_tram[i] << endl;
                cout << "---------------------------" << endl;
                cout << "Введите новое значение: ";
                cin >> temp1;
                vector_tram[i].set_last_station(temp1);
                cout << vector_tram[i] << endl;
                system("pause");
            }
        }
        system("cls");
    }

    void change_transport_number() {
        show_all_tram();
        cout << "---------------------------";
        int temp;
        cout << endl << "Введите порядковый номер трамвая, номер которого хотите изменить: " << endl;
        cin >> temp;
        string temp1;
        for (int i = 0; i < vector_tram.size(); i++)
        {
            if (i == temp)
            {
                system("cls");
                cout << "Изменение номера: ";
                cout << endl << "-------------" << i << "-------------" << endl;
                cout << vector_tram[i] << endl;
                cout << "---------------------------" << endl;
                cout << "Введите новое значение: ";
                cin >> temp1;
                vector_tram[i].set_transport_number(temp1);
                cout << vector_tram[i] << endl;
                system("pause");
            }
        }
        system("cls");
    }

    void change_price_tram() {
        show_all_tram();
        cout << "---------------------------";
        int temp;
        cout << endl << "Введите порядковый номер трамвая, цену которого хотите изменить: " << endl;
        cin >> temp;
        int temp1;
        for (int i = 0; i < vector_tram.size(); i++)
        {
            if (i == temp)
            {
                system("cls");
                cout << "Изменение цены:";
                cout << endl << "-------------" << i << "-------------" << endl;
                cout << vector_tram[i] << endl;
                cout << "---------------------------" << endl;
                cout << "Введите новое значение: ";
                temp1 = getValue_int();
                vector_tram[i].set_price(temp1);
                cout << vector_tram[i] << endl;
                system("pause");
            }
        }
        system("cls");
    }

    void infile() {
        ofstream fout("database_tram.txt");
        for (int i = 0; i < vector_tram.size(); i++) {
            fout << this->vector_tram[i].get_VIN() << "/"
                << this->vector_tram[i].get_first_station() << "/"
                << this->vector_tram[i].get_last_station() << "/"
                << this->vector_tram[i].get_transport_number() << "/";
            if (i == (vector_tram.size() - 1)) fout << this->vector_tram[i].get_price() << "/.";
            else fout << this->vector_tram[i].get_price() << "/";
        }
        fout.close();
    }

    void outfile() {

        vector_tram.clear();

        ifstream ins("database_tram.txt");
        Tram_work tram;
        char q;
        string s;
        string VIN1;
        string first_station1;
        string last_station1;
        string transport_number1;
        string price12;
        int price1=0;
        int i = 0;
        int n = 0;
        int j = -1;
        while (1) {

            ins.get(q);
            if (ins.eof()) { cout << "Данные отсутствуют!" << endl; break; }
            else
                ins.seekg(j, ins.cur);

            ins.get(q);
            if (q == '.' || ins.eof()) break; 
            else
                ins.seekg(j, ins.cur);

            getline(ins, VIN1, '/');
            tram.set_VIN(VIN1);

            getline(ins, first_station1, '/');
            tram.set_first_station(first_station1);

            getline(ins, last_station1, '/');
            tram.set_last_station(last_station1);

            getline(ins, transport_number1, '/');
            tram.set_transport_number(transport_number1);

            getline(ins, price12, '/');
            price1 = stoi(price12);
            tram.set_price(price1);

            vector_tram.push_back(tram);

        }
        ins.close();

    }

    ~Tram_work() {}

};

void select_transport_type() {
    cout << endl << "------------MENU------------" << endl;
    cout << "Выберите тип транспорта:" << endl;
    cout << "1. Автобус" << endl;
    cout << "2. Троллейбус" << endl;
    cout << "3. Трамвай" << endl;
    cout << "----------------------------" << endl;
    cout << "0. Выход" << endl;
    cout << "----------------------------" << endl;
}

void menu_Bus() {
    system("cls");
    Bus_work bus;
    int b = 0;
    do {
        system("cls");
        cout << endl << "------------MENU------------" << endl;
        cout << "1. Просмотреть автобус(ы)" << endl;
        cout << "2. добавить новый автобус" << endl;
        cout << "3. удалить автобус" << endl;
        cout << "4. Изменить данные автобуса" << endl;
        cout << "----------------------------" << endl;
        cout << "0. Выход" << endl;
        cout << "----------------------------" << endl;
        cin >> b;
        string first_station1;
        string last_station1;
        string transport_number1;
        int price1=0;
        switch (b) {
        case 1:
            system("cls");
            bus.outfile();
            bus.show_all_bus();
            system("pause");
            bus.infile();
            break;
        case 2:
            system("cls");
            bus.outfile();
            bus.add_bus();
            system("cls");
            bus.infile();
            break;
        case 3:
            system("cls");
            bus.outfile();
            bus.delete_bus();
            system("pause");
            bus.infile();
            break;
        case 4:
            system("cls");
            int c;
            do {
                cout << "----------------------------" << endl;
                cout << "1. Номер автобуса" << endl;
                cout << "2. Первую остановку" << endl;
                cout << "3. Конечную остановку" << endl;
                cout << "4. Цену" << endl;
                cout << "----------------------------" << endl;
                cout << "0. Выход" << endl;
                cout << "----------------------------" << endl;
                cout << "Выберите данные которые хотите изменить: ";
                cin >> c;
                switch (c) {
                case 1:
                    system("cls");
                    bus.outfile();
                    bus.change_transport_number();
                    system("cls");
                    bus.infile();
                    break;
                case 2:
                    system("cls");
                    bus.outfile();
                    bus.change_first_station_bus();
                    system("cls");
                    bus.infile();
                    break;
                case 3:
                    system("cls");
                    bus.outfile();
                    bus.change_last_station_bus();
                    system("cls");
                    bus.infile();
                    break;
                case 4:
                    system("cls");
                    bus.outfile();
                    bus.change_price_bus();
                    system("cls");
                    bus.infile();
                    break;
                }
            } while (c != 0);

        }
    } while (b != 0);
    if (b == 0) { system("cls"); return; }
    system("cls");
}

void menu_Tram() {
    system("cls");
    Tram_work tram;
    int b = 0;
    do {
        system("cls");
        cout << endl << "------------MENU------------" << endl;
        cout << "1. Просмотреть трамвай(и)" << endl;
        cout << "2. добавить новый трамвай" << endl;
        cout << "3. удалить трамвай" << endl;
        cout << "4. Изменить данные трамвая" << endl;
        cout << "----------------------------" << endl;
        cout << "0. Выход" << endl;
        cout << "----------------------------" << endl;
        cin >> b;
        string first_station1;
        string last_station1;
        string transport_number1;
        int price1 = 0;
        switch (b) {
        case 1:
            system("cls");
            tram.outfile();
            tram.show_all_tram();
            system("pause");
            tram.infile();
            break;
        case 2:
            system("cls");
            tram.outfile();
            tram.add_tram();
            system("cls");
            tram.infile();
            break;
        case 3:
            system("cls");
            tram.outfile();
            tram.delete_tram();
            system("pause");
            tram.infile();
            break;
        case 4:
            system("cls");
            int c;
            do {
                cout << "----------------------------" << endl;
                cout << "1. Номер трамвая" << endl;
                cout << "2. Первую остановку" << endl;
                cout << "3. Конечную остановку" << endl;
                cout << "4. Цену" << endl;
                cout << "----------------------------" << endl;
                cout << "0. Выход" << endl;
                cout << "----------------------------" << endl;
                cout << "Выберите данные которые хотите изменить: ";
                cin >> c;
                switch (c) {
                case 1:
                    system("cls");
                    tram.outfile();
                    tram.change_transport_number();
                    system("cls");
                    tram.infile();
                    break;
                case 2:
                    system("cls");
                    tram.outfile();
                    tram.change_first_station_tram();
                    system("cls");
                    tram.infile();
                    break;
                case 3:
                    system("cls");
                    tram.outfile();
                    tram.change_last_station_tram();
                    system("cls");
                    tram.infile();
                    break;
                case 4:
                    system("cls");
                    tram.outfile();
                    tram.change_price_tram();
                    system("cls");
                    tram.infile();
                    break;
                }
            } while (c != 0);

        }
    } while (b != 0);
    if (b == 0) { system("cls"); return; }
    system("cls");
}

void menu_Trolleybus() {
    system("cls");
    Trolleybus_work troll;
    int b = 0;
    do {
        system("cls");
        cout << endl << "------------MENU------------" << endl;
        cout << "1. Просмотреть троллейбус(ы)" << endl;
        cout << "2. добавить новый троллейбус" << endl;
        cout << "3. удалить троллейбус" << endl;
        cout << "4. Изменить данные троллейбуса" << endl;
        cout << "----------------------------" << endl;
        cout << "0. Выход" << endl;
        cout << "----------------------------" << endl;
        cin >> b;
        string first_station1;
        string last_station1;
        string transport_number1;
        int price1 = 0;
        switch (b) {
        case 1:
            system("cls");
            troll.outfile();
            troll.show_all_trolleybus();
            system("pause");
            troll.infile();
            break;
        case 2:
            system("cls");
            troll.outfile();
            troll.add_trolleybus();
            system("cls");
            troll.infile();
            break;
        case 3:
            system("cls");
            troll.outfile();
            troll.delete_bus();
            system("pause");
            troll.infile();
            break;
        case 4:
            system("cls");
            int c;
            do {
                cout << "----------------------------" << endl;
                cout << "1. Номер троллейбуса" << endl;
                cout << "2. Первую остановку" << endl;
                cout << "3. Конечную остановку" << endl;
                cout << "4. Цену" << endl;
                cout << "----------------------------" << endl;
                cout << "0. Выход" << endl;
                cout << "----------------------------" << endl;
                cout << "Выберите данные которые хотите изменить: ";
                cin >> c;
                switch (c) {
                case 1:
                    system("cls");
                    troll.outfile();
                    troll.change_transport_number();
                    troll.infile();
                    system("cls");
                    break;
                case 2:
                    system("cls");
                    troll.outfile();
                    troll.change_first_station_trolleybus();
                    system("cls");
                    troll.infile();
                    break;
                case 3:
                    system("cls");
                    troll.outfile();
                    troll.change_last_station_trolleybus();
                    system("cls");
                    troll.infile();
                    break;
                case 4:
                    system("cls");
                    troll.outfile();
                    troll.change_price_trolleybus();
                    system("cls");
                    troll.infile();
                    break;
                }
            } while (c != 0);

        }
    } while (b != 0);
    if (b == 0) { system("cls"); return; }
    system("cls");
}

bool login() {
    string login = "admin";
    string log;
    cout << "|Авторизация|" << endl;
    cout << "--------------" << endl;
    cout << "Логин: ";
    cin >> log;
    if (log == login)
        return true;
    else { system("cls"); return false; }
}

bool Password() {
    char key;
    string password = "admin";
    string pass;

        cout << "Пароль: ";
        while ((key = _getch()) != 13) {
            pass += key;
            cout << "*";
        }
        cout << endl;
        if (pass == password)
            return true;
        else { return false; }
}

int main()
{
    setlocale(LC_ALL, "Russian");


    while (!login());
    cout << "--------------" << endl;
    while (!Password());


    system("cls");
    int number = 0;
    do {
        select_transport_type();
        cin >> number;
        switch (number) {
        case 1:                                                                      
            menu_Bus();
            break;
        case 2:                                                                            
            menu_Trolleybus();
            break;
        case 3:                                                                       
            menu_Tram();
            break;
        }
        system("cls");
    } while (number != 0);

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
