from tkinter import Canvas
import PySimpleGUI as sg
from PIL import Image, ImageTk
import math

def collapse(layout, key):
	return sg.pin(sg.Column(layout, key=key, visible=False))
	
def imprimirImagen(lista ,imagen, canvas):
	#2345 #123 #12 #4
	#2345+123+12+4

	ejeY=20
	for num in lista:
		sep = resto(num) #[2,3,4,5]
		m=1
		c=1
		d=1
		u=1
		ejeX=20

		while m <= sep[0]:
			canvas.create_image((ejeX),(ejeY),image=imagen[3],anchor='center')
			ejeX+=32
			m+=1
		while c <= sep[1]:
			canvas.create_image((ejeX),(ejeY),image=imagen[2],anchor='center')
			ejeX+=32
			c+=1
		while d <= sep[2]:
			canvas.create_image((ejeX),(ejeY),image=imagen[1],anchor='center')
			ejeX+=20
			d+=1
		while u <= sep[3]:
			canvas.create_image((ejeX),(ejeY),image=imagen[0],anchor='center')
			ejeX+=15
			u+=1
		ejeY+=30
	

def resto(num):
	tmp=[]
	millar = (num//1000)	#2   0   0  0
	restoM = num%1000		#345 123 12 4
	tmp.append(millar)

	centena = (restoM//100) #3   1   0  0
	restoC = (restoM%100) 	#45  23  12 4
	tmp.append(centena)

	decena = (restoC//10)	#4   2   1  0 
	restoD = (restoC%10) 	#5   3   2  4
	tmp.append(decena)

	unidad = (restoD//1) 	#5   3   2  4
	restoU = (restoD%1) 	#0   0   0  0
	tmp.append(unidad)
	return tmp


def suma():

	SYMBOL_UP =    '▲ Procedimiento'
	SYMBOL_DOWN =  '▼ Procedimiento'

	datos = [
			[sg.Text("Suma de numeros: ")],
			[sg.Input(key='-INPUT1-')],
			[sg.T(key='Resultado')],
			[sg.Button('Aceptar'), sg.Button('Salir')]
		]
	process = [[sg.Canvas(size=(450, 300), background_color='#afeeee', key='-canvas-')]]
	layout = [	datos,	[sg.B(SYMBOL_DOWN,  key="-open_process-")], [collapse(process, '-Process-')]]

	window = sg.Window('Suma', layout, modal=True, finalize=True)

	canvas = window['-canvas-']
	canvass = canvas.TKCanvas
     
	# coin = Image.open("coin.png")
	coin = Image.open("unidad.png")
	resizCoin = coin.resize((20, 20))
	imgCoin = ImageTk.PhotoImage(resizCoin)

	# coin10 = Image.open("coin10.png")
	coin10 = Image.open("decena.png")
	resizCoin10 = coin10.resize((30, 30))
	imgCoin10 = ImageTk.PhotoImage(resizCoin10)

	coin100 = Image.open("centena.png")
	resizCoin100 = coin100.resize((30, 30))
	imgCoin100 = ImageTk.PhotoImage(resizCoin100)

	coin1000 = Image.open("coin10.png")
	resizCoin1000 = coin1000.resize((30, 30))
	imgCoin1000 = ImageTk.PhotoImage(resizCoin1000)

	


	opened1 = False
	while True:
		event, values = window.read()
		if event == sg.WINDOW_CLOSED or event == 'Salir':
			break
		if event == 'Aceptar':
			canvass.delete('all')
			if values['-INPUT1-']:
				sep = values['-INPUT1-'].split('+')
				clean = [num.strip(' ') for num in sep]
				check = [int(s) for s in clean if s.isdigit()]
				# check2 = [s for s in clean if s.isdigit()]
				# check.sort()
				print('Lista: ',check,'\n')
				un=[]
				de=[]
				ce=[]
				mi=[]
				imagenes=[imgCoin,imgCoin10,imgCoin100,imgCoin1000]
				# for i in check2:
				# 	# if len(i) == 1:
						
				# 	# 	# imprimirImagen(un,'Unidades',imgCoin,i,1,canvass)
				# 	# elif len(i) == 2:

				# 	# 	# varX = imprimirImagen(de,'Decenas',imgCoin10,i,10,canvass)
				# 	# 	# last_char = i[-1]
				# 	# 	# print('Return var: ',varX)
				# 	# 	# imprimirImagen(un,'Unidades',imgCoin,last_char,90,1,canvass)

				# 	# elif len(i) == 3:
				# 	# 	print('Centenas')
				# 	# 	print(ce)
				# 	# elif len(i) == 4:
				# 	# 	print('Millares')
				# 	# 	m= int(i)
				# 	# 	mi.append(m)
				# 	# 	print(mi)
				# for i in check:
				# imprimirImagen(check,imagenes,i,canvass)
				imprimirImagen(check,imagenes,canvass)
				Fin = sum(check)
			
				window['Resultado'].update("La suma es {0}".format(Fin))
			else:
				window['Resultado'].update("Debes de escribir al menos dos numeros para sumar!")							

		if event.startswith('-open_process-'):
			opened1 = not opened1
			window['-open_process-'].update(SYMBOL_DOWN if opened1 else SYMBOL_UP)
			window['-Process-'].update(visible=opened1)
	window.close()

def sumar(a, b):
	return (a + b)







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
		if event == WINDOW_CLOSED or event == 'Salir':
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
		if event == WINDOW_CLOSED or event == 'Salir':
			break
		CatetoOpuesto = float(values['CateoOpuesto'])
		CatetoAdyacente = float(values['CatetoAdyacente'])
		hipotenusa = math.sqrt((CatetoOpuesto**2)+(CatetoAdyacente**2))
		window['resultado'].update('La hipotenusa resultante es {}'.format(hipotenusa))
	window.close()

