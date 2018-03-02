# Source (Developers)  ------------ OUTDATED/DESOLETE [2/3/2018] -------------

Copying the work done by people mentioned/contributed in the following link :

- https://github.com/omkarmoghe/Pokemap
- https://github.com/AHAAAAAAA/PokemonGo-Map (Read The ReadMe for the Old Original Version, for working of it)

Note : (The above Project is closed, but another following project which is a fork of it is working)

- https://github.com/PokemonGoMap/PokemonGo-Map (Working Fork)


# Objective 

I am recreating the results.

The Downloaded compiled file is the latest running build as of (10:26am Friday, 28 August, 2016)



# Directions 

Some commands that i ran (so specific order)

```sh
git clone https://github.com/PokemonGoMap/PokemonGo-Map.git
```

Open up the folder PokemonGo-Maps/config
```sh
	cd PokemonGo-Map/config
	cp config.ini.example config.ini
```

Edit this above copy of config.ini

```
	(Uncomment gmaps-key and copy paste the google api - browser key [create credentials -> api key -> browser key] against it)
	gmaps-key: AIzaSyCUKE3-7z2WtEm0K-_HJTuc7xhYH1ZQkxI
```

```sh
	mkvirtualenv pokemonGoMaps 		# already exists 
	workon pokemonGoMaps
	pip install -r requirements.txt   # done

	sudo npm install -g grunt-cli
	sudo npm install && npm run build


	python runserver.py -a ptc  -u felizlorenzo -p mindgenius -l "12.9409 77.6305" -st 100 -H 0.0.0.0  ## Ejipura Location
	python runserver.py -a ptc  -u felizlorenzo -p mindgenius -l "21.1316 79.0978" -st 100 -H 0.0.0.0  ## Nagpur Location
	python runserver.py -a ptc  -u felizlorenzo -p mindgenius -l "40.785091 -73.968285" -st 100 -H 0.0.0.0  ## Central Park  Location
	python runserver.py -a ptc  -u felizlorenzo -p mindgenius -l "40.702318 -73.996297" -st 100 -H 0.0.0.0 	## Another NY location

```

Link to check :
http://localhost:5000

# Reference 

- Vedio Tutorial : https://www.youtube.com/watch?v=2ACJHCNZ3ow




