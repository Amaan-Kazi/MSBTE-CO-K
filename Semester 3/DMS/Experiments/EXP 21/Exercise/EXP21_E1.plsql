CREATE TABLE student (
    student_id NUMBER PRIMARY KEY,
    name VARCHAR2(50),
    department VARCHAR2(50),
    age NUMBER
);

INSERT INTO student (student_id, name, department, age) VALUES (1, 'Alice Smith', 'Computer', 20);
INSERT INTO student (student_id, name, department, age) VALUES (2, 'Bob Johnson', 'Mathematics', 21);
INSERT INTO student (student_id, name, department, age) VALUES (3, 'Charlie Rob', 'Computer', 22);
INSERT INTO student (student_id, name, department, age) VALUES (4, 'Robinson', 'Physics', 19);
INSERT INTO student (student_id, name, department, age) VALUES (5, 'John Wick', 'Computer', 23);

DECLARE
    CURSOR student_cursor IS
        SELECT student_id, name, age
        FROM student
        WHERE department = 'Computer';
    
    student_record student_cursor%ROWTYPE;
BEGIN
    DBMS_OUTPUT.PUT_LINE('Details of Students in Computer Department:');

    OPEN student_cursor;
    LOOP
        FETCH student_cursor INTO student_record;
        EXIT WHEN student_cursor%NOTFOUND;
        
        DBMS_OUTPUT.PUT_LINE(
            student_record.student_id || '    ' || 
            student_record.name || '    ' || 
            student_record.age
        );
    END LOOP;
    CLOSE student_cursor;
END;

COMMIT;
