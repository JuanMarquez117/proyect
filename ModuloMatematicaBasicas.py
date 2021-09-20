from tkinter import *

from PIL import Image, ImageTk

import PySimpleGUI as sg

import math

#variables globales
ejeX = 20

def collapse(layout, key):
	return sg.pin(sg.Column(layout, key=key, visible=False))
	
def imprimirImagen(lista_numeros ,lista_imagen, cantidad_elementos, canvas, signo=None, simbolo='N'):
												#lista_numeros[12] 	|	lista_numeros[2,2]
												#cantidad_elem[1]	|	cantidad_elem[2]
	bandera = 1
	for num in lista_numeros:
		aux = list(str(num))					#['1','2']			|	['2']
		sep = [int(x) for x in aux]				#[1,2]				|	[2]
		print('sep:',sep)

		ejeY = 60
		global ejeX

		img = len(str(num))-1					#len(str(12))-1 = 1	| len(str(2))-1 = 0
		i = 0
		print('lista numeros:{}, cantidad_elementos:{}, Simbolo:{}, Signo:{}, num:{}, img:{}'.format(lista_numeros, cantidad_elementos, simbolo, signo, num, img))

		for n in sep:							#[1]->[2]	|	[2]
			m = 0
			print('sep: ',sep)
			if sep[i] != 0:
				while m < sep[i]:
					canvas.create_image((ejeX),(ejeY),image=lista_imagen[img],anchor='center')
					ejeY+=20		#controla el espaciado entre elementos iguales
					m+=1
			else:
				ejeX-=25			#si hay ceros, ignora el espacio del tipo de elemento correspondiente
			img-=1
			i+=1
			ejeY=60		#Posiciona a la misma altura la separacion de unidades, decenas, centenas
			ejeX+=25	#separa los tipos de elementos que hay en cada numero ingresado
		if simbolo == 'S' and bandera < len(lista_numeros):
			ejeX+=10		#espacia el signo
			bandera+=1
			canvas.create_text(ejeX, ejeY+25, fill="darkblue", font="Times 25 italic bold", text=signo)
		ejeX+=30	#Separacion entre ultimo elemento de la suma y la linea de resultado o siguiente grupo
		sep.clear()
		
	


def general(Operacion, Funcion, Signo):
	SYMBOL_UP =    '▲ Procedimiento'
	SYMBOL_DOWN =  '▼ Procedimiento'

	datos = [
			[sg.Text(Operacion + " de numeros: ")],
			[sg.Input(key='-INPUT1-')],		
			[sg.T(key='Resultado')],
			[sg.Button('Aceptar'), sg.Button('Salir')]
		]
	process = [[sg.Canvas(size=(450, 300), background_color='#afeeee', key='-canvas-')]]
	layout = [datos,[sg.B(SYMBOL_DOWN,  key="-open_process-")], [collapse(process, '-Process-')]]

	window = sg.Window(Operacion, layout, modal=True, finalize=True)
	canvas = window['-canvas-']
	canvass = canvas.TKCanvas
	h, w = 25,25

	unidad = Image.open("Unidades.png")
	resize_unidad = unidad.resize((h,w))
	img_unidad = ImageTk.PhotoImage(resize_unidad)

	decena = Image.open("Decenas.png")
	resize_decena = decena.resize((h,w))
	img_decena = ImageTk.PhotoImage(resize_decena)

	centena = Image.open("Centenas.png")
	resize_centena = centena.resize((h,w))
	img_centena = ImageTk.PhotoImage(resize_centena)

	unidadesMillar = Image.open("UnidadesMillar.png")
	resize_unidadesMillar = unidadesMillar.resize((h,w))
	img_millar = ImageTk.PhotoImage(resize_unidadesMillar)

	decenasMillar = Image.open("DecenasMillar.png")
	resize_decenasMillar = decenasMillar.resize((h,w))
	img_decena_millar = ImageTk.PhotoImage(resize_decenasMillar)	

	centenasMillar = Image.open("CentenasMillar.png")
	resize_centenasMillar = centenasMillar.resize((h,w))
	img_centena_millar = ImageTk.PhotoImage(resize_centenasMillar)		

	millon = Image.open("UnidadMillon.png")
	resize_millon = millon.resize((h,w))
	img_millon = ImageTk.PhotoImage(resize_millon)

	imagenes = [img_unidad, img_decena, img_centena, img_millar, img_decena_millar,
				img_centena_millar, img_millon]

	opened1 = False
	while True:
		event, values = window.read()
		if event == sg.WINDOW_CLOSED or event == 'Salir':
			break
		if event == 'Aceptar':
			canvass.delete('all')
			if values['-INPUT1-']:
				sep = values['-INPUT1-'].split(Signo)	
				cantidad_elementos = len(sep)
				clean = [num.strip(' ') for num in sep]
				check = [int(s) for s in clean if s.isdigit()]
				print('Lista: ',check,'\n')

				Resultado = Funcion(check)

				window['Resultado'].update("La {0} es {1}".format(Operacion, Resultado))

				imprimirImagen(check, imagenes, cantidad_elementos, canvass, Signo, 'S')
				aux = []				
				aux.append(Resultado)
				global ejeX

				canvass.create_line(ejeX-10, 50 , ejeX-10 , 200, fill="black", width="5")
				ejeX += 12

				imprimirImagen(aux, imagenes, 0, canvass)
				ejeX = 20
			else:
				window['Resultado'].update("Debes de escribir al menos un numero")							

		if event.startswith('-open_process-'):
			opened1 = not opened1
			window['-open_process-'].update(SYMBOL_DOWN if opened1 else SYMBOL_UP)
			window['-Process-'].update(visible=opened1)
	window.close()


def suma(list):
	return sum(list)

def multiplicacion(list):
	return 0 if len(list)==0 else list[0] if len(list)==1 else list[0]*multiplicacion(list[1:])

def dividir(list):
	# 0 2	= 0
	# 0 0	= Resultado indefinido	
	# 2 0 	= Error, no se puede dividir entre 0
	# 2 2	= 1
	pass



def areaRectangulo():
	layout = [
			[sg.T("Base del rectangulo: ")], [sg.I(key='Base')],
			[sg.T("Altura del rectangulo: ")], [sg.I(key='Altura')],
			[sg.T(key='Resultado')],
			[sg.B('Aceptar'), sg.B('Salir')]
		]
	window = sg.Window('Area Rectangulo', layout, modal=True)
	while True:
		event, values = window.read()
		if event == sg.WINDOW_CLOSED or event == 'Salir':
			break

		a = int(values['Altura'])
		b = int(values['Base'])
		area = (b * a)
		window['Resultado'].update('El area del rectangulo es: {}'.format(area))
		# print("Area es igual a: {}".format(area))
	window.close()


def ComparacionNumero():
	layout = [
		[sg.Text('Teclee el primer número')],
		[sg.Input(key='-INPUT1-')],
		[sg.Text('Teclee el segundo numero')],
		[sg.Input(key='-INPUT2-')],
		[sg.Text(key='resultado')],
		[sg.Button('Aceptar'), sg.Button('Salir')],
	]

	window = sg.Window('Comparacion de números', layout, modal = True)
	while True:
		event, values = window.read()
		if event == sg.WINDOW_CLOSED or event == 'Salir':
			break
		a=(values['-INPUT1-'])
		b=(values['-INPUT2-'])
		if (a < b):
			window['resultado'].update("El número {0} es menor que {1}".format(values['-INPUT1-'], values['-INPUT2-']))
		elif(a > b):
			window['resultado'].update('El numero {0} es mayor que {1}'.format(values['-INPUT1-'], values['-INPUT2-']))
		else:
			window['resultado'].update('Los números son iguales')
	window.close()


def PorcentajeReglaTres():
	layout = [
		[sg.Text('Teclee el total')],
		[sg.Input(key='total')],
		[sg.Text('Teclee la cantidad a calcular')],
		[sg.Input(key='cantidad')],
		[sg.Text(key='resultado')],
		[sg.Button('Aceptar'), sg.Button('Salir')],
	]
	window = sg.Window('Porcentaje en regla de tres', layout, modal = True)
	while True:
		event, values = window.read()
		if event == sg.WINDOW_CLOSED or event == 'Salir':
			break
		total = float(values['total'])
		cantidad = float(values['cantidad'])
		porcentaje = float(total/100)*cantidad
		window['resultado'].update('El porcentaje correspondiente es {}'.format(porcentaje))
	window.close()

def HipotenusaPitagoras():
	layout = [
		[sg.Text('Teclee la longitud del cateto opuesto')],
		[sg.Input(key='CatetoOpuesto')],
		[sg.Text('Teclee la longitud del cateto adyacente')],
		[sg.Input(key='CatetoAdyacente')],
		[sg.Text(key='resultado')],
		[sg.Button('Aceptar'), sg.Button('Salir')],
	]
	window = sg.Window('Hipotenusa en teorema de pitagoras', layout, modal=True)
	while True:
		event, values = window.read()
		if event == sg.WINDOW_CLOSED or event == 'Salir':
			break
		CatetoOpuesto = float(values['CateoOpuesto'])
		CatetoAdyacente = float(values['CatetoAdyacente'])
		hipotenusa = math.sqrt((CatetoOpuesto**2)+(CatetoAdyacente**2))
		window['resultado'].update('La hipotenusa resultante es {}'.format(hipotenusa))
	window.close()

