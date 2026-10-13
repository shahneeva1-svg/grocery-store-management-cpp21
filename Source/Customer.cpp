#include "Customer.h"
#include <fstream>
#include <iomanip>
#include <limits>

// Default constructor
Customer::Customer() : customerID(0), customerName(""), phoneNumber(""), 
                       email(""), address(""), totalSpent(0.0) {}

// Parameterized constructor
Customer::Customer(int id, std::string name, std::string phone, std::string mail, std::string addr)
    : customerID(id), customerName(name), phoneNumber(phone), email(mail), 
      address(addr), totalSpent(0.0) {}

// Destructor
Customer::~Customer() {}

// Getters
int Customer::getCustomerID() const { return customerID; }
std::string Customer::getCustomerName() const { return customerName; }
std::string Customer::getPhoneNumber() const { return phoneNumber; }
std::string Customer::getEmail() const { return email; }
std::string Customer::getAddress() const { return address; }
double Customer::getTotalSpent() const { return totalSpent; }

// Setters
void Customer::setCustomerID(int id) { customerID = id; }
void Customer::setCustomerName(std::string name) { customerName = name; }
void Customer::setPhoneNumber(std::string phone) { phoneNumber = phone; }
void Customer::setEmail(std::string mail) { email = mail; }
void Customer::setAddress(std::string addr) { address = addr; }

void Customer::addPurchase(double amount) {
    if (amount < 0) throw std::invalid_argument("Purchase amount cannot be negative");
    totalSpent += amount;
}

void Customer::display() const {
    std::cout << std::left << std::setw(6) << customerID 
              << std::setw(20) << customerName 
              << std::setw(15) << phoneNumber 
              << std::setw(20) << email 
              << std::setw(25) << address 
              << std::setw(12) << std::fixed << std::setprecision(2) << totalSpent << std::endl;
}

void Customer::save(std::ofstream& file) const {
    file << customerID << "," << customerName << "," << phoneNumber << "," 
         << email << "," << address << "," << totalSpent << std::endl;
}

Customer Customer::load(std::ifstream& file) {
    int id;
    double spent;
    std::string name, phone, email, addr;
    char comma;
    
    file >> id >> comma;
    std::getline(file, name, ',');
    std::getline(file, phone, ',');
    std::getline(file, email, ',');
    std::getline(file, addr, ',');
    file >> spent;
    file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    Customer c(id, name, phone, email, addr);
    c.totalSpent = spent;
    return c;
}
