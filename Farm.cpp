/*
 * File:          Farm.cpp
 * Project:       CMSC 202 Project 4, Spring 2021
 * Author:        Johnson Xie 
 *
 * Description:   This file contains the Farm.cpp
 *
 *
 */

#include "Farm.h"

Farm::Farm()
{
    m_food = 6;
    m_money = 0;
    m_season = 1;
}

Farm::~Farm()
{
    for(int i = 0; i < int(m_farm.size()); i++)
    {
        delete m_farm[i];
    }
    m_farm.clear();
}

//menu where the user chooses to add something to the farm 
int Farm::ChooseItem()
{
    int choice = 0;
    cout << "What item would you like to choose?" << endl;
    cout << "1. Animal" << endl;
    cout << "2. Vegetable" << endl;
    cout << "3. Tree" << endl;
    cin >> choice;
    while(choice > 3 || choice < 1)
    {
        cout << "Choice must be 1,2,or 3" << endl;
        cout << "try again" << endl;
        cin >> choice;
    }
    return choice;
}

//function to add item to farm by storing them in vector
void Farm::AddItem(int type, int quantity)
{
    int toAdd = 0;
    while(toAdd != quantity)
    {
        //adding animal
        if(type == 1)
        {
            AgItem *newAnimal = new Animal();
            m_farm.push_back(newAnimal);
            cout << "New Animal added to farm" << endl;
        }

        //adding vegetable
        if(type == 2)
        {
            AgItem *newVeggie = new Vegetable();
            m_farm.push_back(newVeggie);
            cout << "New Vegetable added to farm" << endl;
        }

        //addng tree
        if(type == 3)
        {
            AgItem *newTree = new Tree();
            m_farm.push_back(newTree);
            cout << "New Tree added to farm" << endl;
        }

        toAdd++;
    }
}

//tick function that controls the seasons that pass on farm 
void Farm::Tick(int seasons)
{
    int counter = 0;

    //iterates through seasons
    for(int i = 0; i < seasons; i++)
    {
        cout << "Season: " << i + 1 << endl;
        for(vector<AgItem*>::iterator x = m_farm.begin(); x != m_farm.end(); ++x)
        {
            if((*x)->GetType() == "Animal")
            {
                if(m_food != 0)
                {
                    m_food--;
                    (*x)->Tick(true);
                    if((*x)->GetIsHarvestable() == true)
                    {
                        m_money += (*x)->Harvest();
                        cout << (*x)->GetType() << " was harvested" <<endl;
                        delete (*x);
                        m_farm.erase(x--);
                    }
                }

                else
                {
                    m_food = 0;
                    (*x)->Tick(false);
                    if((*x)->GetIsHarvestable() == true)
                    {
                        m_money += (*x)->Harvest();
                        cout << (*x)->GetType() << " was harvested" <<endl;
                        delete (*x);
                        m_farm.erase(x--);
                    }
                }
            }

            else
            {
                (*x)->Tick(true);

                if((*x)->GetType() == "Tree")
                {
                    m_food += (*x)->Harvest();
                }

                if((*x)->GetIsHarvestable() == true)
                {
                    if((*x)->GetType() == "Vegetable")
                    {
                        m_food += (*x)->Harvest();
                        cout << (*x)->GetType() << " was harvested" <<endl;
                        delete(*x);
                        m_farm.erase(x--);
                    }

                    if((*x)->GetType() == "Tree")
                    {
                        cout << (*x)->GetType() << " was harvested" <<endl;
                        delete(*x);
                        m_farm.erase(x--);
                    }
                }
            }
        }
        Status();
        m_season++;
    }
}

//function used to display menu for user and return user selection 
int Farm::Menu()
{
    int choice = 0;
    cout << "1. Add Item to Farm " << endl;
    cout << "2. Add Two of Each Item to Farm" << endl;
    cout << "3. Simulate Time" << endl;
    cout << "4. Status" << endl;
    cout << "5. Quit" << endl;
    cin >> choice;

    while(choice > 5 || choice < 0)
    {
        cout << "1. Add Item to Farm " << endl;
        cout << "2. Add Two of Each Item to Farm" << endl;
        cout << "3. Simulate Time" << endl;
        cout << "4. Status" << endl;
        cout << "5. Quit" << endl;
        cin >> choice;
    }
    return choice;
}

//main controling function for game, will continue until user quits 
void Farm::StartSimulation()
{
    cout << "Welcome to Stardew Valley simulator!" << endl;
    int menu = Menu();
    int seasons = 0;
    while(menu != 5)
    {
        if(menu == 1)
        {
            int theItem = ChooseItem();
            AddItem(theItem, 1);
        }
        if(menu == 2)
        {
            cout << "Adding two of each item to farm" << endl;
            AddItem(1,2);
            AddItem(2,2);
            AddItem(3,2);
        }
        if(menu == 3)
        {
            cout << "Simulating time" << endl;
            cout << "How many seasons to simulate?" << endl;
            cin >> seasons;
            while(seasons <= 0)
            {
                cout << "Cannot be a negative number or , try again" << endl;
                cin >> seasons;
            }
            Tick(seasons);
        }
        if(menu == 4)
        {
            cout << "Loading Farm Status " << endl;
            Status();
        }
        menu = Menu();
    }
    cout << "Thank you for playing!" << endl;
}

//displays current status of farm 
void Farm::Status()
{
    cout << "**** Farm Status ****" << endl;
    cout << "Food: " << m_food << endl;
    cout << "Money: " << m_money << endl;
    cout << "Season " << m_season << endl;

    cout << "Agricultural Items: " << endl;
    if(int(m_farm.size()) == 0)
    {
        cout << "None" << endl;
    }
    else
    {
        for(int i = 0; i < int(m_farm.size()); i++)
        {
            (*m_farm.at(i)) << cout << endl;
        }
    }
}
