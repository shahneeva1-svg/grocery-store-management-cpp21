#include "GroceryStore.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

GroceryStore::GroceryStore(int capacity)
    : productCount(0), customerCount(0), supplierCount(0), saleCount(0), maxCapacity(capacity) {
    products = new Product[capacity];
    customers = new Customer[capacity];
    suppliers = new Supplier[capacity];
    sales = new Sale[capacity];
}

GroceryStore::~GroceryStore() {
    delete[] products;
    delete[] customers;
    delete[] suppliers;
    delete[] sales;
}

// ============== PRODUCT OPERATIONS ==============
void GroceryStore::addProduct(Product p) {
    if (productCount >= maxCapacity) {
        throw std::out_of_range("Product list is full");
    }
    products[productCount++] = p;
}

void GroceryStore::displayProducts() const {
    if (productCount == 0) {
        std::cout << "No products found.\n";
        return;
    }
    std::cout << "\n" << std::string(85, '=') << std::endl;
    std::cout << std::left << std::setw(6) << "ID" 
              << std::setw(25) << "Product Name" 
              << std::setw(12) << "Price" 
              << std::setw(10) << "Quantity" 
              << std::setw(15) << "Category" << std::endl;
    std::cout << std::string(85, '=') << std::endl;
    
    for (int i = 0; i < productCount; i++) {
        products[i].display();
    }
    std::cout << std::string(85, '=') << std::endl << std::endl;
}

Product* GroceryStore::searchProduct(int id) const {
    for (int i = 0; i < productCount; i++) {
        if (products[i].getProductID() == id) {
            return &products[i];
        }
    }
    return nullptr;
}

void GroceryStore::updateProduct(int id, const Product& updatedProduct) {
    Product* p = searchProduct(id);
    if (!p) throw std::runtime_error("Product not found");
    *p = updatedProduct;
}

void GroceryStore::deleteProduct(int id) {
    for (int i = 0; i < productCount; i++) {
        if (products[i].getProductID() == id) {
            for (int j = i; j < productCount - 1; j++) {
                products[j] = products[j + 1];
            }
            productCount--;
            std::cout << "Product deleted successfully.\n";
            return;
        }
    }
    throw std::runtime_error("Product not found");
}

// ============== CUSTOMER OPERATIONS ==============
void GroceryStore::addCustomer(Customer c) {
    if (customerCount >= maxCapacity) {
        throw std::out_of_range("Customer list is full");
    }
    customers[customerCount++] = c;
}

void GroceryStore::displayCustomers() const {
    if (customerCount == 0) {
        std::cout << "No customers found.\n";
        return;
    }
    std::cout << "\n" << std::string(98, '=') << std::endl;
    std::cout << std::left << std::setw(6) << "ID" 
              << std::setw(20) << "Name" 
              << std::setw(15) << "Phone" 
              << std::setw(20) << "Email" 
              << std::setw(25) << "Address" 
              << std::setw(12) << "Total Spent" << std::endl;
    std::cout << std::string(98, '=') << std::endl;
    
    for (int i = 0; i < customerCount; i++) {
        customers[i].display();
    }
    std::cout << std::string(98, '=') << std::endl << std::endl;
}

Customer* GroceryStore::searchCustomer(int id) const {
    for (int i = 0; i < customerCount; i++) {
        if (customers[i].getCustomerID() == id) {
            return &customers[i];
        }
    }
    return nullptr;
}

void GroceryStore::updateCustomer(int id, const Customer& updatedCustomer) {
    Customer* c = searchCustomer(id);
    if (!c) throw std::runtime_error("Customer not found");
    *c = updatedCustomer;
}

void GroceryStore::deleteCustomer(int id) {
    for (int i = 0; i < customerCount; i++) {
        if (customers[i].getCustomerID() == id) {
            for (int j = i; j < customerCount - 1; j++) {
                customers[j] = customers[j + 1];
            }
            customerCount--;
            std::cout << "Customer deleted successfully.\n";
            return;
        }
    }
    throw std::runtime_error("Customer not found");
}

// ============== SUPPLIER OPERATIONS ==============
void GroceryStore::addSupplier(Supplier s) {
    if (supplierCount >= maxCapacity) {
        throw std::out_of_range("Supplier list is full");
    }
    suppliers[supplierCount++] = s;
}

void GroceryStore::displaySuppliers() const {
    if (supplierCount == 0) {
        std::cout << "No suppliers found.\n";
        return;
    }
    std::cout << "\n" << std::string(101, '=') << std::endl;
    std::cout << std::left << std::setw(6) << "ID" 
              << std::setw(20) << "Name" 
              << std::setw(20) << "Contact Person" 
              << std::setw(15) << "Phone" 
              << std::setw(25) << "Address" 
              << std::setw(15) << "Payment Terms" << std::endl;
    std::cout << std::string(101, '=') << std::endl;
    
    for (int i = 0; i < supplierCount; i++) {
        suppliers[i].display();
    }
    std::cout << std::string(101, '=') << std::endl << std::endl;
}

Supplier* GroceryStore::searchSupplier(int id) const {
    for (int i = 0; i < supplierCount; i++) {
        if (suppliers[i].getSupplierID() == id) {
            return &suppliers[i];
        }
    }
    return nullptr;
}

void GroceryStore::updateSupplier(int id, const Supplier& updatedSupplier) {
    Supplier* s = searchSupplier(id);
    if (!s) throw std::runtime_error("Supplier not found");
    *s = updatedSupplier;
}

void GroceryStore::deleteSupplier(int id) {
    for (int i = 0; i < supplierCount; i++) {
        if (suppliers[i].getSupplierID() == id) {
            for (int j = i; j < supplierCount - 1; j++) {
                suppliers[j] = suppliers[j + 1];
            }
            supplierCount--;
            std::cout << "Supplier deleted successfully.\n";
            return;
        }
    }
    throw std::runtime_error("Supplier not found");
}

// ============== SALE OPERATIONS (MAIN TRANSACTION) ==============
void GroceryStore::processSale(int custID, int prodID, int quantity) {
    if (saleCount >= maxCapacity) {
        throw std::out_of_range("Sales log is full");
    }
    
    Product* product = searchProduct(prodID);
    if (!product) throw std::runtime_error("Product not found");
    
    Customer* customer = searchCustomer(custID);
    if (!customer) throw std::runtime_error("Customer not found");
    
    if (product->getQuantity() < quantity) {
        throw std::out_of_range("Insufficient product quantity");
    }
    
    double totalAmount = product->getPrice() * quantity;
    
    product->updateQuantity(-quantity);
    customer->addPurchase(totalAmount);
    
    Sale s(getNextSaleID(), custID, prodID, quantity, totalAmount, Sale::getCurrentDate());
    sales[saleCount++] = s;
    
    std::cout << "Sale processed successfully!\n";
    std::cout << "Sale ID: " << s.getSaleID() << ", Total: " << totalAmount << "\n\n";
}

void GroceryStore::displaySales() const {
    if (saleCount == 0) {
        std::cout << "No sales found.\n";
        return;
    }
    std::cout << "\n" << std::string(63, '=') << std::endl;
    std::cout << std::left << std::setw(8) << "Sale ID" 
              << std::setw(10) << "Cust ID" 
              << std::setw(10) << "Prod ID" 
              << std::setw(8) << "Qty" 
              << std::setw(12) << "Amount" 
              << std::setw(15) << "Date" << std::endl;
    std::cout << std::string(63, '=') << std::endl;
    
    for (int i = 0; i < saleCount; i++) {
        sales[i].display();
    }
    std::cout << std::string(63, '=') << std::endl << std::endl;
}

int GroceryStore::getNextSaleID() const {
    return saleCount + 1;
}

// ============== REPORT OPERATIONS ==============
void GroceryStore::generateSalesReport() const {
    std::cout << "\n========== SALES REPORT ==========\n";
    double totalRevenue = 0;
    for (int i = 0; i < saleCount; i++) {
        totalRevenue += sales[i].getTotalAmount();
    }
    std::cout << "Total Sales Transactions: " << saleCount << std::endl;
    std::cout << "Total Revenue: $" << std::fixed << std::setprecision(2) << totalRevenue << std::endl;
    std::cout << "Average Sale: $" << (saleCount > 0 ? totalRevenue / saleCount : 0) << std::endl;
    std::cout << "===================================\n\n";
}

void GroceryStore::generateInventoryReport() const {
    std::cout << "\n========== INVENTORY REPORT ==========\n";
    int totalItems = 0;
    double totalValue = 0;
    
    for (int i = 0; i < productCount; i++) {
        totalItems += products[i].getQuantity();
        totalValue += products[i].getQuantity() * products[i].getPrice();
    }
    
    std::cout << "Total Products: " << productCount << std::endl;
    std::cout << "Total Items in Stock: " << totalItems << std::endl;
    std::cout << "Total Inventory Value: $" << std::fixed << std::setprecision(2) << totalValue << std::endl;
    std::cout << "======================================\n\n";
}

void GroceryStore::generateCustomerReport() const {
    std::cout << "\n========== CUSTOMER REPORT ==========\n";
    double totalSpending = 0;
    
    for (int i = 0; i < customerCount; i++) {
        totalSpending += customers[i].getTotalSpent();
    }
    
    std::cout << "Total Customers: " << customerCount << std::endl;
    std::cout << "Total Customer Spending: $" << std::fixed << std::setprecision(2) << totalSpending << std::endl;
    std::cout << "Average Customer Spending: $" << (customerCount > 0 ? totalSpending / customerCount : 0) << std::endl;
    std::cout << "====================================\n\n";
}

// ============== FILE OPERATIONS ==============
void GroceryStore::saveAllData() {
    try {
        fileManager.saveProducts(products, productCount);
        fileManager.saveCustomers(customers, customerCount);
        fileManager.saveSuppliersSuppliers(suppliers, supplierCount);
        fileManager.saveSales(sales, saleCount);
        std::cout << "All data saved successfully!\n\n";
    } catch (const std::exception& e) {
        std::cerr << "Error saving data: " << e.what() << std::endl;
    }
}

void GroceryStore::loadAllData() {
    try {
        if (products) delete[] products;
        if (customers) delete[] customers;
        if (suppliers) delete[] suppliers;
        if (sales) delete[] sales;
        
        products = fileManager.loadProducts(productCount);
        if (!products) products = new Product[maxCapacity];
        
        customers = fileManager.loadCustomers(customerCount);
        if (!customers) customers = new Customer[maxCapacity];
        
        suppliers = fileManager.loadSuppliers(supplierCount);
        if (!suppliers) suppliers = new Supplier[maxCapacity];
        
        sales = fileManager.loadSales(saleCount);
        if (!sales) sales = new Sale[maxCapacity];
        
        std::cout << "Data loaded successfully!\n";
        std::cout << "Products: " << productCount << ", Customers: " << customerCount 
                  << ", Suppliers: " << supplierCount << ", Sales: " << saleCount << "\n\n";
    } catch (const std::exception& e) {
        std::cerr << "Error loading data: " << e.what() << std::endl;
    }
}
