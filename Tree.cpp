/*
 * File:          Tree.cpp
 * Project:       CMSC 202 Project 4, Spring 2021
 * Author:        Johnson Xie
 *
 * Description:   This file contains the Tree.cpp
 *
 *
 */

#include "Tree.h"

Tree::Tree():AgItem()
{
    m_age = 0;
}

Tree::~Tree()
{
    for(int i = 0; i < int(m_fruit.size()); i++)
    {
        delete m_fruit.at(i);
    }
    m_fruit.clear();
}

//tick function that manages growth of tree 
void Tree::Tick(bool isMature)
{
    const int MAX_TREE_SIZE = 3;
    m_age++;

    if(m_age == 1)
    {
        SetSize(1);
    }


    if((m_age - 1) % SEASONS_TO_SIZE == 0 && (m_age - 1) != 0)
    {
        if(GetSize() != MAX_TREE_SIZE)
        {
            int newSize = GetSize() + 1;
            SetSize(newSize);
        }
    }

    if((m_age - 1) > SEASONS_TO_FRUIT)
    {
        Fruit *theFruit = new Fruit();
        m_fruit.push_back(theFruit);
    }
    if((m_age - 1) == SEASONS_TO_HARVEST)
    {
        SetIsHarvestable(true);
    }
}

//function to return if it has grown fruit or not 
int Tree::Harvest()
{
    if(int(m_fruit.size()) > 0)
    {
        for(vector<Fruit*>::iterator x = m_fruit.begin(); x != m_fruit.end(); ++x)
        {
            delete (*x);
            m_fruit.erase(x--);
            return 1;
        }
    }
    return 0;
}

//returns type of object
string Tree::GetType()
{
    return "Tree";
}

ostream & Tree::operator<<(ostream &output)
{
    string harvest = "place holder";
    string fruiting = "place holder";

    if(GetIsHarvestable() == true)
        harvest = "Harvestable";
    else
        harvest = "Not Harvestable";

    int numOfFruit = 0;
    if(int(m_fruit.size()) > 0)
    {
        for(int i = 0; i < int(m_fruit.size()); i++)
            numOfFruit++;
    }
    else
    {
        numOfFruit = 0;
    }

    if((m_age - 1) > SEASONS_TO_FRUIT)
    {
        fruiting = "fruiting";
    }
    else
    {
        fruiting = "not fruiting";
    }

    cout << GetType() << CONCAT << TREE_SIZE[GetSize()] << CONCAT << harvest << CONCAT << fruiting << CONCAT << "Fruit count: " << numOfFruit;
    return output;
}
