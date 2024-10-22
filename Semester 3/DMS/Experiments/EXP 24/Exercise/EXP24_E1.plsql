CREATE TABLE employees (
    emp_id NUMBER PRIMARY KEY,
    emp_name VARCHAR2(100),
    department_id NUMBER,              
    salary NUMBER
);

INSERT INTO employees (emp_id, emp_name, department_id, salary) VALUES (1, 'John Doe', 10, 50000);
INSERT INTO employees (emp_id, emp_name, department_id, salary) VALUES (2, 'Jane Smith', 10, 60000);
INSERT INTO employees (emp_id, emp_name, department_id, salary) VALUES (3, 'Alice Johnson', 20, 55000);
INSERT INTO employees (emp_id, emp_name, department_id, salary) VALUES (4, 'Bob Brown', 30, 70000);
INSERT INTO employees (emp_id, emp_name, department_id, salary) VALUES (5, 'Charlie White', 20, 65000);

CREATE OR REPLACE PROCEDURE emp_count(dept_no IN NUMBER) IS
    emp_total NUMBER;
BEGIN
    SELECT COUNT(*)
    INTO emp_total
    FROM employees
    WHERE department_id = dept_no;

    DBMS_OUTPUT.PUT_LINE('Number of employees in department ' || dept_no || ': ' || emp_total);
END;

BEGIN
    EMP_COUNT(100);
END;

COMMIT;
