#ifndef SUPPLIER_H
#define SUPPLIER_H

#include <string>
#include <iostream>

class Supplier {
private:
    int supplierID;
    std::string supplierName;
    std::string contactPerson;
    std::string phoneNumber;
    std::string address;
    std::string paymentTerms;

public:
    // Constructors
    Supplier();
    Supplier(int id, std::string name, std::string contact, std::string phone, 
             std::string addr, std::string terms);
    
    // Destructor
    ~Supplier();
    
    // Getters
    int getSupplierID() const;
    std::string getSupplierName() const;
    std::string getContactPerson() const;
    std::string getPhoneNumber() const;
    std::string getAddress() const;
    std::string getPaymentTerms() const;
    
    // Setters
    void setSupplierID(int id);
    void setSupplierName(std::string name);
    void setContactPerson(std::string contact);
    void setPhoneNumber(std::string phone);
    void setAddress(std::string addr);
    void setPaymentTerms(std::string terms);
    
    // Additional functions
    void display() const;
    void save(std::ofstream& file) const;
    static Supplier load(std::ifstream& file);
};

#endif
