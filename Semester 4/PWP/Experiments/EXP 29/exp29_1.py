import psycopg2

try:
  # Connect to PostgreSQL
  conn = psycopg2.connect(
    dbname="your_database",
    user="your_username",
    password="your_password",
    host="localhost",
    port="5432"
  )
  cursor = conn.cursor()
  
  # Create a table
  cursor.execute("CREATE TABLE IF NOT EXISTS students (id SERIAL PRIMARY KEY, name TEXT, age INT);")
  
  # Insert a record
  cursor.execute("INSERT INTO students (name, age) VALUES (%s, %s);", ("Shirish", 20))
  
  # Fetch and display records
  cursor.execute("SELECT * FROM students;")
  records = cursor.fetchall()
  for row in records:
      print(row)

  # Commit and close
  conn.commit()
  cursor.close()
  conn.close()

except Exception as e:
  print("Error:", e)