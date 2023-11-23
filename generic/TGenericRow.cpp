#include <iostream>
#include <algorithm>
#include "TGenericRow.h"
#include <libpq-fe.h>

using namespace std;

void TGenericRow::show()
{
    this->conn = conn;
    const string query = "SELECT * FROM Generic";
    // Вызываем функцию PQexec из библиотеки libpq, которая выполняет SQL-запрос и возвращает указатель на результат
    PGresult* res = PQexec(conn, query.c_str());
    PQdisplayTuples(res, stdout, 1, "|", 1, 1);
    cout << endl;
    PQclear(res);
}

void TGenericRow::insert()
{
    this->conn = conn;
    cout << "Последовательно введите: param_name, value, mult, measure_unit, source, timestamp, table_name" << endl << "->";
    string param_name, value, measure_unit, source, mult, timestamp, table_name;
    cin >> param_name;
    cin >> value;
    cin >> mult;
    cin >> measure_unit;
    cin >> source;
    cin >> timestamp;
    cin >> table_name;
    const string query = "INSERT INTO generic(param_name, value, mult, measure_unit, source, timestamp, table_name) VALUES \
                        ('" + param_name + "','" + value + "'," + mult + ",'" + measure_unit + "','" + source + "'," + timestamp +
                        ",'" + table_name + "')";
    PGresult* res = PQexec(conn, query.c_str());
    // проверка
    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        cerr << "Ошибка: " << PQerrorMessage(conn) << endl;
        exit(1);
    }
    cout << "Новая запись успешно добавлена" << endl;
    PQclear(res);
}

void TGenericRow::search()
{
    this->conn = conn;
    string query = "SELECT * FROM generic WHERE timestamp = (SELECT MAX(timestamp) FROM Generic);";
    PGresult* res = PQexec(conn, query.c_str());
    cout << "Наибольшее значение timestamp содержится в этой записи:" << endl;
    // вывод в консоль элементов таблицы
    PQdisplayTuples(res, stdout, 1, "|", 1, 1);
    cout << endl;
}

string dotComma(string s) {
    replace(s.begin(), s.end(), ',', '.'); // запятые от тустринга
    return s;
}

void TGenericRow::insertArr(TGenericRow arr[])
{
    this->conn = conn;
    cout << "Введите количество записей для добавления: ";
    int count;
    cin >> count;
    string sql = "INSERT INTO generic (param_name, value, mult, measure_unit, source, timestamp, table_name) VALUES ";
    for (int i = 0; i < count; i++) {
        sql += "(";
        sql += "'" + arr[i].param_name + "', ";
        sql += "'" + arr[i].value + "', ";
        sql += dotComma(to_string(arr[i].mult)) + ", ";
        sql += "'" + arr[i].measure_unit + "', ";
        sql += "'" + arr[i].source + "', ";
        sql += to_string(arr[i].timestamp) + ", ";
        sql += "'" + arr[i].table_name + "'";
        sql += ")";
        if (i < count - 1) {
            sql += ", ";
        }
    }
    sql += ";";
    PGresult* res = PQexec(conn, sql.c_str());
    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        cerr << "Ошибка выполнения команды: " << PQerrorMessage(conn) << endl;
        PQclear(res);
        return;
    }
    else cout << "Вставлено " << count << " строк в таблицу generic" << endl;
    PQclear(res); 
}

void TGenericRow::remove()
{
    this->conn = conn;
    cout << "Введите значение источника для удаления (* - все записи): ";
    string id;
    cin >> id;
    if (id != "*") 
    {
        string sql = "DELETE FROM generic WHERE source = 'sensor" + id + "';";
        PGresult* res = PQexec(conn, sql.c_str());
        if (PQresultStatus(res) != PGRES_COMMAND_OK) 
        {
            cerr << "Ошибка выполнения команды: " << PQerrorMessage(conn) << endl;
            PQclear(res);
            return;
        }
        else cout << "Операция успешно выполнена" << endl << "->";
        PQclear(res);
    }
    else 
    {
        string sql = "DELETE FROM generic";
        PGresult* res = PQexec(conn, sql.c_str());
        cout << "Операция успешно выполнена" << endl;
        PQclear(res);
    }
}
