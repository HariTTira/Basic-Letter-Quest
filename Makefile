all:
	g++ -Isrc/include -L src/lib -o main main.cpp Game.cpp TextureManager.cpp GameObject.cpp Player.cpp RandomLetter.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf