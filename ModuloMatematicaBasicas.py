import PySimpleGUI as sg
from PIL import Image, ImageTk
import math

def collapse(layout, key):
	return sg.pin(sg.Column(layout, key=key, visible=False))


# def suma():

# 	SYMBOL_UP =    '▲ Procedimiento'
# 	SYMBOL_DOWN =  '▼ Procedimiento'

# 	datos = [
# 			[sg.Text("Primer numero: ")],
# 			[sg.Input(key='-INPUT1-')],
# 			[sg.Text("Segundo numero: ")],
# 			[sg.Input(key='-INPUT2-')],	
# 			[sg.T(key='Resultado')],
# 			[sg.Button('Aceptar'), sg.Button('Salir')]
# 		]
# 	process = [
# 				# [sg.Multiline(size=(80,15), key='-ml-', autoscroll=True, disabled=False)]
# 	    		[sg.Canvas(size=(300, 300), background_color='#afeeee', key='-canvas-')]
# 			]
# 	layout = [	datos,
# 				[sg.B(SYMBOL_DOWN,  key="-open_process-")],
# 				[collapse(process, '-Process-')]
# 			]

# 	window = sg.Window('Suma', layout, modal=True, finalize=True)

# 	canvas = window['-canvas-']
# 	cir = canvas.TKCanvas.create_oval(50, 50, 100, 100) 
# 	tex = canvas.TKCanvas.create_text(100, 10, fill="darkblue", font="Times 20 italic bold", text="Bla bla bla")  
    
# 	coin = Image.open("coin.png")
# 	resizCoin = coin.resize((40, 40))
# 	imgCoin = ImageTk.PhotoImage(resizCoin)
# 	img = canvas.TKCanvas.create_image(20, 20, image=imgCoin, anchor='center')
# 	# cir = window['-canvas-'].TKCanvas.create_oval(50, 50, 100, 100)

# 	opened1 = False

# 	while True:
# 		event, values = window.read()
# 		if event == sg.WINDOW_CLOSED or event == 'Salir':
# 			break
# 		if event == 'Aceptar':
# 			if values['-INPUT1-'].isnumeric() and values['-INPUT2-'].isnumeric():
# 				a=int(values['-INPUT1-'])
# 				b=int(values['-INPUT2-'])
# 				window['Resultado'].update("La suma de {0} + {1} es {2}".format(values['-INPUT1-'], values['-INPUT2-'], sumar(a, b)))

# 				canvas.TKCanvas.itemconfig(cir, fill="Blue")

# 				canvas.TKCanvas.itemconfig(tex, text="cambio de texto")

# 				window['-canvas-'].TKCanvas.move(cir, 20, 20)

# 				canvas.TKCanvas.itemconfig(img)

# 				window['-canvas-'].TKCanvas.move(img, 120, 120)


# 				# window['-ml-'].update("La suma de {0} + {1} es {2}\n".format(values['-INPUT1-'], values['-INPUT2-'], sumar(a, b)))
# 				# window['-ml-'].update("Unidades\t\tDecenas\t\tMillares\n⊡ = 1\t\t⸦⸬⸬⸬⸧ = 10\t\t‖ = 1000\n", append=True)
# 				# window['-ml-'].update("""
# 				# N= 123
# 				# ⸦⸬⸬⸬⸧ ⸦⸬⸬⸬⸧ ⸦⸬⸬⸬⸧		⸦⸬⸬⸬⸧ ⸦⸬⸬⸬⸧		⊡⊡⊡
# 				# ⸦⸬⸬⸬⸧ ⸦⸬⸬⸬⸧ ⸦⸬⸬⸬⸧
# 				# ⸦⸬⸬⸬⸧ ⸦⸬⸬⸬⸧ ⸦⸬⸬⸬⸧
# 				# ⸦⸬⸬⸬⸧
# 			 #     100		            		20           	3""", append=True)
# 			else:
# 				window['Resultado'].update("Debes de escribir dos numeros para sumar!")							

# 		if event.startswith('-open_process-'):
# 			opened1 = not opened1
# 			window['-open_process-'].update(SYMBOL_DOWN if opened1 else SYMBOL_UP)
# 			window['-Process-'].update(visible=opened1)
			

# 	window.close()

# def sumar(a, b):
# 	return (a + b)

def imprimirImagen(lista,unidad,imagen,longitud):
	print(unidad)
	d= int(longitud)
	lista.append(d)
	print('Lista {}: '.format(unidad),lista)
	ejeY = 20
	for i in lista:
		ejeX = 30
		x=1
		while x <= d:
			print('x:',x,' i:',longitud)
			print(canvas.TKCanvas.create_image((ejeX), (ejeY), image=imagen, anchor='center'))
			x += 1
			ejeX += 30
		ejeY += 40



def suma():

	SYMBOL_UP =    '▲ Procedimiento'
	SYMBOL_DOWN =  '▼ Procedimiento'

	datos = [
			[sg.Text("Suma de numeros: ")],
			[sg.Input(key='-INPUT1-')],
			[sg.T(key='Resultado')],
			[sg.Button('Aceptar'), sg.Button('Salir')]
		]
	process = [[sg.Canvas(size=(300, 300), background_color='#afeeee', key='-canvas-')]]
	layout = [	datos,	[sg.B(SYMBOL_DOWN,  key="-open_process-")], [collapse(process, '-Process-')]]

	window = sg.Window('Suma', layout, modal=True, finalize=True)

	canvas = window['-canvas-']
#	cir = canvas.TKCanvas.create_oval(50, 50, 100, 100) 
#	tex = canvas.TKCanvas.create_text(100, 10, fill="darkblue", font="Times 20 italic bold", text="Bla bla bla")  
    
	coin = Image.open("coin.png")
	resizCoin = coin.resize((20, 20))
	imgCoin = ImageTk.PhotoImage(resizCoin)
	coin10 = Image.open("coin10.png")
	resizCoin10 = coin10.resize((30, 30))
	imgCoin10 = ImageTk.PhotoImage(resizCoin10)
#	img = canvas.TKCanvas.create_image(20, 20, image=imgCoin, anchor='center')

	opened1 = False
	while True:
		event, values = window.read()
		if event == sg.WINDOW_CLOSED or event == 'Salir':
			break
		if event == 'Aceptar':
			if values['-INPUT1-']:
				sep = values['-INPUT1-'].split('+')
				clean = [num.strip(' ') for num in sep]
				check = [int(s) for s in clean if s.isdigit()]
				check2 = [s for s in clean if s.isdigit()]

				un=[]
				de=[]
				ce=[]
				mi=[]
#				ejeY = 20
				for i in check2:
					if len(i) == 1:
						imprimirImagen(un,'Unidades',imgCoin,i)
					elif len(i) == 2:
						print('Decenas')
						d= int(i)
						d *=.1
						de.append(d)
						print('Lista Decenas: ',de)
						ejeY = 20
						for i in de:
							ejeX = 30
							x=1
							while x <= i:
								print('x:',x,' i:',i)
								print(canvas.TKCanvas.create_image((ejeX), (ejeY), image=imgCoin10, anchor='center'))
								x += 1
								ejeX += 30
							ejeY += 40
					elif len(i) == 3:
						print('Centenas')
						c= int(i)
						ce.append(c)
						print(ce)
					elif len(i) == 4:
						print('Millares')
						m= int(i)
						mi.append(m)
						print(mi)
					ejeY += 40

				# canvas.TKCanvas.itemconfig(tex, text="Text: {0}".format(u))
				Fin = sum(check)
			
				window['Resultado'].update("La suma es {0}".format(Fin))
				

#				canvas.TKCanvas.itemconfig(cir, fill="Blue")

				# canvas.TKCanvas.itemconfig(tex, text="cambio de texto")

#				window['-canvas-'].TKCanvas.move(cir, 20, 20)

#				canvas.TKCanvas.itemconfig(img)
				
#				window['-canvas-'].TKCanvas.move(img, 120, 120)
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

