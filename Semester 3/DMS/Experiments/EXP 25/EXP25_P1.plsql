CREATE OR REPLACE FUNCTION getGreater(num1 IN INT, num2 IN INT)
RETURN INT
IS
    greaterNum INT;
BEGIN
    IF num2 > num1 THEN
        greaterNum := num2;
    ELSE
        greaterNum := num1;
    END IF;

    RETURN greaterNum;
END;

DECLARE
    A INT :=:enter_a;
    B INT :=:enter_b;
BEGIN
    dbms_output.put_line('a: ' || A);
    dbms_output.put_line('b: ' || B);
    dbms_output.put_line('greater: ' || getGreater(A, B));
END;