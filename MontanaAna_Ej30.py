import numpy as np
import matplotlib.animation as animation
import matplotlib.pyplot as plt 


datos = np.genfromtxt("datos30.dat")
x=datos.shape[1]
t=datos.shape[0]



##con la documentacionde matplotlib animation en la siguiente pagina https://jakevdp.github.io/blog/2012/08/18/matplotlib-animation-tutorial/
x= np.linspace(0,1,x)
y=[]
figura, imagen = plt.subplots(figsize=(8,5))
imagen.grid()
imagen2, = plt.plot(x, datos[0])

def primero():  
    imagen.set_xlim(0, 1)
    imagen.set_ylim(-0.05, 0.05)
    imagen.set_xlabel("Posicion [metros]")
    imagen.set_ylabel("U")
    return imagen2,
def animanacionn(i):
    imagen2.set_ydata(datos[i])
    imagen.set_title("Tiempo: "+ str("{0:.2f}".format(2*i/(t-1)))+ " segundos")
    return ln,


animacion = animation.FuncAnimation(figura, animanacionn, init_func=primero, interval=100,frames=range(t), blit=True,repeat=True)


animacion.save("plot.gif",fps=10)