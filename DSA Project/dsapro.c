<!DOCTYPE html>
<html>
<head>
    <title>Attendance System</title>

    <style>
        body {
            font-family: Arial;
            background: linear-gradient(to right, #cfd9df, #e2ebf0);
            padding: 20px;
        }

        h1 {
            text-align: center;
            color: #2c3e50;
            margin-bottom: 5px;
        }

        h2 {
            text-align: center;
            color: #34495e;
            margin-top: 0;
        }

        #search {
            width: 300px;
            padding: 10px;
            margin: 15px auto;
            display: block;
            border-radius: 20px;
            border: 2px solid #3498db;
            font-size: 16px;
        }

        .table-container {
            overflow-x: auto;
            background: white;
            border-radius: 10px;
            padding: 10px;
            box-shadow: 0 6px 12px rgba(0,0,0,0.2);
        }

        table {
            border-collapse: collapse;
            width: 100%;
            min-width: 1600px;
        }

        th, td {
            border: 1px solid #ccc;
            padding: 6px;
            text-align: center;
            font-size: 13px;
        }

        th {
            background: #3498db;
            color: white;
            position: sticky;
            top: 0;
        }

        td.name {
            background: #ecf0f1;
            font-weight: bold;
            position: sticky;
            left: 0;
            z-index: 1;
        }

        select {
            padding: 3px;
            border-radius: 4px;
        }

        .percent {
            font-weight: bold;
            color: green;
        }
    </style>
</head>
<body>

<h1>GSSS College of Engineering and Technology</h1>
<h2>Monthly Attendance Sheet – January 2026</h2>

<input type="text" id="search" placeholder="Search by Name or USN" onkeyup="searchStudent()">

<div class="table-container">
<table id="attendanceTable">
    <thead>
        <tr>
            <th>Name / USN</th>
            <script>
                let startDate = new Date(2026, 0, 1); // Jan = 0
                for (let i = 0; i < 30; i++) {
                    let d = new Date(startDate);
                    d.setDate(startDate.getDate() + i);

                    let day = String(d.getDate()).padStart(2, '0');
                    let month = String(d.getMonth() + 1).padStart(2, '0');
                    let year = d.getFullYear();

                    document.write(`<th>${day}/${month}/${year}</th>`);
                }
            </script>
            <th>%</th>
        </tr>
    </thead>

    <tbody id="tableBody"></tbody>
</table>
</div>

<script>
let students = [
    {name:"vajra", usn:"4GW24CI001"},
    {name:"madhu", usn:"4GW24CI002"},
    {name:"Ramitha", usn:"4GW24CI003"},
    {name:"Sneha", usn:"4GW24CI004"},
    {name:"Disha", usn:"4GW24CI005"},
    {name:"keerthana", usn:"4GW24CI006"},
    {name:"Pooja", usn:"4GW24CI007"},
    {name:"jahnavi", usn:"4GW24CI008"},
    {name:"Neha", usn:"4GW24CI009"},
    {name:"Ganavi", usn:"4GW34CI010"},
    {name:"Divya", usn:"4GW24CI011"}
];

function loadStudents() {
    let body = document.getElementById("tableBody");
    body.innerHTML = "";

    students.forEach((s, rowIndex) => {
        let row = document.createElement("tr");
        row.setAttribute("data-search", (s.name + s.usn).toLowerCase());

        let nameCell = document.createElement("td");
        nameCell.className = "name";
        nameCell.innerHTML = `${s.name}<br><small>${s.usn}</small>`;
        row.appendChild(nameCell);

        for (let i = 0; i < 30; i++) {
            let td = document.createElement("td");
            td.innerHTML = `
                <select onchange="calculate(${rowIndex})">
                    <option value="P">P</option>
                    <option value="A">A</option>
                </select>
            `;
            row.appendChild(td);
        }

        let percent = document.createElement("td");
        percent.className = "percent";
        percent.id = "percent" + rowIndex;
        percent.innerText = "100%";
        row.appendChild(percent);

        body.appendChild(row);
    });
}

function calculate(rowIndex) {
    let table = document.getElementById("attendanceTable");
    let row = table.rows[rowIndex + 1];
    let present = 0;

    for (let i = 1; i <= 30; i++) {
        if (row.cells[i].children[0].value === "P") {
            present++;
        }
    }

    let percent = ((present / 30) * 100).toFixed(1);
    document.getElementById("percent" + rowIndex).innerText = percent + "%";
}

function searchStudent() {
    let value = document.getElementById("search").value.toLowerCase();
    let rows = document.querySelectorAll("#tableBody tr");

    rows.forEach(row => {
        let text = row.getAttribute("data-search");
        row.style.display = text.includes(value) ? "" : "none";
    });
}

loadStudents();
</script>

</body>
</html>