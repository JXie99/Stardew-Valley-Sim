/*
 * File:          AgItem.cpp
 * Project:       CMSC 202 Project 4, Spring 2021
 * Author:        Johnson Xie 
 *
 * Description:   This file contains the AgItem.cpp
 *
 *
 */

#include "AgItem.h"

//Default Constructor
AgItem::AgItem()
{
    m_size = 0;
    m_worth = BASE_WORTH;
    m_isHarvestable = false;
}

//Overloaded Constructor  to intialize variables with given values 
AgItem::AgItem(int size, int worth, bool harvestable)
{
    m_size = size;
    m_worth = worth;
    m_isHarvestable = harvestable;
}

//destructor, no memory allocation for this class
AgItem::~AgItem()
{
    cout << "Destructor for AgItem called" << endl;
    m_size = 0;
    m_worth = 0;
    m_isHarvestable = true;
}

int AgItem::GetSize()
{
    return m_size;
}

int AgItem::GetWorth()
{
    return m_worth;
}

bool AgItem::GetIsHarvestable()
{
    return m_isHarvestable;
}

void AgItem::SetSize(int size)
{
    if(size > 0)
    {
        m_size = size;
    }
    else
    {
        m_size = 0;
    }
}

void AgItem::SetIsHarvestable(bool isAlive)
{
    if(isAlive == true)
    {
        m_isHarvestable = true;
    }
    else
    {
        m_isHarvestable = false;
    }
}

void AgItem::SetWorth(int worth)
{
    if(m_worth < 0)
    {
        m_worth = 0;
    }
    else
    {
        m_worth = worth;
    }
}
