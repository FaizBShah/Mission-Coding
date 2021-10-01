// Mad Libs Game

#include <iostream>

using namespace std;

int main()
{
    string color, noun, celebrity;

    cout << "Enter your color: ";
    getline(cin, color);
    cout << "Enter a plural noun: ";
    getline(cin, noun);
    cout << "Enter your celebrity: ";
    getline(cin, celebrity);

    cout << "Roses are " << color << endl;
    cout << noun << " are blue " << endl;
    cout << "My favourite celebrity is " << celebrity << endl;


    return 0;
}
