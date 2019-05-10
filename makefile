plot.gif: datos30.dat MontanaAna_Ej30.py
	python MontanaAna_Ej30.py 


datos30.dat: MontanaAna_Ej30.x
	./MontanaAna_Ej30.x 

MontanaAna_Ej30.x: MontanaAna_Ej30.cpp
	g++ MontanaAna_Ej30.cpp -o MontanaAna_Ej30.x

clean: 
	rm -rf MontanaAna_Ej30.x datos30.dat plot.gif

