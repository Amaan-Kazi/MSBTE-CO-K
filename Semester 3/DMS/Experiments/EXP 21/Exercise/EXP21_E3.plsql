CREATE TABLE store (
    item_id NUMBER PRIMARY KEY,
    item_name VARCHAR2(100),
    price NUMBER
);

INSERT INTO store (item_id, item_name, price) VALUES (1, 'Laptop', 75000);
INSERT INTO store (item_id, item_name, price) VALUES (2, 'Smartphone', 15000);
INSERT INTO store (item_id, item_name, price) VALUES (3, 'Headphones', 5000);
INSERT INTO store (item_id, item_name, price) VALUES (4, 'Television', 30000);
INSERT INTO store (item_id, item_name, price) VALUES (5, 'Monitor', 20000);

DECLARE
    CURSOR store_cursor IS
        SELECT item_id, item_name, price FROM store WHERE price > 10000;

    v_item_id store.item_id%TYPE;
    v_item_name store.item_name%TYPE;
    v_price store.price%TYPE;
    v_count NUMBER := 0;
BEGIN
    OPEN store_cursor;

    LOOP
        FETCH store_cursor INTO v_item_id, v_item_name, v_price;
        EXIT WHEN store_cursor%NOTFOUND;

        v_count := v_count + 1;
    END LOOP;

    CLOSE store_cursor;
    DBMS_OUTPUT.PUT_LINE('Number of items with price more than 10000: ' || v_count);
END;

COMMIT;
