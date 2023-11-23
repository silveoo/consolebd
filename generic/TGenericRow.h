#pragma once
#include <libpq-fe.h>
#include <stdio.h>
#include <iostream>
#include <sstream>

using namespace std;

class TGenericRow
{
    // указатель на соед с бд
private:
    PGconn* conn;
    string param_name, value, measure_unit, source, table_name;
    double mult;
    long timestamp;

    // соединение с бд
public:
    TGenericRow(string param_name, string value, double mult, string measure_unit, string source, long timestamp, string table_name, 
                string host = "localhost", string port = "5432", string dbname = "testtask", string user = "postgres", string password = "root")
    {
        setlocale(LC_ALL, "Russian");
        string conninfo = "host=" + host + " port=" + port + " dbname=" + dbname + " user=" + user + " password=" + password;
        conn = PQconnectdb(conninfo.c_str());

        // проверка соединения
        if (PQstatus(conn) != CONNECTION_OK)
        {
            cerr << endl << "Не удалось подключиться к БД! Причина: " << PQerrorMessage(conn) << endl;
            exit(1);
        }
        this->param_name = param_name;
        this->value = value;
        this->mult = mult;
        this->measure_unit = measure_unit;
        this->source = source;
        this->timestamp = timestamp;
        this->table_name = table_name;
    }
public:
    ~TGenericRow()
    {
        // память чистка
        PQfinish(conn);
    }

public:
    void show(); //вывод всех элементов таблицы

    void insert(); //добавление нового столбца

    void search(); //поиск большего timestamp

    void insertArr(TGenericRow arr[]); //добавление массива

    void remove(); // удаление записи
};
