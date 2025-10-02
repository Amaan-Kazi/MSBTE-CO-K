cars = {
  "Toyota": 4,
  "Hyundai": 10,
  "Mercedes": 2,
  "Lamborghini": 3,
  "Bugatti": 5
}

top3 = dict( sorted(cars.items(), reverse=True, key=lambda item:item[1])[:3] )
print(top3)
