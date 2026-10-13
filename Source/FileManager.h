#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <fstream>

class FileManager {
private:
    std::string dataDir;

public:
    // Constructor
    FileManager(std::string dir = "Data/");
    
    // Destructor
    ~FileManager();
    
    // File operations for Products
    void saveProducts(const class Product* products, int count) const;
    class Product* loadProducts(int& count) const;
    
    // File operations for Customers
    void saveCustomers(const class Customer* customers, int count) const;
    class Customer* loadCustomers(int& count) const;
    
    // File operations for Suppliers
    void saveSuppliersSuppliers(const class Supplier* suppliers, int count) const;
    class Supplier* loadSuppliers(int& count) const;
    
    // File operations for Sales
    void saveSales(const class Sale* sales, int count) const;
    class Sale* loadSales(int& count) const;
    
    // Utility functions
    bool fileExists(const std::string& filename) const;
    std::string getFilePath(const std::string& filename) const;
};

#endif
