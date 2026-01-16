DSA PROJECT
---


---

## 1. Purpose of the Code

* Creates a **Monthly Attendance Management System** for **January 2026**
* Allows:

  * Marking students **Present (P) / Absent (A)**
  * **Automatic attendance percentage calculation**
  * **Search by student name or USN**
  * Horizontal scrolling for many dates

---

## 2. Technologies Used

* **HTML** → Structure of the page
* **CSS** → Styling and layout
* **JavaScript** → Logic (date generation, attendance calculation, search)

---

## 3. Page Layout & UI Design (CSS)

* Uses a **gradient background** for a modern look
* Centered headings for college name and month
* **Sticky table header** → Dates stay visible while scrolling
* **Sticky first column** → Student names stay visible while scrolling horizontally
* Rounded corners, shadows, and clean font for better UI

---

## 4. Dynamic Date Generation

```javascript
let startDate = new Date(2026, 0, 1);
```

* Automatically generates **30 dates for January 2026**
* Uses JavaScript to:

  * Loop through dates
  * Format as `DD/MM/YYYY`
  * Create `<th>` elements dynamically
* Avoids manual date entry

---

## 5. Student Data Structure

```javascript
let students = [
    {name:"vajra", usn:"4GW24CI001"},
    ...
];
```

* Stores student data in an **array of objects**
* Easy to:

  * Add/remove students
  * Access name and USN dynamically

---

## 6. Dynamic Table Generation

### `loadStudents()` function:

* Creates table rows dynamically for each student
* Adds:

  * Name + USN column
  * 30 attendance dropdowns (`P` / `A`)
  * Attendance percentage column
* Uses:

  * `document.createElement()`
  * `appendChild()`

---

## 7. Attendance Marking System

* Each day has a `<select>` dropdown:

  ```html
  <select onchange="calculate(rowIndex)">
      <option value="P">P</option>
      <option value="A">A</option>
  </select>
  ```
* Default value is **Present (P)**

---

## 8. Attendance Percentage Calculation

### `calculate(rowIndex)` function:

* Counts number of **P (Present)** values
* Formula used:

```javascript
(present / 30) * 100
```

* Updates percentage **automatically on change**
* Displays result with **1 decimal place**
* Initial value set to **100%**

---

## 9. Search Functionality

### `searchStudent()` function:

* Filters students in real time
* Works for:

  * Student name
  * USN
* Uses:

  * `data-search` attribute
  * `toLowerCase()` for case-insensitive search

---

## 10. Sticky Columns & Scrolling

* **Sticky header** → Dates remain visible
* **Sticky name column** → Student names remain visible
* Horizontal scrolling enabled for wide tables

---

## 11. Code Reusability & Efficiency

* No hardcoded dates or rows
* Easy to modify:

  * Month length
  * Student list
  * Attendance status options
* Clean separation of:

  * UI (HTML/CSS)
  * Logic (JavaScript)

---

## 12. Limitations (For Improvement)

* Attendance data is **not saved** (no database / localStorage)
* No total classes or working day customization
* No export (Excel / PDF)
* No role-based access

---

## 13. Best Use Case

* Mini project
* College assignment
* Front-end practice
* Attendance demo system

---
