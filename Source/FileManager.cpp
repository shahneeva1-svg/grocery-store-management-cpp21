#include "FileManager.h"
#include "Product.h"
#include "Customer.h"
#include "Supplier.h"
#include "Sale.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <filesystem>

FileManager::FileManager(std::string dir) : dataDir(dir) {
    if (dataDir == "Data/" && !std::filesystem::is_directory(dataDir) &&
        std::filesystem::is_directory("../Data/")) {
        dataDir = "../Data/";
    }
}

FileManager::~FileManager() {}

std::string FileManager::getFilePath(const std::string& filename) const {
    return dataDir + filename;
}

bool FileManager::fileExists(const std::string& filename) const {
    std::ifstream file(getFilePath(filename));
    return file.good();
}

void FileManager::saveProducts(const Product* products, int count) const {
    std::ofstream file(getFilePath("products.txt"));
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open products file for writing");
    }
    
    for (int i = 0; i < count; i++) {
        products[i].save(file);
    }
    file.close();
}

Product* FileManager::loadProducts(int& count) const {
    std::ifstream file(getFilePath("products.txt"));
    if (!file.is_open()) {
        count = 0;
        return nullptr;
    }
    
    Product* products = new Product[100];
    count = 0;
    
    try {
        while (count < 100 && file.peek() != EOF) {
            products[count] = Product::load(file);
            count++;
        }
    } catch (...) {
        file.close();
        throw;
    }
    
    file.close();
    return products;
}

void FileManager::saveCustomers(const Customer* customers, int count) const {
    std::ofstream file(getFilePath("customers.txt"));
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open customers file for writing");
    }
    
    for (int i = 0; i < count; i++) {
        customers[i].save(file);
    }
    file.close();
}

Customer* FileManager::loadCustomers(int& count) const {
    std::ifstream file(getFilePath("customers.txt"));
    if (!file.is_open()) {
        count = 0;
        return nullptr;
    }
    
    Customer* customers = new Customer[100];
    count = 0;
    
    try {
        while (count < 100 && file.peek() != EOF) {
            customers[count] = Customer::load(file);
            count++;
        }
    } catch (...) {
        file.close();
        throw;
    }
    
    file.close();
    return customers;
}

void FileManager::saveSuppliersSuppliers(const Supplier* suppliers, int count) const {
    std::ofstream file(getFilePath("suppliers.txt"));
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open suppliers file for writing");
    }
    
    for (int i = 0; i < count; i++) {
        suppliers[i].save(file);
    }
    file.close();
}

Supplier* FileManager::loadSuppliers(int& count) const {
    std::ifstream file(getFilePath("suppliers.txt"));
    if (!file.is_open()) {
        count = 0;
        return nullptr;
    }
    
    Supplier* suppliers = new Supplier[100];
    count = 0;
    
    try {
        while (count < 100 && file.peek() != EOF) {
            suppliers[count] = Supplier::load(file);
            count++;
        }
    } catch (...) {
        file.close();
        throw;
    }
    
    file.close();
    return suppliers;
}

void FileManager::saveSales(const Sale* sales, int count) const {
    std::ofstream file(getFilePath("sales.txt"));
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open sales file for writing");
    }
    
    for (int i = 0; i < count; i++) {
        sales[i].save(file);
    }
    file.close();
}

Sale* FileManager::loadSales(int& count) const {
    std::ifstream file(getFilePath("sales.txt"));
    if (!file.is_open()) {
        count = 0;
        return nullptr;
    }
    
    Sale* sales = new Sale[100];
    count = 0;
    
    try {
        while (count < 100 && file.peek() != EOF) {
            sales[count] = Sale::load(file);
            count++;
        }
    } catch (...) {
        file.close();
        throw;
    }
    
    file.close();
    return sales;
}
