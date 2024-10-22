DECLARE
    id NUMBER :=:empId;
    sal INT;
BEGIN
    SELECT salary
    INTO sal
    FROM EMP
    WHERE empId = id;

    DBMS_OUTPUT.PUT_LINE('ID: ' || id || ', Salary: ' || sal);
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        DBMS_OUTPUT.PUT_LINE('Employee ID [' || id || '] not found');
END;