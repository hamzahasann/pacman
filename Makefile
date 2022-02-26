all:
	g++ main.cpp -o main.exe -DSFML_STATIC -I D:\Clibary\SFML\include -L D:\Clibary\SFML\lib -lsfml-window-s -lsfml-graphics-s -lsfml-audio-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype -lopenal32 -lflac -lvorbisenc -lvorbisfile -lvorbis -logg

run:
	main
