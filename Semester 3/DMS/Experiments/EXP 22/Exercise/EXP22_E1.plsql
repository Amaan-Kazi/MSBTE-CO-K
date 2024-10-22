DECLARE
    num1 INT :=:num1;
    num2 INT :=:num2;
BEGIN
    DBMS_OUTPUT.PUT_LINE(num1 || ' / ' || num2 || ' = ' || num1/num2);
EXCEPTION
    WHEN ZERO_DIVIDE THEN
        DBMS_OUTPUT.PUT_LINE('Division by 0 is not allowed');
END;