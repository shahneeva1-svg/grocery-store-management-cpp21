#include "Sale.h"
#include <fstream>
#include <iomanip>
#include <sstream>

// Default constructor
Sale::Sale() : saleID(0), customerID(0), productID(0), quantity(0), totalAmount(0.0), saleDate("") {}

// Parameterized constructor
Sale::Sale(int id, int custID, int prodID, int qty, double amount, std::string date)
    : saleID(id), customerID(custID), productID(prodID), quantity(qty), 
      totalAmount(amount), saleDate(date) {
    if (quantity <= 0 || amount < 0) {
        throw std::invalid_argument("Quantity must be positive and amount cannot be negative");
    }
}

// Destructor
Sale::~Sale() {}

// Getters
int Sale::getSaleID() const { return saleID; }
int Sale::getCustomerID() const { return customerID; }
int Sale::getProductID() const { return productID; }
int Sale::getQuantity() const { return quantity; }
double Sale::getTotalAmount() const { return totalAmount; }
std::string Sale::getSaleDate() const { return saleDate; }

// Setters
void Sale::setSaleID(int id) { saleID = id; }
void Sale::setCustomerID(int custID) { customerID = custID; }
void Sale::setProductID(int prodID) { productID = prodID; }
void Sale::setQuantity(int qty) {
    if (qty <= 0) throw std::invalid_argument("Quantity must be positive");
    quantity = qty;
}
void Sale::setTotalAmount(double amount) {
    if (amount < 0) throw std::invalid_argument("Amount cannot be negative");
    totalAmount = amount;
}
void Sale::setSaleDate(std::string date) { saleDate = date; }

std::string Sale::getCurrentDate() {
    std::time_t now = std::time(nullptr);
    std::tm* timeinfo = std::localtime(&now);
    std::ostringstream oss;
    oss << (timeinfo->tm_year + 1900) << "-" 
        << std::setfill('0') << std::setw(2) << (timeinfo->tm_mon + 1) << "-"
        << std::setw(2) << timeinfo->tm_mday;
    return oss.str();
}

void Sale::display() const {
    std::cout << std::left << std::setw(8) << saleID 
              << std::setw(10) << customerID 
              << std::setw(10) << productID 
              << std::setw(8) << quantity 
              << std::setw(12) << std::fixed << std::setprecision(2) << totalAmount 
              << std::setw(15) << saleDate << std::endl;
}

void Sale::save(std::ofstream& file) const {
    file << saleID << "," << customerID << "," << productID << "," 
         << quantity << "," << totalAmount << "," << saleDate << std::endl;
}

Sale Sale::load(std::ifstream& file) {
    int id, custID, prodID, qty;
    double amount;
    std::string date;
    char comma;
    
    file >> id >> comma >> custID >> comma >> prodID >> comma >> qty >> comma >> amount >> comma;
    std::getline(file, date);
    
    return Sale(id, custID, prodID, qty, amount, date);
}
