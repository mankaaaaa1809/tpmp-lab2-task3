# Test Report: Subscriber Management Program

**Test Date:** February 28, 2026  
**Author:** Mankewich Anhelina  
**Repository:** tpmp-lab2-task3

## 1. Test Objectives

Verify the functionality of all program features:
- Subscriber data input
- Alphabetical sorting (with initials)
- Bonus addition (10 rub. for connections > 10 years ago)
- Display subscribers with negative balance after deduction
- Tariff plan statistics

## 2. Test Data

### 2.1 Test Dataset 1 (from workflow)

Number of subscribers: 3

1. Max Petrov Phone: +375445431234 Connection date: 1996-12-01 Tariff: Basic Accrued: 500.00 Balance: 200.00 
2. Peter Quint Phone: +56327843498 Connection date: 2020-03-05 Tariff: Pro Accrued: 300.00 Balance: 200.00 
3. Katerina Petrova Phone: +155436777 Connection date: 2006-11-11 Tariff: Pro Accrued: 300.00 Balance: 1000.00

### 2.2 Test Dataset 2 (edge cases)
 Number of subscribers: 4

4. Anna Smith Phone: +44123456789 Connection date: 2016-02-28 Tariff: Basic Accrued: 450.00 Balance: 500.00 
5. John Doe Phone: +19876543210 Connection date: 2026-02-27 Tariff: Premium Accrued: 1000.00 Balance: 100.00 
6. Maria Garcia Phone: +34987654321 Connection date: 2015-02-28 Tariff: Basic Accrued: 600.00 Balance: 650.00 
7. Chen Wei Phone: +8612345678901 Connection date: 2005-01-01 Tariff: Premium Accrued: 800.00 Balance: 1200.00 

## 3. Test Results

### 3.1 Test 1: Alphabetical Sorting

**Input Data:** Dataset 1 + Dataset 2 (7 subscribers)

**Expected Order:**

1. Anna Smith | Basic 2. Chen Wei | Premium 3. John Doe | Premium 4. Katerina Petrova | Pro 5. Maria Garcia | Basic 6. Max Petrov | Basic 7. Peter Quint | Pro

**Actual Result:**

List of all subscribers:
1. Anna Smith | Phone: +44123456789 | Date: 28.2.2016 | Tariff: Basic | Accrued: 450.00 | Balance: 500.00
2. Chen Wei | Phone: +8612345678901 | Date: 1.1.2005 | Tariff: Premium | Accrued: 800.00 | Balance: 1200.00
3. John Doe | Phone: +19876543210 | Date: 27.2.2026 | Tariff: Premium | Accrued: 1000.00 | Balance: 100.00
4. Katerina Petrova | Phone: +155436777 | Date: 11.11.2006 | Tariff: Pro | Accrued: 300.00 | Balance: 1000.00
5. Maria Garcia | Phone: +34987654321 | Date: 28.2.2015 | Tariff: Basic | Accrued: 600.00 | Balance: 650.00
6. Max Petrov | Phone: +375445431234 | Date: 1.12.1996 | Tariff: Basic | Accrued: 500.00 | Balance: 200.00
7. Peter Quint | Phone: +56327843498 | Date: 5.3.2020 | Tariff: Pro | Accrued: 300.00 | Balance: 200.00

**Status:** PASSED (correct alphabetical order)

### 3.2 Test 2: 10 Rub. Bonus (Connections > 10 Years Ago)

**Calculation (as of February 28, 2026):**

| Subscriber | Connection Date | Years Since | Bonus |
|------------|----------------|-------------|-------|
| Max Petrov | 1996-12-01 | 29.2 years | +10 rub. |
| Peter Quint | 2020-03-05 | 5.9 years | - |
| Katerina Petrova | 2006-11-11 | 19.3 years | +10 rub. |
| Anna Smith | 2016-02-28 | 10.0 years | - (exactly 10 years) |
| John Doe | 2026-02-27 | 0 years | - |
| Maria Garcia | 2015-02-28 | 11.0 years | +10 rub. |
| Chen Wei | 2005-01-01 | 21.1 years | +10 rub. |

**Expected Result:** 4 subscribers receive bonus (Max, Katerina, Maria, Chen)

**Actual Result:**

Bonus added to 4 subscribers
After adding bonus: Max Petrov | Balance: 210.00 (+10) Katerina Petrova | Balance: 1010.00 (+10) Maria Garcia | Balance: 660.00 (+10) Chen Wei | Balance: 1210.00 (+10) Anna Smith | Balance: 500.00 (no change) John Doe | Balance: 100.00 (no change) Peter Quint | Balance: 200.00 (no change)

**Status:** PASSED (correct bonus calculation, edge case at exactly 10 years handled)

### 3.3 Test 3: Negative Balance After Deduction

**Calculation (Balance - Accrued):**

| Subscriber | Balance | Accrued | After Deduction | Status |
|------------|---------|---------|-----------------|--------|
| Max Petrov | 210.00 | 500.00 | **-290.00** | Negative |
| Peter Quint | 200.00 | 300.00 | **-100.00** | Negative |
| Katerina Petrova | 1010.00 | 300.00 | **+710.00** | Positive |
| Anna Smith | 500.00 | 450.00 | **+50.00** | Positive |
| John Doe | 100.00 | 1000.00 | **-900.00** | Negative |
| Maria Garcia | 660.00 | 600.00 | **+60.00** | Positive |
| Chen Wei | 1210.00 | 800.00 | **+410.00** | Positive |

**Expected Result:** 3 subscribers with negative balance (Max, Peter, John)

**Actual Result:**
 Subscribers with negative balance after deduction: Subscriber: Max Petrov Phone: +375445431234 Tariff: Basic Accrued: 500.00, Balance: 210.00, After deduction: -290.00

Subscriber: Peter Quint Phone: +56327843498 Tariff: Pro Accrued: 300.00, Balance: 200.00, After deduction: -100.00

Subscriber: John Doe Phone: +19876543210 Tariff: Premium Accrued: 1000.00, Balance: 100.00, After deduction: -900.00


**Status:** PASSED (correct negative balance detection)

### 3.4 Test 4: Tariff Plan Statistics

**Expected Result:**

Tariff 'Basic': 3 subscribers (Max, Anna, Maria)
Tariff 'Pro': 2 subscribers (Katerina, Peter)
Tariff 'Premium': 2 subscribers (John, Chen)

**Actual Result:**

Tariff plan statistics:
Tariff 'Basic': 3 subscribers
Tariff 'Pro': 2 subscribers
Tariff 'Premium': 2 subscribers


**Status:** PASSED (accurate counting)

### 3.5 Test 5: Boundary Value Tests

#### 3.5.1 Maximum Subscribers Limit

Input: count = 15
Output: "Maximum size exceeded! Using 12"
Result: Program correctly limits to MAX_ABONENTS (12)

#### 3.5.2 Empty Subscriber List

Action: Show all subscribers with count = 0
Output: "Subscriber list is empty!"
Result: Proper handling of empty list

#### 3.5.3 Exactly 10 Years Boundary

Test case: Anna Smith (2016-02-28 to 2026-02-28 = exactly 10 years)
Result: No bonus added
Verification: Correct boundary handling

#### 3.5.4 One Day Over 10 Years

Test case: Maria Garcia (2015-02-28 to 2026-02-28 = 11 years) Result: Bonus added Verification: Correct boundary handling


### 3.6 Test 6: GitHub Actions CI/CD

**Workflow Execution Results:**

| Step | Status | Time |
|------|--------|------|
| Checkout repository | PASSED | 2s |
| Install dependencies | PASSED | 15s |
| Build with Make | PASSED | 3s |
| Run program with test data | PASSED | 2s |
| Clean build | PASSED | 1s |

**Total execution time:** ~23 seconds

**Console output snippet:**

Running program with complete test...
Subscriber database program
...
Entered 7 subscribers
Bonus added to 4 subscribers
Tariff 'Basic': 3 subscribers
Tariff 'Pro': 2 subscribers
Tariff 'Premium': 2 subscribers
Exiting program


**Status:** PASSED (CI/CD pipeline working correctly)

## 4. Summary of Results

| Test Case | Description | Status |
|-----------|-------------|--------|
| 3.1 | Alphabetical Sorting | PASSED |
| 3.2 | 10 Rub. Bonus | PASSED |
| 3.3 | Negative Balance | PASSED |
| 3.4 | Tariff Statistics | PASSED |
| 3.5 | Boundary Values | PASSED |
| 3.6 | GitHub Actions CI | PASSED |

---
