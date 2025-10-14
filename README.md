# JAFN-Hosptal-Billing-System
A C-based console application developed that is designed to manage and calculate patient billing for JAFN Hospital, supporting both inpatient and outpatient services.

## Overview
**The Hospital Billing System allows hospital staff to:**
- Log in securely using staff credentials
- Add and manage patient records
- Categorize patients based on type, employment, and treatment
- Automatically calculate billing based on hospital pricing rules
- View detailed bills for individual patients

---

## Features
**1. Secure Login System** – Staff authentication using ID and password
**2. Patient Management** – Add and store patient details using arrays
**3. Automated Billing** – Calculates charges based on:
- Patient type (Inpatient/Outpatient)
- Room type (Single/Multi-bedded)
- Consultation time (with midnight surcharge)
- Employment category (Government, Pensioner, Private)
- Treatment type (Medical/Surgical)

**4. Bill Display** – Shows itemized billing for selected patients
**5. Input Validation** – Handles invalid inputs gracefully

---

## Technologies Used
**Language:** C
**Concepts:** Arrays, Functions, Loops, Conditional Statements, User Input Validation
**Tools:** Code::Blocks / Dev C++ / Any C Compiler

---

## How to Run
1. Compile the .cpp file using a C compiler
2. Run the executable
3. Login with:
- **Staff ID**: 12345
- **Password**: 54321
4. Follow the menu to add patients and view bills
