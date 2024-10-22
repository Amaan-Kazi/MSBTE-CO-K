CREATE TABLE Department (
    deptId NUMBER,
    deptName VARCHAR2(20)
);

CREATE OR REPLACE TRIGGER onDepartmentUpdate
AFTER UPDATE
ON Department
FOR EACH ROW
BEGIN
    DBMS_OUTPUT.PUT_LINE('Invoked trigger due to update in Department');
END;

INSERT INTO Department
VALUES (1, 'Department 1');

UPDATE Department
SET deptName = 'Computer'
WHERE deptId = 1;

COMMIT;
