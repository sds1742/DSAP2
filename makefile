output: main.cpp math.cpp Priority.cpp customer.cpp event.cpp
	g++ main.cpp math.cpp Priority.cpp customer.cpp event.cpp -o output.exe
clean:
	rm output.exe

