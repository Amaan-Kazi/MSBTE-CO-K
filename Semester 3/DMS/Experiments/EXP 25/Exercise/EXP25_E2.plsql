CREATE OR REPLACE FUNCTION factorial (x NUMBER)
RETURN NUMBER
IS
BEGIN
    IF x < 1 THEN
        RETURN 1;
    ELSE
        RETURN x * factorial(x-1);
    END IF;
END;

DECLARE
    num NUMBER :=:enter_num;
BEGIN
    dbms_output.put_line(num || '! = ' || factorial(num));
END;

COMMIT;