marvel_heroes = ['Iron Man', 'Spider-Man', 'Captain America']
dc_heroes = ['Batman', 'Flash', 'Aquaman']

del(dc_heroes[1])
print(dc_heroes)

dc_heroes.insert(1,'Flash')
print(dc_heroes)

dc_heroes.append('Green Arrow')
print(dc_heroes)

print( dc_heroes.index('Green Arrow') ) # Returns the index of the object

dc_heroes.remove('Aquaman')
print(dc_heroes)
dc_heroes.reverse()
print(dc_heroes)
print(dc_heroes.count("Batman"))

heroes = marvel_heroes + dc_heroes
print(heroes)