CREATE OR REPLACE FUNCTION getGreater(num1 IN INT, num2 IN INT)
RETURN INT
IS
    greaterNum INT;
BEGIN
    IF num2 > num1 THEN
        greaterNum := num1;
    ELSE
        greaterNum := num2;
    END IF;

    RETURN greaterNum;
END;

CREATE TABLE abc (
    a INT,
    b NUMBER
);
INSERT INTO abc
VALUES (5.2, 2);

SELECT * FROM abc;