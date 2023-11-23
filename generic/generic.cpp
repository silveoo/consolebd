#include "TGenericRow.h"
#include <iostream>
#include <libpq-fe.h>

using namespace std;

int main()
{
    bool conti = true;
    setlocale(LC_ALL, "Russian");

    //Вывод версии libpq
    int libpq_ver = PQlibVersion();
    cout << "Версия libpq: " << libpq_ver << endl << endl;
    cout << "+-------------------------+\n"
         << "Команды: s - показать, + - добавить запись, m - добавить несколько записей, d - удалить записи, p - поиск наибольшего timestamp, o - выход\n"
         << "+-------------------------+\n" << endl;

    TGenericRow generic("humidity_2", "60", 0.01, "percent", "sensor6", 16213127, "weather");

    TGenericRow arr[10] = 
    {
    TGenericRow("temperature", "25", 1.0, "Celsius", "sensor1", 226377, "weather"),
    TGenericRow("humidity", "60", 0.01, "percent", "sensor2", 36477, "weather"),
    TGenericRow("pressure", "1013", 0.001, "bar", "sensor3", 1000000, "weather"),
    TGenericRow("wind_speed", "10", 1.0, "m/s", "sensor4", 7800500, "weather"),
    TGenericRow("wind_direction", "N", 1.0, "degree", "sensor5", 26376064, "weather"),
    TGenericRow("altitude", "10000", 10.0, "meter", "sensor6", 36116438, "navigation"),
    TGenericRow("airspeed", "250", 1.0, "km/h", "sensor7", 11237645, "navigation"),
    TGenericRow("fuel_level", "80", 0.1, "liter", "sensor8", 1637606478, "engine"),
    TGenericRow("oil_temperature", "90", 1.0, "Celsius", "sensor9", 66734682, "engine"),
    TGenericRow("brake_torque", "500", 1.0, "Newton meter", "sensor10", 1637606478, "operation")
    };

    while (conti)
    {
        cout << "->";
        char todo;
        cin >> todo;
        switch (todo)
        {
        case 'o':
            conti = false;
            break;
        case 's':
            generic.show();
            break;
        case'p':
            generic.search();
            break;
        case '+':
            generic.insert();
            break;
        case 'm':
            generic.insertArr(arr);
            break;
        case 'd':
            generic.remove();
            break;
        default:
            cout << todo << " не является командой\n";
        }

    }

    return 0;
}
