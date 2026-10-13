# Grocery Store Management System

**Project Code:** CPP21  
**Enrollment Number:** IU2541230444  
**Language:** C++ (Standard C++17)

## Project Overview
A comprehensive Grocery Store Management system built in C++ that demonstrates core Object-Oriented Programming concepts including classes, encapsulation, inheritance, polymorphism, dynamic memory management, file persistence, and exception handling.

## Core Features

### 1. **Entity Management**
- **Products:** Manage inventory with ID, name, price, quantity, and category
- **Customers:** Track customer information and purchase history
- **Suppliers:** Maintain supplier details and payment terms
- **Sales:** Record all transactions with automatic date tracking

### 2. **Main Menu Operations**
1. **Add Record** - Add new products, customers, or suppliers
2. **Display Records** - View all records in a formatted table
3. **Search Record** - Find specific records by ID
4. **Update Record** - Modify existing records
5. **Delete Record** - Remove records from the system
6. **Main Transaction/Process** - Process sales with automatic inventory and customer spending updates
7. **Report** - Generate:
   - Sales Report (total revenue, transaction count, average sale)
   - Inventory Report (stock levels, total value)
   - Customer Report (spending analysis)
8. **Save/Load** - Persist data to files and load on startup
9. **Exit** - Close program with automatic data save

### 3. **OOP Features Implemented**

#### Encapsulation
- Private data members with public getter/setter methods
- Input validation in setters
- Controlled access to class attributes

#### Constructors & Destructors
- **Default Constructors:** Initialize with default values
- **Parameterized Constructors:** Initialize with specific values
- **Destructors:** Proper cleanup of resources

#### Inheritance & Polymorphism
- `Sale::getCurrentDate()` - Static utility for date management
- Virtual methods for file I/O operations
- Polymorphic behavior in entity management

#### Dynamic Memory
- Dynamic arrays: `Entity* array = new Entity[capacity]`
- Proper deallocation with `delete[]`
- Used in GroceryStore for entity storage (products, customers, suppliers, sales)

#### File Persistence
- CSV-based file format for easy data exchange
- Automatic load on startup, save on exit
- Separate files for each entity type:
  - `Data/products.txt`
  - `Data/customers.txt`
  - `Data/suppliers.txt`
  - `Data/sales.txt`

#### Exception Handling
- `try-catch` blocks for safe operations
- Custom exceptions for:
  - Invalid input (negative prices/quantities)
  - Not found errors
  - Insufficient inventory
  - Capacity limits

#### Validation
- Negative value prevention
- Required field checks
- Inventory consistency validation
- Duplicate ID handling

## Project Structure

```
GroceryStoreManagement/
│
├── Source/
│   ├── main.cpp                 # Main program with menu system
│   ├── Product.h/cpp            # Product entity class
│   ├── Customer.h/cpp           # Customer entity class
│   ├── Supplier.h/cpp           # Supplier entity class
│   ├── Sale.h/cpp               # Sale transaction class
│   ├── GroceryStore.h/cpp       # Main system class
│   └── FileManager.h/cpp        # File I/O operations
│
├── Data/                        # Data files (created at runtime)
│   ├── products.txt
│   ├── customers.txt
│   ├── suppliers.txt
│   └── sales.txt
│
├── Diagrams/                    # UML diagrams
│   ├── UseCase.pdf
│   ├── ClassDiagram.pdf
│   ├── Sequence1.pdf            # Main transaction/process
│   └── Sequence2.pdf            # Other important operation
│
├── Screenshots/                 # Program screenshots
│   ├── main_menu.png
│   ├── product_menu.png
│   ├── sale_process.png
│   └── reports.png
│
├── Executable/
│   └── Project.exe              # Compiled executable
│
├── compile.bat                  # Build script
├── README.txt                   # This file
└── ProjectReport.pdf            # Detailed project report

```

## How to Compile

### Prerequisites
You need one of the following C++ compilers:
- **Visual Studio 2019 or later** (includes cl.exe)
- **MinGW-w64**
- **Clang**

### Step 1: Open Command Prompt
Navigate to the project directory:
```bash
cd C:\GroceryStoreManagement
```

### Step 2: Run the Build Script
```bash
compile.bat
```

### Step 3: (Alternative) Manual Compilation with g++

If using MinGW and g++ is in your PATH:
```bash
cd Source
g++ -c Product.cpp
g++ -c Customer.cpp
g++ -c Supplier.cpp
g++ -c Sale.cpp
g++ -c FileManager.cpp
g++ -c GroceryStore.cpp
g++ -c main.cpp

g++ *.o -o ..\Executable\Project.exe
```

### Step 4: (Alternative) Manual Compilation with cl.exe

If using Visual Studio:
```bash
cd Source
cl /EHsc /std:c++17 Product.cpp Customer.cpp Supplier.cpp Sale.cpp FileManager.cpp GroceryStore.cpp main.cpp /Fe..\Executable\Project.exe
```

## How to Run

```bash
cd Executable
Project.exe
```

## Usage Example

### Adding Products
```
Enter your choice: 1              # Product Management
Enter choice: 1                   # Add Product
Enter Product ID: 101
Enter Product Name: Apples
Enter Price: 2.50
Enter Quantity: 100
Enter Category: Fruits
```

### Processing a Sale (Main Transaction)
```
Enter your choice: 4              # Process Sale
Enter Customer ID: 1001
Enter Product ID: 101
Enter Quantity: 5
```
The system will:
1. Verify customer exists
2. Verify product exists and has sufficient inventory
3. Deduct quantity from inventory
4. Update customer's total spending
5. Record the sale with date and amount

### Viewing Reports
```
Enter your choice: 5              # View Reports
1. Sales Report
   - Shows total revenue and transaction count
2. Inventory Report
   - Shows total items in stock and their value
3. Customer Report
   - Shows customer spending statistics
```

## Data Persistence

**On Startup:**
- Program automatically loads all saved data from `Data/` folder
- If no data files exist, starts with empty system

**During Operation:**
- All changes are kept in memory
- Manual save via "Save Data" menu option

**On Exit:**
- Program automatically saves all data before closing
- Changes persist for next program run

**Verification:**
You can verify persistence by:
1. Running the program
2. Adding some records
3. Using "Save Data" option
4. Closing the program
5. Reopening - all records should still be there

## Key Classes and Methods

### Product
```cpp
Product(int id, string name, double price, int qty, string category);
void updateQuantity(int change);        // Add/subtract inventory
double getPrice() const;
int getQuantity() const;
```

### Customer
```cpp
Customer(int id, string name, string phone, string email, string addr);
void addPurchase(double amount);        // Track spending
double getTotalSpent() const;
```

### Sale (Main Transaction)
```cpp
Sale(int id, int custID, int prodID, int qty, double amount, string date);
static string getCurrentDate();         // Automatic date tracking
```

### GroceryStore (System Controller)
```cpp
void addProduct(Product p);
void processSale(int custID, int prodID, int qty);    // MAIN TRANSACTION
void generateSalesReport();
void saveAllData();
void loadAllData();
```

## Error Handling Examples

The system handles various error scenarios:

```cpp
// Invalid quantity
if (product->getQuantity() < quantity) {
    throw std::out_of_range("Insufficient product quantity");
}

// Invalid price
if (price < 0) {
    throw std::invalid_argument("Price cannot be negative");
}

// Entity not found
if (!searchProduct(id)) {
    throw std::runtime_error("Product not found");
}
```

## Memory Management

All dynamic memory is properly managed:

```cpp
// Allocation in constructor
Product* products = new Product[capacity];

// Usage during program
products[i] = new_product;

// Deallocation in destructor
delete[] products;
```

## File Format

All data files use CSV format for readability:

**products.txt:**
```
101,Apples,2.50,100,Fruits
102,Milk,1.99,50,Dairy
```

**sales.txt:**
```
1,1001,101,5,12.50,2024-10-08
2,1002,102,3,5.97,2024-10-08
```

## Testing Checklist

- [ ] Compile successfully
- [ ] Add products, customers, suppliers
- [ ] Display all records
- [ ] Search for records
- [ ] Update records
- [ ] Delete records
- [ ] Process sales with inventory deduction
- [ ] Generate all reports
- [ ] Save data
- [ ] Close and reopen to verify persistence
- [ ] Exception handling (invalid input)

## UML Diagrams Included

1. **Use Case Diagram** - Shows 6+ use cases with 2+ actors
2. **Class Diagram** - All 6 core classes with relationships
3. **Sequence Diagram 1** - Main transaction/sale process flow
4. **Sequence Diagram 2** - Product inventory update process

## Compiler Flags Used

```
/EHsc          - Enable exception handling (Visual Studio)
/std:c++17      - Use C++17 standard
-Wall           - Show all warnings (GCC)
-std=c++17      - Use C++17 standard (GCC)
```

## Troubleshooting

**Issue: "Cannot compile - cl.exe not found"**
- Install Visual Studio Build Tools
- Add cl.exe to PATH environment variable
- Or use compile.bat which attempts automatic detection

**Issue: "Data not persisting"**
- Ensure `Data/` folder exists
- Use "Save Data" before closing
- Check file permissions

**Issue: "Insufficient product quantity error"**
- Product doesn't have enough items
- Add more quantity or try with different product

**Issue: "Entity not found"**
- Verify the ID exists
- Use Display Records to see available IDs

## Performance Notes

- Supports up to 100 records per entity type (configurable)
- O(n) linear search for record lookup (could be optimized with indexing)
- File I/O happens explicitly on user request or exit

## Future Enhancements

1. Database integration (SQLite/MySQL)
2. User authentication and roles
3. Advanced reporting with filters and exports
4. Binary search for faster lookups
5. Graphical User Interface (GUI)
6. Network features for multi-store management
7. Barcode scanning support
8. Advanced analytics and forecasting

## Notes

- All source files follow modular .h/.cpp structure
- Proper encapsulation with private members
- Comprehensive exception handling throughout
- File persistence ensures data durability
- Easy to extend with new entity types

---

**Created for:** CPP21 Project (IU2541230444)  
**Last Updated:** October 2024
