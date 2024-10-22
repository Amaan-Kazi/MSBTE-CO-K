DECLARE
    id INT :=:id;
    invalid_id EXCEPTION;
BEGIN
    IF id < 1 THEN
        RAISE invalid_id;
    END IF;
EXCEPTION
    WHEN invalid_id THEN
        DBMS_OUTPUT.PUT_LINE('Invalid ID [' || id || ']');
END;