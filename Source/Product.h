#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>

class Product {
private:
    int productID;
    std::string productName;
    double price;
    int quantity;
    std::string category;

public:
    // Constructors
    Product();
    Product(int id, std::string name, double p, int qty, std::string cat);
    
    // Destructor
    ~Product();
    
    // Getters
    int getProductID() const;
    std::string getProductName() const;
    double getPrice() const;
    int getQuantity() const;
    std::string getCategory() const;
    
    // Setters
    void setProductID(int id);
    void setProductName(std::string name);
    void setPrice(double p);
    void setQuantity(int qty);
    void setCategory(std::string cat);
    
    // Additional functions
    void updateQuantity(int change);
    void display() const;
    void save(std::ofstream& file) const;
    static Product load(std::ifstream& file);
};

#endif
