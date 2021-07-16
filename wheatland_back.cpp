#include "wheatland_back.h"

int tmpId = 1, tmpArea = 5, tmpIsKeshting = 0, tmpAmountKeshting = 0, thisDay = 0, tmpday = 0, startDayFarming = 0;

wheatland_back::wheatland_back(int _id)
{

    //seting id of wheatland
    id = _id;

    std::ifstream wheat("wheat.txt");
    std::ofstream wheat2("Wheat2.txt");
    if ( wheat.peek() == std::ifstream::traits_type::eof() )
    {
         //file is empty
         wheat2 << id << ' ' << tmpArea << ' ' << tmpIsKeshting<< ' ' << tmpAmountKeshting<< ' ' << startDayFarming << '\n';
         area = tmpArea;
         isKeshting = true;
         keshtAmount = 0;
         startDayFarming = 0;
         wheat2.close();
         wheat.close();
         remove("wheat.txt");
         rename("wheat2.txt", "wheat.txt");
    }
    else {
       //file is not empty
       while (wheat >> tmpId >> tmpArea >> tmpIsKeshting >> tmpAmountKeshting >> startDayFarming )
        {
            if (tmpId == id)
            {
                area = tmpArea;
                isKeshting = tmpIsKeshting;
                keshtAmount = tmpAmountKeshting;
                startDay = startDayFarming;
              break;
            }
         wheat.close();
         wheat2.close();
         remove("wheat2.txt");
       }
    }

}

int wheatland_back::upGrade(int _startDay)
{
    std::ofstream temp("temp.txt");
    std::ifstream wheat("wheatlandUpgrade.txt");
    int tmpId2 = 1,tmpArea2 = 5, tmpIsupgrading= 0, tmpdayUpgradeStart = 0 ;
    if ( wheat.peek() == std::ifstream::traits_type::eof() )
    {
         //file is empty
           isUpgrading = 1;
           startDayUpgrading = _startDay;
           temp << id << ' ' << area << ' ' << isUpgrading << ' ' << _startDay << '\n';
    }
    else
    {
    while (wheat >> tmpId2 >> tmpArea2 >> tmpIsupgrading >> tmpdayUpgradeStart )
    {
        if (id == tmpId2)
        {
            if(tmpIsupgrading == 1)
                return 0;
            tmpIsupgrading = true;
            isUpgrading = true;

            tmpdayUpgradeStart = _startDay;
            startDayUpgrading = _startDay;

            break;
        }
        temp << tmpId2 << ' ' << tmpArea2 << ' ' << tmpIsupgrading << ' ' << tmpdayUpgradeStart << '\n';
    }
    temp.close();
    wheat.close();
    remove("wheatlandUpgrade.txt");
    rename("temp.txt", "wheatlandUpgrade.txt");
    }
    isUpgrading = true;
    startDayUpgrading = _startDay;
    return 1;
}

void wheatland_back::upDateFile()
{
    std::ofstream temp("temp.txt");
    std::ifstream wheat("wheat.txt");
    int tmpId3 = 1, tmpArea3 = 5, tmpIsKeshting3 = 0, tmpAmountKeshting3 = 0, thisDay3 = 0, tmpday3 = 0, startDayFarming3 = 0;
    while (wheat >> tmpId3 >> tmpArea3 >> tmpIsKeshting3 >> tmpAmountKeshting3 >> thisDay3 )
    {
        if (id == tmpId3)
        {
            tmpArea3 = area;
            tmpIsKeshting3 = isKeshting;
            tmpAmountKeshting3 = keshtAmount;
            thisDay3 = startDay;

            break;
        }
        temp << tmpId3 << ' ' << tmpArea3 << ' ' << tmpIsKeshting3 << ' ' << tmpAmountKeshting3 << '\n';
    }
    temp.close();
    wheat.close();
    remove("wheat.txt");
    rename("temp.txt", "wheat.txt");
}
