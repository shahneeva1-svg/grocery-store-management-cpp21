#ifndef GROCERYSTORE_H
#define GROCERYSTORE_H

#include "Product.h"
#include "Customer.h"
#include "Supplier.h"
#include "Sale.h"
#include "FileManager.h"

class GroceryStore {
private:
    Product* products;
    Customer* customers;
    Supplier* suppliers;
    Sale* sales;
    
    int productCount;
    int customerCount;
    int supplierCount;
    int saleCount;
    
    int maxCapacity;
    FileManager fileManager;

public:
    // Constructor
    GroceryStore(int capacity = 100);
    
    // Destructor
    ~GroceryStore();
    
    // Product operations
    void addProduct(Product p);
    void displayProducts() const;
    Product* searchProduct(int id) const;
    void updateProduct(int id, const Product& updatedProduct);
    void deleteProduct(int id);
    
    // Customer operations
    void addCustomer(Customer c);
    void displayCustomers() const;
    Customer* searchCustomer(int id) const;
    void updateCustomer(int id, const Customer& updatedCustomer);
    void deleteCustomer(int id);
    
    // Supplier operations
    void addSupplier(Supplier s);
    void displaySuppliers() const;
    Supplier* searchSupplier(int id) const;
    void updateSupplier(int id, const Supplier& updatedSupplier);
    void deleteSupplier(int id);
    
    // Sale operations (main transaction/process)
    void processSale(int custID, int prodID, int quantity);
    void displaySales() const;
    
    // Report operations
    void generateSalesReport() const;
    void generateInventoryReport() const;
    void generateCustomerReport() const;
    
    // File operations
    void saveAllData();
    void loadAllData();
    
    // Utility
    int getNextSaleID() const;
};

#endif
