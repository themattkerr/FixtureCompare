
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include "FixtureData.h"
#include "fixtruecalculations.h"
#include <iomanip>
#include <fstream>

#define MAX_NUM_FIXTURES 10

void OpenSavedData(AllData &cData)
{
    using namespace std;

    ifstream inf("Fixture Data.csv");

    if(!inf)
    {
        cerr << "Warning! Could not open file (Fixture Data.csv) " << endl;
        exit (1);
    }

    //work to be done here

}


void SaveToFile(AllData &cData)
{
    std::ofstream outf("Fixture Data.csv");
    outf << cData;

    outf << "Fixture name,Candela,Distance in Meters,Lux,Distance in feet,Footcandles,Field angle,Field diameter in meters,Field Diameter in feet" << std::endl;

    for (unsigned int iii = 1; iii <= cData.nNumberOfFixtures; iii++)
        outf << cData.Fixture[iii];
}

void clearScreen()
{
    const int nLinesToClear = 100;
    for (int cls = 1;cls <= nLinesToClear; cls++)
    {

        //1sleep(0);
        std::cout << " \n";
    }
}
void PrintLine()
{
    using namespace std;
    unsigned int nNumberOfDashes = 45;
    for(unsigned int iii=1; iii<=nNumberOfDashes; iii++)
        cout << "_";
    cout << endl;
}
void printFixtureInfo(AllData &cData, int nFixtureNumber)
{
    using namespace std;


    cout << " Fixture Number\t" << nFixtureNumber << "\n\n";
    cout << " " << cData.Fixture[nFixtureNumber].getFixtureName() << " \n Candela = \t" << cData.Fixture[nFixtureNumber].getCandela() << endl;
    cout << "\n >Distance<\t\t>Light Level<" << endl;
    cout << " " << cData.Fixture[nFixtureNumber].getDistanceMeters() << "\tMeters\t\t" << cData.Fixture[nFixtureNumber].getLux() << "\tlux" << endl;
    cout << " " << cData.Fixture[nFixtureNumber].getDistanceFeet() << "\tFeet\t\t" <<  cData.Fixture[nFixtureNumber].getdFootcandles() << "\tfc" << endl;
    cout << "\n >Field Angle<\t\t>Field Size<"<< endl;
    cout << " ";
    cout << cData.Fixture[nFixtureNumber].getFieldAngle();
    cout << "\t\t\t";
    cout <<  cData.Fixture[nFixtureNumber].getFieldSizeMeters() << "\tMeters";
    cout << "\n\t\t\t";
    cout << cData.Fixture[nFixtureNumber].getFieldSizeFeet() << "\tFeet";
    cout << endl;

}
void printAllFixtures(AllData &cData)
{

    using namespace std;
    //clearScreen();
    for(unsigned int nCurrentFixture = 1; nCurrentFixture <= cData.nNumberOfFixtures; nCurrentFixture++)\

    {
        PrintLine();
        cout << endl;
        printFixtureInfo(cData, nCurrentFixture);
        cout << "\n\n";
    }
    PrintLine();
}



int GetNumberOfFixtures(AllData &cData)
{
    using namespace std;
    while (1){
        //clearScreen();
        cout << "How many fixtures would you like to compare? (Up to 10 fixtures allowed) \n\n==>";
        int nNumberOfFixtures = 0;
        cin >> nNumberOfFixtures;
        //clearScreen();
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(255, '\n');
            nNumberOfFixtures = 0;
        }
        if (nNumberOfFixtures < 1 || nNumberOfFixtures > 10)
        {
            cout << "The number of you fixutures you entered is not within the proper range. \n\n";

        }
        else
        {
                cData.nNumberOfFixtures = nNumberOfFixtures;
                return nNumberOfFixtures;
        }
    }
}
bool AddEditQuit(AllData &cData)
{
    using namespace std;
    clearScreen();
    printAllFixtures(cData);
    char chSelection;
    while(KEEP_GOING)
    {
        cout << "Select what you would like to do:\n\n\t";

        if(cData.nNumberOfFixtures < MAX_NUM_FIXTURES)
        cout<< "(a)\tAdd a new fixture\n\t";
        else
        cout << "(a)\t-------------------\n\t";

        cout<< "(e)\tEdit an existing fixure\n\t"
            << "(t)\tEdit all fixtures\n\t"
            << "(q)\tQuit - Exit program and save\n==>";
        cin >> chSelection;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore (255, '\n');
            chSelection = 0;
        }
        switch(chSelection)
        {
            case 'a'://Add a new fixture
            case 'A':
                {
                    if (cData.nNumberOfFixtures >= MAX_NUM_FIXTURES)
                    {
                        cout << "You have already reached the maximum number of fixtures" << endl;
                        cout << "Press enter to continue:";
                        string temp;

                        cin.clear();
                        cin.ignore(255, '\n');
                        getline (cin, temp);
                    }
                    else
                    {
                        cData.nNumberOfFixtures++;
                        cData.nCurrentFixture = cData.nNumberOfFixtures;
                        clearScreen();
                        cout << "Adding a new fixture: \n\n";
                        MakeEditsTofixture (cData);
                    }
                    return KEEP_GOING;
                }
            case 'e':
            case 'E':
                {
                    return editSingleFixture(cData);
                }
            case 't':
            case 'T':
                {
                     return EditFixturesMenu(cData, ALL_FIXTURES, ALL_FIXTURES);
                }
            case 'q':
            case 'Q':
                {
                    return STOP;
                }
        }
        cout << "\nYou did not make a proper entry!\nPlease try again.\n\n";
        PrintLine();
    }//End of while loop
    return STOP;
}

bool EditFixturesMenu(AllData &cData, unsigned int nLowRange = SINGLE_FIXTURE, unsigned int nHighRange = SINGLE_FIXTURE)
{

    using namespace std;
    if(nLowRange == SINGLE_FIXTURE && nHighRange == SINGLE_FIXTURE)
    {
        nLowRange =cData.nCurrentFixture;
        nHighRange = cData.nCurrentFixture;
    }
    else
    {
        nLowRange = 1;
        nHighRange = cData.nNumberOfFixtures;
        clearScreen();
        cout << "Make a change to all fixtures" << endl;
    }

    cout << "\nWhat would you like to change:\n\n \t(n) Fixture name / description\n\n\t(c) Candela\n\t(m) Distance in meters\n\t(f) Distance in feet\n\t(l) Lux\n\t(b) Footcandles\n\n\t(a) Field angle\n\t(d) Field diameter in meters\n\t(w) Field diameter in feet\n\t(k) Done - Back\n\n==>";

    char chFieldToChange = 0;
    cin >> chFieldToChange;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(255, '\n');
        chFieldToChange =0;
    }

        switch(chFieldToChange)
        {

            case 'n':
            case 'N':
                {
                    cout << "Please enter the name or description of the fixture:  ";
                    string strFixtureName;

                    cin.clear();				// <<=============================================== Hack why do I need this?
                    cin.ignore(255, '\n');
                    getline (cin, strFixtureName);
                    for(unsigned int nFixtureToEdit = nLowRange; nFixtureToEdit <= nHighRange; nFixtureToEdit++)
                        cData.Fixture[nFixtureToEdit].enterFixtureName(strFixtureName);
                    return KEEP_GOING;
                }

            case 'c':
            case 'C':
                {
                    cout << "Please enter candela: ";
                    double dCandela;
                    cin >> dCandela;
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(255, '\n');
                    }
                    for(unsigned int nFixtureToEdit = nLowRange; nFixtureToEdit <= nHighRange; nFixtureToEdit++)
                        cData.Fixture[nFixtureToEdit].enterCandela(dCandela);
                    return KEEP_GOING;
                }
            case 'm':
            case 'M':
                {
                    cout << "Please enter distance in Meters: ";
                    double dDistanceMeters;
                    cin >> dDistanceMeters;
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(255, '\n');
                    }
                    for(unsigned int nFixtureToEdit = nLowRange; nFixtureToEdit <= nHighRange; nFixtureToEdit++)
                        cData.Fixture[nFixtureToEdit].enterDistanceMeters(dDistanceMeters);
                    return KEEP_GOING;
                }
            case 'f':
            case 'F':
                {
                    cout << "Please enter distance in feet: ";
                    double dDistanceFeet;
                    cin >> dDistanceFeet;
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(255, '\n');
                    }
                    for(unsigned int nFixtureToEdit = nLowRange; nFixtureToEdit <= nHighRange; nFixtureToEdit++)
                        cData.Fixture[nFixtureToEdit].enterDistanceFeet(dDistanceFeet);
                    return KEEP_GOING;
                }
            case 'l':
            case 'L':
                {
                    cout << "Please enter lux: ";
                    double dLux;
                    cin >> dLux;
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(255, '\n');
                    }
                    for(unsigned int nFixtureToEdit = nLowRange; nFixtureToEdit <= nHighRange; nFixtureToEdit++)
                        cData.Fixture[nFixtureToEdit].enterLux(dLux);
                    return KEEP_GOING;
                }
            case 'b':
            case 'B':
                {
                    cout << "Please enter footcandles: ";
                    double dFc;
                    cin >> dFc;
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(255, '\n');
                    }
                    for(unsigned int nFixtureToEdit = nLowRange; nFixtureToEdit <= nHighRange; nFixtureToEdit++)
                        cData.Fixture[nFixtureToEdit].enterFootcandles(dFc);
                    return KEEP_GOING;
                }
            case 'a':
            case 'A':
                {
                    cout << "Please enter the field angle in degrees: ";
                    double dFieldAngle;
                    cin >> dFieldAngle;
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(255, '\n');
                    }
                    for(unsigned int nFixtureToEdit = nLowRange; nFixtureToEdit <= nHighRange; nFixtureToEdit++)
                        cData.Fixture[nFixtureToEdit].enterFieldAngle(dFieldAngle);
                    return KEEP_GOING;
                }
            case 'd':
            case 'D':
                {
                    cout << "Please enter the diameter of the field in Meters: ";
                    double dFieldDiameterMeters;
                    cin >> dFieldDiameterMeters;
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(255, '\n');
                    }
                    for(unsigned int nFixtureToEdit = nLowRange; nFixtureToEdit <= nHighRange; nFixtureToEdit++)
                        cData.Fixture[nFixtureToEdit].enterFieldSizeMeters(dFieldDiameterMeters);
                    return KEEP_GOING;
                }
            case 'w':
            case 'W':
                {
                    cout << "Please enter the diameter of the field in feet: ";
                    double dFieldDiameterFeet;
                    cin >> dFieldDiameterFeet;
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(255, '\n');
                    }
                    for(unsigned int nFixtureToEdit = nLowRange; nFixtureToEdit <= nHighRange; nFixtureToEdit++)
                        cData.Fixture[nFixtureToEdit].enterFieldSizeFeet(dFieldDiameterFeet);
                    return KEEP_GOING;
                }
            case 'k':
            case 'K':
                {
                    //clearScreen();
                    return STOP;
                }
            cout << "you did not make a proper entry. Pleae try again.\n" << endl;
        }
        //return STOP;
    }
bool editSingleFixture(AllData &cData)
{
    using namespace std;
    bool bContinue = KEEP_GOING;
    unsigned int nFixtureToEdit = 0;

    while (KEEP_GOING)
    {
        if (cData.nNumberOfFixtures == 1)
        {
            nFixtureToEdit = 1;
            cData.nCurrentFixture = nFixtureToEdit;
            break;
        }
        cout << "\nWhich fixture would you like to edit: \n\n==>";
        cin >> nFixtureToEdit;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(255, '\n');
            nFixtureToEdit = 0;
        }
        if ((nFixtureToEdit > 0 && nFixtureToEdit <= cData.nNumberOfFixtures)||(cData.nNumberOfFixtures == 1))
        {
            cData.nCurrentFixture = nFixtureToEdit;
            break;
        }
        else
        {
            //clearScreen();
            cout << "You did not enter a proper number!\n"<< endl;
            cin.clear();
            cin.ignore(255, '\n');
        }
    }// end of entry loop
    clearScreen();
    cout << "Editing fixture:\n\n";
    MakeEditsTofixture (cData);
    return KEEP_GOING;
}
void MakeEditsTofixture (AllData &cData)
{
    bool bContinue = KEEP_GOING;
    do{
        PrintLine();
        printFixtureInfo(cData, cData.nCurrentFixture);
        PrintLine();
        bContinue = EditFixturesMenu(cData, SINGLE_FIXTURE, SINGLE_FIXTURE);
        clearScreen();
    }while(bContinue);

}
