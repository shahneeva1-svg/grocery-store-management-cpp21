#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <iostream>

class Customer {
private:
    int customerID;
    std::string customerName;
    std::string phoneNumber;
    std::string email;
    std::string address;
    double totalSpent;

public:
    // Constructors
    Customer();
    Customer(int id, std::string name, std::string phone, std::string mail, std::string addr);
    
    // Destructor
    ~Customer();
    
    // Getters
    int getCustomerID() const;
    std::string getCustomerName() const;
    std::string getPhoneNumber() const;
    std::string getEmail() const;
    std::string getAddress() const;
    double getTotalSpent() const;
    
    // Setters
    void setCustomerID(int id);
    void setCustomerName(std::string name);
    void setPhoneNumber(std::string phone);
    void setEmail(std::string mail);
    void setAddress(std::string addr);
    
    // Additional functions
    void addPurchase(double amount);
    void display() const;
    void save(std::ofstream& file) const;
    static Customer load(std::ifstream& file);
};

#endif
