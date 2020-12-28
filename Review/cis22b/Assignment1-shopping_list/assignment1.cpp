//
//  assignment1.cpp
//  Review
//
//  Created by Philip Nguyen on 12/28/20.
//  Copyright © 2020 Philip Nguyen. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "assignment1.hpp"

void fileOutput() {    
    std::ifstream shoppingList{"/Users/philipnguyen/Documents/cpp/Review/Review/cis22b/Assignment1-shopping_list/shoppinglist.txt"};
    std::ofstream report("/Users/philipnguyen/Documents/cpp/Review/Review/cis22b/Assignment1-shopping_list/report.txt");
    float total{0};
    
    if(!shoppingList)
        std::cout << "Uh oh, shoppinglist.txt could not be opened!\n";
    else {
        // if it does exist, ignore the first line
        std::string str{};
        std::getline(shoppingList, str);
    }
    
    // Pass be reference!
    writeHeaders(report);
    
    while(shoppingList) {
        // read from the file
        std::string strInput;
        float cost;
        // item name
        std::getline(shoppingList, strInput, '\n');
        std::istringstream iss(strInput);
        iss >> strInput >> cost;
        
        report << std::setw(12) << std::left << strInput;
        // item cost
        
        //std::getline(shoppingList, strInput, '\n');
        //cost = std::stof(strInput);
        
        // summate the cost + tax of all items
        total += cost + taxAmount(cost);
        report << std::setw(10) << std::right << std::fixed << std::setprecision(2) << cost;
        report << std::setw(8)  << std::right << std::setprecision(2) << taxAmount(cost);
        report << std::setw(12) << std::right << std::setprecision(2) << cost + taxAmount(cost) << std::endl;
    }
    
    report << std::setw(42) << std::right << "-------" << std::endl;
    report << std::setw(36) << "Total: " << std::setprecision(2) << total;
    
}

// Table Header Output
void writeHeaders(std::ofstream &outf) {
    //std::ofstream outf{"report.txt"};
    
    outf << std::setw(12) << std::left << "Item"
    << std::setw(10) << std::right << "Cost"
    << std::setw(8) << std::right << "Tax"
    << std::setw(12) << std::right << "Subtotal" << std::endl;
    
    outf << std::setw(12) << std::left << "-----------"
    << std::setw(10) << std::right << "-----"
    << std::setw(8) << std::right << "----"
    << std::setw(12) << std::right << "-------" << std::endl;
}

float taxAmount(float cost) {
    return cost * 0.09;
}
