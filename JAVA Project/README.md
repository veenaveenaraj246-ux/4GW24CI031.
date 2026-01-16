JAVA PROJECT
## 1. Purpose of the Program

This Java program creates a **desktop-based Attendance System** using **Java Swing**.
It allows:

* Displaying a list of students
* Marking attendance as **Present (P)** for 30 days
* Automatically calculating **attendance percentage**

---

## 2. Packages Imported

```java
import javax.swing.*;
import javax.swing.table.*;
import java.awt.*;
```

### Explanation:

* `javax.swing.*` → Used for GUI components like `JFrame`, `JTable`, `JButton`
* `javax.swing.table.*` → Used for table model (`DefaultTableModel`)
* `java.awt.*` → Used for layouts and GUI positioning

---

## 3. Class Declaration

```java
public class AttendanceSystem extends JFrame
```

### Explanation:

* Creates a class named `AttendanceSystem`
* Extends `JFrame` → makes this class a **window-based GUI application**

---

## 4. Student Data

```java
String[] students = {
   "vajra (4GW24CI001)",
   ...
};
```

### Explanation:

* Stores **student name and USN** in a string array
* Each student will be displayed as one row in the table

---

## 5. JTable and Table Model

```java
JTable table;
DefaultTableModel model;
```

### Explanation:

* `JTable` → Displays attendance in tabular form
* `DefaultTableModel` → Controls table data (rows & columns)

---

## 6. Constructor: `AttendanceSystem()`

This method **builds the entire GUI**.

### a) Window Settings

```java
setTitle("Attendance System");
setSize(1200, 500);
setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
setLocationRelativeTo(null);
```

* Sets window title
* Sets window size
* Closes application when window is closed
* Centers window on screen

---

## 7. Creating Table Columns

```java
String[] columns = new String[32];
columns[0] = "Name / USN";
```

### Explanation:

* Total columns = **32**

  * 1 → Name/USN
  * 30 → Attendance days
  * 1 → Percentage

```java
for (int i = 1; i <= 30; i++) {
    columns[i] = "Day " + i;
}
columns[31] = "%";
```

* Automatically generates **Day 1 to Day 30**
* Last column shows attendance percentage

---

## 8. Creating the Table Model

```java
model = new DefaultTableModel(columns, 0);
table = new JTable(model);
```

### Explanation:

* Creates table structure using column names
* `0` → No rows initially
* `JTable` uses this model to display data

---

## 9. Adding Student Rows

```java
for (String student : students) {
```

### Explanation:

* Loops through each student
* Creates one table row per student

```java
row[0] = student;
for (int i = 1; i <= 30; i++) {
    row[i] = "P";
}
row[31] = "100%";
```

* Sets default attendance as **Present (P)**
* Default attendance percentage = **100%**

---

## 10. Scroll Pane

```java
JScrollPane scrollPane = new JScrollPane(table);
add(scrollPane, BorderLayout.CENTER);
```

### Explanation:

* Adds scrolling functionality to the table
* Required because the table is wide (many columns)

---

## 11. Calculate Attendance Button

```java
JButton calculateBtn = new JButton("Calculate Attendance");
```

* Creates a button to calculate attendance

```java
calculateBtn.addActionListener(e -> calculateAttendance());
```

* When clicked → calls `calculateAttendance()` method

---

## 12. Attendance Calculation Logic

```java
void calculateAttendance() {
```

### Explanation:

* Calculates attendance for **each student**

```java
if (model.getValueAt(i, j).toString().equals("P")) {
    present++;
}
```

* Counts number of **Present (P)** entries

```java
double percent = (present / 30.0) * 100;
```

* Formula for attendance percentage

```java
model.setValueAt(String.format("%.1f%%", percent), i, 31);
```

* Updates percentage column

---

## 13. Main Method

```java
public static void main(String[] args)
```

### Explanation:

* Entry point of the Java program

```java
SwingUtilities.invokeLater(() -> {
    new AttendanceSystem().setVisible(true);
});
```

* Ensures Swing GUI runs safely
* Displays the attendance window

---

## 14. Output of the Program

* Displays a **table-based attendance sheet**
* Users can:

  * Modify P/A values
  * Click **Calculate Attendance**
  * View updated percentages

---

## 15. Limitations

* No database or file storage
* No search feature
* No date-wise calendar
* Only desktop-based

---

## 16. Conclusion (Exam-Friendly)

This program demonstrates how **Java Swing** can be used to create a **GUI-based attendance management system** that dynamically calculates attendance percentages using table models and event handling.

---

