#include "wheatland_back.h"


wheatland_back::wheatland_back(int _id)
{

    //seting id of wheatland
    id = _id;

}

int wheatland_back::upGrade(int _startDay)
{
    std::ofstream temp("temp.txt");
    std::ifstream wheat("wheatlandUpgrade.txt");
    int tmpId2 = 1,tmpArea2 = 5, tmpIsupgrading= 0, tmpdayUpgradeStart = 0 ;
    while (wheat >> tmpId2 >> tmpArea2 >> tmpIsupgrading >> tmpdayUpgradeStart )
    {
        if (id == tmpId2)
        {
            if(tmpIsupgrading == 1)
                return 0;
            tmpIsupgrading = 1;

            tmpdayUpgradeStart = _startDay;

            break;
        }
        temp << tmpId2 << ' ' << tmpArea2 << ' ' << tmpIsupgrading << ' ' << tmpdayUpgradeStart << '\n';
    }
    temp.close();
    wheat.close();
    remove("wheatlandUpgrade.txt");
    rename("temp.txt", "wheatlandUpgrade.txt");
    isUpgrading = true;
    startDayUpgrading = _startDay;
    return 1;
}


