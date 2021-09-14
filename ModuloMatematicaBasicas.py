from tkinter import *

from PIL import Image, ImageTk

import PySimpleGUI as sg

import math

#variables globales
ejeY = 20

def collapse(layout, key):
	return sg.pin(sg.Column(layout, key=key, visible=False))
	
def imprimirImagen(lista_numeros ,lista_imagen, cantidad_elementos, canvas, signo='N'):
												#lista_numeros[12] 	|	lista_numeros[2,2]
												#cantidad_elem[1]	|	cantidad_elem[2]
	for num in lista_numeros:
		aux = list(str(num))					#['1','2']			|	['2']
		sep = [int(x) for x in aux]				#[1,2]				|	[2]
		print('sep:',sep)

		ejeX = 60
		global ejeY

		img = len(str(num))-1					#len(str(12))-1 = 1	| len(str(2))-1 = 0
		i = 0

		print('lista numeros:{}, cantidad_elementos:{}, String:{}, num:{}, img:{}'.format(lista_numeros,cantidad_elementos,signo,num,img))

		for n in sep:							#[1]->[2]	|	[2]
			m = 1
			while m <= sep[i]: 
				canvas.create_image((ejeX),(ejeY),image=lista_imagen[img],anchor='center')
				ejeX+=30
				m+=1
			img-=1
			i+=1
		ejeY+=32
		sep.clear()

	if signo == 'S':
		canvas.create_text(10, ejeY/2, fill="darkblue", font="Times 25 italic bold", text="+")
	
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


	unidad = Image.open("Unidades.png")
	resize_unidad = unidad.resize((20, 20))
	img_unidad = ImageTk.PhotoImage(resize_unidad)

	decena = Image.open("Decenas.png")
	resize_decena = decena.resize((20, 20))
	img_decena = ImageTk.PhotoImage(resize_decena)

	centena = Image.open("Centenas.png")
	resize_centena = centena.resize((20, 20))
	img_centena = ImageTk.PhotoImage(resize_centena)

	unidadesMillar = Image.open("UnidadesMillar.png")
	resize_unidadesMillar = unidadesMillar.resize((20, 20))
	img_millar = ImageTk.PhotoImage(resize_unidadesMillar)

	decenasMillar = Image.open("DecenasMillar.png")
	resize_decenasMillar = decenasMillar.resize((20, 20))
	img_decena_millar = ImageTk.PhotoImage(resize_decenasMillar)	

	centenasMillar = Image.open("CentenasMillar.png")
	resize_centenasMillar = centenasMillar.resize((20, 20))
	img_centena_millar = ImageTk.PhotoImage(resize_centenasMillar)		

	millon = Image.open("UnidadMillon.png")
	resize_millon = millon.resize((20, 20))
	img_millon = ImageTk.PhotoImage(resize_millon)

	guia = Image.open("Resume.png")
	resize_resume = guia.resize((250,100))
	img_resume = ImageTk.PhotoImage(resize_resume)


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
				cantidad_elementos = len(sep)
				clean = [num.strip(' ') for num in sep]				#quita posibles espacios ingresados
				check = [int(s) for s in clean if s.isdigit()]		#convierte numeros str en int
				print('Lista: ',check,'\n')
				sumatoria = sum(check)
				window['Resultado'].update("La suma es {0}".format(sumatoria))

				#inicio de la impresion de imagenes
				#NOTA: pruebas.py tiene codigo para la linea de resultado
				imprimirImagen(check, imagenes, cantidad_elementos, canvass, 'S')
				aux = []					#lista vacia para convertir el resultado
				aux.append(sumatoria)
				global ejeY

				#create_line(ejeX,inicio_de_linea_ejeY, longitud_de_linea, final_de_linea_ejeY)
				canvass.create_line(0, ejeY-10, 400, ejeY-10, fill="black", width="5")
				ejeY += 12

				imprimirImagen(aux, imagenes, 0, canvass)
				ejeY = 20
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

