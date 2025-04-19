# 🛒 Supermarket Management System – C++ OOP Project

A **C++ object-oriented program** simulating the core backend of a **supermarket management system**. It supports **product inventory**, **shopping cart operations**, **discount application**, and **order processing**, making it a modular and extensible solution for retail scenarios.

---

## 📚 Project Overview

This system models key retail operations through class-based architecture, handling real-world product types, applying diverse discounts, tracking stock, and calculating final order values. It emphasizes the use of templates, polymorphism, and operator overloading.

Designed with extensibility in mind, it can be adapted to manage additional product types or connect to a UI or database for full-scale retail applications.

---

## ✨ Key Features

- 📦 **Product Management** – Add, remove, and sort items like books, electronics, and food.
- 🛍️ **Shopping Cart System** – Add items to cart with real-time stock updates.
- 💸 **Dynamic Discounting** – Apply percentage, fixed, and BOGO discounts.
- 🧾 **Order Summary** – Consolidate carts into a full order with savings breakdown.
- 📊 **Warranty Stats (Electronics)** – Specialized analytics for electronics category.

---

## 🧱 Core Components

### 📦 Product & Derived Classes  
Defines base product attributes and specialized types:
- `BooksProduct` – Includes author & genre  
- `ElectronicsProduct` – Includes warranty, factory, type  
- `FoodProduct` – Includes expiry date & type

### 🧠 ProductManager (Template)  
Manages inventory operations per product type with:
- Add/remove functionality  
- Sorting by price, quantity, or name  
- Operator overloading (`+`, `-`)  
- Specialization for electronics stats

### 🛒 ShoppingCart (Template)  
Handles product selection with automatic stock sync.
- Increasing/reducing product manager quantity  

### 🏷️ Discount (Template)  
Applies discounts via overloaded `-` operator.
- Supports percentage, fixed, and BOGO deals  
- Allows custom coupons and loss tracking

### 📦 Order Class  
Aggregates carts from all categories and calculates:
- Total cost  
- Total savings  
- Discount breakdown

---

## 🔁 Workflow & Logic

### Product Inventory  
- Products are added via `ProductManager`  
- Sorted by price, name, or quantity as needed

### Cart Operations  
- Shopping carts interact directly with stock  
- Quantity updates are immediate and consistent

### Discount Application  
- Applied either per product or globally  
- Discounts recorded and total savings updated

### Order Finalization  
- Consolidates carts into a single order  
- Generates a receipt with all calculations

---


## 🧠 Concepts Demonstrated

- Object-Oriented Programming in C++  
- Templates & Specialization  
- Operator Overloading (`+`, `-`)  
- Inheritance & Polymorphism  
- Real-time Stock Tracking  
- Modular Class Design

---

## 🛠️ Technologies Used

- **Language:** C++  
- **Libraries:** Standard Template Library (STL)  
- **Concepts:** OOP, Templates, Overloading, Sorting

---

## 📬 Contact

For questions or contributions, feel free to reach out:

📧 mahmoudhossam@aucegypt.edu
