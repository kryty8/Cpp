#include <iostream>
using namespace std;
int main()
{
    char znak = 92; // '\'
    char znak_d = 95; // '_'
    int liczba;
    cout << "Wybierz poziom od 1 do 3: ";
    cin >> liczba;
    switch(liczba)
    {
    case 1:
        cout << " " <<"/" << znak << endl;
        cout << "/" << znak_d << znak_d << znak;
        break;
    case 2:
        cout << "   " <<"/" << znak << endl;
        cout << "  /" << znak_d << znak_d << znak << endl;
        cout << " /" << znak_d << znak_d << znak_d << znak_d << znak << endl;
        break;
    case 3:
        cout << "    " <<"/" << znak << endl;
        cout << "   /" << znak_d << znak_d << znak << endl;
        cout << "  /" << znak_d << znak_d << znak_d << znak_d << znak << endl;
        cout << " /" << znak_d << znak_d << znak_d << znak_d << znak_d << znak_d << znak;
        break;
    default:
        cout << "Wybrano inna liczbe lub znak " <<endl;
    }
    return 0;
}
