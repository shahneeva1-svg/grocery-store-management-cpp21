#include "Supplier.h"
#include <fstream>
#include <iomanip>

// Default constructor
Supplier::Supplier() : supplierID(0), supplierName(""), contactPerson(""), 
                       phoneNumber(""), address(""), paymentTerms("") {}

// Parameterized constructor
Supplier::Supplier(int id, std::string name, std::string contact, std::string phone, 
                   std::string addr, std::string terms)
    : supplierID(id), supplierName(name), contactPerson(contact), 
      phoneNumber(phone), address(addr), paymentTerms(terms) {}

// Destructor
Supplier::~Supplier() {}

// Getters
int Supplier::getSupplierID() const { return supplierID; }
std::string Supplier::getSupplierName() const { return supplierName; }
std::string Supplier::getContactPerson() const { return contactPerson; }
std::string Supplier::getPhoneNumber() const { return phoneNumber; }
std::string Supplier::getAddress() const { return address; }
std::string Supplier::getPaymentTerms() const { return paymentTerms; }

// Setters
void Supplier::setSupplierID(int id) { supplierID = id; }
void Supplier::setSupplierName(std::string name) { supplierName = name; }
void Supplier::setContactPerson(std::string contact) { contactPerson = contact; }
void Supplier::setPhoneNumber(std::string phone) { phoneNumber = phone; }
void Supplier::setAddress(std::string addr) { address = addr; }
void Supplier::setPaymentTerms(std::string terms) { paymentTerms = terms; }

void Supplier::display() const {
    std::cout << std::left << std::setw(6) << supplierID 
              << std::setw(20) << supplierName 
              << std::setw(20) << contactPerson 
              << std::setw(15) << phoneNumber 
              << std::setw(25) << address 
              << std::setw(15) << paymentTerms << std::endl;
}

void Supplier::save(std::ofstream& file) const {
    file << supplierID << "," << supplierName << "," << contactPerson << "," 
         << phoneNumber << "," << address << "," << paymentTerms << std::endl;
}

Supplier Supplier::load(std::ifstream& file) {
    int id;
    std::string name, contact, phone, addr, terms;
    char comma;
    
    file >> id >> comma;
    std::getline(file, name, ',');
    std::getline(file, contact, ',');
    std::getline(file, phone, ',');
    std::getline(file, addr, ',');
    std::getline(file, terms);
    
    return Supplier(id, name, contact, phone, addr, terms);
}
