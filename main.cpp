#include "functions.h"

int main()
{
    int c;
    srand(time(0));

    Student s; // okay
    cin >> s;
    cout << s;
    //    Human h; // error: cannot create instance of abstract class


    cin.exceptions(std::istream::failbit);
    try
    {
        cout << endl << "Iveskite studentu kieki: ";
        cin >> c;
        GetStudents(c);
    }


    catch (const ios_base::failure& e)
    {
        cout << "Netinkamai ivestas studentu kiekis" << endl;
        cout << e.what() << endl;
    }

    return 0;
}
