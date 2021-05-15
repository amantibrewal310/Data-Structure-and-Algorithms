marvel_heroes = {
    'Iron Man' : 100,
    'Spider-Man' : 90,
    'Captain America' : 85
}

dc_heroes = {
    'Batman' : 100,
    'Flash' : 95,
    'Green Arrow' : 90
}

print( len(dc_heroes) )
print( len(marvel_heroes) )
print( dc_heroes.keys() )
print( dc_heroes.values() )

dc_heroes.update(marvel_heroes)
print(dc_heroes)

myTags = ("Name", "Last_Name", "Age", "Phone")
myOne = dict.fromkeys(myTags)
print("My dictionay is : %s" %str(myOne) )