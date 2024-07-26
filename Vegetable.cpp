/*
 * File:          Vegetable.cpp
 * Project:       CMSC 202 Project 4, Spring 2021
 * Author:        Johnson Xie 
 *
 * Description:   This file contains the Vegetable.cpp
 *
 *
 */

#include "Vegetable.h"

Vegetable::Vegetable():AgItem()
{}

int Vegetable::Harvest()
{
    if(GetIsHarvestable() == true)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//tick function that controls growth of vegetable 
void Vegetable::Tick(bool isOk)
{
    if(GetSize() < MAX_VEG_SIZE)
    {
        int newSize = GetSize() + 1;
        SetSize(newSize);
    }
    if(GetSize() == MAX_VEG_SIZE)
    {
        SetIsHarvestable(true);
    }
}

//returns type of object 
string Vegetable::GetType()
{
    return "Vegetable";
}

ostream & Vegetable::operator<<(ostream &output)
{
    string harvest = "place holder";

    if(GetIsHarvestable() == true)
        harvest = "Harvestable";
    else
        harvest = "Not Harvestable";

    cout << GetType() << CONCAT << harvest << CONCAT << Veg_Size[GetSize()];
    return output;
}