#include "Product.h"
#include <fstream>
#include <iomanip>

// Default constructor
Product::Product() : productID(0), productName(""), price(0.0), quantity(0), category("") {}

// Parameterized constructor
Product::Product(int id, std::string name, double p, int qty, std::string cat)
    : productID(id), productName(name), price(p), quantity(qty), category(cat) {
    if (price < 0 || quantity < 0) {
        throw std::invalid_argument("Price and quantity cannot be negative");
    }
}

// Destructor
Product::~Product() {}

// Getters
int Product::getProductID() const { return productID; }
std::string Product::getProductName() const { return productName; }
double Product::getPrice() const { return price; }
int Product::getQuantity() const { return quantity; }
std::string Product::getCategory() const { return category; }

// Setters
void Product::setProductID(int id) { productID = id; }
void Product::setProductName(std::string name) { productName = name; }
void Product::setPrice(double p) {
    if (p < 0) throw std::invalid_argument("Price cannot be negative");
    price = p;
}
void Product::setQuantity(int qty) {
    if (qty < 0) throw std::invalid_argument("Quantity cannot be negative");
    quantity = qty;
}
void Product::setCategory(std::string cat) { category = cat; }

void Product::updateQuantity(int change) {
    if (quantity + change < 0) {
        throw std::out_of_range("Insufficient quantity");
    }
    quantity += change;
}

void Product::display() const {
    std::cout << std::left << std::setw(6) << productID 
              << std::setw(25) << productName 
              << std::setw(12) << std::fixed << std::setprecision(2) << price 
              << std::setw(10) << quantity 
              << std::setw(15) << category << std::endl;
}

void Product::save(std::ofstream& file) const {
    file << productID << "," << productName << "," << price << "," 
         << quantity << "," << category << std::endl;
}

Product Product::load(std::ifstream& file) {
    int id, qty;
    double p;
    std::string name, cat;
    char comma;
    
    file >> id >> comma;
    std::getline(file, name, ',');
    file >> p >> comma >> qty >> comma;
    std::getline(file, cat);
    
    return Product(id, name, p, qty, cat);
}
