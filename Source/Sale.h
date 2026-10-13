#ifndef SALE_H
#define SALE_H

#include <string>
#include <iostream>
#include <ctime>

class Sale {
private:
    int saleID;
    int customerID;
    int productID;
    int quantity;
    double totalAmount;
    std::string saleDate;

public:
    // Constructors
    Sale();
    Sale(int id, int custID, int prodID, int qty, double amount, std::string date);
    
    // Destructor
    ~Sale();
    
    // Getters
    int getSaleID() const;
    int getCustomerID() const;
    int getProductID() const;
    int getQuantity() const;
    double getTotalAmount() const;
    std::string getSaleDate() const;
    
    // Setters
    void setSaleID(int id);
    void setCustomerID(int custID);
    void setProductID(int prodID);
    void setQuantity(int qty);
    void setTotalAmount(double amount);
    void setSaleDate(std::string date);
    
    // Additional functions
    void display() const;
    void save(std::ofstream& file) const;
    static Sale load(std::ifstream& file);
    static std::string getCurrentDate();
};

#endif
