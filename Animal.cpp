/*
 * File:          Animal.cpp
 * Project:       CMSC 202 Project 4, Spring 2021
 * Author:        Johnson Xie 
 *
 * Description:   This file contains the Animal.cpp
 *
 *
 */

#include "Animal.h"

Animal::Animal():AgItem()
{
    m_name = "chicken";
    m_IsHungry = true;
}

//checks to see if animal is fed or not
void Animal::Tick(bool isFed)
{
    //if animal is fed and not max size, animal grows and is not hungry
    if(isFed == true && GetSize() < ANIMAL_MAX_SIZE)
    {
        int newSize = GetSize() + 1;
        SetSize(newSize);
        m_IsHungry = false;
    }

    //if animal is max size, it becomes harvestable 
    if(GetSize() == ANIMAL_MAX_SIZE)
    {
        m_IsHungry = false;
        SetIsHarvestable(true);
    }

    //if animal is not fed and hungry, it will be harvestable 
    if(isFed == false)
    {
        if(m_IsHungry == true)
        {
            SetIsHarvestable(true);
        }
        m_IsHungry = true;
    }
}

//returns how much animal is worth
int Animal::Harvest()
{
    return GetWorth() * GetSize();
}

//returns type of object
string Animal::GetType()
{
    return "Animal";
}

ostream & Animal::operator<<(ostream &output)
{
    string harvest = "place holder";
    string fedOrNot = "place holder";

    if(GetIsHarvestable() == true)
        harvest = "Harvestable";
    else
        harvest = "Not Harvestable";

    if(m_IsHungry == true)
        fedOrNot = "Not Fed";
    else
        fedOrNot = "Fed";

    output << GetType() << CONCAT << m_name << CONCAT << harvest << CONCAT << ANIMAL_SIZE[GetSize()] << CONCAT << fedOrNot;
    return output;
}