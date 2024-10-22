DECLARE
    CURSOR student_cursor IS
        SELECT student_id, name, department, age FROM student;

    v_student_id student.student_id%TYPE;
    v_name student.name%TYPE;
    v_department student.department%TYPE;
    v_age student.age%TYPE;
    v_record_number NUMBER := 0;
BEGIN
    OPEN student_cursor;

    LOOP
        FETCH student_cursor INTO v_student_id, v_name, v_department, v_age;
        EXIT WHEN student_cursor%NOTFOUND;

        v_record_number := v_record_number + 1;

        IF MOD(v_record_number, 2) = 0 THEN
            DBMS_OUTPUT.PUT_LINE('Student ID: ' || v_student_id || 
                                 ', Name: ' || v_name || 
                                 ', Department: ' || v_department || 
                                 ', Age: ' || v_age);
        END IF;
    END LOOP;

    CLOSE student_cursor;
END;
