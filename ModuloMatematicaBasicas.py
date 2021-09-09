from tkinter import Canvas
from tkinter.constants import X
from tkinter import *

from PIL import Image, ImageTk

import PySimpleGUI as sg

import math

def collapse(layout, key):
	return sg.pin(sg.Column(layout, key=key, visible=False))
	
def imprimirImagen(lista_numeros ,lista_imagen, canvas):
	#2345 #123 #12 #4
	#2345+123+12+4

	ejeY=20
	num=0
	for num in lista_numeros:
		aux = list(str(num))					#separa el numero en lista
		sep = [int(x) for x in aux]				#convierte cada elemento de la lista aux en entero
#		sep = resto(num) #[2,3,4,5]
		print('sep:',sep)

		ejeX = 20
		img = len(str(num))
		i = 0
		for n in sep: 
			m = 1
			while m <= sep[i]: 
				canvas.create_image((ejeX),(ejeY),image=lista_imagen[img-1],anchor='center')
				ejeX+=30
				m+=1
			img-=1
			i+=1
		ejeY+=30
		sep.clear()
	

def suma():

	SYMBOL_UP =    '▲ Procedimiento'
	SYMBOL_DOWN =  '▼ Procedimiento'

	datos = [
			[sg.Text("Suma de numeros: ")],
			[sg.Input(key='-INPUT1-')],					#cadena de caracteres como entrada de datos
			[sg.T(key='Resultado')],
			[sg.Button('Aceptar'), sg.Button('Salir')]
		]
	process = [[sg.Canvas(size=(450, 300), background_color='#afeeee', key='-canvas-')]]
	layout = [	datos,	[sg.B(SYMBOL_DOWN,  key="-open_process-")], [collapse(process, '-Process-')]]

	window = sg.Window('Suma', layout, modal=True, finalize=True)

	canvas = window['-canvas-']
	canvass = canvas.TKCanvas

	unidad = Image.open("unidad.png")
	resize_unidad = unidad.resize((20, 20))
	img_unidad = ImageTk.PhotoImage(resize_unidad)

	decena = Image.open("decena.png")
	resize_decena = decena.resize((30, 30))
	img_decena = ImageTk.PhotoImage(resize_decena)

	centena = Image.open("centena.png")
	resize_centena = centena.resize((30, 30))
	img_centena = ImageTk.PhotoImage(resize_centena)

	millar = Image.open("millar.png")
	resize_millar = millar.resize((30, 30))
	img_millar = ImageTk.PhotoImage(resize_millar)

	decena_millar = Image.open("decenas de millar.png")
	resize_decena_millar = decena_millar.resize((30, 30))
	img_decena_millar = ImageTk.PhotoImage(resize_decena_millar)

	centena_millar = Image.open("centenas de millar.png")
	resize_centena_millar = centena_millar.resize((30, 30))
	img_centena_millar = ImageTk.PhotoImage(resize_centena_millar)

	millon = Image.open("coin.png")
	resize_millon = millon.resize((40, 40))
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
				sep = values['-INPUT1-'].split('+')					#separa la cadena de caracteres en lista de str
				clean = [num.strip(' ') for num in sep]				#quita posibles espacios ingresados
				check = [int(s) for s in clean if s.isdigit()]		#convierte numeros str en int
				print('Lista: ',check,'\n')
				sumatoria = sum(check)
				window['Resultado'].update("La suma es {0}".format(sumatoria))

				#inicio de la impresion de imagenes
				imprimirImagen(check,imagenes,canvass)
				aux = []
#				check.append(sumatoria)
				aux.append(sumatoria)
#				print(type(check))
#				print('check: ',check)
				print(type(aux))
				print('aux: ',aux)
#				imprimirImagen(check, imagenes, canvass)
				imprimirImagen(aux, imagenes, canvass)
			else:
				window['Resultado'].update("Debes de escribir al menos dos numeros para sumar!")							

		if event.startswith('-open_process-'):
			opened1 = not opened1
			window['-open_process-'].update(SYMBOL_DOWN if opened1 else SYMBOL_UP)
			window['-Process-'].update(visible=opened1)
	window.close()















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


def multiplicacion():
	layout = [
				[sg.T("Multiplicacion de numeros: ")],[sg.Input(key="Numeros")],
				[sg.B('Aceptar'), sg.B('Salir')]
			]
	window = sg.Window("Multiplicacion", layout, modal=True)
	while True:
		event, values = window.read()
		if event == sg.WINDOW_CLOSED or event == 'Salir':
			break
		Sep = values['Numeros'].split('*')
		clean = [num.strip(' ') for num in Sep]
		Total = [int(i) for i in clean]
		Fin = 1
		for x in Total:
			Fin *= x
		print(Fin)
	window.close()

# def mul(n):
# 	total = 1
# 	for i in range(0, len(n)):
# 		total *= n[i]
# 	print total

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

def Division():
	layout = [
		[sg.Text('Teclee el dividendo')],
		[sg.Input(key='-Input2-')],
		[sg.Text('Teclee el divisor')],
		[sg.Input(key='-Input1-')],
		[sg.Text(key='resultado')],
		[sg.Button('aceptar'), sg.Button('Salir')],
	]

	window = sg.Window('División', layout, modal = True)
	while True:
		event, values = window.read()
		if event == sg.WINDOW_CLOSED or event == 'Salir':
			break
		a=float(values['-Input1-'])
		b=float(values['-Input2-'])
		if (a <= 0) or (b <= 0):
			window['resultado'].update('Error: los números deben ser positivos')
		else:
			window['resultado'].update('El resultado es {}'.format(dividir(a,b)))
	window.close()

def dividir(divisor, dividendo):
	return (dividendo/divisor)

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

