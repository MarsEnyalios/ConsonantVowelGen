#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

void alphabet(string cons[], string vows[], string sylls[]);
void genRand();
void name();
void add();
void rid(string cons[], string vows[], string sylls[]);

int main()
{
    const int ARRAY_SIZE = 500;
    string cons[ARRAY_SIZE];
    string vows[ARRAY_SIZE];
    string sylls[ARRAY_SIZE];
    int mainMenu = 0;

    do
    {
        cout << "\t1. View current alphabet"
             << "\n\t2. Generate a random name"
             << "\n\t3. Generate a name"
             << "\n\t4. Exit"
             << "\n\nWhat would you like to do? ";

        cin >> mainMenu;

        if (mainMenu == 1)
            alphabet(cons, vows, sylls);
        else if (mainMenu == 4)
            return 0;
    } while (mainMenu != 4);

}

void alphabet(string cons[], string vows[], string sylls[])
{
    int numCons = 0;
    int numVows = 0;
    int numSylls = 0;
    int choose = 0;

    ifstream fin;

    cout << "\n";

    fin.open("cons.txt");

    if (fin.is_open())
    {
        while (isalnum(fin.peek()) || ispunct(fin.peek()))
        {
            getline(fin, cons[numCons]);
            cout << cons[numCons] << " ";
            numCons++;
        }

        cout << endl;
        fin.close();
    }

    fin.open("vows.txt");

    if (fin.is_open())
    {
        while (isalnum(fin.peek()) || ispunct(fin.peek()))
        {
            getline(fin, vows[numVows]);
            cout << vows[numVows] << " ";
            numVows++;
        }

        cout << endl;
        fin.close();
    }

    fin.open("sylls.txt");

    if (fin.is_open())
    {
        while (isalnum(fin.peek()) || ispunct(fin.peek()))
        {
            getline(fin, sylls[numSylls]);
            cout << sylls[numSylls] << " ";
            numSylls++;
        }

        cout << endl;
        fin.close();
    }

    cout << "\nThere are " << numCons << " consonants, " << numVows << " vowels, and " << numSylls << " syllable structures saved. \n" << endl
         << "\n\t1. Add something"
         << "\n\t2. Delete something"
         << "\n\t3. Main Menu"
         << "\n\nWhat would you like to do? ";

        cin >> choose;

        if (choose == 1)
            add();
        else if (choose == 2)
            rid(cons, vows, sylls);
        else
            main();
}

void add()
{
    string newThing;
    int menuChoice;
    string file;
    bool added = true;

    ifstream fin;
    ofstream fout;

    cout << "\nAdd to: "
         << "\n\n\t1. Consonants"
         << "\n\t2. Vowels"
         << "\n\t3. Syllable structures"
         << "\n\t4. I lied and I wanna go back to the Main Menu"
         << "\n\nYour choice: ";
    do
    {
        cin >> menuChoice;

        if (menuChoice == 1)
            file = "cons.txt";
        else if (menuChoice == 2)
            file = "vows.txt";
        else if (menuChoice == 3)
            file = "sylls.txt";
        else if (menuChoice == 4)
        {
            cout << endl;
            main();
        }
        else
            cout << "That's not an option. Choose again: ";
    } while (menuChoice < 1 || menuChoice > 4);

    fin.open(file.c_str());

    if (fin.is_open())
    {

        while (isalnum(fin.peek()) || ispunct(fin.peek()))
        {
            getline(fin, newThing);
        }
        fin.close();
    }
    else
        added = false;

    fout.open(file.c_str(), ios::app);

    if (fout.is_open())
    {
        cout << "\nThing to add: ";
        cin >> newThing;                  //Getline was hating life. Don't use spaces or you'll hate life.

        fout << newThing << "\n";

        fout.close();
    }
    else
        added = false;

    if (added)
        cout << "\n\nAddition successful!\n\n";
    else
        cout << "\n\nSomething went wrong.\n\n";
}

void rid(string cons[], string vows[], string sylls[])
{
    int menuChoice;
    int thisOne;
    int counter = 1;
    char iAmSure = 'n';
    string readRid;
    string file;
    string destroy;
    bool deleted = true;

    ifstream fin;
    ofstream fout;

    cout << "\nDelete a:"
         << "\n\n\t1. Consonant"
         << "\n\t2. Vowel"
         << "\n\t3. Syllable structure"
         << "\n\t4. I lied and I wanna go back to the Main Menu"
         <<"\n\nYour choice: ";

    do
    {
        cin >> menuChoice;

        if (menuChoice == 1)
        {
            cout << "\n";
            file = "cons.txt";
        }
        else if (menuChoice == 2)
        {
            cout << "\n";
            file = "vows.txt";
        }
        else if (menuChoice == 3)
        {
            cout << "\n";
            file = "sylls.txt";
        }
        else if (menuChoice == 4)
        {
            cout << endl;
            main();
        }
        else
            cout << "Not an option. Choose again: ";
    } while (menuChoice < 1 || menuChoice > 4);

    fin.open(file.c_str());

    if (fin.is_open())
    {

        while (isalnum(fin.peek()) || ispunct(fin.peek()))
        {
            getline(fin, destroy);
            cout << counter << ". " << destroy << endl;
            counter++;
        }
        fin.close();
    }
    else
        deleted = false;

    cout << "\nWhich one would you like to delete? ";
    cin >> thisOne;

    thisOne--;
    cout << endl;

    if (menuChoice == 1)
        cout << "That one is '" << cons[thisOne] << "'. ";
    else if (menuChoice == 2)
        cout << "That one is '" << vows[thisOne] << "'. ";
    else if (menuChoice == 3)
        cout << "That one is '" << sylls[thisOne] << "'. ";
    else
        deleted = false;

    cout << "Are you sure you would like to delete it (Y/N)? ";
    cin >> iAmSure;

    if (iAmSure == 'y' || iAmSure == 'Y')
    {
        counter = 1;
        fin.open(file.c_str());

        if (fin.is_open())
        {
            while (isalnum(fin.peek()) || ispunct(fin.peek()))
            {
                getline(fin, readRid);

                if (menuChoice == 1)
                {
                    if (cons[thisOne] != readRid)
                    {
                        cons[counter] = readRid;
                        counter++;
                    }
                    else
                        deleted = true;
                }
                else if (menuChoice == 2)
                {
                    if (vows[thisOne] != readRid)
                    {
                        vows[counter] = readRid;
                        counter++;
                    }
                    else
                        deleted = true;
                }
                else if (menuChoice == 3)
                {
                    if (sylls[thisOne] != readRid)
                    {
                        sylls[counter] = readRid;
                        counter++;
                    }
                    else
                        deleted = true;
                }
                else
                    deleted = false;
            }
            fin.close();
        }
        else
            deleted = false;

        //Overwrite the file with the new information.

        fout.open(file.c_str());

        if (fout.is_open())
        {
            for (int i = 0; i < counter; i++)
            {
                if (menuChoice == 1)
                    fout << cons[i] << endl;
                else if (menuChoice == 2)
                    fout << vows[i] << endl;
                else if (menuChoice == 3)
                    fout << sylls[i] << endl;
                else
                    deleted = false;
            }
        }
        else
            deleted = false;

    fout.close();
    }
    else
        deleted = false;

    if (deleted)
        cout << "\nDeletion successful!\n" << endl;
    else
        cout << "\nNothing was deleted.\n" << endl;
}
