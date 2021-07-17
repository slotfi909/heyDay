#include "wheatland_back.h"

int tmpIdWh = 1, tmpAreaWh = 5, tmpIsKeshtingWh = 0, tmpAmountKeshtingWh = 0, thisDayWh = 0, tmpdayWh = 0, startDayFarmingWh = 0;

wheatland_back::wheatland_back(int _id)
{

    //seting id of wheatland
    id = _id;


    int flag = 0;


    std::ifstream wheat("wheat.txt");
    std::ofstream wheat2("wheat2.txt");
    if ( wheat.peek() == std::ifstream::traits_type::eof() )
    {
         //file is empty
         flag = 1;
         wheat2 << id << ' ' << tmpAreaWh << ' ' << tmpIsKeshtingWh<< ' ' << tmpAmountKeshtingWh<< ' ' << startDayFarmingWh << '\n';
         area = tmpAreaWh;
         isKeshting = true;
         keshtAmount = 0;
         startDayFarmingWh = 0;
         wheat2.close();
         wheat.close();
         remove("wheat.txt");
         rename("wheat2.txt", "wheat.txt");
    }
    else {
       //file is not empty
       while (wheat >> tmpIdWh >> tmpAreaWh >> tmpIsKeshtingWh >> tmpAmountKeshtingWh >> startDayFarmingWh )
        {
            if (tmpIdWh == id)
            {
                flag = 1;
                area = tmpAreaWh;
                isKeshting = tmpIsKeshtingWh;
                keshtAmount = tmpAmountKeshtingWh;
                startDay = startDayFarmingWh;
                break;
            }
       }
       wheat.close();
       wheat2.close();
       remove("wheat2.txt");
    }


    //Add new user
    if(flag == 0){
        std::ifstream wheatAdd("wheat.txt");
        std::ofstream wheat2Add("wheat2.txt");
        while (wheatAdd >> tmpIdWh >> tmpAreaWh >> tmpIsKeshtingWh >> tmpAmountKeshtingWh >> startDayFarmingWh )
         {
             wheat2Add << tmpIdWh << ' ' << tmpAreaWh << ' '  << tmpIsKeshtingWh << ' ' << tmpAmountKeshtingWh << ' ' << startDayFarmingWh << '\n';
         }
        wheat2Add << _id << ' ' << 5 << ' ' << 0 << ' ' << 0 << ' ' << 0 << '\n';
        wheatAdd.close();
        wheat2Add.close();
        remove("wheat.txt");
        rename("wheat2.txt", "wheat.txt");
    }


}

int wheatland_back::upGrade(int _startDay)
{

    int flag = 0;

    std::ofstream temp("temp.txt");
    std::ifstream wheat("wheatlandUpgrade.txt");
    int tmpId2 = 1,tmpArea2 = 5, tmpIsupgrading= 0, tmpdayUpgradeStart = 0 ;
    if ( wheat.peek() == std::ifstream::traits_type::eof() )
    {
         //file is empty
           flag = 1;
           isUpgrading = 1;
           startDayUpgrading = _startDay;
           temp << id << ' ' << area << ' ' << isUpgrading << ' ' << _startDay << '\n';
           temp.close();
           wheat.close();
           remove("wheatlandUpgrade.txt");
           rename("temp.txt", "wheatlandUpgrade.txt");
    }
    else
    {
    while (wheat >> tmpId2 >> tmpArea2 >> tmpIsupgrading >> tmpdayUpgradeStart )
    {
        if (id == tmpId2)
        {
            flag = 1;
            if(tmpIsupgrading == 1)
                return 0;
            tmpIsupgrading = true;
            isUpgrading = true;
            tmpdayUpgradeStart = _startDay;
            startDayUpgrading = _startDay;
        }
        temp << tmpId2 << ' ' << tmpArea2 << ' ' << tmpIsupgrading << ' ' << tmpdayUpgradeStart << '\n';
    }
    temp.close();
    wheat.close();
    remove("wheatlandUpgrade.txt");
    rename("temp.txt", "wheatlandUpgrade.txt");
    }

    //add new upgrade
    if( flag == 0 ){
        std::ifstream wheatAddUpgrade("wheatlandUpgrade.txt");
        std::ofstream wheat2AddUpgrade("tempUpgrade.txt");
        while (wheatAddUpgrade >> tmpId2 >> tmpArea2 >> tmpIsupgrading >> tmpdayUpgradeStart  )
         {
             wheat2AddUpgrade << tmpId2 << ' ' << tmpArea2 << ' '  << tmpIsupgrading << ' ' << tmpdayUpgradeStart << '\n';
         }
        wheat2AddUpgrade << id << ' ' << 5 << ' ' << 0 << ' ' << 0 << ' ' << 0 << '\n';
        wheatAddUpgrade.close();
        wheat2AddUpgrade.close();
        remove("wheatlandUpgrade.txt");
        rename("tempUpgrade.txt", "wheatlandUpgrade.txt");
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
